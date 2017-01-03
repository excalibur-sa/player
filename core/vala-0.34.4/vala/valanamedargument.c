/* valanamedargument.c generated by valac, the Vala compiler
 * generated from valanamedargument.vala, do not modify */

/* valanamedargument.vala
 *
 * Copyright (C) 2009-2010  Jürg Billeter
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
#include <valagee.h>


#define VALA_TYPE_CODE_NODE (vala_code_node_get_type ())
#define VALA_CODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_NODE, ValaCodeNode))
#define VALA_CODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_NODE, ValaCodeNodeClass))
#define VALA_IS_CODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_NODE))
#define VALA_IS_CODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_NODE))
#define VALA_CODE_NODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_NODE, ValaCodeNodeClass))

typedef struct _ValaCodeNode ValaCodeNode;
typedef struct _ValaCodeNodeClass ValaCodeNodeClass;
typedef struct _ValaCodeNodePrivate ValaCodeNodePrivate;

#define VALA_TYPE_CODE_VISITOR (vala_code_visitor_get_type ())
#define VALA_CODE_VISITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_VISITOR, ValaCodeVisitor))
#define VALA_CODE_VISITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_VISITOR, ValaCodeVisitorClass))
#define VALA_IS_CODE_VISITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_VISITOR))
#define VALA_IS_CODE_VISITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_VISITOR))
#define VALA_CODE_VISITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_VISITOR, ValaCodeVisitorClass))

typedef struct _ValaCodeVisitor ValaCodeVisitor;
typedef struct _ValaCodeVisitorClass ValaCodeVisitorClass;

#define VALA_TYPE_CODE_CONTEXT (vala_code_context_get_type ())
#define VALA_CODE_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_CONTEXT, ValaCodeContext))
#define VALA_CODE_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_CONTEXT, ValaCodeContextClass))
#define VALA_IS_CODE_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_CONTEXT))
#define VALA_IS_CODE_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_CONTEXT))
#define VALA_CODE_CONTEXT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_CONTEXT, ValaCodeContextClass))

typedef struct _ValaCodeContext ValaCodeContext;
typedef struct _ValaCodeContextClass ValaCodeContextClass;

#define VALA_TYPE_CODE_GENERATOR (vala_code_generator_get_type ())
#define VALA_CODE_GENERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_GENERATOR, ValaCodeGenerator))
#define VALA_CODE_GENERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_GENERATOR, ValaCodeGeneratorClass))
#define VALA_IS_CODE_GENERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_GENERATOR))
#define VALA_IS_CODE_GENERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_GENERATOR))
#define VALA_CODE_GENERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_GENERATOR, ValaCodeGeneratorClass))

typedef struct _ValaCodeGenerator ValaCodeGenerator;
typedef struct _ValaCodeGeneratorClass ValaCodeGeneratorClass;

#define VALA_TYPE_DATA_TYPE (vala_data_type_get_type ())
#define VALA_DATA_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_DATA_TYPE, ValaDataType))
#define VALA_DATA_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_DATA_TYPE, ValaDataTypeClass))
#define VALA_IS_DATA_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_DATA_TYPE))
#define VALA_IS_DATA_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_DATA_TYPE))
#define VALA_DATA_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_DATA_TYPE, ValaDataTypeClass))

typedef struct _ValaDataType ValaDataType;
typedef struct _ValaDataTypeClass ValaDataTypeClass;

#define VALA_TYPE_EXPRESSION (vala_expression_get_type ())
#define VALA_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_EXPRESSION, ValaExpression))
#define VALA_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_EXPRESSION, ValaExpressionClass))
#define VALA_IS_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_EXPRESSION))
#define VALA_IS_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_EXPRESSION))
#define VALA_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_EXPRESSION, ValaExpressionClass))

typedef struct _ValaExpression ValaExpression;
typedef struct _ValaExpressionClass ValaExpressionClass;

#define VALA_TYPE_SYMBOL (vala_symbol_get_type ())
#define VALA_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SYMBOL, ValaSymbol))
#define VALA_SYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SYMBOL, ValaSymbolClass))
#define VALA_IS_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SYMBOL))
#define VALA_IS_SYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SYMBOL))
#define VALA_SYMBOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SYMBOL, ValaSymbolClass))

typedef struct _ValaSymbol ValaSymbol;
typedef struct _ValaSymbolClass ValaSymbolClass;

#define VALA_TYPE_VARIABLE (vala_variable_get_type ())
#define VALA_VARIABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_VARIABLE, ValaVariable))
#define VALA_VARIABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_VARIABLE, ValaVariableClass))
#define VALA_IS_VARIABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_VARIABLE))
#define VALA_IS_VARIABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_VARIABLE))
#define VALA_VARIABLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_VARIABLE, ValaVariableClass))

typedef struct _ValaVariable ValaVariable;
typedef struct _ValaVariableClass ValaVariableClass;

#define VALA_TYPE_ATTRIBUTE (vala_attribute_get_type ())
#define VALA_ATTRIBUTE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ATTRIBUTE, ValaAttribute))
#define VALA_ATTRIBUTE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ATTRIBUTE, ValaAttributeClass))
#define VALA_IS_ATTRIBUTE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ATTRIBUTE))
#define VALA_IS_ATTRIBUTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ATTRIBUTE))
#define VALA_ATTRIBUTE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ATTRIBUTE, ValaAttributeClass))

typedef struct _ValaAttribute ValaAttribute;
typedef struct _ValaAttributeClass ValaAttributeClass;
typedef struct _ValaExpressionPrivate ValaExpressionPrivate;

#define VALA_TYPE_NAMED_ARGUMENT (vala_named_argument_get_type ())
#define VALA_NAMED_ARGUMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_NAMED_ARGUMENT, ValaNamedArgument))
#define VALA_NAMED_ARGUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_NAMED_ARGUMENT, ValaNamedArgumentClass))
#define VALA_IS_NAMED_ARGUMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_NAMED_ARGUMENT))
#define VALA_IS_NAMED_ARGUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_NAMED_ARGUMENT))
#define VALA_NAMED_ARGUMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_NAMED_ARGUMENT, ValaNamedArgumentClass))

typedef struct _ValaNamedArgument ValaNamedArgument;
typedef struct _ValaNamedArgumentClass ValaNamedArgumentClass;
typedef struct _ValaNamedArgumentPrivate ValaNamedArgumentPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

#define VALA_TYPE_SOURCE_REFERENCE (vala_source_reference_get_type ())
#define VALA_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReference))
#define VALA_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))
#define VALA_IS_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_IS_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_SOURCE_REFERENCE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))

typedef struct _ValaSourceReference ValaSourceReference;
typedef struct _ValaSourceReferenceClass ValaSourceReferenceClass;

struct _ValaCodeNode {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaCodeNodePrivate * priv;
	GList* attributes;
};

struct _ValaCodeNodeClass {
	GTypeClass parent_class;
	void (*finalize) (ValaCodeNode *self);
	void (*accept) (ValaCodeNode* self, ValaCodeVisitor* visitor);
	void (*accept_children) (ValaCodeNode* self, ValaCodeVisitor* visitor);
	gboolean (*check) (ValaCodeNode* self, ValaCodeContext* context);
	void (*emit) (ValaCodeNode* self, ValaCodeGenerator* codegen);
	void (*replace_type) (ValaCodeNode* self, ValaDataType* old_type, ValaDataType* new_type);
	void (*replace_expression) (ValaCodeNode* self, ValaExpression* old_node, ValaExpression* new_node);
	gchar* (*to_string) (ValaCodeNode* self);
	void (*get_defined_variables) (ValaCodeNode* self, ValaCollection* collection);
	void (*get_used_variables) (ValaCodeNode* self, ValaCollection* collection);
};

struct _ValaExpression {
	ValaCodeNode parent_instance;
	ValaExpressionPrivate * priv;
};

struct _ValaExpressionClass {
	ValaCodeNodeClass parent_class;
	gboolean (*is_constant) (ValaExpression* self);
	gboolean (*is_pure) (ValaExpression* self);
	gboolean (*is_non_null) (ValaExpression* self);
};

struct _ValaNamedArgument {
	ValaExpression parent_instance;
	ValaNamedArgumentPrivate * priv;
};

struct _ValaNamedArgumentClass {
	ValaExpressionClass parent_class;
};

struct _ValaNamedArgumentPrivate {
	gchar* _name;
	ValaExpression* _inner;
};


static gpointer vala_named_argument_parent_class = NULL;

gpointer vala_code_node_ref (gpointer instance);
void vala_code_node_unref (gpointer instance);
GParamSpec* vala_param_spec_code_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_code_node (GValue* value, gpointer v_object);
void vala_value_take_code_node (GValue* value, gpointer v_object);
gpointer vala_value_get_code_node (const GValue* value);
GType vala_code_node_get_type (void) G_GNUC_CONST;
gpointer vala_code_visitor_ref (gpointer instance);
void vala_code_visitor_unref (gpointer instance);
GParamSpec* vala_param_spec_code_visitor (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_code_visitor (GValue* value, gpointer v_object);
void vala_value_take_code_visitor (GValue* value, gpointer v_object);
gpointer vala_value_get_code_visitor (const GValue* value);
GType vala_code_visitor_get_type (void) G_GNUC_CONST;
gpointer vala_code_context_ref (gpointer instance);
void vala_code_context_unref (gpointer instance);
GParamSpec* vala_param_spec_code_context (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_code_context (GValue* value, gpointer v_object);
void vala_value_take_code_context (GValue* value, gpointer v_object);
gpointer vala_value_get_code_context (const GValue* value);
GType vala_code_context_get_type (void) G_GNUC_CONST;
GType vala_code_generator_get_type (void) G_GNUC_CONST;
GType vala_data_type_get_type (void) G_GNUC_CONST;
GType vala_expression_get_type (void) G_GNUC_CONST;
GType vala_symbol_get_type (void) G_GNUC_CONST;
GType vala_variable_get_type (void) G_GNUC_CONST;
GType vala_attribute_get_type (void) G_GNUC_CONST;
GType vala_named_argument_get_type (void) G_GNUC_CONST;
#define VALA_NAMED_ARGUMENT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_NAMED_ARGUMENT, ValaNamedArgumentPrivate))
enum  {
	VALA_NAMED_ARGUMENT_DUMMY_PROPERTY
};
gpointer vala_source_reference_ref (gpointer instance);
void vala_source_reference_unref (gpointer instance);
GParamSpec* vala_param_spec_source_reference (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_source_reference (GValue* value, gpointer v_object);
void vala_value_take_source_reference (GValue* value, gpointer v_object);
gpointer vala_value_get_source_reference (const GValue* value);
GType vala_source_reference_get_type (void) G_GNUC_CONST;
ValaNamedArgument* vala_named_argument_new (const gchar* name, ValaExpression* inner, ValaSourceReference* source_reference);
ValaNamedArgument* vala_named_argument_construct (GType object_type, const gchar* name, ValaExpression* inner, ValaSourceReference* source_reference);
ValaExpression* vala_expression_construct (GType object_type);
void vala_named_argument_set_name (ValaNamedArgument* self, const gchar* value);
void vala_named_argument_set_inner (ValaNamedArgument* self, ValaExpression* value);
void vala_code_node_set_source_reference (ValaCodeNode* self, ValaSourceReference* value);
static void vala_named_argument_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor);
void vala_code_visitor_visit_named_argument (ValaCodeVisitor* self, ValaNamedArgument* expr);
void vala_code_visitor_visit_expression (ValaCodeVisitor* self, ValaExpression* expr);
static void vala_named_argument_real_accept_children (ValaCodeNode* base, ValaCodeVisitor* visitor);
ValaExpression* vala_named_argument_get_inner (ValaNamedArgument* self);
void vala_code_node_accept (ValaCodeNode* self, ValaCodeVisitor* visitor);
static void vala_named_argument_real_replace_expression (ValaCodeNode* base, ValaExpression* old_node, ValaExpression* new_node);
static gboolean vala_named_argument_real_is_pure (ValaExpression* base);
gboolean vala_expression_is_pure (ValaExpression* self);
static gboolean vala_named_argument_real_check (ValaCodeNode* base, ValaCodeContext* context);
gboolean vala_code_node_get_checked (ValaCodeNode* self);
gboolean vala_code_node_get_error (ValaCodeNode* self);
void vala_code_node_set_checked (ValaCodeNode* self, gboolean value);
ValaDataType* vala_expression_get_target_type (ValaExpression* self);
void vala_expression_set_target_type (ValaExpression* self, ValaDataType* value);
gboolean vala_code_node_check (ValaCodeNode* self, ValaCodeContext* context);
void vala_code_node_set_error (ValaCodeNode* self, gboolean value);
ValaDataType* vala_expression_get_value_type (ValaExpression* self);
void vala_expression_set_value_type (ValaExpression* self, ValaDataType* value);
static void vala_named_argument_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen);
void vala_code_node_emit (ValaCodeNode* self, ValaCodeGenerator* codegen);
static void vala_named_argument_real_get_defined_variables (ValaCodeNode* base, ValaCollection* collection);
void vala_code_node_get_defined_variables (ValaCodeNode* self, ValaCollection* collection);
static void vala_named_argument_real_get_used_variables (ValaCodeNode* base, ValaCollection* collection);
void vala_code_node_get_used_variables (ValaCodeNode* self, ValaCollection* collection);
const gchar* vala_named_argument_get_name (ValaNamedArgument* self);
void vala_code_node_set_parent_node (ValaCodeNode* self, ValaCodeNode* value);
static void vala_named_argument_finalize (ValaCodeNode* obj);


ValaNamedArgument* vala_named_argument_construct (GType object_type, const gchar* name, ValaExpression* inner, ValaSourceReference* source_reference) {
	ValaNamedArgument* self = NULL;
	const gchar* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaSourceReference* _tmp2_ = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (inner != NULL, NULL);
	self = (ValaNamedArgument*) vala_expression_construct (object_type);
	_tmp0_ = name;
	vala_named_argument_set_name (self, _tmp0_);
	_tmp1_ = inner;
	vala_named_argument_set_inner (self, _tmp1_);
	_tmp2_ = source_reference;
	vala_code_node_set_source_reference ((ValaCodeNode*) self, _tmp2_);
	return self;
}


ValaNamedArgument* vala_named_argument_new (const gchar* name, ValaExpression* inner, ValaSourceReference* source_reference) {
	return vala_named_argument_construct (VALA_TYPE_NAMED_ARGUMENT, name, inner, source_reference);
}


static void vala_named_argument_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor) {
	ValaNamedArgument * self;
	ValaCodeVisitor* _tmp0_ = NULL;
	ValaCodeVisitor* _tmp1_ = NULL;
	self = (ValaNamedArgument*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = visitor;
	vala_code_visitor_visit_named_argument (_tmp0_, self);
	_tmp1_ = visitor;
	vala_code_visitor_visit_expression (_tmp1_, (ValaExpression*) self);
}


static void vala_named_argument_real_accept_children (ValaCodeNode* base, ValaCodeVisitor* visitor) {
	ValaNamedArgument * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaCodeVisitor* _tmp2_ = NULL;
	self = (ValaNamedArgument*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_named_argument_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = visitor;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, _tmp2_);
}


static void vala_named_argument_real_replace_expression (ValaCodeNode* base, ValaExpression* old_node, ValaExpression* new_node) {
	ValaNamedArgument * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaExpression* _tmp2_ = NULL;
	self = (ValaNamedArgument*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_named_argument_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = old_node;
	if (_tmp1_ == _tmp2_) {
		ValaExpression* _tmp3_ = NULL;
		_tmp3_ = new_node;
		vala_named_argument_set_inner (self, _tmp3_);
	}
}


static gboolean vala_named_argument_real_is_pure (ValaExpression* base) {
	ValaNamedArgument * self;
	gboolean result = FALSE;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	self = (ValaNamedArgument*) base;
	_tmp0_ = vala_named_argument_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_expression_is_pure (_tmp1_);
	result = _tmp2_;
	return result;
}


static gboolean vala_named_argument_real_check (ValaCodeNode* base, ValaCodeContext* context) {
	ValaNamedArgument * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	ValaExpression* _tmp4_ = NULL;
	ValaExpression* _tmp5_ = NULL;
	ValaDataType* _tmp6_ = NULL;
	ValaDataType* _tmp7_ = NULL;
	ValaExpression* _tmp8_ = NULL;
	ValaExpression* _tmp9_ = NULL;
	ValaCodeContext* _tmp10_ = NULL;
	gboolean _tmp11_ = FALSE;
	ValaExpression* _tmp12_ = NULL;
	ValaExpression* _tmp13_ = NULL;
	ValaExpression* _tmp14_ = NULL;
	ValaExpression* _tmp15_ = NULL;
	ValaDataType* _tmp16_ = NULL;
	ValaDataType* _tmp17_ = NULL;
	ValaExpression* _tmp18_ = NULL;
	ValaExpression* _tmp19_ = NULL;
	ValaDataType* _tmp20_ = NULL;
	ValaDataType* _tmp21_ = NULL;
	gboolean _tmp22_ = FALSE;
	gboolean _tmp23_ = FALSE;
	self = (ValaNamedArgument*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_ = FALSE;
		gboolean _tmp3_ = FALSE;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = vala_named_argument_get_inner (self);
	_tmp5_ = _tmp4_;
	_tmp6_ = vala_expression_get_target_type ((ValaExpression*) self);
	_tmp7_ = _tmp6_;
	vala_expression_set_target_type (_tmp5_, _tmp7_);
	_tmp8_ = vala_named_argument_get_inner (self);
	_tmp9_ = _tmp8_;
	_tmp10_ = context;
	_tmp11_ = vala_code_node_check ((ValaCodeNode*) _tmp9_, _tmp10_);
	if (!_tmp11_) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp12_ = vala_named_argument_get_inner (self);
	_tmp13_ = _tmp12_;
	_tmp14_ = vala_named_argument_get_inner (self);
	_tmp15_ = _tmp14_;
	_tmp16_ = vala_expression_get_value_type (_tmp15_);
	_tmp17_ = _tmp16_;
	vala_expression_set_target_type (_tmp13_, _tmp17_);
	_tmp18_ = vala_named_argument_get_inner (self);
	_tmp19_ = _tmp18_;
	_tmp20_ = vala_expression_get_value_type (_tmp19_);
	_tmp21_ = _tmp20_;
	vala_expression_set_value_type ((ValaExpression*) self, _tmp21_);
	_tmp22_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp23_ = _tmp22_;
	result = !_tmp23_;
	return result;
}


static void vala_named_argument_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen) {
	ValaNamedArgument * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaCodeGenerator* _tmp2_ = NULL;
	ValaCodeGenerator* _tmp3_ = NULL;
	ValaCodeGenerator* _tmp4_ = NULL;
	self = (ValaNamedArgument*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_named_argument_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = codegen;
	vala_code_node_emit ((ValaCodeNode*) _tmp1_, _tmp2_);
	_tmp3_ = codegen;
	vala_code_visitor_visit_named_argument ((ValaCodeVisitor*) _tmp3_, self);
	_tmp4_ = codegen;
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) _tmp4_, (ValaExpression*) self);
}


static void vala_named_argument_real_get_defined_variables (ValaCodeNode* base, ValaCollection* collection) {
	ValaNamedArgument * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaCollection* _tmp2_ = NULL;
	self = (ValaNamedArgument*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_named_argument_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = collection;
	vala_code_node_get_defined_variables ((ValaCodeNode*) _tmp1_, _tmp2_);
}


static void vala_named_argument_real_get_used_variables (ValaCodeNode* base, ValaCollection* collection) {
	ValaNamedArgument * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaCollection* _tmp2_ = NULL;
	self = (ValaNamedArgument*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_named_argument_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = collection;
	vala_code_node_get_used_variables ((ValaCodeNode*) _tmp1_, _tmp2_);
}


const gchar* vala_named_argument_get_name (ValaNamedArgument* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void vala_named_argument_set_name (ValaNamedArgument* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
}


ValaExpression* vala_named_argument_get_inner (ValaNamedArgument* self) {
	ValaExpression* result;
	ValaExpression* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_inner;
	result = _tmp0_;
	return result;
}


static gpointer _vala_code_node_ref0 (gpointer self) {
	return self ? vala_code_node_ref (self) : NULL;
}


void vala_named_argument_set_inner (ValaNamedArgument* self, ValaExpression* value) {
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaExpression* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_inner);
	self->priv->_inner = _tmp1_;
	_tmp2_ = self->priv->_inner;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
}


static void vala_named_argument_class_init (ValaNamedArgumentClass * klass) {
	vala_named_argument_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_named_argument_finalize;
	g_type_class_add_private (klass, sizeof (ValaNamedArgumentPrivate));
	((ValaCodeNodeClass *) klass)->accept = vala_named_argument_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = vala_named_argument_real_accept_children;
	((ValaCodeNodeClass *) klass)->replace_expression = vala_named_argument_real_replace_expression;
	((ValaExpressionClass *) klass)->is_pure = vala_named_argument_real_is_pure;
	((ValaCodeNodeClass *) klass)->check = vala_named_argument_real_check;
	((ValaCodeNodeClass *) klass)->emit = vala_named_argument_real_emit;
	((ValaCodeNodeClass *) klass)->get_defined_variables = vala_named_argument_real_get_defined_variables;
	((ValaCodeNodeClass *) klass)->get_used_variables = vala_named_argument_real_get_used_variables;
}


static void vala_named_argument_instance_init (ValaNamedArgument * self) {
	self->priv = VALA_NAMED_ARGUMENT_GET_PRIVATE (self);
}


static void vala_named_argument_finalize (ValaCodeNode* obj) {
	ValaNamedArgument * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_NAMED_ARGUMENT, ValaNamedArgument);
	_g_free0 (self->priv->_name);
	_vala_code_node_unref0 (self->priv->_inner);
	VALA_CODE_NODE_CLASS (vala_named_argument_parent_class)->finalize (obj);
}


GType vala_named_argument_get_type (void) {
	static volatile gsize vala_named_argument_type_id__volatile = 0;
	if (g_once_init_enter (&vala_named_argument_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaNamedArgumentClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_named_argument_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaNamedArgument), 0, (GInstanceInitFunc) vala_named_argument_instance_init, NULL };
		GType vala_named_argument_type_id;
		vala_named_argument_type_id = g_type_register_static (VALA_TYPE_EXPRESSION, "ValaNamedArgument", &g_define_type_info, 0);
		g_once_init_leave (&vala_named_argument_type_id__volatile, vala_named_argument_type_id);
	}
	return vala_named_argument_type_id__volatile;
}



