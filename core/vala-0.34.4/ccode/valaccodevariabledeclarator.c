/* valaccodevariabledeclarator.c generated by valac, the Vala compiler
 * generated from valaccodevariabledeclarator.vala, do not modify */

/* valaccodevariabledeclarator.vala
 *
 * Copyright (C) 2006-2009  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define VALA_TYPE_CCODE_NODE (vala_ccode_node_get_type ())
#define VALA_CCODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_NODE, ValaCCodeNode))
#define VALA_CCODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_NODE, ValaCCodeNodeClass))
#define VALA_IS_CCODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_NODE))
#define VALA_IS_CCODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_NODE))
#define VALA_CCODE_NODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_NODE, ValaCCodeNodeClass))

typedef struct _ValaCCodeNode ValaCCodeNode;
typedef struct _ValaCCodeNodeClass ValaCCodeNodeClass;
typedef struct _ValaCCodeNodePrivate ValaCCodeNodePrivate;

#define VALA_TYPE_CCODE_WRITER (vala_ccode_writer_get_type ())
#define VALA_CCODE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_WRITER, ValaCCodeWriter))
#define VALA_CCODE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_WRITER, ValaCCodeWriterClass))
#define VALA_IS_CCODE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_WRITER))
#define VALA_IS_CCODE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_WRITER))
#define VALA_CCODE_WRITER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_WRITER, ValaCCodeWriterClass))

typedef struct _ValaCCodeWriter ValaCCodeWriter;
typedef struct _ValaCCodeWriterClass ValaCCodeWriterClass;

#define VALA_TYPE_CCODE_DECLARATOR (vala_ccode_declarator_get_type ())
#define VALA_CCODE_DECLARATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_DECLARATOR, ValaCCodeDeclarator))
#define VALA_CCODE_DECLARATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_DECLARATOR, ValaCCodeDeclaratorClass))
#define VALA_IS_CCODE_DECLARATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_DECLARATOR))
#define VALA_IS_CCODE_DECLARATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_DECLARATOR))
#define VALA_CCODE_DECLARATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_DECLARATOR, ValaCCodeDeclaratorClass))

typedef struct _ValaCCodeDeclarator ValaCCodeDeclarator;
typedef struct _ValaCCodeDeclaratorClass ValaCCodeDeclaratorClass;
typedef struct _ValaCCodeDeclaratorPrivate ValaCCodeDeclaratorPrivate;

#define VALA_TYPE_CCODE_VARIABLE_DECLARATOR (vala_ccode_variable_declarator_get_type ())
#define VALA_CCODE_VARIABLE_DECLARATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_VARIABLE_DECLARATOR, ValaCCodeVariableDeclarator))
#define VALA_CCODE_VARIABLE_DECLARATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_VARIABLE_DECLARATOR, ValaCCodeVariableDeclaratorClass))
#define VALA_IS_CCODE_VARIABLE_DECLARATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_VARIABLE_DECLARATOR))
#define VALA_IS_CCODE_VARIABLE_DECLARATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_VARIABLE_DECLARATOR))
#define VALA_CCODE_VARIABLE_DECLARATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_VARIABLE_DECLARATOR, ValaCCodeVariableDeclaratorClass))

typedef struct _ValaCCodeVariableDeclarator ValaCCodeVariableDeclarator;
typedef struct _ValaCCodeVariableDeclaratorClass ValaCCodeVariableDeclaratorClass;
typedef struct _ValaCCodeVariableDeclaratorPrivate ValaCCodeVariableDeclaratorPrivate;

#define VALA_TYPE_CCODE_EXPRESSION (vala_ccode_expression_get_type ())
#define VALA_CCODE_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpression))
#define VALA_CCODE_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpressionClass))
#define VALA_IS_CCODE_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_EXPRESSION))
#define VALA_IS_CCODE_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_EXPRESSION))
#define VALA_CCODE_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpressionClass))

typedef struct _ValaCCodeExpression ValaCCodeExpression;
typedef struct _ValaCCodeExpressionClass ValaCCodeExpressionClass;

#define VALA_TYPE_CCODE_DECLARATOR_SUFFIX (vala_ccode_declarator_suffix_get_type ())
#define VALA_CCODE_DECLARATOR_SUFFIX(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_DECLARATOR_SUFFIX, ValaCCodeDeclaratorSuffix))
#define VALA_CCODE_DECLARATOR_SUFFIX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_DECLARATOR_SUFFIX, ValaCCodeDeclaratorSuffixClass))
#define VALA_IS_CCODE_DECLARATOR_SUFFIX(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_DECLARATOR_SUFFIX))
#define VALA_IS_CCODE_DECLARATOR_SUFFIX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_DECLARATOR_SUFFIX))
#define VALA_CCODE_DECLARATOR_SUFFIX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_DECLARATOR_SUFFIX, ValaCCodeDeclaratorSuffixClass))

typedef struct _ValaCCodeDeclaratorSuffix ValaCCodeDeclaratorSuffix;
typedef struct _ValaCCodeDeclaratorSuffixClass ValaCCodeDeclaratorSuffixClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))
#define _vala_ccode_declarator_suffix_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_declarator_suffix_unref (var), NULL)))

#define VALA_TYPE_CCODE_LINE_DIRECTIVE (vala_ccode_line_directive_get_type ())
#define VALA_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirective))
#define VALA_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))
#define VALA_IS_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_IS_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_CCODE_LINE_DIRECTIVE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))

typedef struct _ValaCCodeLineDirective ValaCCodeLineDirective;
typedef struct _ValaCCodeLineDirectiveClass ValaCCodeLineDirectiveClass;
typedef struct _ValaCCodeDeclaratorSuffixPrivate ValaCCodeDeclaratorSuffixPrivate;
typedef struct _ValaParamSpecCCodeDeclaratorSuffix ValaParamSpecCCodeDeclaratorSuffix;

struct _ValaCCodeNode {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaCCodeNodePrivate * priv;
};

struct _ValaCCodeNodeClass {
	GTypeClass parent_class;
	void (*finalize) (ValaCCodeNode *self);
	void (*write) (ValaCCodeNode* self, ValaCCodeWriter* writer);
	void (*write_declaration) (ValaCCodeNode* self, ValaCCodeWriter* writer);
	void (*write_combined) (ValaCCodeNode* self, ValaCCodeWriter* writer);
};

struct _ValaCCodeDeclarator {
	ValaCCodeNode parent_instance;
	ValaCCodeDeclaratorPrivate * priv;
};

struct _ValaCCodeDeclaratorClass {
	ValaCCodeNodeClass parent_class;
	void (*write_initialization) (ValaCCodeDeclarator* self, ValaCCodeWriter* writer);
};

struct _ValaCCodeVariableDeclarator {
	ValaCCodeDeclarator parent_instance;
	ValaCCodeVariableDeclaratorPrivate * priv;
};

struct _ValaCCodeVariableDeclaratorClass {
	ValaCCodeDeclaratorClass parent_class;
};

struct _ValaCCodeVariableDeclaratorPrivate {
	gchar* _name;
	ValaCCodeExpression* _initializer;
	ValaCCodeDeclaratorSuffix* _declarator_suffix;
	gboolean _init0;
};

struct _ValaCCodeDeclaratorSuffix {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaCCodeDeclaratorSuffixPrivate * priv;
	gboolean array;
	ValaCCodeExpression* array_length;
	gboolean deprecated;
};

struct _ValaCCodeDeclaratorSuffixClass {
	GTypeClass parent_class;
	void (*finalize) (ValaCCodeDeclaratorSuffix *self);
};

struct _ValaParamSpecCCodeDeclaratorSuffix {
	GParamSpec parent_instance;
};


static gpointer vala_ccode_variable_declarator_parent_class = NULL;
static gpointer vala_ccode_declarator_suffix_parent_class = NULL;

gpointer vala_ccode_node_ref (gpointer instance);
void vala_ccode_node_unref (gpointer instance);
GParamSpec* vala_param_spec_ccode_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_ccode_node (GValue* value, gpointer v_object);
void vala_value_take_ccode_node (GValue* value, gpointer v_object);
gpointer vala_value_get_ccode_node (const GValue* value);
GType vala_ccode_node_get_type (void) G_GNUC_CONST;
gpointer vala_ccode_writer_ref (gpointer instance);
void vala_ccode_writer_unref (gpointer instance);
GParamSpec* vala_param_spec_ccode_writer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_ccode_writer (GValue* value, gpointer v_object);
void vala_value_take_ccode_writer (GValue* value, gpointer v_object);
gpointer vala_value_get_ccode_writer (const GValue* value);
GType vala_ccode_writer_get_type (void) G_GNUC_CONST;
GType vala_ccode_declarator_get_type (void) G_GNUC_CONST;
GType vala_ccode_variable_declarator_get_type (void) G_GNUC_CONST;
GType vala_ccode_expression_get_type (void) G_GNUC_CONST;
gpointer vala_ccode_declarator_suffix_ref (gpointer instance);
void vala_ccode_declarator_suffix_unref (gpointer instance);
GParamSpec* vala_param_spec_ccode_declarator_suffix (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_ccode_declarator_suffix (GValue* value, gpointer v_object);
void vala_value_take_ccode_declarator_suffix (GValue* value, gpointer v_object);
gpointer vala_value_get_ccode_declarator_suffix (const GValue* value);
GType vala_ccode_declarator_suffix_get_type (void) G_GNUC_CONST;
#define VALA_CCODE_VARIABLE_DECLARATOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_CCODE_VARIABLE_DECLARATOR, ValaCCodeVariableDeclaratorPrivate))
enum  {
	VALA_CCODE_VARIABLE_DECLARATOR_DUMMY_PROPERTY
};
ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_new (const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix);
ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_construct (GType object_type, const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix);
ValaCCodeDeclarator* vala_ccode_declarator_construct (GType object_type);
void vala_ccode_variable_declarator_set_name (ValaCCodeVariableDeclarator* self, const gchar* value);
void vala_ccode_variable_declarator_set_initializer (ValaCCodeVariableDeclarator* self, ValaCCodeExpression* value);
void vala_ccode_variable_declarator_set_declarator_suffix (ValaCCodeVariableDeclarator* self, ValaCCodeDeclaratorSuffix* value);
ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_new_zero (const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix);
ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_construct_zero (GType object_type, const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix);
void vala_ccode_variable_declarator_set_init0 (ValaCCodeVariableDeclarator* self, gboolean value);
static void vala_ccode_variable_declarator_real_write (ValaCCodeNode* base, ValaCCodeWriter* writer);
void vala_ccode_writer_write_string (ValaCCodeWriter* self, const gchar* s);
const gchar* vala_ccode_variable_declarator_get_name (ValaCCodeVariableDeclarator* self);
ValaCCodeDeclaratorSuffix* vala_ccode_variable_declarator_get_declarator_suffix (ValaCCodeVariableDeclarator* self);
void vala_ccode_declarator_suffix_write (ValaCCodeDeclaratorSuffix* self, ValaCCodeWriter* writer);
ValaCCodeExpression* vala_ccode_variable_declarator_get_initializer (ValaCCodeVariableDeclarator* self);
void vala_ccode_node_write (ValaCCodeNode* self, ValaCCodeWriter* writer);
static void vala_ccode_variable_declarator_real_write_declaration (ValaCCodeNode* base, ValaCCodeWriter* writer);
gboolean vala_ccode_variable_declarator_get_init0 (ValaCCodeVariableDeclarator* self);
static void vala_ccode_variable_declarator_real_write_initialization (ValaCCodeDeclarator* base, ValaCCodeWriter* writer);
GType vala_ccode_line_directive_get_type (void) G_GNUC_CONST;
void vala_ccode_writer_write_indent (ValaCCodeWriter* self, ValaCCodeLineDirective* line);
ValaCCodeLineDirective* vala_ccode_node_get_line (ValaCCodeNode* self);
void vala_ccode_writer_write_newline (ValaCCodeWriter* self);
static void vala_ccode_variable_declarator_finalize (ValaCCodeNode* obj);
enum  {
	VALA_CCODE_DECLARATOR_SUFFIX_DUMMY_PROPERTY
};
ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_new_with_array (ValaCCodeExpression* array_length);
ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_construct_with_array (GType object_type, ValaCCodeExpression* array_length);
ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_new (void);
ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_construct (GType object_type);
static void vala_ccode_declarator_suffix_finalize (ValaCCodeDeclaratorSuffix* obj);


ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_construct (GType object_type, const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix) {
	ValaCCodeVariableDeclarator* self = NULL;
	const gchar* _tmp0_ = NULL;
	ValaCCodeExpression* _tmp1_ = NULL;
	ValaCCodeDeclaratorSuffix* _tmp2_ = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (ValaCCodeVariableDeclarator*) vala_ccode_declarator_construct (object_type);
	_tmp0_ = name;
	vala_ccode_variable_declarator_set_name (self, _tmp0_);
	_tmp1_ = initializer;
	vala_ccode_variable_declarator_set_initializer (self, _tmp1_);
	_tmp2_ = declarator_suffix;
	vala_ccode_variable_declarator_set_declarator_suffix (self, _tmp2_);
	return self;
}


ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_new (const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix) {
	return vala_ccode_variable_declarator_construct (VALA_TYPE_CCODE_VARIABLE_DECLARATOR, name, initializer, declarator_suffix);
}


ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_construct_zero (GType object_type, const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix) {
	ValaCCodeVariableDeclarator* self = NULL;
	const gchar* _tmp0_ = NULL;
	ValaCCodeExpression* _tmp1_ = NULL;
	ValaCCodeDeclaratorSuffix* _tmp2_ = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (ValaCCodeVariableDeclarator*) vala_ccode_declarator_construct (object_type);
	_tmp0_ = name;
	vala_ccode_variable_declarator_set_name (self, _tmp0_);
	_tmp1_ = initializer;
	vala_ccode_variable_declarator_set_initializer (self, _tmp1_);
	_tmp2_ = declarator_suffix;
	vala_ccode_variable_declarator_set_declarator_suffix (self, _tmp2_);
	vala_ccode_variable_declarator_set_init0 (self, TRUE);
	return self;
}


ValaCCodeVariableDeclarator* vala_ccode_variable_declarator_new_zero (const gchar* name, ValaCCodeExpression* initializer, ValaCCodeDeclaratorSuffix* declarator_suffix) {
	return vala_ccode_variable_declarator_construct_zero (VALA_TYPE_CCODE_VARIABLE_DECLARATOR, name, initializer, declarator_suffix);
}


static void vala_ccode_variable_declarator_real_write (ValaCCodeNode* base, ValaCCodeWriter* writer) {
	ValaCCodeVariableDeclarator * self;
	ValaCCodeWriter* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	ValaCCodeDeclaratorSuffix* _tmp2_ = NULL;
	ValaCCodeExpression* _tmp5_ = NULL;
	self = (ValaCCodeVariableDeclarator*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = writer;
	_tmp1_ = self->priv->_name;
	vala_ccode_writer_write_string (_tmp0_, _tmp1_);
	_tmp2_ = self->priv->_declarator_suffix;
	if (_tmp2_ != NULL) {
		ValaCCodeDeclaratorSuffix* _tmp3_ = NULL;
		ValaCCodeWriter* _tmp4_ = NULL;
		_tmp3_ = self->priv->_declarator_suffix;
		_tmp4_ = writer;
		vala_ccode_declarator_suffix_write (_tmp3_, _tmp4_);
	}
	_tmp5_ = self->priv->_initializer;
	if (_tmp5_ != NULL) {
		ValaCCodeWriter* _tmp6_ = NULL;
		ValaCCodeExpression* _tmp7_ = NULL;
		ValaCCodeWriter* _tmp8_ = NULL;
		_tmp6_ = writer;
		vala_ccode_writer_write_string (_tmp6_, " = ");
		_tmp7_ = self->priv->_initializer;
		_tmp8_ = writer;
		vala_ccode_node_write ((ValaCCodeNode*) _tmp7_, _tmp8_);
	}
}


static void vala_ccode_variable_declarator_real_write_declaration (ValaCCodeNode* base, ValaCCodeWriter* writer) {
	ValaCCodeVariableDeclarator * self;
	ValaCCodeWriter* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	ValaCCodeDeclaratorSuffix* _tmp2_ = NULL;
	gboolean _tmp5_ = FALSE;
	ValaCCodeExpression* _tmp6_ = NULL;
	self = (ValaCCodeVariableDeclarator*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = writer;
	_tmp1_ = self->priv->_name;
	vala_ccode_writer_write_string (_tmp0_, _tmp1_);
	_tmp2_ = self->priv->_declarator_suffix;
	if (_tmp2_ != NULL) {
		ValaCCodeDeclaratorSuffix* _tmp3_ = NULL;
		ValaCCodeWriter* _tmp4_ = NULL;
		_tmp3_ = self->priv->_declarator_suffix;
		_tmp4_ = writer;
		vala_ccode_declarator_suffix_write (_tmp3_, _tmp4_);
	}
	_tmp6_ = self->priv->_initializer;
	if (_tmp6_ != NULL) {
		gboolean _tmp7_ = FALSE;
		_tmp7_ = self->priv->_init0;
		_tmp5_ = _tmp7_;
	} else {
		_tmp5_ = FALSE;
	}
	if (_tmp5_) {
		ValaCCodeWriter* _tmp8_ = NULL;
		ValaCCodeExpression* _tmp9_ = NULL;
		ValaCCodeWriter* _tmp10_ = NULL;
		_tmp8_ = writer;
		vala_ccode_writer_write_string (_tmp8_, " = ");
		_tmp9_ = self->priv->_initializer;
		_tmp10_ = writer;
		vala_ccode_node_write ((ValaCCodeNode*) _tmp9_, _tmp10_);
	}
}


static void vala_ccode_variable_declarator_real_write_initialization (ValaCCodeDeclarator* base, ValaCCodeWriter* writer) {
	ValaCCodeVariableDeclarator * self;
	gboolean _tmp0_ = FALSE;
	ValaCCodeExpression* _tmp1_ = NULL;
	self = (ValaCCodeVariableDeclarator*) base;
	g_return_if_fail (writer != NULL);
	_tmp1_ = self->priv->_initializer;
	if (_tmp1_ != NULL) {
		gboolean _tmp2_ = FALSE;
		_tmp2_ = self->priv->_init0;
		_tmp0_ = !_tmp2_;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		ValaCCodeWriter* _tmp3_ = NULL;
		ValaCCodeLineDirective* _tmp4_ = NULL;
		ValaCCodeLineDirective* _tmp5_ = NULL;
		ValaCCodeWriter* _tmp6_ = NULL;
		const gchar* _tmp7_ = NULL;
		ValaCCodeWriter* _tmp8_ = NULL;
		ValaCCodeExpression* _tmp9_ = NULL;
		ValaCCodeWriter* _tmp10_ = NULL;
		ValaCCodeWriter* _tmp11_ = NULL;
		ValaCCodeWriter* _tmp12_ = NULL;
		_tmp3_ = writer;
		_tmp4_ = vala_ccode_node_get_line ((ValaCCodeNode*) self);
		_tmp5_ = _tmp4_;
		vala_ccode_writer_write_indent (_tmp3_, _tmp5_);
		_tmp6_ = writer;
		_tmp7_ = self->priv->_name;
		vala_ccode_writer_write_string (_tmp6_, _tmp7_);
		_tmp8_ = writer;
		vala_ccode_writer_write_string (_tmp8_, " = ");
		_tmp9_ = self->priv->_initializer;
		_tmp10_ = writer;
		vala_ccode_node_write ((ValaCCodeNode*) _tmp9_, _tmp10_);
		_tmp11_ = writer;
		vala_ccode_writer_write_string (_tmp11_, ";");
		_tmp12_ = writer;
		vala_ccode_writer_write_newline (_tmp12_);
	}
}


const gchar* vala_ccode_variable_declarator_get_name (ValaCCodeVariableDeclarator* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void vala_ccode_variable_declarator_set_name (ValaCCodeVariableDeclarator* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
}


ValaCCodeExpression* vala_ccode_variable_declarator_get_initializer (ValaCCodeVariableDeclarator* self) {
	ValaCCodeExpression* result;
	ValaCCodeExpression* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_initializer;
	result = _tmp0_;
	return result;
}


static gpointer _vala_ccode_node_ref0 (gpointer self) {
	return self ? vala_ccode_node_ref (self) : NULL;
}


void vala_ccode_variable_declarator_set_initializer (ValaCCodeVariableDeclarator* self, ValaCCodeExpression* value) {
	ValaCCodeExpression* _tmp0_ = NULL;
	ValaCCodeExpression* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_ccode_node_ref0 (_tmp0_);
	_vala_ccode_node_unref0 (self->priv->_initializer);
	self->priv->_initializer = _tmp1_;
}


ValaCCodeDeclaratorSuffix* vala_ccode_variable_declarator_get_declarator_suffix (ValaCCodeVariableDeclarator* self) {
	ValaCCodeDeclaratorSuffix* result;
	ValaCCodeDeclaratorSuffix* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_declarator_suffix;
	result = _tmp0_;
	return result;
}


static gpointer _vala_ccode_declarator_suffix_ref0 (gpointer self) {
	return self ? vala_ccode_declarator_suffix_ref (self) : NULL;
}


void vala_ccode_variable_declarator_set_declarator_suffix (ValaCCodeVariableDeclarator* self, ValaCCodeDeclaratorSuffix* value) {
	ValaCCodeDeclaratorSuffix* _tmp0_ = NULL;
	ValaCCodeDeclaratorSuffix* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_ccode_declarator_suffix_ref0 (_tmp0_);
	_vala_ccode_declarator_suffix_unref0 (self->priv->_declarator_suffix);
	self->priv->_declarator_suffix = _tmp1_;
}


gboolean vala_ccode_variable_declarator_get_init0 (ValaCCodeVariableDeclarator* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_init0;
	result = _tmp0_;
	return result;
}


void vala_ccode_variable_declarator_set_init0 (ValaCCodeVariableDeclarator* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_init0 = _tmp0_;
}


static void vala_ccode_variable_declarator_class_init (ValaCCodeVariableDeclaratorClass * klass) {
	vala_ccode_variable_declarator_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_variable_declarator_finalize;
	g_type_class_add_private (klass, sizeof (ValaCCodeVariableDeclaratorPrivate));
	((ValaCCodeNodeClass *) klass)->write = vala_ccode_variable_declarator_real_write;
	((ValaCCodeNodeClass *) klass)->write_declaration = vala_ccode_variable_declarator_real_write_declaration;
	((ValaCCodeDeclaratorClass *) klass)->write_initialization = vala_ccode_variable_declarator_real_write_initialization;
}


static void vala_ccode_variable_declarator_instance_init (ValaCCodeVariableDeclarator * self) {
	self->priv = VALA_CCODE_VARIABLE_DECLARATOR_GET_PRIVATE (self);
}


static void vala_ccode_variable_declarator_finalize (ValaCCodeNode* obj) {
	ValaCCodeVariableDeclarator * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_VARIABLE_DECLARATOR, ValaCCodeVariableDeclarator);
	_g_free0 (self->priv->_name);
	_vala_ccode_node_unref0 (self->priv->_initializer);
	_vala_ccode_declarator_suffix_unref0 (self->priv->_declarator_suffix);
	VALA_CCODE_NODE_CLASS (vala_ccode_variable_declarator_parent_class)->finalize (obj);
}


/**
 * Represents a variable declarator in the C code.
 */
GType vala_ccode_variable_declarator_get_type (void) {
	static volatile gsize vala_ccode_variable_declarator_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_variable_declarator_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeVariableDeclaratorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_variable_declarator_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeVariableDeclarator), 0, (GInstanceInitFunc) vala_ccode_variable_declarator_instance_init, NULL };
		GType vala_ccode_variable_declarator_type_id;
		vala_ccode_variable_declarator_type_id = g_type_register_static (VALA_TYPE_CCODE_DECLARATOR, "ValaCCodeVariableDeclarator", &g_define_type_info, 0);
		g_once_init_leave (&vala_ccode_variable_declarator_type_id__volatile, vala_ccode_variable_declarator_type_id);
	}
	return vala_ccode_variable_declarator_type_id__volatile;
}


ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_construct_with_array (GType object_type, ValaCCodeExpression* array_length) {
	ValaCCodeDeclaratorSuffix* self = NULL;
	ValaCCodeExpression* _tmp0_ = NULL;
	ValaCCodeExpression* _tmp1_ = NULL;
	self = (ValaCCodeDeclaratorSuffix*) g_type_create_instance (object_type);
	_tmp0_ = array_length;
	_tmp1_ = _vala_ccode_node_ref0 (_tmp0_);
	_vala_ccode_node_unref0 (self->array_length);
	self->array_length = _tmp1_;
	self->array = TRUE;
	return self;
}


ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_new_with_array (ValaCCodeExpression* array_length) {
	return vala_ccode_declarator_suffix_construct_with_array (VALA_TYPE_CCODE_DECLARATOR_SUFFIX, array_length);
}


void vala_ccode_declarator_suffix_write (ValaCCodeDeclaratorSuffix* self, ValaCCodeWriter* writer) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp6_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (writer != NULL);
	_tmp0_ = self->array;
	if (_tmp0_) {
		ValaCCodeWriter* _tmp1_ = NULL;
		ValaCCodeExpression* _tmp2_ = NULL;
		ValaCCodeWriter* _tmp5_ = NULL;
		_tmp1_ = writer;
		vala_ccode_writer_write_string (_tmp1_, "[");
		_tmp2_ = self->array_length;
		if (_tmp2_ != NULL) {
			ValaCCodeExpression* _tmp3_ = NULL;
			ValaCCodeWriter* _tmp4_ = NULL;
			_tmp3_ = self->array_length;
			_tmp4_ = writer;
			vala_ccode_node_write ((ValaCCodeNode*) _tmp3_, _tmp4_);
		}
		_tmp5_ = writer;
		vala_ccode_writer_write_string (_tmp5_, "]");
	}
	_tmp6_ = self->deprecated;
	if (_tmp6_) {
		ValaCCodeWriter* _tmp7_ = NULL;
		_tmp7_ = writer;
		vala_ccode_writer_write_string (_tmp7_, " G_GNUC_DEPRECATED");
	}
}


ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_construct (GType object_type) {
	ValaCCodeDeclaratorSuffix* self = NULL;
	self = (ValaCCodeDeclaratorSuffix*) g_type_create_instance (object_type);
	return self;
}


ValaCCodeDeclaratorSuffix* vala_ccode_declarator_suffix_new (void) {
	return vala_ccode_declarator_suffix_construct (VALA_TYPE_CCODE_DECLARATOR_SUFFIX);
}


static void vala_value_ccode_declarator_suffix_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void vala_value_ccode_declarator_suffix_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		vala_ccode_declarator_suffix_unref (value->data[0].v_pointer);
	}
}


static void vala_value_ccode_declarator_suffix_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = vala_ccode_declarator_suffix_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer vala_value_ccode_declarator_suffix_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* vala_value_ccode_declarator_suffix_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		ValaCCodeDeclaratorSuffix* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = vala_ccode_declarator_suffix_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* vala_value_ccode_declarator_suffix_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	ValaCCodeDeclaratorSuffix** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = vala_ccode_declarator_suffix_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* vala_param_spec_ccode_declarator_suffix (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ValaParamSpecCCodeDeclaratorSuffix* spec;
	g_return_val_if_fail (g_type_is_a (object_type, VALA_TYPE_CCODE_DECLARATOR_SUFFIX), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer vala_value_get_ccode_declarator_suffix (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_CCODE_DECLARATOR_SUFFIX), NULL);
	return value->data[0].v_pointer;
}


void vala_value_set_ccode_declarator_suffix (GValue* value, gpointer v_object) {
	ValaCCodeDeclaratorSuffix* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_CCODE_DECLARATOR_SUFFIX));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALA_TYPE_CCODE_DECLARATOR_SUFFIX));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		vala_ccode_declarator_suffix_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_ccode_declarator_suffix_unref (old);
	}
}


void vala_value_take_ccode_declarator_suffix (GValue* value, gpointer v_object) {
	ValaCCodeDeclaratorSuffix* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_CCODE_DECLARATOR_SUFFIX));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALA_TYPE_CCODE_DECLARATOR_SUFFIX));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_ccode_declarator_suffix_unref (old);
	}
}


static void vala_ccode_declarator_suffix_class_init (ValaCCodeDeclaratorSuffixClass * klass) {
	vala_ccode_declarator_suffix_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeDeclaratorSuffixClass *) klass)->finalize = vala_ccode_declarator_suffix_finalize;
}


static void vala_ccode_declarator_suffix_instance_init (ValaCCodeDeclaratorSuffix * self) {
	self->ref_count = 1;
}


static void vala_ccode_declarator_suffix_finalize (ValaCCodeDeclaratorSuffix* obj) {
	ValaCCodeDeclaratorSuffix * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_DECLARATOR_SUFFIX, ValaCCodeDeclaratorSuffix);
	g_signal_handlers_destroy (self);
	_vala_ccode_node_unref0 (self->array_length);
}


GType vala_ccode_declarator_suffix_get_type (void) {
	static volatile gsize vala_ccode_declarator_suffix_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_declarator_suffix_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { vala_value_ccode_declarator_suffix_init, vala_value_ccode_declarator_suffix_free_value, vala_value_ccode_declarator_suffix_copy_value, vala_value_ccode_declarator_suffix_peek_pointer, "p", vala_value_ccode_declarator_suffix_collect_value, "p", vala_value_ccode_declarator_suffix_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeDeclaratorSuffixClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_declarator_suffix_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeDeclaratorSuffix), 0, (GInstanceInitFunc) vala_ccode_declarator_suffix_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType vala_ccode_declarator_suffix_type_id;
		vala_ccode_declarator_suffix_type_id = g_type_register_fundamental (g_type_fundamental_next (), "ValaCCodeDeclaratorSuffix", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&vala_ccode_declarator_suffix_type_id__volatile, vala_ccode_declarator_suffix_type_id);
	}
	return vala_ccode_declarator_suffix_type_id__volatile;
}


gpointer vala_ccode_declarator_suffix_ref (gpointer instance) {
	ValaCCodeDeclaratorSuffix* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void vala_ccode_declarator_suffix_unref (gpointer instance) {
	ValaCCodeDeclaratorSuffix* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		VALA_CCODE_DECLARATOR_SUFFIX_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


