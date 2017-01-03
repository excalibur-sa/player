/*
 * Copyright (C) 2003-2016 Free Software Foundation, Inc.
 * Copyright (C) 2014-2016 Red Hat
 * Copyright (C) 2014-2016 Nikos Mavrogiannopoulos
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GnuTLS.
 *
 * The GnuTLS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

#include "gnutls_int.h"

#include <datum.h>
#include <global.h>
#include "errors.h"
#include <common.h>
#include <x509.h>
#include <x509_b64.h>
#include "x509_int.h"
#include "pkcs7_int.h"
#include <algorithms.h>
#include <num.h>
#include <random.h>
#include <pk.h>
#include <nettle/pbkdf2.h>

static int _decode_pkcs8_ecc_key(ASN1_TYPE pkcs8_asn,
				 gnutls_x509_privkey_t pkey);
static
int pkcs8_key_info(const gnutls_datum_t * raw_key,
		   const struct pkcs_cipher_schema_st **p,
		   struct pbkdf2_params *kdf_params,
		   char **oid);

static int decode_private_key_info(const gnutls_datum_t * der,
				   gnutls_x509_privkey_t pkey);

#define PEM_PKCS8 "ENCRYPTED PRIVATE KEY"
#define PEM_UNENCRYPTED_PKCS8 "PRIVATE KEY"

/* Returns a negative error code if the encryption schema in
 * the OID is not supported. The schema ID is returned.
 */
/* Encodes a private key to the raw format PKCS #8 needs.
 * For RSA it is a PKCS #1 DER private key and for DSA it is
 * an ASN.1 INTEGER of the x value.
 */
inline static int
_encode_privkey(gnutls_x509_privkey_t pkey, gnutls_datum_t * raw)
{
	int ret;
	ASN1_TYPE spk = ASN1_TYPE_EMPTY;

	switch (pkey->pk_algorithm) {
	case GNUTLS_PK_RSA:
	case GNUTLS_PK_EC:
		ret =
		    gnutls_x509_privkey_export2(pkey, GNUTLS_X509_FMT_DER,
						raw);
		if (ret < 0) {
			gnutls_assert();
			goto error;
		}

		break;
	case GNUTLS_PK_DSA:
		/* DSAPublicKey == INTEGER */
		if ((ret = asn1_create_element
		     (_gnutls_get_gnutls_asn(), "GNUTLS.DSAPublicKey",
		      &spk))
		    != ASN1_SUCCESS) {
			gnutls_assert();
			return _gnutls_asn2err(ret);
		}

		ret =
		    _gnutls_x509_write_int(spk, "", pkey->params.params[4],
					   1);
		if (ret < 0) {
			gnutls_assert();
			goto error;
		}
		ret = _gnutls_x509_der_encode(spk, "", raw, 0);
		if (ret < 0) {
			gnutls_assert();
			goto error;
		}

		asn1_delete_structure2(&spk, ASN1_DELETE_FLAG_ZEROIZE);
		break;

	default:
		gnutls_assert();
		return GNUTLS_E_INVALID_REQUEST;
	}

	return 0;

      error:
	asn1_delete_structure2(&spk, ASN1_DELETE_FLAG_ZEROIZE);
	asn1_delete_structure(&spk);
	return ret;

}

/* 
 * Encodes a PKCS #1 private key to a PKCS #8 private key
 * info. The output will be allocated and stored into der. Also
 * the ASN1_TYPE of private key info will be returned.
 */
static int
encode_to_private_key_info(gnutls_x509_privkey_t pkey,
			   gnutls_datum_t * der, ASN1_TYPE * pkey_info)
{
	int result, len;
	uint8_t null = 0;
	const char *oid;
	gnutls_datum_t algo_params = { NULL, 0 };
	gnutls_datum_t algo_privkey = { NULL, 0 };

	oid = gnutls_pk_get_oid(pkey->pk_algorithm);
	if (oid == NULL) {
		gnutls_assert();
		return GNUTLS_E_UNIMPLEMENTED_FEATURE;
	}

	result =
	    _gnutls_x509_write_pubkey_params(pkey->pk_algorithm,
					     &pkey->params, &algo_params);
	if (result < 0) {
		gnutls_assert();
		return result;
	}

	if ((result =
	     asn1_create_element(_gnutls_get_pkix(),
				 "PKIX1.pkcs-8-PrivateKeyInfo",
				 pkey_info)) != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* Write the version.
	 */
	result = asn1_write_value(*pkey_info, "version", &null, 1);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* write the privateKeyAlgorithm
	 * fields. (OID+NULL data)
	 */
	result =
	    asn1_write_value(*pkey_info, "privateKeyAlgorithm.algorithm",
			     oid, 1);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	result =
	    asn1_write_value(*pkey_info, "privateKeyAlgorithm.parameters",
			     algo_params.data, algo_params.size);
	_gnutls_free_key_datum(&algo_params);

	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}


	/* Write the raw private key
	 */
	result = _encode_privkey(pkey, &algo_privkey);
	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	result =
	    asn1_write_value(*pkey_info, "privateKey", algo_privkey.data,
			     algo_privkey.size);
	_gnutls_free_key_datum(&algo_privkey);

	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* Append an empty Attributes field.
	 */
	result = asn1_write_value(*pkey_info, "attributes", NULL, 0);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* DER Encode the generated private key info.
	 */
	len = 0;
	result = asn1_der_coding(*pkey_info, "", NULL, &len, NULL);
	if (result != ASN1_MEM_ERROR) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* allocate data for the der
	 */
	der->size = len;
	der->data = gnutls_malloc(len);
	if (der->data == NULL) {
		gnutls_assert();
		return GNUTLS_E_MEMORY_ERROR;
	}

	result = asn1_der_coding(*pkey_info, "", der->data, &len, NULL);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	return 0;

      error:
	asn1_delete_structure2(pkey_info, ASN1_DELETE_FLAG_ZEROIZE);
	_gnutls_free_datum(&algo_params);
	_gnutls_free_key_datum(&algo_privkey);
	return result;

}

/* Converts a PKCS #8 private key info to
 * a PKCS #8 EncryptedPrivateKeyInfo.
 */
static int
encode_to_pkcs8_key(schema_id schema, const gnutls_datum_t * der_key,
		    const char *password, ASN1_TYPE * out)
{
	int result;
	gnutls_datum_t key = { NULL, 0 };
	gnutls_datum_t tmp = { NULL, 0 };
	ASN1_TYPE pkcs8_asn = ASN1_TYPE_EMPTY;
	struct pbkdf2_params kdf_params;
	struct pbe_enc_params enc_params;
	const struct pkcs_cipher_schema_st *s;

	s = _gnutls_pkcs_schema_get(schema);
	if (s == NULL || s->decrypt_only) {
		return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);
	}

	if ((result =
	     asn1_create_element(_gnutls_get_pkix(),
				 "PKIX1.pkcs-8-EncryptedPrivateKeyInfo",
				 &pkcs8_asn)) != ASN1_SUCCESS) {
		gnutls_assert();
		return _gnutls_asn2err(result);
	}

	/* Write the encryption schema OID
	 */
	result =
	    asn1_write_value(pkcs8_asn, "encryptionAlgorithm.algorithm",
			     s->write_oid, 1);

	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* Generate a symmetric key.
	 */

	result =
	    _gnutls_pkcs_generate_key(schema, password, &kdf_params, &enc_params, &key);
	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	result =
	    _gnutls_pkcs_write_schema_params(schema, pkcs8_asn,
				"encryptionAlgorithm.parameters",
				&kdf_params, &enc_params);
	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	/* Parameters have been encoded. Now
	 * encrypt the Data.
	 */
	result = _gnutls_pkcs_raw_encrypt_data(der_key, &enc_params, &key, &tmp);
	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	/* write the encrypted data.
	 */
	result =
	    asn1_write_value(pkcs8_asn, "encryptedData", tmp.data,
			     tmp.size);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	_gnutls_free_datum(&tmp);
	_gnutls_free_key_datum(&key);

	*out = pkcs8_asn;

	return 0;

      error:
	_gnutls_free_key_datum(&key);
	_gnutls_free_datum(&tmp);
	asn1_delete_structure2(&pkcs8_asn, ASN1_DELETE_FLAG_ZEROIZE);
	return result;
}


/**
 * gnutls_x509_privkey_export_pkcs8:
 * @key: Holds the key
 * @format: the format of output params. One of PEM or DER.
 * @password: the password that will be used to encrypt the key.
 * @flags: an ORed sequence of gnutls_pkcs_encrypt_flags_t
 * @output_data: will contain a private key PEM or DER encoded
 * @output_data_size: holds the size of output_data (and will be
 *   replaced by the actual size of parameters)
 *
 * This function will export the private key to a PKCS8 structure.
 * Both RSA and DSA keys can be exported. For DSA keys we use
 * PKCS #11 definitions. If the flags do not specify the encryption
 * cipher, then the default 3DES (PBES2) will be used.
 *
 * The @password can be either ASCII or UTF-8 in the default PBES2
 * encryption schemas, or ASCII for the PKCS12 schemas.
 *
 * If the buffer provided is not long enough to hold the output, then
 * *output_data_size is updated and GNUTLS_E_SHORT_MEMORY_BUFFER will
 * be returned.
 *
 * If the structure is PEM encoded, it will have a header
 * of "BEGIN ENCRYPTED PRIVATE KEY" or "BEGIN PRIVATE KEY" if
 * encryption is not used.
 *
 * Returns: In case of failure a negative error code will be
 *   returned, and 0 on success.
 **/
int
gnutls_x509_privkey_export_pkcs8(gnutls_x509_privkey_t key,
				 gnutls_x509_crt_fmt_t format,
				 const char *password,
				 unsigned int flags,
				 void *output_data,
				 size_t * output_data_size)
{
	ASN1_TYPE pkcs8_asn, pkey_info;
	int ret;
	gnutls_datum_t tmp;
	schema_id schema;

	if (key == NULL) {
		gnutls_assert();
		return GNUTLS_E_INVALID_REQUEST;
	}

	/* Get the private key info
	 * tmp holds the DER encoding.
	 */
	ret = encode_to_private_key_info(key, &tmp, &pkey_info);
	if (ret < 0) {
		gnutls_assert();
		return ret;
	}

	schema = _gnutls_pkcs_flags_to_schema(flags);

	if (((flags & GNUTLS_PKCS_PLAIN) || password == NULL)
	    && !(flags & GNUTLS_PKCS_NULL_PASSWORD)) {
		_gnutls_free_datum(&tmp);

		ret =
		    _gnutls_x509_export_int(pkey_info, format,
					    PEM_UNENCRYPTED_PKCS8,
					    output_data, output_data_size);

		asn1_delete_structure2(&pkey_info, ASN1_DELETE_FLAG_ZEROIZE);
	} else {
		asn1_delete_structure2(&pkey_info, ASN1_DELETE_FLAG_ZEROIZE);	/* we don't need it */

		ret =
		    encode_to_pkcs8_key(schema, &tmp, password,
					&pkcs8_asn);
		_gnutls_free_key_datum(&tmp);

		if (ret < 0) {
			gnutls_assert();
			return ret;
		}

		ret =
		    _gnutls_x509_export_int(pkcs8_asn, format, PEM_PKCS8,
					    output_data, output_data_size);

		asn1_delete_structure2(&pkcs8_asn, ASN1_DELETE_FLAG_ZEROIZE);
	}

	return ret;
}

/**
 * gnutls_pkcs8_info:
 * @data: Holds the PKCS #8 data
 * @format: the format of the PKCS #8 data
 * @schema: indicate the schema as one of %gnutls_pkcs_encrypt_flags_t
 * @cipher: the cipher used as %gnutls_cipher_algorithm_t
 * @salt: PBKDF2 salt (if non-NULL then @salt_size initially holds its size)
 * @salt_size: PBKDF2 salt size
 * @iter_count: PBKDF2 iteration count
 * @oid: if non-NULL it will contain an allocated null-terminated variable with the OID
 *
 * This function will provide information on the algorithms used
 * in a particular PKCS #8 structure. If the structure algorithms
 * are unknown the code %GNUTLS_E_UNKNOWN_CIPHER_TYPE will be returned,
 * and only @oid, will be set. That is, @oid will be set on encrypted PKCS #8
 * structures whether supported or not. It must be deinitialized using gnutls_free().
 * The other variables are only set on supported structures.
 *
 * Returns: %GNUTLS_E_INVALID_REQUEST if the provided structure isn't encrypted,
 *  %GNUTLS_E_UNKNOWN_CIPHER_TYPE if the structure's encryption isn't supported, or
 *  another negative error code in case of a failure. Zero on success.
 **/
int
gnutls_pkcs8_info(const gnutls_datum_t * data, gnutls_x509_crt_fmt_t format,
		  unsigned int *schema, unsigned int *cipher,
		  void *salt, unsigned int *salt_size,
		  unsigned int *iter_count,
		  char **oid)
{
	int ret = 0, need_free = 0;
	gnutls_datum_t _data;
	const struct pkcs_cipher_schema_st *p = NULL;
	struct pbkdf2_params kdf;

	if (oid)
		*oid = NULL;

	_data.data = data->data;
	_data.size = data->size;

	/* If the Certificate is in PEM format then decode it
	 */
	if (format == GNUTLS_X509_FMT_PEM) {
		/* Try the first header 
		 */
		ret =
		    _gnutls_fbase64_decode(PEM_UNENCRYPTED_PKCS8,
					   data->data, data->size, &_data);

		if (ret < 0) {	/* Try the encrypted header 
					 */
			ret =
			    _gnutls_fbase64_decode(PEM_PKCS8, data->data,
						   data->size, &_data);

			if (ret < 0) {
				gnutls_assert();
				return ret;
			}
		}

		need_free = 1;
	}

	ret = pkcs8_key_info(&_data, &p, &kdf, oid);
	if (ret == GNUTLS_E_DECRYPTION_FAILED)
		ret = GNUTLS_E_INVALID_REQUEST;
	if (ret < 0) {
		gnutls_assert();
		goto cleanup;
	}

	if (need_free)
		_gnutls_free_datum(&_data);

	if (schema)
		*schema = p->flag;

	if (cipher)
		*cipher = p->cipher;

	if (iter_count)
		*iter_count = kdf.iter_count;

	if (salt) {
		if (*salt_size >= (unsigned)kdf.salt_size) {
			memcpy(salt, kdf.salt, kdf.salt_size);
		} else {
			*salt_size = kdf.salt_size;
			return gnutls_assert_val(GNUTLS_E_SHORT_MEMORY_BUFFER);
		}
	}

	if (salt_size)
		*salt_size = kdf.salt_size;


	return 0;

      cleanup:
	if (need_free)
		_gnutls_free_datum(&_data);
	return ret;
}

/**
 * gnutls_x509_privkey_export2_pkcs8:
 * @key: Holds the key
 * @format: the format of output params. One of PEM or DER.
 * @password: the password that will be used to encrypt the key.
 * @flags: an ORed sequence of gnutls_pkcs_encrypt_flags_t
 * @out: will contain a private key PEM or DER encoded
 *
 * This function will export the private key to a PKCS8 structure.
 * Both RSA and DSA keys can be exported. For DSA keys we use
 * PKCS #11 definitions. If the flags do not specify the encryption
 * cipher, then the default 3DES (PBES2) will be used.
 *
 * The @password can be either ASCII or UTF-8 in the default PBES2
 * encryption schemas, or ASCII for the PKCS12 schemas.
 *
 * The output buffer is allocated using gnutls_malloc().
 *
 * If the structure is PEM encoded, it will have a header
 * of "BEGIN ENCRYPTED PRIVATE KEY" or "BEGIN PRIVATE KEY" if
 * encryption is not used.
 *
 * Returns: In case of failure a negative error code will be
 *   returned, and 0 on success.
 *
 * Since 3.1.3
 **/
int
gnutls_x509_privkey_export2_pkcs8(gnutls_x509_privkey_t key,
				  gnutls_x509_crt_fmt_t format,
				  const char *password,
				  unsigned int flags, gnutls_datum_t * out)
{
	ASN1_TYPE pkcs8_asn, pkey_info;
	int ret;
	gnutls_datum_t tmp;
	schema_id schema;

	if (key == NULL) {
		gnutls_assert();
		return GNUTLS_E_INVALID_REQUEST;
	}

	/* Get the private key info
	 * tmp holds the DER encoding.
	 */
	ret = encode_to_private_key_info(key, &tmp, &pkey_info);
	if (ret < 0) {
		gnutls_assert();
		return ret;
	}

	schema = _gnutls_pkcs_flags_to_schema(flags);

	if (((flags & GNUTLS_PKCS_PLAIN) || password == NULL)
	    && !(flags & GNUTLS_PKCS_NULL_PASSWORD)) {
		_gnutls_free_key_datum(&tmp);

		ret =
		    _gnutls_x509_export_int2(pkey_info, format,
					     PEM_UNENCRYPTED_PKCS8, out);

		asn1_delete_structure2(&pkey_info, ASN1_DELETE_FLAG_ZEROIZE);
	} else {
		asn1_delete_structure2(&pkey_info, ASN1_DELETE_FLAG_ZEROIZE);	/* we don't need it */

		ret =
		    encode_to_pkcs8_key(schema, &tmp, password,
					&pkcs8_asn);
		_gnutls_free_key_datum(&tmp);

		if (ret < 0) {
			gnutls_assert();
			return ret;
		}

		ret =
		    _gnutls_x509_export_int2(pkcs8_asn, format, PEM_PKCS8,
					     out);

		asn1_delete_structure2(&pkcs8_asn, ASN1_DELETE_FLAG_ZEROIZE);
	}

	return ret;
}



	/* We've gotten this far. In the real world it's almost certain
	 * that we're dealing with a good file, but wrong password.
	 * Sadly like 90% of random data is somehow valid DER for the
	 * a first small number of bytes, so no easy way to guarantee. */
#define CHECK_ERR_FOR_ENCRYPTED(result) \
		if (result == GNUTLS_E_ASN1_ELEMENT_NOT_FOUND || \
		    result == GNUTLS_E_ASN1_IDENTIFIER_NOT_FOUND || \
		    result == GNUTLS_E_ASN1_DER_ERROR || \
		    result == GNUTLS_E_ASN1_VALUE_NOT_FOUND || \
		    result == GNUTLS_E_ASN1_GENERIC_ERROR || \
		    result == GNUTLS_E_ASN1_VALUE_NOT_VALID || \
		    result == GNUTLS_E_ASN1_TAG_ERROR || \
		    result == GNUTLS_E_ASN1_TAG_IMPLICIT || \
		    result == GNUTLS_E_ASN1_TYPE_ANY_ERROR || \
		    result == GNUTLS_E_ASN1_SYNTAX_ERROR || \
		    result == GNUTLS_E_ASN1_DER_OVERFLOW) { \
			result = GNUTLS_E_DECRYPTION_FAILED; \
		}

static int pkcs8_key_decrypt(const gnutls_datum_t * raw_key,
			     ASN1_TYPE pkcs8_asn, const char *password,
			     gnutls_x509_privkey_t pkey)
{
	int result, len;
	char enc_oid[MAX_OID_SIZE];
	gnutls_datum_t tmp;
	int params_start, params_end, params_len;
	struct pbkdf2_params kdf_params;
	struct pbe_enc_params enc_params;
	schema_id schema;

	/* Check the encryption schema OID
	 */
	len = sizeof(enc_oid);
	result =
	    asn1_read_value(pkcs8_asn, "encryptionAlgorithm.algorithm",
			    enc_oid, &len);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		goto error;
	}

	if ((result = _gnutls_check_pkcs_cipher_schema(enc_oid)) < 0) {
		gnutls_assert();
		goto error;
	}

	schema = result;

	/* Get the DER encoding of the parameters.
	 */
	result =
	    asn1_der_decoding_startEnd(pkcs8_asn, raw_key->data,
				       raw_key->size,
				       "encryptionAlgorithm.parameters",
				       &params_start, &params_end);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}
	params_len = params_end - params_start + 1;

	result =
	    _gnutls_read_pkcs_schema_params(&schema, password,
				    &raw_key->data[params_start],
				    params_len, &kdf_params, &enc_params);

	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	/* Parameters have been decoded. Now
	 * decrypt the EncryptedData.
	 */
	result =
	    _gnutls_pkcs_raw_decrypt_data(schema, pkcs8_asn, "encryptedData", password,
			 &kdf_params, &enc_params, &tmp);
	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	result = decode_private_key_info(&tmp, pkey);
	_gnutls_free_key_datum(&tmp);

	CHECK_ERR_FOR_ENCRYPTED(result);
	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	return 0;

      error:
	return result;
}

static
int pkcs8_key_info(const gnutls_datum_t * raw_key,
		   const struct pkcs_cipher_schema_st **p,
		   struct pbkdf2_params *kdf_params,
		   char **oid)
{
	int result, len;
	char enc_oid[MAX_OID_SIZE];
	int params_start, params_end, params_len;
	struct pbe_enc_params enc_params;
	schema_id schema;
	ASN1_TYPE pkcs8_asn = ASN1_TYPE_EMPTY;

	if ((result =
	     asn1_create_element(_gnutls_get_pkix(),
				 "PKIX1.pkcs-8-EncryptedPrivateKeyInfo",
				 &pkcs8_asn)) != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	result =
	    _asn1_strict_der_decode(&pkcs8_asn, raw_key->data, raw_key->size,
			      NULL);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		CHECK_ERR_FOR_ENCRYPTED(result);
		goto error;
	}

	/* Check the encryption schema OID
	 */
	len = sizeof(enc_oid);
	result =
	    asn1_read_value(pkcs8_asn, "encryptionAlgorithm.algorithm",
			    enc_oid, &len);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		goto error;
	}

	if (oid) {
		*oid = gnutls_strdup(enc_oid);
	}

	if ((result = _gnutls_check_pkcs_cipher_schema(enc_oid)) < 0) {
		gnutls_assert();
		goto error;
	}

	schema = result;

	/* Get the DER encoding of the parameters.
	 */
	result =
	    asn1_der_decoding_startEnd(pkcs8_asn, raw_key->data,
				       raw_key->size,
				       "encryptionAlgorithm.parameters",
				       &params_start, &params_end);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}
	params_len = params_end - params_start + 1;

	result =
	    _gnutls_read_pkcs_schema_params(&schema, NULL,
				    &raw_key->data[params_start],
				    params_len, kdf_params, &enc_params);

	if (result < 0) {
		gnutls_assert();
		goto error;
	}

	*p = _gnutls_pkcs_schema_get(schema);
	if (*p == NULL) {
		gnutls_assert();
		result = GNUTLS_E_UNKNOWN_CIPHER_TYPE;
		goto error;
	}

	result = 0;

      error:
	asn1_delete_structure2(&pkcs8_asn, ASN1_DELETE_FLAG_ZEROIZE);
	return result;
}

/* Converts a PKCS #8 key to
 * an internal structure (gnutls_private_key)
 * (normally a PKCS #1 encoded RSA key)
 */
static int
pkcs8_key_decode(const gnutls_datum_t * raw_key,
		 const char *password, gnutls_x509_privkey_t pkey,
		 unsigned int decrypt)
{
	int result;
	ASN1_TYPE pkcs8_asn = ASN1_TYPE_EMPTY;

	if ((result =
	     asn1_create_element(_gnutls_get_pkix(),
				 "PKIX1.pkcs-8-EncryptedPrivateKeyInfo",
				 &pkcs8_asn)) != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	result =
	    _asn1_strict_der_decode(&pkcs8_asn, raw_key->data, raw_key->size,
			      NULL);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	if (decrypt)
		result =
		    pkcs8_key_decrypt(raw_key, pkcs8_asn, password, pkey);
	else
		result = 0;

      error:
	asn1_delete_structure2(&pkcs8_asn, ASN1_DELETE_FLAG_ZEROIZE);
	return result;

}

/* Decodes an RSA privateKey from a PKCS8 structure.
 */
static int
_decode_pkcs8_rsa_key(ASN1_TYPE pkcs8_asn, gnutls_x509_privkey_t pkey)
{
	int ret;
	gnutls_datum_t tmp;

	ret = _gnutls_x509_read_value(pkcs8_asn, "privateKey", &tmp);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	pkey->key = _gnutls_privkey_decode_pkcs1_rsa_key(&tmp, pkey);
	_gnutls_free_key_datum(&tmp);

	if (pkey->key == NULL) {
		gnutls_assert();
		goto error;
	}

	ret = 0;

      error:
	return ret;
}

/* Decodes an ECC privateKey from a PKCS8 structure.
 */
static int
_decode_pkcs8_ecc_key(ASN1_TYPE pkcs8_asn, gnutls_x509_privkey_t pkey)
{
	int ret;
	gnutls_datum_t tmp;
	unsigned char oid[MAX_OID_SIZE];
	unsigned curve = GNUTLS_ECC_CURVE_INVALID;
	int len, result;

	/* openssl PKCS #8 files with ECC keys place the curve in
	 * privateKeyAlgorithm.parameters instead of the ECPrivateKey.parameters.
	 */
	len = sizeof(oid);
	result =
	    asn1_read_value(pkcs8_asn, "privateKeyAlgorithm.parameters",
			    oid, &len);
	if (result == ASN1_SUCCESS) {
		ret = _gnutls_x509_read_ecc_params(oid, len, &curve);
		if (ret < 0) {
			curve = GNUTLS_ECC_CURVE_INVALID;
		}
	}

	ret = _gnutls_x509_read_value(pkcs8_asn, "privateKey", &tmp);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	ret = _gnutls_privkey_decode_ecc_key(&pkey->key, &tmp, pkey, curve);
	_gnutls_free_key_datum(&tmp);

	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	ret = 0;

      error:
	return ret;
}

/* Decodes an DSA privateKey and params from a PKCS8 structure.
 */
static int
_decode_pkcs8_dsa_key(ASN1_TYPE pkcs8_asn, gnutls_x509_privkey_t pkey)
{
	int ret;
	gnutls_datum_t tmp;

	ret = _gnutls_x509_read_value(pkcs8_asn, "privateKey", &tmp);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	ret =
	    _gnutls_x509_read_der_int(tmp.data, tmp.size,
				      &pkey->params.params[4]);
	_gnutls_free_key_datum(&tmp);

	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	ret =
	    _gnutls_x509_read_value(pkcs8_asn,
				    "privateKeyAlgorithm.parameters",
				    &tmp);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	ret =
	    _gnutls_x509_read_pubkey_params(GNUTLS_PK_DSA, tmp.data,
					    tmp.size, &pkey->params);
	_gnutls_free_datum(&tmp);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	/* the public key can be generated as g^x mod p */
	ret = _gnutls_mpi_init(&pkey->params.params[3]);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	ret = _gnutls_mpi_powm(pkey->params.params[3], pkey->params.params[2],
			 pkey->params.params[4], pkey->params.params[0]);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	ret =
	    _gnutls_asn1_encode_privkey(GNUTLS_PK_DSA, &pkey->key,
					&pkey->params, pkey->flags&GNUTLS_PRIVKEY_FLAG_EXPORT_COMPAT);
	if (ret < 0) {
		gnutls_assert();
		goto error;
	}

	pkey->params.algo = GNUTLS_PK_DSA;
	pkey->params.params_nr = DSA_PRIVATE_PARAMS;

	ret = 0;

      error:
	return ret;
}


static int
decode_private_key_info(const gnutls_datum_t * der,
			gnutls_x509_privkey_t pkey)
{
	int result, len;
	char oid[MAX_OID_SIZE];
	ASN1_TYPE pkcs8_asn = ASN1_TYPE_EMPTY;

	if ((result =
	     asn1_create_element(_gnutls_get_pkix(),
				 "PKIX1.pkcs-8-PrivateKeyInfo",
				 &pkcs8_asn)) != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	result = _asn1_strict_der_decode(&pkcs8_asn, der->data, der->size, NULL);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* Check the private key algorithm OID
	 */
	len = sizeof(oid);
	result =
	    asn1_read_value(pkcs8_asn, "privateKeyAlgorithm.algorithm",
			    oid, &len);
	if (result != ASN1_SUCCESS) {
		gnutls_assert();
		result = _gnutls_asn2err(result);
		goto error;
	}

	/* we only support RSA and DSA private keys.
	 */

	pkey->pk_algorithm = gnutls_oid_to_pk(oid);
	if (pkey->pk_algorithm == GNUTLS_PK_UNKNOWN) {
		gnutls_assert();
		_gnutls_debug_log
		    ("PKCS #8 private key OID '%s' is unsupported.\n",
		     oid);
		result = GNUTLS_E_UNKNOWN_PK_ALGORITHM;
		goto error;
	}

	/* Get the DER encoding of the actual private key.
	 */

	if (pkey->pk_algorithm == GNUTLS_PK_RSA)
		result = _decode_pkcs8_rsa_key(pkcs8_asn, pkey);
	else if (pkey->pk_algorithm == GNUTLS_PK_DSA)
		result = _decode_pkcs8_dsa_key(pkcs8_asn, pkey);
	else if (pkey->pk_algorithm == GNUTLS_PK_EC)
		result = _decode_pkcs8_ecc_key(pkcs8_asn, pkey);
	else
		return gnutls_assert_val(GNUTLS_E_UNIMPLEMENTED_FEATURE);

	if (result < 0) {
		gnutls_assert();
		return result;
	}

	result = 0;

error:
	asn1_delete_structure2(&pkcs8_asn, ASN1_DELETE_FLAG_ZEROIZE);

	return result;

}

/**
 * gnutls_x509_privkey_import_pkcs8:
 * @key: The data to store the parsed key
 * @data: The DER or PEM encoded key.
 * @format: One of DER or PEM
 * @password: the password to decrypt the key (if it is encrypted).
 * @flags: 0 if encrypted or GNUTLS_PKCS_PLAIN if not encrypted.
 *
 * This function will convert the given DER or PEM encoded PKCS8 2.0
 * encrypted key to the native gnutls_x509_privkey_t format. The
 * output will be stored in @key.  Both RSA and DSA keys can be
 * imported, and flags can only be used to indicate an unencrypted
 * key.
 *
 * The @password can be either ASCII or UTF-8 in the default PBES2
 * encryption schemas, or ASCII for the PKCS12 schemas.
 *
 * If the Certificate is PEM encoded it should have a header of
 * "ENCRYPTED PRIVATE KEY", or "PRIVATE KEY". You only need to
 * specify the flags if the key is DER encoded, since in that case
 * the encryption status cannot be auto-detected.
 *
 * If the %GNUTLS_PKCS_PLAIN flag is specified and the supplied data
 * are encrypted then %GNUTLS_E_DECRYPTION_FAILED is returned.
 *
 * Returns: On success, %GNUTLS_E_SUCCESS (0) is returned, otherwise a
 *   negative error value.
 **/
int
gnutls_x509_privkey_import_pkcs8(gnutls_x509_privkey_t key,
				 const gnutls_datum_t * data,
				 gnutls_x509_crt_fmt_t format,
				 const char *password, unsigned int flags)
{
	int result = 0, need_free = 0;
	gnutls_datum_t _data;

	if (key == NULL) {
		gnutls_assert();
		return GNUTLS_E_INVALID_REQUEST;
	}

	_data.data = data->data;
	_data.size = data->size;

	key->pk_algorithm = GNUTLS_PK_UNKNOWN;

	/* If the Certificate is in PEM format then decode it
	 */
	if (format == GNUTLS_X509_FMT_PEM) {
		/* Try the first header 
		 */
		result =
		    _gnutls_fbase64_decode(PEM_UNENCRYPTED_PKCS8,
					   data->data, data->size, &_data);

		if (result < 0) {	/* Try the encrypted header 
					 */
			result =
			    _gnutls_fbase64_decode(PEM_PKCS8, data->data,
						   data->size, &_data);

			if (result < 0) {
				gnutls_assert();
				return result;
			}
		} else if (flags == 0)
			flags |= GNUTLS_PKCS_PLAIN;

		need_free = 1;
	}

	if (key->expanded) {
		_gnutls_x509_privkey_reinit(key);
	}
	key->expanded = 1;

	/* Here we don't check for password == NULL to maintain a backwards
	 * compatibility behavior, with old versions that were encrypting using
	 * a NULL password.
	 */
	if (flags & GNUTLS_PKCS_PLAIN) {
		result = decode_private_key_info(&_data, key);
		if (result < 0) {	/* check if it is encrypted */
			if (pkcs8_key_decode(&_data, "", key, 0) == 0)
				result = GNUTLS_E_DECRYPTION_FAILED;
		}
	} else {		/* encrypted. */
		result = pkcs8_key_decode(&_data, password, key, 1);
	}

	if (result < 0) {
		gnutls_assert();
		goto cleanup;
	}

	result =
	    _gnutls_pk_fixup(key->pk_algorithm, GNUTLS_IMPORT, &key->params);
	if (result < 0) {
		gnutls_assert();
		goto cleanup;
	}

	if (need_free)
		_gnutls_free_datum(&_data);

	/* The key has now been decoded.
	 */
	return 0;

      cleanup:
	key->pk_algorithm = GNUTLS_PK_UNKNOWN;
	if (need_free)
		_gnutls_free_datum(&_data);
	return result;
}
