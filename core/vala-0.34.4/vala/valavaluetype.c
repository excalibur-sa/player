/* valavaluetype.c generated by valac, the Vala compiler
 * generated from valavaluetype.vala, do not modify */

/* valavaluetype.vala
 *
 * Copyright (C) 2007-2009  Jürg Billeter
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
typedef struct _ValaDataTypePrivate ValaDataTypePrivate;

#define VALA_TYPE_SCOPE (vala_scope_get_type ())
#define VALA_SCOPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SCOPE, ValaScope))
#define VALA_SCOPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SCOPE, ValaScopeClass))
#define VALA_IS_SCOPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SCOPE))
#define VALA_IS_SCOPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SCOPE))
#define VALA_SCOPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SCOPE, ValaScopeClass))

typedef struct _ValaScope ValaScope;
typedef struct _ValaScopeClass ValaScopeClass;

#define VALA_TYPE_PARAMETER (vala_parameter_get_type ())
#define VALA_PARAMETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_PARAMETER, ValaParameter))
#define VALA_PARAMETER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_PARAMETER, ValaParameterClass))
#define VALA_IS_PARAMETER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_PARAMETER))
#define VALA_IS_PARAMETER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_PARAMETER))
#define VALA_PARAMETER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_PARAMETER, ValaParameterClass))

typedef struct _ValaParameter ValaParameter;
typedef struct _ValaParameterClass ValaParameterClass;

#define VALA_TYPE_TYPEPARAMETER (vala_typeparameter_get_type ())
#define VALA_TYPEPARAMETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_TYPEPARAMETER, ValaTypeParameter))
#define VALA_TYPEPARAMETER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_TYPEPARAMETER, ValaTypeParameterClass))
#define VALA_IS_TYPEPARAMETER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_TYPEPARAMETER))
#define VALA_IS_TYPEPARAMETER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_TYPEPARAMETER))
#define VALA_TYPEPARAMETER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_TYPEPARAMETER, ValaTypeParameterClass))

typedef struct _ValaTypeParameter ValaTypeParameter;
typedef struct _ValaTypeParameterClass ValaTypeParameterClass;

#define VALA_TYPE_VALUE_TYPE (vala_value_type_get_type ())
#define VALA_VALUE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_VALUE_TYPE, ValaValueType))
#define VALA_VALUE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_VALUE_TYPE, ValaValueTypeClass))
#define VALA_IS_VALUE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_VALUE_TYPE))
#define VALA_IS_VALUE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_VALUE_TYPE))
#define VALA_VALUE_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_VALUE_TYPE, ValaValueTypeClass))

typedef struct _ValaValueType ValaValueType;
typedef struct _ValaValueTypeClass ValaValueTypeClass;
typedef struct _ValaValueTypePrivate ValaValueTypePrivate;

#define VALA_TYPE_TYPESYMBOL (vala_typesymbol_get_type ())
#define VALA_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbol))
#define VALA_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))
#define VALA_IS_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_TYPESYMBOL))
#define VALA_IS_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_TYPESYMBOL))
#define VALA_TYPESYMBOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))

typedef struct _ValaTypeSymbol ValaTypeSymbol;
typedef struct _ValaTypeSymbolClass ValaTypeSymbolClass;

#define VALA_TYPE_STRUCT (vala_struct_get_type ())
#define VALA_STRUCT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_STRUCT, ValaStruct))
#define VALA_STRUCT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_STRUCT, ValaStructClass))
#define VALA_IS_STRUCT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_STRUCT))
#define VALA_IS_STRUCT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_STRUCT))
#define VALA_STRUCT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_STRUCT, ValaStructClass))

typedef struct _ValaStruct ValaStruct;
typedef struct _ValaStructClass ValaStructClass;
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

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

struct _ValaDataType {
	ValaCodeNode parent_instance;
	ValaDataTypePrivate * priv;
};

struct _ValaDataTypeClass {
	ValaCodeNodeClass parent_class;
	gchar* (*to_qualified_string) (ValaDataType* self, ValaScope* scope);
	ValaDataType* (*copy) (ValaDataType* self);
	gboolean (*equals) (ValaDataType* self, ValaDataType* type2);
	gboolean (*stricter) (ValaDataType* self, ValaDataType* type2);
	gboolean (*compatible) (ValaDataType* self, ValaDataType* target_type);
	gboolean (*is_invokable) (ValaDataType* self);
	ValaDataType* (*get_return_type) (ValaDataType* self);
	ValaList* (*get_parameters) (ValaDataType* self);
	gboolean (*is_reference_type_or_type_parameter) (ValaDataType* self);
	gboolean (*is_array) (ValaDataType* self);
	gboolean (*is_accessible) (ValaDataType* self, ValaSymbol* sym);
	ValaSymbol* (*get_member) (ValaDataType* self, const gchar* member_name);
	ValaSymbol* (*get_pointer_member) (ValaDataType* self, const gchar* member_name);
	gboolean (*is_real_struct_type) (ValaDataType* self);
	gboolean (*is_disposable) (ValaDataType* self);
	ValaDataType* (*get_actual_type) (ValaDataType* self, ValaDataType* derived_instance_type, ValaList* method_type_arguments, ValaCodeNode* node_reference);
	ValaDataType* (*infer_type_argument) (ValaDataType* self, ValaTypeParameter* type_param, ValaDataType* value_type);
};

struct _ValaValueType {
	ValaDataType parent_instance;
	ValaValueTypePrivate * priv;
};

struct _ValaValueTypeClass {
	ValaDataTypeClass parent_class;
};

struct _ValaValueTypePrivate {
	ValaTypeSymbol* _type_symbol;
};


static gpointer vala_value_type_parent_class = NULL;

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
gpointer vala_scope_ref (gpointer instance);
void vala_scope_unref (gpointer instance);
GParamSpec* vala_param_spec_scope (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_scope (GValue* value, gpointer v_object);
void vala_value_take_scope (GValue* value, gpointer v_object);
gpointer vala_value_get_scope (const GValue* value);
GType vala_scope_get_type (void) G_GNUC_CONST;
GType vala_parameter_get_type (void) G_GNUC_CONST;
GType vala_typeparameter_get_type (void) G_GNUC_CONST;
GType vala_value_type_get_type (void) G_GNUC_CONST;
GType vala_typesymbol_get_type (void) G_GNUC_CONST;
#define VALA_VALUE_TYPE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_VALUE_TYPE, ValaValueTypePrivate))
enum  {
	VALA_VALUE_TYPE_DUMMY_PROPERTY
};
ValaValueType* vala_value_type_construct (GType object_type, ValaTypeSymbol* type_symbol);
ValaDataType* vala_data_type_construct (GType object_type);
void vala_value_type_set_type_symbol (ValaValueType* self, ValaTypeSymbol* value);
void vala_data_type_set_data_type (ValaDataType* self, ValaTypeSymbol* value);
static gboolean vala_value_type_real_is_disposable (ValaDataType* base);
gboolean vala_data_type_get_value_owned (ValaDataType* self);
gboolean vala_data_type_get_nullable (ValaDataType* self);
GType vala_struct_get_type (void) G_GNUC_CONST;
ValaTypeSymbol* vala_value_type_get_type_symbol (ValaValueType* self);
gboolean vala_struct_is_disposable (ValaStruct* self);
static gboolean vala_value_type_real_check (ValaCodeNode* base, ValaCodeContext* context);
gboolean vala_code_node_check (ValaCodeNode* self, ValaCodeContext* context);
static void vala_value_type_finalize (ValaCodeNode* obj);


ValaValueType* vala_value_type_construct (GType object_type, ValaTypeSymbol* type_symbol) {
	ValaValueType* self = NULL;
	ValaTypeSymbol* _tmp0_ = NULL;
	ValaTypeSymbol* _tmp1_ = NULL;
	g_return_val_if_fail (type_symbol != NULL, NULL);
	self = (ValaValueType*) vala_data_type_construct (object_type);
	_tmp0_ = type_symbol;
	vala_value_type_set_type_symbol (self, _tmp0_);
	_tmp1_ = type_symbol;
	vala_data_type_set_data_type ((ValaDataType*) self, _tmp1_);
	return self;
}


static gpointer _vala_code_node_ref0 (gpointer self) {
	return self ? vala_code_node_ref (self) : NULL;
}


static gboolean vala_value_type_real_is_disposable (ValaDataType* base) {
	ValaValueType * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	ValaStruct* st = NULL;
	ValaTypeSymbol* _tmp4_ = NULL;
	ValaStruct* _tmp5_ = NULL;
	ValaStruct* _tmp6_ = NULL;
	self = (ValaValueType*) base;
	_tmp0_ = vala_data_type_get_value_owned ((ValaDataType*) self);
	_tmp1_ = _tmp0_;
	if (!_tmp1_) {
		result = FALSE;
		return result;
	}
	_tmp2_ = vala_data_type_get_nullable ((ValaDataType*) self);
	_tmp3_ = _tmp2_;
	if (_tmp3_) {
		result = TRUE;
		return result;
	}
	_tmp4_ = self->priv->_type_symbol;
	_tmp5_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp4_, VALA_TYPE_STRUCT) ? ((ValaStruct*) _tmp4_) : NULL);
	st = _tmp5_;
	_tmp6_ = st;
	if (_tmp6_ != NULL) {
		ValaStruct* _tmp7_ = NULL;
		gboolean _tmp8_ = FALSE;
		_tmp7_ = st;
		_tmp8_ = vala_struct_is_disposable (_tmp7_);
		result = _tmp8_;
		_vala_code_node_unref0 (st);
		return result;
	}
	result = FALSE;
	_vala_code_node_unref0 (st);
	return result;
}


static gboolean vala_value_type_real_check (ValaCodeNode* base, ValaCodeContext* context) {
	ValaValueType * self;
	gboolean result = FALSE;
	ValaTypeSymbol* _tmp0_ = NULL;
	ValaCodeContext* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	self = (ValaValueType*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = self->priv->_type_symbol;
	_tmp1_ = context;
	_tmp2_ = vala_code_node_check ((ValaCodeNode*) _tmp0_, _tmp1_);
	result = _tmp2_;
	return result;
}


ValaTypeSymbol* vala_value_type_get_type_symbol (ValaValueType* self) {
	ValaTypeSymbol* result;
	ValaTypeSymbol* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_type_symbol;
	result = _tmp0_;
	return result;
}


void vala_value_type_set_type_symbol (ValaValueType* self, ValaTypeSymbol* value) {
	ValaTypeSymbol* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_type_symbol = _tmp0_;
}


static void vala_value_type_class_init (ValaValueTypeClass * klass) {
	vala_value_type_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_value_type_finalize;
	g_type_class_add_private (klass, sizeof (ValaValueTypePrivate));
	((ValaDataTypeClass *) klass)->is_disposable = vala_value_type_real_is_disposable;
	((ValaCodeNodeClass *) klass)->check = vala_value_type_real_check;
}


static void vala_value_type_instance_init (ValaValueType * self) {
	self->priv = VALA_VALUE_TYPE_GET_PRIVATE (self);
}


static void vala_value_type_finalize (ValaCodeNode* obj) {
	ValaValueType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_VALUE_TYPE, ValaValueType);
	VALA_CODE_NODE_CLASS (vala_value_type_parent_class)->finalize (obj);
}


/**
 * A value type, i.e. a struct or an enum type.
 */
GType vala_value_type_get_type (void) {
	static volatile gsize vala_value_type_type_id__volatile = 0;
	if (g_once_init_enter (&vala_value_type_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaValueTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_value_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaValueType), 0, (GInstanceInitFunc) vala_value_type_instance_init, NULL };
		GType vala_value_type_type_id;
		vala_value_type_type_id = g_type_register_static (VALA_TYPE_DATA_TYPE, "ValaValueType", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&vala_value_type_type_id__volatile, vala_value_type_type_id);
	}
	return vala_value_type_type_id__volatile;
}



