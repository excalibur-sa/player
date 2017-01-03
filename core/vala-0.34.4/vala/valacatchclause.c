/* valacatchclause.c generated by valac, the Vala compiler
 * generated from valacatchclause.vala, do not modify */

/* valacatchclause.vala
 *
 * Copyright (C) 2007-2010  Jürg Billeter
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

#define VALA_TYPE_CATCH_CLAUSE (vala_catch_clause_get_type ())
#define VALA_CATCH_CLAUSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CATCH_CLAUSE, ValaCatchClause))
#define VALA_CATCH_CLAUSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CATCH_CLAUSE, ValaCatchClauseClass))
#define VALA_IS_CATCH_CLAUSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CATCH_CLAUSE))
#define VALA_IS_CATCH_CLAUSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CATCH_CLAUSE))
#define VALA_CATCH_CLAUSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CATCH_CLAUSE, ValaCatchClauseClass))

typedef struct _ValaCatchClause ValaCatchClause;
typedef struct _ValaCatchClauseClass ValaCatchClauseClass;
typedef struct _ValaCatchClausePrivate ValaCatchClausePrivate;

#define VALA_TYPE_BLOCK (vala_block_get_type ())
#define VALA_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_BLOCK, ValaBlock))
#define VALA_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_BLOCK, ValaBlockClass))
#define VALA_IS_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_BLOCK))
#define VALA_IS_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_BLOCK))
#define VALA_BLOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_BLOCK, ValaBlockClass))

typedef struct _ValaBlock ValaBlock;
typedef struct _ValaBlockClass ValaBlockClass;

#define VALA_TYPE_LOCAL_VARIABLE (vala_local_variable_get_type ())
#define VALA_LOCAL_VARIABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_LOCAL_VARIABLE, ValaLocalVariable))
#define VALA_LOCAL_VARIABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_LOCAL_VARIABLE, ValaLocalVariableClass))
#define VALA_IS_LOCAL_VARIABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_LOCAL_VARIABLE))
#define VALA_IS_LOCAL_VARIABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_LOCAL_VARIABLE))
#define VALA_LOCAL_VARIABLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_LOCAL_VARIABLE, ValaLocalVariableClass))

typedef struct _ValaLocalVariable ValaLocalVariable;
typedef struct _ValaLocalVariableClass ValaLocalVariableClass;
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

#define VALA_TYPE_REFERENCE_TYPE (vala_reference_type_get_type ())
#define VALA_REFERENCE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_REFERENCE_TYPE, ValaReferenceType))
#define VALA_REFERENCE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_REFERENCE_TYPE, ValaReferenceTypeClass))
#define VALA_IS_REFERENCE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_REFERENCE_TYPE))
#define VALA_IS_REFERENCE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_REFERENCE_TYPE))
#define VALA_REFERENCE_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_REFERENCE_TYPE, ValaReferenceTypeClass))

typedef struct _ValaReferenceType ValaReferenceType;
typedef struct _ValaReferenceTypeClass ValaReferenceTypeClass;

#define VALA_TYPE_ERROR_TYPE (vala_error_type_get_type ())
#define VALA_ERROR_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ERROR_TYPE, ValaErrorType))
#define VALA_ERROR_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ERROR_TYPE, ValaErrorTypeClass))
#define VALA_IS_ERROR_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ERROR_TYPE))
#define VALA_IS_ERROR_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ERROR_TYPE))
#define VALA_ERROR_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ERROR_TYPE, ValaErrorTypeClass))

typedef struct _ValaErrorType ValaErrorType;
typedef struct _ValaErrorTypeClass ValaErrorTypeClass;

#define VALA_TYPE_SCOPE (vala_scope_get_type ())
#define VALA_SCOPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SCOPE, ValaScope))
#define VALA_SCOPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SCOPE, ValaScopeClass))
#define VALA_IS_SCOPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SCOPE))
#define VALA_IS_SCOPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SCOPE))
#define VALA_SCOPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SCOPE, ValaScopeClass))

typedef struct _ValaScope ValaScope;
typedef struct _ValaScopeClass ValaScopeClass;

#define VALA_TYPE_TYPESYMBOL (vala_typesymbol_get_type ())
#define VALA_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbol))
#define VALA_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))
#define VALA_IS_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_TYPESYMBOL))
#define VALA_IS_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_TYPESYMBOL))
#define VALA_TYPESYMBOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))

typedef struct _ValaTypeSymbol ValaTypeSymbol;
typedef struct _ValaTypeSymbolClass ValaTypeSymbolClass;

#define VALA_TYPE_ERROR_DOMAIN (vala_error_domain_get_type ())
#define VALA_ERROR_DOMAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ERROR_DOMAIN, ValaErrorDomain))
#define VALA_ERROR_DOMAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ERROR_DOMAIN, ValaErrorDomainClass))
#define VALA_IS_ERROR_DOMAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ERROR_DOMAIN))
#define VALA_IS_ERROR_DOMAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ERROR_DOMAIN))
#define VALA_ERROR_DOMAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ERROR_DOMAIN, ValaErrorDomainClass))

typedef struct _ValaErrorDomain ValaErrorDomain;
typedef struct _ValaErrorDomainClass ValaErrorDomainClass;

#define VALA_TYPE_ERROR_CODE (vala_error_code_get_type ())
#define VALA_ERROR_CODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ERROR_CODE, ValaErrorCode))
#define VALA_ERROR_CODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ERROR_CODE, ValaErrorCodeClass))
#define VALA_IS_ERROR_CODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ERROR_CODE))
#define VALA_IS_ERROR_CODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ERROR_CODE))
#define VALA_ERROR_CODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ERROR_CODE, ValaErrorCodeClass))

typedef struct _ValaErrorCode ValaErrorCode;
typedef struct _ValaErrorCodeClass ValaErrorCodeClass;

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

struct _ValaCatchClause {
	ValaCodeNode parent_instance;
	ValaCatchClausePrivate * priv;
};

struct _ValaCatchClauseClass {
	ValaCodeNodeClass parent_class;
};

struct _ValaCatchClausePrivate {
	gchar* _variable_name;
	gchar* _clabel_name;
	ValaDataType* _data_type;
	ValaBlock* _body;
	ValaLocalVariable* _error_variable;
};


static gpointer vala_catch_clause_parent_class = NULL;

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
GType vala_catch_clause_get_type (void) G_GNUC_CONST;
GType vala_block_get_type (void) G_GNUC_CONST;
GType vala_local_variable_get_type (void) G_GNUC_CONST;
#define VALA_CATCH_CLAUSE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_CATCH_CLAUSE, ValaCatchClausePrivate))
enum  {
	VALA_CATCH_CLAUSE_DUMMY_PROPERTY
};
gpointer vala_source_reference_ref (gpointer instance);
void vala_source_reference_unref (gpointer instance);
GParamSpec* vala_param_spec_source_reference (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_source_reference (GValue* value, gpointer v_object);
void vala_value_take_source_reference (GValue* value, gpointer v_object);
gpointer vala_value_get_source_reference (const GValue* value);
GType vala_source_reference_get_type (void) G_GNUC_CONST;
ValaCatchClause* vala_catch_clause_new (ValaDataType* error_type, const gchar* variable_name, ValaBlock* body, ValaSourceReference* source_reference);
ValaCatchClause* vala_catch_clause_construct (GType object_type, ValaDataType* error_type, const gchar* variable_name, ValaBlock* body, ValaSourceReference* source_reference);
ValaCodeNode* vala_code_node_construct (GType object_type);
void vala_catch_clause_set_error_type (ValaCatchClause* self, ValaDataType* value);
void vala_catch_clause_set_variable_name (ValaCatchClause* self, const gchar* value);
void vala_catch_clause_set_body (ValaCatchClause* self, ValaBlock* value);
void vala_code_node_set_source_reference (ValaCodeNode* self, ValaSourceReference* value);
static void vala_catch_clause_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor);
void vala_code_visitor_visit_catch_clause (ValaCodeVisitor* self, ValaCatchClause* clause);
static void vala_catch_clause_real_accept_children (ValaCodeNode* base, ValaCodeVisitor* visitor);
ValaDataType* vala_catch_clause_get_error_type (ValaCatchClause* self);
void vala_code_node_accept (ValaCodeNode* self, ValaCodeVisitor* visitor);
ValaBlock* vala_catch_clause_get_body (ValaCatchClause* self);
static void vala_catch_clause_real_replace_type (ValaCodeNode* base, ValaDataType* old_type, ValaDataType* new_type);
static gboolean vala_catch_clause_real_check (ValaCodeNode* base, ValaCodeContext* context);
gboolean vala_code_node_get_checked (ValaCodeNode* self);
gboolean vala_code_node_get_error (ValaCodeNode* self);
void vala_code_node_set_checked (ValaCodeNode* self, gboolean value);
GType vala_reference_type_get_type (void) G_GNUC_CONST;
GType vala_error_type_get_type (void) G_GNUC_CONST;
void vala_report_error (ValaSourceReference* source, const gchar* message);
ValaSourceReference* vala_code_node_get_source_reference (ValaCodeNode* self);
gchar* vala_code_node_to_string (ValaCodeNode* self);
void vala_code_node_set_error (ValaCodeNode* self, gboolean value);
const gchar* vala_catch_clause_get_variable_name (ValaCatchClause* self);
ValaDataType* vala_data_type_copy (ValaDataType* self);
ValaLocalVariable* vala_local_variable_new (ValaDataType* variable_type, const gchar* name, ValaExpression* initializer, ValaSourceReference* source_reference);
ValaLocalVariable* vala_local_variable_construct (GType object_type, ValaDataType* variable_type, const gchar* name, ValaExpression* initializer, ValaSourceReference* source_reference);
void vala_catch_clause_set_error_variable (ValaCatchClause* self, ValaLocalVariable* value);
gpointer vala_scope_ref (gpointer instance);
void vala_scope_unref (gpointer instance);
GParamSpec* vala_param_spec_scope (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_scope (GValue* value, gpointer v_object);
void vala_value_take_scope (GValue* value, gpointer v_object);
gpointer vala_value_get_scope (const GValue* value);
GType vala_scope_get_type (void) G_GNUC_CONST;
ValaScope* vala_symbol_get_scope (ValaSymbol* self);
void vala_scope_add (ValaScope* self, const gchar* name, ValaSymbol* sym);
ValaLocalVariable* vala_catch_clause_get_error_variable (ValaCatchClause* self);
void vala_block_add_local_variable (ValaBlock* self, ValaLocalVariable* local);
GType vala_typesymbol_get_type (void) G_GNUC_CONST;
GType vala_error_domain_get_type (void) G_GNUC_CONST;
GType vala_error_code_get_type (void) G_GNUC_CONST;
ValaErrorType* vala_error_type_new (ValaErrorDomain* error_domain, ValaErrorCode* error_code, ValaSourceReference* source_reference);
ValaErrorType* vala_error_type_construct (GType object_type, ValaErrorDomain* error_domain, ValaErrorCode* error_code, ValaSourceReference* source_reference);
gboolean vala_code_node_check (ValaCodeNode* self, ValaCodeContext* context);
static void vala_catch_clause_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen);
void vala_symbol_set_active (ValaSymbol* self, gboolean value);
static void vala_catch_clause_real_get_defined_variables (ValaCodeNode* base, ValaCollection* collection);
void vala_code_node_set_parent_node (ValaCodeNode* self, ValaCodeNode* value);
const gchar* vala_catch_clause_get_clabel_name (ValaCatchClause* self);
void vala_catch_clause_set_clabel_name (ValaCatchClause* self, const gchar* value);
static void vala_catch_clause_finalize (ValaCodeNode* obj);


/**
 * Creates a new catch
 *
 * @param error_type       error type
 * @param variable_name    error variable name
 * @param body             error handler body
 * @param source_reference reference to source code
 * @return                 newly created catch clause
 */
ValaCatchClause* vala_catch_clause_construct (GType object_type, ValaDataType* error_type, const gchar* variable_name, ValaBlock* body, ValaSourceReference* source_reference) {
	ValaCatchClause* self = NULL;
	ValaDataType* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	ValaBlock* _tmp2_ = NULL;
	ValaSourceReference* _tmp3_ = NULL;
	g_return_val_if_fail (body != NULL, NULL);
	self = (ValaCatchClause*) vala_code_node_construct (object_type);
	_tmp0_ = error_type;
	vala_catch_clause_set_error_type (self, _tmp0_);
	_tmp1_ = variable_name;
	vala_catch_clause_set_variable_name (self, _tmp1_);
	_tmp2_ = body;
	vala_catch_clause_set_body (self, _tmp2_);
	_tmp3_ = source_reference;
	vala_code_node_set_source_reference ((ValaCodeNode*) self, _tmp3_);
	return self;
}


ValaCatchClause* vala_catch_clause_new (ValaDataType* error_type, const gchar* variable_name, ValaBlock* body, ValaSourceReference* source_reference) {
	return vala_catch_clause_construct (VALA_TYPE_CATCH_CLAUSE, error_type, variable_name, body, source_reference);
}


static void vala_catch_clause_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor) {
	ValaCatchClause * self;
	ValaCodeVisitor* _tmp0_ = NULL;
	self = (ValaCatchClause*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = visitor;
	vala_code_visitor_visit_catch_clause (_tmp0_, self);
}


static void vala_catch_clause_real_accept_children (ValaCodeNode* base, ValaCodeVisitor* visitor) {
	ValaCatchClause * self;
	ValaDataType* _tmp0_ = NULL;
	ValaDataType* _tmp1_ = NULL;
	ValaBlock* _tmp5_ = NULL;
	ValaBlock* _tmp6_ = NULL;
	ValaCodeVisitor* _tmp7_ = NULL;
	self = (ValaCatchClause*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_catch_clause_get_error_type (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValaDataType* _tmp2_ = NULL;
		ValaDataType* _tmp3_ = NULL;
		ValaCodeVisitor* _tmp4_ = NULL;
		_tmp2_ = vala_catch_clause_get_error_type (self);
		_tmp3_ = _tmp2_;
		_tmp4_ = visitor;
		vala_code_node_accept ((ValaCodeNode*) _tmp3_, _tmp4_);
	}
	_tmp5_ = vala_catch_clause_get_body (self);
	_tmp6_ = _tmp5_;
	_tmp7_ = visitor;
	vala_code_node_accept ((ValaCodeNode*) _tmp6_, _tmp7_);
}


static void vala_catch_clause_real_replace_type (ValaCodeNode* base, ValaDataType* old_type, ValaDataType* new_type) {
	ValaCatchClause * self;
	ValaDataType* _tmp0_ = NULL;
	ValaDataType* _tmp1_ = NULL;
	ValaDataType* _tmp2_ = NULL;
	self = (ValaCatchClause*) base;
	g_return_if_fail (old_type != NULL);
	g_return_if_fail (new_type != NULL);
	_tmp0_ = vala_catch_clause_get_error_type (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = old_type;
	if (_tmp1_ == _tmp2_) {
		ValaDataType* _tmp3_ = NULL;
		_tmp3_ = new_type;
		vala_catch_clause_set_error_type (self, _tmp3_);
	}
}


static gboolean vala_catch_clause_real_check (ValaCodeNode* base, ValaCodeContext* context) {
	ValaCatchClause * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	ValaDataType* _tmp4_ = NULL;
	ValaDataType* _tmp5_ = NULL;
	ValaDataType* _tmp41_ = NULL;
	ValaDataType* _tmp42_ = NULL;
	ValaCodeContext* _tmp43_ = NULL;
	ValaBlock* _tmp44_ = NULL;
	ValaBlock* _tmp45_ = NULL;
	ValaCodeContext* _tmp46_ = NULL;
	gboolean _tmp47_ = FALSE;
	gboolean _tmp48_ = FALSE;
	self = (ValaCatchClause*) base;
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
	_tmp4_ = vala_catch_clause_get_error_type (self);
	_tmp5_ = _tmp4_;
	if (_tmp5_ != NULL) {
		ValaDataType* _tmp6_ = NULL;
		ValaDataType* _tmp7_ = NULL;
		const gchar* _tmp16_ = NULL;
		_tmp6_ = vala_catch_clause_get_error_type (self);
		_tmp7_ = _tmp6_;
		if (!G_TYPE_CHECK_INSTANCE_TYPE (_tmp7_, VALA_TYPE_ERROR_TYPE)) {
			ValaSourceReference* _tmp8_ = NULL;
			ValaSourceReference* _tmp9_ = NULL;
			ValaDataType* _tmp10_ = NULL;
			ValaDataType* _tmp11_ = NULL;
			gchar* _tmp12_ = NULL;
			gchar* _tmp13_ = NULL;
			gchar* _tmp14_ = NULL;
			gchar* _tmp15_ = NULL;
			_tmp8_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp9_ = _tmp8_;
			_tmp10_ = vala_catch_clause_get_error_type (self);
			_tmp11_ = _tmp10_;
			_tmp12_ = vala_code_node_to_string ((ValaCodeNode*) _tmp11_);
			_tmp13_ = _tmp12_;
			_tmp14_ = g_strdup_printf ("clause must catch a valid error type, found `%s' instead", _tmp13_);
			_tmp15_ = _tmp14_;
			vala_report_error (_tmp9_, _tmp15_);
			_g_free0 (_tmp15_);
			_g_free0 (_tmp13_);
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		}
		_tmp16_ = self->priv->_variable_name;
		if (_tmp16_ != NULL) {
			ValaDataType* _tmp17_ = NULL;
			ValaDataType* _tmp18_ = NULL;
			ValaDataType* _tmp19_ = NULL;
			ValaDataType* _tmp20_ = NULL;
			const gchar* _tmp21_ = NULL;
			ValaLocalVariable* _tmp22_ = NULL;
			ValaLocalVariable* _tmp23_ = NULL;
			ValaBlock* _tmp24_ = NULL;
			ValaBlock* _tmp25_ = NULL;
			ValaScope* _tmp26_ = NULL;
			ValaScope* _tmp27_ = NULL;
			const gchar* _tmp28_ = NULL;
			ValaLocalVariable* _tmp29_ = NULL;
			ValaLocalVariable* _tmp30_ = NULL;
			ValaBlock* _tmp31_ = NULL;
			ValaBlock* _tmp32_ = NULL;
			ValaLocalVariable* _tmp33_ = NULL;
			ValaLocalVariable* _tmp34_ = NULL;
			ValaLocalVariable* _tmp35_ = NULL;
			ValaLocalVariable* _tmp36_ = NULL;
			_tmp17_ = vala_catch_clause_get_error_type (self);
			_tmp18_ = _tmp17_;
			_tmp19_ = vala_data_type_copy (_tmp18_);
			_tmp20_ = _tmp19_;
			_tmp21_ = self->priv->_variable_name;
			_tmp22_ = vala_local_variable_new (_tmp20_, _tmp21_, NULL, NULL);
			_tmp23_ = _tmp22_;
			vala_catch_clause_set_error_variable (self, _tmp23_);
			_vala_code_node_unref0 (_tmp23_);
			_vala_code_node_unref0 (_tmp20_);
			_tmp24_ = vala_catch_clause_get_body (self);
			_tmp25_ = _tmp24_;
			_tmp26_ = vala_symbol_get_scope ((ValaSymbol*) _tmp25_);
			_tmp27_ = _tmp26_;
			_tmp28_ = self->priv->_variable_name;
			_tmp29_ = vala_catch_clause_get_error_variable (self);
			_tmp30_ = _tmp29_;
			vala_scope_add (_tmp27_, _tmp28_, (ValaSymbol*) _tmp30_);
			_tmp31_ = vala_catch_clause_get_body (self);
			_tmp32_ = _tmp31_;
			_tmp33_ = vala_catch_clause_get_error_variable (self);
			_tmp34_ = _tmp33_;
			vala_block_add_local_variable (_tmp32_, _tmp34_);
			_tmp35_ = vala_catch_clause_get_error_variable (self);
			_tmp36_ = _tmp35_;
			vala_code_node_set_checked ((ValaCodeNode*) _tmp36_, TRUE);
		}
	} else {
		ValaSourceReference* _tmp37_ = NULL;
		ValaSourceReference* _tmp38_ = NULL;
		ValaErrorType* _tmp39_ = NULL;
		ValaErrorType* _tmp40_ = NULL;
		_tmp37_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp38_ = _tmp37_;
		_tmp39_ = vala_error_type_new (NULL, NULL, _tmp38_);
		_tmp40_ = _tmp39_;
		vala_catch_clause_set_error_type (self, (ValaDataType*) _tmp40_);
		_vala_code_node_unref0 (_tmp40_);
	}
	_tmp41_ = vala_catch_clause_get_error_type (self);
	_tmp42_ = _tmp41_;
	_tmp43_ = context;
	vala_code_node_check ((ValaCodeNode*) _tmp42_, _tmp43_);
	_tmp44_ = vala_catch_clause_get_body (self);
	_tmp45_ = _tmp44_;
	_tmp46_ = context;
	vala_code_node_check ((ValaCodeNode*) _tmp45_, _tmp46_);
	_tmp47_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp48_ = _tmp47_;
	result = !_tmp48_;
	return result;
}


static void vala_catch_clause_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen) {
	ValaCatchClause * self;
	ValaLocalVariable* _tmp0_ = NULL;
	ValaLocalVariable* _tmp1_ = NULL;
	ValaCodeGenerator* _tmp4_ = NULL;
	self = (ValaCatchClause*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_catch_clause_get_error_variable (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValaLocalVariable* _tmp2_ = NULL;
		ValaLocalVariable* _tmp3_ = NULL;
		_tmp2_ = vala_catch_clause_get_error_variable (self);
		_tmp3_ = _tmp2_;
		vala_symbol_set_active ((ValaSymbol*) _tmp3_, TRUE);
	}
	_tmp4_ = codegen;
	vala_code_visitor_visit_catch_clause ((ValaCodeVisitor*) _tmp4_, self);
}


static void vala_catch_clause_real_get_defined_variables (ValaCodeNode* base, ValaCollection* collection) {
	ValaCatchClause * self;
	ValaLocalVariable* _tmp0_ = NULL;
	ValaLocalVariable* _tmp1_ = NULL;
	self = (ValaCatchClause*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_catch_clause_get_error_variable (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValaCollection* _tmp2_ = NULL;
		ValaLocalVariable* _tmp3_ = NULL;
		ValaLocalVariable* _tmp4_ = NULL;
		_tmp2_ = collection;
		_tmp3_ = vala_catch_clause_get_error_variable (self);
		_tmp4_ = _tmp3_;
		vala_collection_add (_tmp2_, (ValaVariable*) _tmp4_);
	}
}


ValaDataType* vala_catch_clause_get_error_type (ValaCatchClause* self) {
	ValaDataType* result;
	ValaDataType* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data_type;
	result = _tmp0_;
	return result;
}


static gpointer _vala_code_node_ref0 (gpointer self) {
	return self ? vala_code_node_ref (self) : NULL;
}


void vala_catch_clause_set_error_type (ValaCatchClause* self, ValaDataType* value) {
	ValaDataType* _tmp0_ = NULL;
	ValaDataType* _tmp1_ = NULL;
	ValaDataType* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_data_type);
	self->priv->_data_type = _tmp1_;
	_tmp2_ = self->priv->_data_type;
	if (_tmp2_ != NULL) {
		ValaDataType* _tmp3_ = NULL;
		_tmp3_ = self->priv->_data_type;
		vala_code_node_set_parent_node ((ValaCodeNode*) _tmp3_, (ValaCodeNode*) self);
	}
}


const gchar* vala_catch_clause_get_variable_name (ValaCatchClause* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_variable_name;
	result = _tmp0_;
	return result;
}


void vala_catch_clause_set_variable_name (ValaCatchClause* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_variable_name);
	self->priv->_variable_name = _tmp1_;
}


ValaBlock* vala_catch_clause_get_body (ValaCatchClause* self) {
	ValaBlock* result;
	ValaBlock* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_body;
	result = _tmp0_;
	return result;
}


void vala_catch_clause_set_body (ValaCatchClause* self, ValaBlock* value) {
	ValaBlock* _tmp0_ = NULL;
	ValaBlock* _tmp1_ = NULL;
	ValaBlock* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_body);
	self->priv->_body = _tmp1_;
	_tmp2_ = self->priv->_body;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
}


ValaLocalVariable* vala_catch_clause_get_error_variable (ValaCatchClause* self) {
	ValaLocalVariable* result;
	ValaLocalVariable* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_error_variable;
	result = _tmp0_;
	return result;
}


void vala_catch_clause_set_error_variable (ValaCatchClause* self, ValaLocalVariable* value) {
	ValaLocalVariable* _tmp0_ = NULL;
	ValaLocalVariable* _tmp1_ = NULL;
	ValaLocalVariable* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_error_variable);
	self->priv->_error_variable = _tmp1_;
	_tmp2_ = self->priv->_error_variable;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
}


const gchar* vala_catch_clause_get_clabel_name (ValaCatchClause* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_clabel_name;
	result = _tmp0_;
	return result;
}


void vala_catch_clause_set_clabel_name (ValaCatchClause* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_clabel_name);
	self->priv->_clabel_name = _tmp1_;
}


static void vala_catch_clause_class_init (ValaCatchClauseClass * klass) {
	vala_catch_clause_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_catch_clause_finalize;
	g_type_class_add_private (klass, sizeof (ValaCatchClausePrivate));
	((ValaCodeNodeClass *) klass)->accept = vala_catch_clause_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = vala_catch_clause_real_accept_children;
	((ValaCodeNodeClass *) klass)->replace_type = vala_catch_clause_real_replace_type;
	((ValaCodeNodeClass *) klass)->check = vala_catch_clause_real_check;
	((ValaCodeNodeClass *) klass)->emit = vala_catch_clause_real_emit;
	((ValaCodeNodeClass *) klass)->get_defined_variables = vala_catch_clause_real_get_defined_variables;
}


static void vala_catch_clause_instance_init (ValaCatchClause * self) {
	self->priv = VALA_CATCH_CLAUSE_GET_PRIVATE (self);
}


static void vala_catch_clause_finalize (ValaCodeNode* obj) {
	ValaCatchClause * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CATCH_CLAUSE, ValaCatchClause);
	_g_free0 (self->priv->_variable_name);
	_g_free0 (self->priv->_clabel_name);
	_vala_code_node_unref0 (self->priv->_data_type);
	_vala_code_node_unref0 (self->priv->_body);
	_vala_code_node_unref0 (self->priv->_error_variable);
	VALA_CODE_NODE_CLASS (vala_catch_clause_parent_class)->finalize (obj);
}


/**
 * Represents a catch clause in a try statement in the source code.
 */
GType vala_catch_clause_get_type (void) {
	static volatile gsize vala_catch_clause_type_id__volatile = 0;
	if (g_once_init_enter (&vala_catch_clause_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaCatchClauseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_catch_clause_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCatchClause), 0, (GInstanceInitFunc) vala_catch_clause_instance_init, NULL };
		GType vala_catch_clause_type_id;
		vala_catch_clause_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaCatchClause", &g_define_type_info, 0);
		g_once_init_leave (&vala_catch_clause_type_id__volatile, vala_catch_clause_type_id);
	}
	return vala_catch_clause_type_id__volatile;
}



