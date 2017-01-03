/* valaccodemacroreplacement.c generated by valac, the Vala compiler
 * generated from valaccodemacroreplacement.vala, do not modify */

/* valaccodemacroreplacement.vala
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

#define VALA_TYPE_CCODE_MACRO_REPLACEMENT (vala_ccode_macro_replacement_get_type ())
#define VALA_CCODE_MACRO_REPLACEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_MACRO_REPLACEMENT, ValaCCodeMacroReplacement))
#define VALA_CCODE_MACRO_REPLACEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_MACRO_REPLACEMENT, ValaCCodeMacroReplacementClass))
#define VALA_IS_CCODE_MACRO_REPLACEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_MACRO_REPLACEMENT))
#define VALA_IS_CCODE_MACRO_REPLACEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_MACRO_REPLACEMENT))
#define VALA_CCODE_MACRO_REPLACEMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_MACRO_REPLACEMENT, ValaCCodeMacroReplacementClass))

typedef struct _ValaCCodeMacroReplacement ValaCCodeMacroReplacement;
typedef struct _ValaCCodeMacroReplacementClass ValaCCodeMacroReplacementClass;
typedef struct _ValaCCodeMacroReplacementPrivate ValaCCodeMacroReplacementPrivate;

#define VALA_TYPE_CCODE_EXPRESSION (vala_ccode_expression_get_type ())
#define VALA_CCODE_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpression))
#define VALA_CCODE_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpressionClass))
#define VALA_IS_CCODE_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_EXPRESSION))
#define VALA_IS_CCODE_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_EXPRESSION))
#define VALA_CCODE_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpressionClass))

typedef struct _ValaCCodeExpression ValaCCodeExpression;
typedef struct _ValaCCodeExpressionClass ValaCCodeExpressionClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))

#define VALA_TYPE_CCODE_LINE_DIRECTIVE (vala_ccode_line_directive_get_type ())
#define VALA_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirective))
#define VALA_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))
#define VALA_IS_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_IS_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_CCODE_LINE_DIRECTIVE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))

typedef struct _ValaCCodeLineDirective ValaCCodeLineDirective;
typedef struct _ValaCCodeLineDirectiveClass ValaCCodeLineDirectiveClass;

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

struct _ValaCCodeMacroReplacement {
	ValaCCodeNode parent_instance;
	ValaCCodeMacroReplacementPrivate * priv;
};

struct _ValaCCodeMacroReplacementClass {
	ValaCCodeNodeClass parent_class;
};

struct _ValaCCodeMacroReplacementPrivate {
	gchar* _name;
	gchar* _replacement;
	ValaCCodeExpression* _replacement_expression;
};


static gpointer vala_ccode_macro_replacement_parent_class = NULL;

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
GType vala_ccode_macro_replacement_get_type (void) G_GNUC_CONST;
GType vala_ccode_expression_get_type (void) G_GNUC_CONST;
#define VALA_CCODE_MACRO_REPLACEMENT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_CCODE_MACRO_REPLACEMENT, ValaCCodeMacroReplacementPrivate))
enum  {
	VALA_CCODE_MACRO_REPLACEMENT_DUMMY_PROPERTY
};
ValaCCodeMacroReplacement* vala_ccode_macro_replacement_new (const gchar* name, const gchar* replacement);
ValaCCodeMacroReplacement* vala_ccode_macro_replacement_construct (GType object_type, const gchar* name, const gchar* replacement);
ValaCCodeNode* vala_ccode_node_construct (GType object_type);
void vala_ccode_macro_replacement_set_replacement (ValaCCodeMacroReplacement* self, const gchar* value);
void vala_ccode_macro_replacement_set_name (ValaCCodeMacroReplacement* self, const gchar* value);
ValaCCodeMacroReplacement* vala_ccode_macro_replacement_new_with_expression (const gchar* name, ValaCCodeExpression* replacement_expression);
ValaCCodeMacroReplacement* vala_ccode_macro_replacement_construct_with_expression (GType object_type, const gchar* name, ValaCCodeExpression* replacement_expression);
void vala_ccode_macro_replacement_set_replacement_expression (ValaCCodeMacroReplacement* self, ValaCCodeExpression* value);
static void vala_ccode_macro_replacement_real_write (ValaCCodeNode* base, ValaCCodeWriter* writer);
GType vala_ccode_line_directive_get_type (void) G_GNUC_CONST;
void vala_ccode_writer_write_indent (ValaCCodeWriter* self, ValaCCodeLineDirective* line);
void vala_ccode_writer_write_string (ValaCCodeWriter* self, const gchar* s);
const gchar* vala_ccode_macro_replacement_get_name (ValaCCodeMacroReplacement* self);
const gchar* vala_ccode_macro_replacement_get_replacement (ValaCCodeMacroReplacement* self);
ValaCCodeExpression* vala_ccode_macro_replacement_get_replacement_expression (ValaCCodeMacroReplacement* self);
void vala_ccode_expression_write_inner (ValaCCodeExpression* self, ValaCCodeWriter* writer);
void vala_ccode_writer_write_newline (ValaCCodeWriter* self);
static void vala_ccode_macro_replacement_finalize (ValaCCodeNode* obj);


ValaCCodeMacroReplacement* vala_ccode_macro_replacement_construct (GType object_type, const gchar* name, const gchar* replacement) {
	ValaCCodeMacroReplacement* self = NULL;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	self = (ValaCCodeMacroReplacement*) vala_ccode_node_construct (object_type);
	_tmp0_ = replacement;
	vala_ccode_macro_replacement_set_replacement (self, _tmp0_);
	_tmp1_ = name;
	vala_ccode_macro_replacement_set_name (self, _tmp1_);
	return self;
}


ValaCCodeMacroReplacement* vala_ccode_macro_replacement_new (const gchar* name, const gchar* replacement) {
	return vala_ccode_macro_replacement_construct (VALA_TYPE_CCODE_MACRO_REPLACEMENT, name, replacement);
}


ValaCCodeMacroReplacement* vala_ccode_macro_replacement_construct_with_expression (GType object_type, const gchar* name, ValaCCodeExpression* replacement_expression) {
	ValaCCodeMacroReplacement* self = NULL;
	const gchar* _tmp0_ = NULL;
	ValaCCodeExpression* _tmp1_ = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (replacement_expression != NULL, NULL);
	self = (ValaCCodeMacroReplacement*) vala_ccode_node_construct (object_type);
	_tmp0_ = name;
	vala_ccode_macro_replacement_set_name (self, _tmp0_);
	_tmp1_ = replacement_expression;
	vala_ccode_macro_replacement_set_replacement_expression (self, _tmp1_);
	return self;
}


ValaCCodeMacroReplacement* vala_ccode_macro_replacement_new_with_expression (const gchar* name, ValaCCodeExpression* replacement_expression) {
	return vala_ccode_macro_replacement_construct_with_expression (VALA_TYPE_CCODE_MACRO_REPLACEMENT, name, replacement_expression);
}


static void vala_ccode_macro_replacement_real_write (ValaCCodeNode* base, ValaCCodeWriter* writer) {
	ValaCCodeMacroReplacement * self;
	ValaCCodeWriter* _tmp0_ = NULL;
	ValaCCodeWriter* _tmp1_ = NULL;
	ValaCCodeWriter* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	ValaCCodeWriter* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	ValaCCodeWriter* _tmp10_ = NULL;
	self = (ValaCCodeMacroReplacement*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = writer;
	vala_ccode_writer_write_indent (_tmp0_, NULL);
	_tmp1_ = writer;
	vala_ccode_writer_write_string (_tmp1_, "#define ");
	_tmp2_ = writer;
	_tmp3_ = self->priv->_name;
	vala_ccode_writer_write_string (_tmp2_, _tmp3_);
	_tmp4_ = writer;
	vala_ccode_writer_write_string (_tmp4_, " ");
	_tmp5_ = self->priv->_replacement;
	if (_tmp5_ != NULL) {
		ValaCCodeWriter* _tmp6_ = NULL;
		const gchar* _tmp7_ = NULL;
		_tmp6_ = writer;
		_tmp7_ = self->priv->_replacement;
		vala_ccode_writer_write_string (_tmp6_, _tmp7_);
	} else {
		ValaCCodeExpression* _tmp8_ = NULL;
		ValaCCodeWriter* _tmp9_ = NULL;
		_tmp8_ = self->priv->_replacement_expression;
		_tmp9_ = writer;
		vala_ccode_expression_write_inner (_tmp8_, _tmp9_);
	}
	_tmp10_ = writer;
	vala_ccode_writer_write_newline (_tmp10_);
}


const gchar* vala_ccode_macro_replacement_get_name (ValaCCodeMacroReplacement* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void vala_ccode_macro_replacement_set_name (ValaCCodeMacroReplacement* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
}


const gchar* vala_ccode_macro_replacement_get_replacement (ValaCCodeMacroReplacement* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_replacement;
	result = _tmp0_;
	return result;
}


void vala_ccode_macro_replacement_set_replacement (ValaCCodeMacroReplacement* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_replacement);
	self->priv->_replacement = _tmp1_;
}


ValaCCodeExpression* vala_ccode_macro_replacement_get_replacement_expression (ValaCCodeMacroReplacement* self) {
	ValaCCodeExpression* result;
	ValaCCodeExpression* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_replacement_expression;
	result = _tmp0_;
	return result;
}


static gpointer _vala_ccode_node_ref0 (gpointer self) {
	return self ? vala_ccode_node_ref (self) : NULL;
}


void vala_ccode_macro_replacement_set_replacement_expression (ValaCCodeMacroReplacement* self, ValaCCodeExpression* value) {
	ValaCCodeExpression* _tmp0_ = NULL;
	ValaCCodeExpression* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_ccode_node_ref0 (_tmp0_);
	_vala_ccode_node_unref0 (self->priv->_replacement_expression);
	self->priv->_replacement_expression = _tmp1_;
}


static void vala_ccode_macro_replacement_class_init (ValaCCodeMacroReplacementClass * klass) {
	vala_ccode_macro_replacement_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_macro_replacement_finalize;
	g_type_class_add_private (klass, sizeof (ValaCCodeMacroReplacementPrivate));
	((ValaCCodeNodeClass *) klass)->write = vala_ccode_macro_replacement_real_write;
}


static void vala_ccode_macro_replacement_instance_init (ValaCCodeMacroReplacement * self) {
	self->priv = VALA_CCODE_MACRO_REPLACEMENT_GET_PRIVATE (self);
}


static void vala_ccode_macro_replacement_finalize (ValaCCodeNode* obj) {
	ValaCCodeMacroReplacement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_MACRO_REPLACEMENT, ValaCCodeMacroReplacement);
	_g_free0 (self->priv->_name);
	_g_free0 (self->priv->_replacement);
	_vala_ccode_node_unref0 (self->priv->_replacement_expression);
	VALA_CCODE_NODE_CLASS (vala_ccode_macro_replacement_parent_class)->finalize (obj);
}


/**
 * Represents a preprocessor macro replacement definition in the C code.
 */
GType vala_ccode_macro_replacement_get_type (void) {
	static volatile gsize vala_ccode_macro_replacement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_macro_replacement_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeMacroReplacementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_macro_replacement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeMacroReplacement), 0, (GInstanceInitFunc) vala_ccode_macro_replacement_instance_init, NULL };
		GType vala_ccode_macro_replacement_type_id;
		vala_ccode_macro_replacement_type_id = g_type_register_static (VALA_TYPE_CCODE_NODE, "ValaCCodeMacroReplacement", &g_define_type_info, 0);
		g_once_init_leave (&vala_ccode_macro_replacement_type_id__volatile, vala_ccode_macro_replacement_type_id);
	}
	return vala_ccode_macro_replacement_type_id__volatile;
}


