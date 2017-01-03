/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (cli-args.h)
 *
 *  It has been AutoGen-ed
 *  From the definitions    cli-args.def
 *  and the template file   options
 *
 * Generated from AutoOpts 41:1:16 templates.
 *
 *  AutoOpts is a copyrighted work.  This header file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the gnutls-cli author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The gnutls-cli program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 2000-2016 Free Software Foundation, and others, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the GNU General Public License,
 *  version 3 or later <http://gnu.org/licenses/gpl.html>
 *
 *  gnutls-cli is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gnutls-cli is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the gnutls-cli program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_CLI_ARGS_H_GUARD
#define AUTOOPTS_CLI_ARGS_H_GUARD 1
#include "config.h"
#include <autoopts/options.h>

/**
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 167937
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/**
 *  Enumeration of each option type for gnutls-cli
 */
typedef enum {
    INDEX_OPT_DEBUG                   =  0,
    INDEX_OPT_VERBOSE                 =  1,
    INDEX_OPT_TOFU                    =  2,
    INDEX_OPT_STRICT_TOFU             =  3,
    INDEX_OPT_DANE                    =  4,
    INDEX_OPT_LOCAL_DNS               =  5,
    INDEX_OPT_CA_VERIFICATION         =  6,
    INDEX_OPT_OCSP                    =  7,
    INDEX_OPT_RESUME                  =  8,
    INDEX_OPT_REHANDSHAKE             =  9,
    INDEX_OPT_STARTTLS                = 10,
    INDEX_OPT_APP_PROTO               = 11,
    INDEX_OPT_STARTTLS_PROTO          = 12,
    INDEX_OPT_UDP                     = 13,
    INDEX_OPT_MTU                     = 14,
    INDEX_OPT_CRLF                    = 15,
    INDEX_OPT_FASTOPEN                = 16,
    INDEX_OPT_X509FMTDER              = 17,
    INDEX_OPT_FINGERPRINT             = 18,
    INDEX_OPT_PRINT_CERT              = 19,
    INDEX_OPT_SAVE_CERT               = 20,
    INDEX_OPT_SAVE_OCSP               = 21,
    INDEX_OPT_DH_BITS                 = 22,
    INDEX_OPT_PRIORITY                = 23,
    INDEX_OPT_X509CAFILE              = 24,
    INDEX_OPT_X509CRLFILE             = 25,
    INDEX_OPT_PGPKEYFILE              = 26,
    INDEX_OPT_PGPKEYRING              = 27,
    INDEX_OPT_PGPCERTFILE             = 28,
    INDEX_OPT_X509KEYFILE             = 29,
    INDEX_OPT_X509CERTFILE            = 30,
    INDEX_OPT_PGPSUBKEY               = 31,
    INDEX_OPT_SRPUSERNAME             = 32,
    INDEX_OPT_SRPPASSWD               = 33,
    INDEX_OPT_PSKUSERNAME             = 34,
    INDEX_OPT_PSKKEY                  = 35,
    INDEX_OPT_PORT                    = 36,
    INDEX_OPT_INSECURE                = 37,
    INDEX_OPT_RANGES                  = 38,
    INDEX_OPT_BENCHMARK_CIPHERS       = 39,
    INDEX_OPT_BENCHMARK_TLS_KX        = 40,
    INDEX_OPT_BENCHMARK_TLS_CIPHERS   = 41,
    INDEX_OPT_LIST                    = 42,
    INDEX_OPT_PRIORITY_LIST           = 43,
    INDEX_OPT_NOTICKET                = 44,
    INDEX_OPT_SRTP_PROFILES           = 45,
    INDEX_OPT_ALPN                    = 46,
    INDEX_OPT_HEARTBEAT               = 47,
    INDEX_OPT_RECORDSIZE              = 48,
    INDEX_OPT_DISABLE_SNI             = 49,
    INDEX_OPT_DISABLE_EXTENSIONS      = 50,
    INDEX_OPT_INLINE_COMMANDS         = 51,
    INDEX_OPT_INLINE_COMMANDS_PREFIX  = 52,
    INDEX_OPT_PROVIDER                = 53,
    INDEX_OPT_FIPS140_MODE            = 54,
    INDEX_OPT_VERSION                 = 55,
    INDEX_OPT_HELP                    = 56,
    INDEX_OPT_MORE_HELP               = 57
} teOptIndex;
/** count of all options for gnutls-cli */
#define OPTION_CT    58
/** gnutls-cli version */
#define GNUTLS_CLI_VERSION       "3.5.7"
/** Full gnutls-cli version text */
#define GNUTLS_CLI_FULL_VERSION  "gnutls-cli 3.5.7"

/**
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teOptIndex enumeration above).
 *  e.g. HAVE_OPT(DEBUG)
 */
#define         DESC(n) (gnutls_cliOptions.pOptDesc[INDEX_OPT_## n])
/** 'true' if an option has been specified in any way */
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
/** The string argument to an option. The argument type must be \"string\". */
#define      OPT_ARG(n) (DESC(n).optArg.argString)
/** Mask the option state revealing how an option was specified.
 *  It will be one and only one of \a OPTST_SET, \a OPTST_PRESET,
 * \a OPTST_DEFINED, \a OPTST_RESET or zero.
 */
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
/** Count of option's occurrances *on the command line*. */
#define    COUNT_OPT(n) (DESC(n).optOccCt)
/** mask of \a OPTST_SET and \a OPTST_DEFINED. */
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
/** 'true' if \a HAVE_OPT would yield 'false'. */
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
/** 'true' if OPTST_DISABLED bit not set. */
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
/** number of stacked option arguments.
 *  Valid only for stacked option arguments. */
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
/** stacked argument vector.
 *  Valid only for stacked option arguments. */
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
/** Reset an option. */
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ((DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 *  Enumeration of gnutls-cli exit codes
 */
typedef enum {
    GNUTLS_CLI_EXIT_SUCCESS         = 0,
    GNUTLS_CLI_EXIT_FAILURE         = 1,
    GNUTLS_CLI_EXIT_USAGE_ERROR     = 64,
    GNUTLS_CLI_EXIT_LIBOPTS_FAILURE = 70
}   gnutls_cli_exit_code_t;
/**
 *  Interface defines for specific options.
 * @{
 */
#define VALUE_OPT_DEBUG          'd'

#define OPT_VALUE_DEBUG          (DESC(DEBUG).optArg.argInt)
#define VALUE_OPT_VERBOSE        'V'
#define VALUE_OPT_TOFU           0x1001
#define VALUE_OPT_STRICT_TOFU    0x1002
#define VALUE_OPT_DANE           0x1003
#define VALUE_OPT_LOCAL_DNS      0x1004
#define VALUE_OPT_CA_VERIFICATION 0x1005
#define VALUE_OPT_OCSP           0x1006
#define VALUE_OPT_RESUME         'r'
#define VALUE_OPT_REHANDSHAKE    'e'
#define VALUE_OPT_STARTTLS       's'
#define VALUE_OPT_APP_PROTO      0x1007
#define VALUE_OPT_STARTTLS_PROTO 0x1008
#define VALUE_OPT_UDP            'u'
#define VALUE_OPT_MTU            0x1009

#define OPT_VALUE_MTU            (DESC(MTU).optArg.argInt)
#define VALUE_OPT_CRLF           0x100A
#define VALUE_OPT_FASTOPEN       0x100B
#define VALUE_OPT_X509FMTDER     0x100C
#define VALUE_OPT_FINGERPRINT    'f'
#define VALUE_OPT_PRINT_CERT     0x100D
#define VALUE_OPT_SAVE_CERT      0x100E
#define VALUE_OPT_SAVE_OCSP      0x100F
#define VALUE_OPT_DH_BITS        0x1010

#define OPT_VALUE_DH_BITS        (DESC(DH_BITS).optArg.argInt)
#define VALUE_OPT_PRIORITY       0x1011
#define VALUE_OPT_X509CAFILE     0x1012
#define VALUE_OPT_X509CRLFILE    0x1013
#define VALUE_OPT_PGPKEYFILE     0x1014
#define VALUE_OPT_PGPKEYRING     0x1015
#define VALUE_OPT_PGPCERTFILE    0x1016
#define VALUE_OPT_X509KEYFILE    0x1017
#define VALUE_OPT_X509CERTFILE   0x1018
#define VALUE_OPT_PGPSUBKEY      0x1019
#define VALUE_OPT_SRPUSERNAME    0x101A
#define VALUE_OPT_SRPPASSWD      0x101B
#define VALUE_OPT_PSKUSERNAME    0x101C
#define VALUE_OPT_PSKKEY         0x101D
#define VALUE_OPT_PORT           'p'
#define VALUE_OPT_INSECURE       0x101E
#define VALUE_OPT_RANGES         0x101F
#define VALUE_OPT_BENCHMARK_CIPHERS 0x1020
#define VALUE_OPT_BENCHMARK_TLS_KX 0x1021
#define VALUE_OPT_BENCHMARK_TLS_CIPHERS 0x1022
#define VALUE_OPT_LIST           'l'
#define VALUE_OPT_PRIORITY_LIST  0x1023
#define VALUE_OPT_NOTICKET       0x1024
#define VALUE_OPT_SRTP_PROFILES  0x1025
#define VALUE_OPT_ALPN           0x1026
#define VALUE_OPT_HEARTBEAT      'b'
#define VALUE_OPT_RECORDSIZE     0x1027

#define OPT_VALUE_RECORDSIZE     (DESC(RECORDSIZE).optArg.argInt)
#define VALUE_OPT_DISABLE_SNI    0x1028
#define VALUE_OPT_DISABLE_EXTENSIONS 0x1029
#define VALUE_OPT_INLINE_COMMANDS 0x102A
#define VALUE_OPT_INLINE_COMMANDS_PREFIX 0x102B
#define VALUE_OPT_PROVIDER       0x102C
#define VALUE_OPT_FIPS140_MODE   0x102D
/** option flag (value) for help-value option */
#define VALUE_OPT_HELP          'h'
/** option flag (value) for more-help-value option */
#define VALUE_OPT_MORE_HELP     '!'
/** option flag (value) for version-value option */
#define VALUE_OPT_VERSION       'v'
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS(gnutls_cliOptions.fOptSet &= ~OPTPROC_ERRSTOP)
#define ERRSTOP_OPTERR  STMTS(gnutls_cliOptions.fOptSet |= OPTPROC_ERRSTOP)
#define RESTART_OPT(n)  STMTS( \
                gnutls_cliOptions.curOptIdx = (n); \
                gnutls_cliOptions.pzCurOpt  = NULL )
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*gnutls_cliOptions.pUsageProc)(&gnutls_cliOptions, c)

#ifdef  __cplusplus
extern "C" {
#endif
/*
 *  global exported definitions
 */
#include <gettext.h>


/* * * * * *
 *
 *  Declare the gnutls-cli option descriptor.
 */
extern tOptions gnutls_cliOptions;

#if defined(ENABLE_NLS)
# ifndef _
#   include <stdio.h>
#   ifndef HAVE_GETTEXT
      extern char * gettext(char const *);
#   else
#     include <libintl.h>
#   endif

# ifndef ATTRIBUTE_FORMAT_ARG
#   define ATTRIBUTE_FORMAT_ARG(_a)
# endif

static inline char* aoGetsText(char const* pz) ATTRIBUTE_FORMAT_ARG(1);
static inline char* aoGetsText(char const* pz) {
    if (pz == NULL) return NULL;
    return (char*)gettext(pz);
}
#   define _(s)  aoGetsText(s)
# endif /* _() */

# define OPT_NO_XLAT_CFG_NAMES  STMTS(gnutls_cliOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT_CFG;)
# define OPT_NO_XLAT_OPT_NAMES  STMTS(gnutls_cliOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)

# define OPT_XLAT_CFG_NAMES     STMTS(gnutls_cliOptions.fOptSet &= \
                                  ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
# define OPT_XLAT_OPT_NAMES     STMTS(gnutls_cliOptions.fOptSet &= \
                                  ~OPTPROC_NXLAT_OPT;)

#else   /* ENABLE_NLS */
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#endif  /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_CLI_ARGS_H_GUARD */

/* cli-args.h ends here */
