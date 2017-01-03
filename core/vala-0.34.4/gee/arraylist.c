/* arraylist.c generated by valac, the Vala compiler
 * generated from arraylist.vala, do not modify */

/* arraylist.vala
 *
 * Copyright (C) 2004-2005  Novell, Inc
 * Copyright (C) 2005  David Waite
 * Copyright (C) 2007-2008  Jürg Billeter
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
#include <string.h>


#define VALA_TYPE_ITERABLE (vala_iterable_get_type ())
#define VALA_ITERABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ITERABLE, ValaIterable))
#define VALA_ITERABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ITERABLE, ValaIterableClass))
#define VALA_IS_ITERABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ITERABLE))
#define VALA_IS_ITERABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ITERABLE))
#define VALA_ITERABLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ITERABLE, ValaIterableClass))

typedef struct _ValaIterable ValaIterable;
typedef struct _ValaIterableClass ValaIterableClass;
typedef struct _ValaIterablePrivate ValaIterablePrivate;

#define VALA_TYPE_ITERATOR (vala_iterator_get_type ())
#define VALA_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ITERATOR, ValaIterator))
#define VALA_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ITERATOR, ValaIteratorClass))
#define VALA_IS_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ITERATOR))
#define VALA_IS_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ITERATOR))
#define VALA_ITERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ITERATOR, ValaIteratorClass))

typedef struct _ValaIterator ValaIterator;
typedef struct _ValaIteratorClass ValaIteratorClass;

#define VALA_TYPE_COLLECTION (vala_collection_get_type ())
#define VALA_COLLECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_COLLECTION, ValaCollection))
#define VALA_COLLECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_COLLECTION, ValaCollectionClass))
#define VALA_IS_COLLECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_COLLECTION))
#define VALA_IS_COLLECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_COLLECTION))
#define VALA_COLLECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_COLLECTION, ValaCollectionClass))

typedef struct _ValaCollection ValaCollection;
typedef struct _ValaCollectionClass ValaCollectionClass;
typedef struct _ValaCollectionPrivate ValaCollectionPrivate;

#define VALA_TYPE_LIST (vala_list_get_type ())
#define VALA_LIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_LIST, ValaList))
#define VALA_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_LIST, ValaListClass))
#define VALA_IS_LIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_LIST))
#define VALA_IS_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_LIST))
#define VALA_LIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_LIST, ValaListClass))

typedef struct _ValaList ValaList;
typedef struct _ValaListClass ValaListClass;
typedef struct _ValaListPrivate ValaListPrivate;

#define VALA_TYPE_ARRAY_LIST (vala_array_list_get_type ())
#define VALA_ARRAY_LIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ARRAY_LIST, ValaArrayList))
#define VALA_ARRAY_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ARRAY_LIST, ValaArrayListClass))
#define VALA_IS_ARRAY_LIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ARRAY_LIST))
#define VALA_IS_ARRAY_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ARRAY_LIST))
#define VALA_ARRAY_LIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ARRAY_LIST, ValaArrayListClass))

typedef struct _ValaArrayList ValaArrayList;
typedef struct _ValaArrayListClass ValaArrayListClass;
typedef struct _ValaArrayListPrivate ValaArrayListPrivate;

#define VALA_ARRAY_LIST_TYPE_ITERATOR (vala_array_list_iterator_get_type ())
#define VALA_ARRAY_LIST_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_ARRAY_LIST_TYPE_ITERATOR, ValaArrayListIterator))
#define VALA_ARRAY_LIST_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_ARRAY_LIST_TYPE_ITERATOR, ValaArrayListIteratorClass))
#define VALA_ARRAY_LIST_IS_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_ARRAY_LIST_TYPE_ITERATOR))
#define VALA_ARRAY_LIST_IS_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_ARRAY_LIST_TYPE_ITERATOR))
#define VALA_ARRAY_LIST_ITERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_ARRAY_LIST_TYPE_ITERATOR, ValaArrayListIteratorClass))

typedef struct _ValaArrayListIterator ValaArrayListIterator;
typedef struct _ValaArrayListIteratorClass ValaArrayListIteratorClass;
typedef struct _ValaIteratorPrivate ValaIteratorPrivate;
typedef struct _ValaArrayListIteratorPrivate ValaArrayListIteratorPrivate;
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _ValaIterable {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaIterablePrivate * priv;
};

struct _ValaIterableClass {
	GTypeClass parent_class;
	void (*finalize) (ValaIterable *self);
	GType (*get_element_type) (ValaIterable* self);
	ValaIterator* (*iterator) (ValaIterable* self);
};

struct _ValaCollection {
	ValaIterable parent_instance;
	ValaCollectionPrivate * priv;
};

struct _ValaCollectionClass {
	ValaIterableClass parent_class;
	gboolean (*contains) (ValaCollection* self, gconstpointer item);
	gboolean (*add) (ValaCollection* self, gconstpointer item);
	gboolean (*remove) (ValaCollection* self, gconstpointer item);
	void (*clear) (ValaCollection* self);
	gint (*get_size) (ValaCollection* self);
};

struct _ValaList {
	ValaCollection parent_instance;
	ValaListPrivate * priv;
};

struct _ValaListClass {
	ValaCollectionClass parent_class;
	gpointer (*get) (ValaList* self, gint index);
	void (*set) (ValaList* self, gint index, gconstpointer item);
	gint (*index_of) (ValaList* self, gconstpointer item);
	void (*insert) (ValaList* self, gint index, gconstpointer item);
	void (*remove_at) (ValaList* self, gint index);
};

struct _ValaArrayList {
	ValaList parent_instance;
	ValaArrayListPrivate * priv;
};

struct _ValaArrayListClass {
	ValaListClass parent_class;
};

struct _ValaArrayListPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	gpointer* _items;
	gint _items_length1;
	gint __items_size_;
	gint _size;
	GEqualFunc _equal_func;
	gint _stamp;
};

struct _ValaIterator {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaIteratorPrivate * priv;
};

struct _ValaIteratorClass {
	GTypeClass parent_class;
	void (*finalize) (ValaIterator *self);
	gboolean (*next) (ValaIterator* self);
	gpointer (*get) (ValaIterator* self);
};

struct _ValaArrayListIterator {
	ValaIterator parent_instance;
	ValaArrayListIteratorPrivate * priv;
	gint _stamp;
};

struct _ValaArrayListIteratorClass {
	ValaIteratorClass parent_class;
};

struct _ValaArrayListIteratorPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	ValaArrayList* _list;
	gint _index;
};


static gpointer vala_array_list_parent_class = NULL;
static gpointer vala_array_list_iterator_parent_class = NULL;

gpointer vala_iterable_ref (gpointer instance);
void vala_iterable_unref (gpointer instance);
GParamSpec* vala_param_spec_iterable (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_iterable (GValue* value, gpointer v_object);
void vala_value_take_iterable (GValue* value, gpointer v_object);
gpointer vala_value_get_iterable (const GValue* value);
GType vala_iterable_get_type (void) G_GNUC_CONST;
gpointer vala_iterator_ref (gpointer instance);
void vala_iterator_unref (gpointer instance);
GParamSpec* vala_param_spec_iterator (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_iterator (GValue* value, gpointer v_object);
void vala_value_take_iterator (GValue* value, gpointer v_object);
gpointer vala_value_get_iterator (const GValue* value);
GType vala_iterator_get_type (void) G_GNUC_CONST;
GType vala_collection_get_type (void) G_GNUC_CONST;
GType vala_list_get_type (void) G_GNUC_CONST;
GType vala_array_list_get_type (void) G_GNUC_CONST;
#define VALA_ARRAY_LIST_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_ARRAY_LIST, ValaArrayListPrivate))
enum  {
	VALA_ARRAY_LIST_DUMMY_PROPERTY
};
ValaArrayList* vala_array_list_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GEqualFunc equal_func);
ValaArrayList* vala_array_list_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GEqualFunc equal_func);
ValaList* vala_list_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func);
void vala_array_list_set_equal_func (ValaArrayList* self, GEqualFunc value);
static GType vala_array_list_real_get_element_type (ValaIterable* base);
static ValaIterator* vala_array_list_real_iterator (ValaIterable* base);
static ValaArrayListIterator* vala_array_list_iterator_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, ValaArrayList* list);
static ValaArrayListIterator* vala_array_list_iterator_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, ValaArrayList* list);
static GType vala_array_list_iterator_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
static gboolean vala_array_list_real_contains (ValaCollection* base, gconstpointer item);
gint vala_list_index_of (ValaList* self, gconstpointer item);
static gint vala_array_list_real_index_of (ValaList* base, gconstpointer item);
static gpointer vala_array_list_real_get (ValaList* base, gint index);
static void vala_array_list_real_set (ValaList* base, gint index, gconstpointer item);
static gboolean vala_array_list_real_add (ValaCollection* base, gconstpointer item);
static void vala_array_list_grow_if_needed (ValaArrayList* self, gint new_count);
static void vala_array_list_real_insert (ValaList* base, gint index, gconstpointer item);
static void vala_array_list_shift (ValaArrayList* self, gint start, gint delta);
static gboolean vala_array_list_real_remove (ValaCollection* base, gconstpointer item);
void vala_list_remove_at (ValaList* self, gint index);
static void vala_array_list_real_remove_at (ValaList* base, gint index);
static void vala_array_list_real_clear (ValaCollection* base);
static void vala_array_list_set_capacity (ValaArrayList* self, gint value);
#define VALA_ARRAY_LIST_ITERATOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_ARRAY_LIST_TYPE_ITERATOR, ValaArrayListIteratorPrivate))
enum  {
	VALA_ARRAY_LIST_ITERATOR_DUMMY_PROPERTY
};
ValaIterator* vala_iterator_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func);
static void vala_array_list_iterator_set_list (ValaArrayListIterator* self, ValaArrayList* value);
static gboolean vala_array_list_iterator_real_next (ValaIterator* base);
static gpointer vala_array_list_iterator_real_get (ValaIterator* base);
gpointer vala_list_get (ValaList* self, gint index);
static void vala_array_list_iterator_finalize (ValaIterator* obj);
static void vala_array_list_finalize (ValaIterable* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_move (gpointer array, gsize element_size, gint src, gint dest, gint length);


ValaArrayList* vala_array_list_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GEqualFunc equal_func) {
	ValaArrayList* self = NULL;
	GEqualFunc _tmp0_ = NULL;
	self = (ValaArrayList*) vala_list_construct (object_type, g_type, (GBoxedCopyFunc) g_dup_func, g_destroy_func);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	_tmp0_ = equal_func;
	vala_array_list_set_equal_func (self, _tmp0_);
	return self;
}


ValaArrayList* vala_array_list_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GEqualFunc equal_func) {
	return vala_array_list_construct (VALA_TYPE_ARRAY_LIST, g_type, g_dup_func, g_destroy_func, equal_func);
}


static GType vala_array_list_real_get_element_type (ValaIterable* base) {
	ValaArrayList * self;
	GType result = 0UL;
	self = (ValaArrayList*) base;
	result = self->priv->g_type;
	return result;
}


static ValaIterator* vala_array_list_real_iterator (ValaIterable* base) {
	ValaArrayList * self;
	ValaIterator* result = NULL;
	ValaArrayListIterator* _tmp0_ = NULL;
	self = (ValaArrayList*) base;
	_tmp0_ = vala_array_list_iterator_new (self->priv->g_type, (GBoxedCopyFunc) self->priv->g_dup_func, self->priv->g_destroy_func, self);
	result = (ValaIterator*) _tmp0_;
	return result;
}


static gboolean vala_array_list_real_contains (ValaCollection* base, gconstpointer item) {
	ValaArrayList * self;
	gboolean result = FALSE;
	gconstpointer _tmp0_ = NULL;
	gint _tmp1_ = 0;
	self = (ValaArrayList*) base;
	_tmp0_ = item;
	_tmp1_ = vala_list_index_of ((ValaList*) self, _tmp0_);
	result = _tmp1_ != -1;
	return result;
}


static gint vala_array_list_real_index_of (ValaList* base, gconstpointer item) {
	ValaArrayList * self;
	gint result = 0;
	self = (ValaArrayList*) base;
	{
		gint index = 0;
		index = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gint _tmp3_ = 0;
				GEqualFunc _tmp4_ = NULL;
				gpointer* _tmp5_ = NULL;
				gint _tmp5__length1 = 0;
				gint _tmp6_ = 0;
				gconstpointer _tmp7_ = NULL;
				gconstpointer _tmp8_ = NULL;
				gboolean _tmp9_ = FALSE;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = index;
					index = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = index;
				_tmp3_ = self->priv->_size;
				if (!(_tmp2_ < _tmp3_)) {
					break;
				}
				_tmp4_ = self->priv->_equal_func;
				_tmp5_ = self->priv->_items;
				_tmp5__length1 = self->priv->_items_length1;
				_tmp6_ = index;
				_tmp7_ = _tmp5_[_tmp6_];
				_tmp8_ = item;
				_tmp9_ = _tmp4_ (_tmp7_, _tmp8_);
				if (_tmp9_) {
					result = index;
					return result;
				}
			}
		}
	}
	result = -1;
	return result;
}


static gpointer vala_array_list_real_get (ValaList* base, gint index) {
	ValaArrayList * self;
	gpointer result = NULL;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_ = 0;
	gpointer* _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	gint _tmp5_ = 0;
	gconstpointer _tmp6_ = NULL;
	gpointer _tmp7_ = NULL;
	self = (ValaArrayList*) base;
	_tmp1_ = index;
	if (_tmp1_ >= 0) {
		gint _tmp2_ = 0;
		gint _tmp3_ = 0;
		_tmp2_ = index;
		_tmp3_ = self->priv->_size;
		_tmp0_ = _tmp2_ < _tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	_vala_assert (_tmp0_, "index >= 0 && index < _size");
	_tmp4_ = self->priv->_items;
	_tmp4__length1 = self->priv->_items_length1;
	_tmp5_ = index;
	_tmp6_ = _tmp4_[_tmp5_];
	_tmp7_ = ((_tmp6_ != NULL) && (self->priv->g_dup_func != NULL)) ? self->priv->g_dup_func ((gpointer) _tmp6_) : ((gpointer) _tmp6_);
	result = _tmp7_;
	return result;
}


static void vala_array_list_real_set (ValaList* base, gint index, gconstpointer item) {
	ValaArrayList * self;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_ = 0;
	gpointer* _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	gint _tmp5_ = 0;
	gconstpointer _tmp6_ = NULL;
	gpointer _tmp7_ = NULL;
	gpointer _tmp8_ = NULL;
	self = (ValaArrayList*) base;
	_tmp1_ = index;
	if (_tmp1_ >= 0) {
		gint _tmp2_ = 0;
		gint _tmp3_ = 0;
		_tmp2_ = index;
		_tmp3_ = self->priv->_size;
		_tmp0_ = _tmp2_ < _tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	_vala_assert (_tmp0_, "index >= 0 && index < _size");
	_tmp4_ = self->priv->_items;
	_tmp4__length1 = self->priv->_items_length1;
	_tmp5_ = index;
	_tmp6_ = item;
	_tmp7_ = ((_tmp6_ != NULL) && (self->priv->g_dup_func != NULL)) ? self->priv->g_dup_func ((gpointer) _tmp6_) : ((gpointer) _tmp6_);
	((_tmp4_[_tmp5_] == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (_tmp4_[_tmp5_] = (self->priv->g_destroy_func (_tmp4_[_tmp5_]), NULL));
	_tmp4_[_tmp5_] = _tmp7_;
	_tmp8_ = _tmp4_[_tmp5_];
}


static gboolean vala_array_list_real_add (ValaCollection* base, gconstpointer item) {
	ValaArrayList * self;
	gboolean result = FALSE;
	gint _tmp0_ = 0;
	gpointer* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	gpointer* _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	gint _tmp3_ = 0;
	gconstpointer _tmp4_ = NULL;
	gpointer _tmp5_ = NULL;
	gpointer _tmp6_ = NULL;
	gint _tmp7_ = 0;
	self = (ValaArrayList*) base;
	_tmp0_ = self->priv->_size;
	_tmp1_ = self->priv->_items;
	_tmp1__length1 = self->priv->_items_length1;
	if (_tmp0_ == _tmp1__length1) {
		vala_array_list_grow_if_needed (self, 1);
	}
	_tmp2_ = self->priv->_items;
	_tmp2__length1 = self->priv->_items_length1;
	_tmp3_ = self->priv->_size;
	self->priv->_size = _tmp3_ + 1;
	_tmp4_ = item;
	_tmp5_ = ((_tmp4_ != NULL) && (self->priv->g_dup_func != NULL)) ? self->priv->g_dup_func ((gpointer) _tmp4_) : ((gpointer) _tmp4_);
	((_tmp2_[_tmp3_] == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (_tmp2_[_tmp3_] = (self->priv->g_destroy_func (_tmp2_[_tmp3_]), NULL));
	_tmp2_[_tmp3_] = _tmp5_;
	_tmp6_ = _tmp2_[_tmp3_];
	_tmp7_ = self->priv->_stamp;
	self->priv->_stamp = _tmp7_ + 1;
	result = TRUE;
	return result;
}


static void vala_array_list_real_insert (ValaList* base, gint index, gconstpointer item) {
	ValaArrayList * self;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_ = 0;
	gint _tmp4_ = 0;
	gpointer* _tmp5_ = NULL;
	gint _tmp5__length1 = 0;
	gint _tmp6_ = 0;
	gpointer* _tmp7_ = NULL;
	gint _tmp7__length1 = 0;
	gint _tmp8_ = 0;
	gconstpointer _tmp9_ = NULL;
	gpointer _tmp10_ = NULL;
	gpointer _tmp11_ = NULL;
	gint _tmp12_ = 0;
	self = (ValaArrayList*) base;
	_tmp1_ = index;
	if (_tmp1_ >= 0) {
		gint _tmp2_ = 0;
		gint _tmp3_ = 0;
		_tmp2_ = index;
		_tmp3_ = self->priv->_size;
		_tmp0_ = _tmp2_ <= _tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	_vala_assert (_tmp0_, "index >= 0 && index <= _size");
	_tmp4_ = self->priv->_size;
	_tmp5_ = self->priv->_items;
	_tmp5__length1 = self->priv->_items_length1;
	if (_tmp4_ == _tmp5__length1) {
		vala_array_list_grow_if_needed (self, 1);
	}
	_tmp6_ = index;
	vala_array_list_shift (self, _tmp6_, 1);
	_tmp7_ = self->priv->_items;
	_tmp7__length1 = self->priv->_items_length1;
	_tmp8_ = index;
	_tmp9_ = item;
	_tmp10_ = ((_tmp9_ != NULL) && (self->priv->g_dup_func != NULL)) ? self->priv->g_dup_func ((gpointer) _tmp9_) : ((gpointer) _tmp9_);
	((_tmp7_[_tmp8_] == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (_tmp7_[_tmp8_] = (self->priv->g_destroy_func (_tmp7_[_tmp8_]), NULL));
	_tmp7_[_tmp8_] = _tmp10_;
	_tmp11_ = _tmp7_[_tmp8_];
	_tmp12_ = self->priv->_stamp;
	self->priv->_stamp = _tmp12_ + 1;
}


static gboolean vala_array_list_real_remove (ValaCollection* base, gconstpointer item) {
	ValaArrayList * self;
	gboolean result = FALSE;
	self = (ValaArrayList*) base;
	{
		gint index = 0;
		index = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gint _tmp3_ = 0;
				GEqualFunc _tmp4_ = NULL;
				gpointer* _tmp5_ = NULL;
				gint _tmp5__length1 = 0;
				gint _tmp6_ = 0;
				gconstpointer _tmp7_ = NULL;
				gconstpointer _tmp8_ = NULL;
				gboolean _tmp9_ = FALSE;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = index;
					index = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = index;
				_tmp3_ = self->priv->_size;
				if (!(_tmp2_ < _tmp3_)) {
					break;
				}
				_tmp4_ = self->priv->_equal_func;
				_tmp5_ = self->priv->_items;
				_tmp5__length1 = self->priv->_items_length1;
				_tmp6_ = index;
				_tmp7_ = _tmp5_[_tmp6_];
				_tmp8_ = item;
				_tmp9_ = _tmp4_ (_tmp7_, _tmp8_);
				if (_tmp9_) {
					gint _tmp10_ = 0;
					_tmp10_ = index;
					vala_list_remove_at ((ValaList*) self, _tmp10_);
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


static void vala_array_list_real_remove_at (ValaList* base, gint index) {
	ValaArrayList * self;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_ = 0;
	gpointer* _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	gint _tmp5_ = 0;
	gpointer _tmp6_ = NULL;
	gint _tmp7_ = 0;
	gint _tmp8_ = 0;
	self = (ValaArrayList*) base;
	_tmp1_ = index;
	if (_tmp1_ >= 0) {
		gint _tmp2_ = 0;
		gint _tmp3_ = 0;
		_tmp2_ = index;
		_tmp3_ = self->priv->_size;
		_tmp0_ = _tmp2_ < _tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	_vala_assert (_tmp0_, "index >= 0 && index < _size");
	_tmp4_ = self->priv->_items;
	_tmp4__length1 = self->priv->_items_length1;
	_tmp5_ = index;
	((_tmp4_[_tmp5_] == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (_tmp4_[_tmp5_] = (self->priv->g_destroy_func (_tmp4_[_tmp5_]), NULL));
	_tmp4_[_tmp5_] = NULL;
	_tmp6_ = _tmp4_[_tmp5_];
	_tmp7_ = index;
	vala_array_list_shift (self, _tmp7_ + 1, -1);
	_tmp8_ = self->priv->_stamp;
	self->priv->_stamp = _tmp8_ + 1;
}


static void vala_array_list_real_clear (ValaCollection* base) {
	ValaArrayList * self;
	gint _tmp7_ = 0;
	self = (ValaArrayList*) base;
	{
		gint index = 0;
		index = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gint _tmp3_ = 0;
				gpointer* _tmp4_ = NULL;
				gint _tmp4__length1 = 0;
				gint _tmp5_ = 0;
				gpointer _tmp6_ = NULL;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = index;
					index = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = index;
				_tmp3_ = self->priv->_size;
				if (!(_tmp2_ < _tmp3_)) {
					break;
				}
				_tmp4_ = self->priv->_items;
				_tmp4__length1 = self->priv->_items_length1;
				_tmp5_ = index;
				((_tmp4_[_tmp5_] == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (_tmp4_[_tmp5_] = (self->priv->g_destroy_func (_tmp4_[_tmp5_]), NULL));
				_tmp4_[_tmp5_] = NULL;
				_tmp6_ = _tmp4_[_tmp5_];
			}
		}
	}
	self->priv->_size = 0;
	_tmp7_ = self->priv->_stamp;
	self->priv->_stamp = _tmp7_ + 1;
}


static void vala_array_list_shift (ValaArrayList* self, gint start, gint delta) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gint _tmp2_ = 0;
	gint _tmp7_ = 0;
	gint _tmp8_ = 0;
	gint _tmp9_ = 0;
	gint _tmp10_ = 0;
	gint _tmp11_ = 0;
	gint _tmp12_ = 0;
	gint _tmp13_ = 0;
	g_return_if_fail (self != NULL);
	_tmp2_ = start;
	if (_tmp2_ >= 0) {
		gint _tmp3_ = 0;
		gint _tmp4_ = 0;
		_tmp3_ = start;
		_tmp4_ = self->priv->_size;
		_tmp1_ = _tmp3_ <= _tmp4_;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		gint _tmp5_ = 0;
		gint _tmp6_ = 0;
		_tmp5_ = start;
		_tmp6_ = delta;
		_tmp0_ = _tmp5_ >= (-_tmp6_);
	} else {
		_tmp0_ = FALSE;
	}
	_vala_assert (_tmp0_, "start >= 0 && start <= _size && start >= -delta");
	_tmp7_ = start;
	_tmp8_ = start;
	_tmp9_ = delta;
	_tmp10_ = self->priv->_size;
	_tmp11_ = start;
	_vala_array_move (self->priv->_items, sizeof (gpointer), _tmp7_, _tmp8_ + _tmp9_, _tmp10_ - _tmp11_);
	_tmp12_ = self->priv->_size;
	_tmp13_ = delta;
	self->priv->_size = _tmp12_ + _tmp13_;
}


static void vala_array_list_grow_if_needed (ValaArrayList* self, gint new_count) {
	gint _tmp0_ = 0;
	gint minimum_size = 0;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gpointer* _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = new_count;
	_vala_assert (_tmp0_ >= 0, "new_count >= 0");
	_tmp1_ = self->priv->_size;
	_tmp2_ = new_count;
	minimum_size = _tmp1_ + _tmp2_;
	_tmp3_ = minimum_size;
	_tmp4_ = self->priv->_items;
	_tmp4__length1 = self->priv->_items_length1;
	if (_tmp3_ > _tmp4__length1) {
		gint _tmp5_ = 0;
		gint _tmp6_ = 0;
		gpointer* _tmp7_ = NULL;
		gint _tmp7__length1 = 0;
		_tmp6_ = new_count;
		_tmp7_ = self->priv->_items;
		_tmp7__length1 = self->priv->_items_length1;
		if (_tmp6_ > _tmp7__length1) {
			gint _tmp8_ = 0;
			_tmp8_ = minimum_size;
			_tmp5_ = _tmp8_;
		} else {
			gpointer* _tmp9_ = NULL;
			gint _tmp9__length1 = 0;
			_tmp9_ = self->priv->_items;
			_tmp9__length1 = self->priv->_items_length1;
			_tmp5_ = 2 * _tmp9__length1;
		}
		vala_array_list_set_capacity (self, _tmp5_);
	}
}


static void vala_array_list_set_capacity (ValaArrayList* self, gint value) {
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = self->priv->_size;
	_vala_assert (_tmp0_ >= _tmp1_, "value >= _size");
	_tmp2_ = value;
	_tmp3_ = _tmp2_;
	self->priv->_items = g_renew (gpointer, self->priv->_items, _tmp2_);
	(_tmp3_ > self->priv->_items_length1) ? memset (self->priv->_items + self->priv->_items_length1, 0, sizeof (gpointer) * (_tmp3_ - self->priv->_items_length1)) : NULL;
	self->priv->_items_length1 = _tmp3_;
	self->priv->__items_size_ = _tmp3_;
}


static gint vala_array_list_real_get_size (ValaCollection* base) {
	gint result;
	ValaArrayList* self;
	gint _tmp0_ = 0;
	self = (ValaArrayList*) base;
	_tmp0_ = self->priv->_size;
	result = _tmp0_;
	return result;
}


void vala_array_list_set_equal_func (ValaArrayList* self, GEqualFunc value) {
	GEqualFunc _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_equal_func = _tmp0_;
}


static ValaArrayListIterator* vala_array_list_iterator_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, ValaArrayList* list) {
	ValaArrayListIterator* self = NULL;
	ValaArrayList* _tmp0_ = NULL;
	g_return_val_if_fail (list != NULL, NULL);
	self = (ValaArrayListIterator*) vala_iterator_construct (object_type, g_type, (GBoxedCopyFunc) g_dup_func, g_destroy_func);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	_tmp0_ = list;
	vala_array_list_iterator_set_list (self, _tmp0_);
	return self;
}


static ValaArrayListIterator* vala_array_list_iterator_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, ValaArrayList* list) {
	return vala_array_list_iterator_construct (VALA_ARRAY_LIST_TYPE_ITERATOR, g_type, g_dup_func, g_destroy_func, list);
}


static gboolean vala_array_list_iterator_real_next (ValaIterator* base) {
	ValaArrayListIterator * self;
	gboolean result = FALSE;
	gint _tmp0_ = 0;
	ValaArrayList* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	ValaArrayList* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	gint _tmp7_ = 0;
	ValaArrayList* _tmp8_ = NULL;
	gint _tmp9_ = 0;
	self = (ValaArrayListIterator*) base;
	_tmp0_ = self->_stamp;
	_tmp1_ = self->priv->_list;
	_tmp2_ = _tmp1_->priv->_stamp;
	_vala_assert (_tmp0_ == _tmp2_, "_stamp == _list._stamp");
	_tmp3_ = self->priv->_index;
	_tmp4_ = self->priv->_list;
	_tmp5_ = _tmp4_->priv->_size;
	if (_tmp3_ < _tmp5_) {
		gint _tmp6_ = 0;
		_tmp6_ = self->priv->_index;
		self->priv->_index = _tmp6_ + 1;
	}
	_tmp7_ = self->priv->_index;
	_tmp8_ = self->priv->_list;
	_tmp9_ = _tmp8_->priv->_size;
	result = _tmp7_ < _tmp9_;
	return result;
}


static gpointer vala_array_list_iterator_real_get (ValaIterator* base) {
	ValaArrayListIterator * self;
	gpointer result = NULL;
	gint _tmp0_ = 0;
	ValaArrayList* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gboolean _tmp3_ = FALSE;
	gint _tmp4_ = 0;
	ValaArrayList* _tmp8_ = NULL;
	gint _tmp9_ = 0;
	gpointer _tmp10_ = NULL;
	self = (ValaArrayListIterator*) base;
	_tmp0_ = self->_stamp;
	_tmp1_ = self->priv->_list;
	_tmp2_ = _tmp1_->priv->_stamp;
	_vala_assert (_tmp0_ == _tmp2_, "_stamp == _list._stamp");
	_tmp4_ = self->priv->_index;
	if (_tmp4_ < 0) {
		_tmp3_ = TRUE;
	} else {
		gint _tmp5_ = 0;
		ValaArrayList* _tmp6_ = NULL;
		gint _tmp7_ = 0;
		_tmp5_ = self->priv->_index;
		_tmp6_ = self->priv->_list;
		_tmp7_ = _tmp6_->priv->_size;
		_tmp3_ = _tmp5_ >= _tmp7_;
	}
	if (_tmp3_) {
		result = NULL;
		return result;
	}
	_tmp8_ = self->priv->_list;
	_tmp9_ = self->priv->_index;
	_tmp10_ = vala_list_get ((ValaList*) _tmp8_, _tmp9_);
	result = _tmp10_;
	return result;
}


static gpointer _vala_iterable_ref0 (gpointer self) {
	return self ? vala_iterable_ref (self) : NULL;
}


static void vala_array_list_iterator_set_list (ValaArrayListIterator* self, ValaArrayList* value) {
	ValaArrayList* _tmp0_ = NULL;
	ValaArrayList* _tmp1_ = NULL;
	ValaArrayList* _tmp2_ = NULL;
	gint _tmp3_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_iterable_ref0 (_tmp0_);
	_vala_iterable_unref0 (self->priv->_list);
	self->priv->_list = _tmp1_;
	_tmp2_ = self->priv->_list;
	_tmp3_ = _tmp2_->priv->_stamp;
	self->_stamp = _tmp3_;
}


static void vala_array_list_iterator_class_init (ValaArrayListIteratorClass * klass) {
	vala_array_list_iterator_parent_class = g_type_class_peek_parent (klass);
	((ValaIteratorClass *) klass)->finalize = vala_array_list_iterator_finalize;
	g_type_class_add_private (klass, sizeof (ValaArrayListIteratorPrivate));
	((ValaIteratorClass *) klass)->next = vala_array_list_iterator_real_next;
	((ValaIteratorClass *) klass)->get = vala_array_list_iterator_real_get;
}


static void vala_array_list_iterator_instance_init (ValaArrayListIterator * self) {
	self->priv = VALA_ARRAY_LIST_ITERATOR_GET_PRIVATE (self);
	self->priv->_index = -1;
	self->_stamp = 0;
}


static void vala_array_list_iterator_finalize (ValaIterator* obj) {
	ValaArrayListIterator * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_ARRAY_LIST_TYPE_ITERATOR, ValaArrayListIterator);
	_vala_iterable_unref0 (self->priv->_list);
	VALA_ITERATOR_CLASS (vala_array_list_iterator_parent_class)->finalize (obj);
}


static GType vala_array_list_iterator_get_type (void) {
	static volatile gsize vala_array_list_iterator_type_id__volatile = 0;
	if (g_once_init_enter (&vala_array_list_iterator_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaArrayListIteratorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_array_list_iterator_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaArrayListIterator), 0, (GInstanceInitFunc) vala_array_list_iterator_instance_init, NULL };
		GType vala_array_list_iterator_type_id;
		vala_array_list_iterator_type_id = g_type_register_static (VALA_TYPE_ITERATOR, "ValaArrayListIterator", &g_define_type_info, 0);
		g_once_init_leave (&vala_array_list_iterator_type_id__volatile, vala_array_list_iterator_type_id);
	}
	return vala_array_list_iterator_type_id__volatile;
}


static void vala_array_list_class_init (ValaArrayListClass * klass) {
	vala_array_list_parent_class = g_type_class_peek_parent (klass);
	((ValaIterableClass *) klass)->finalize = vala_array_list_finalize;
	g_type_class_add_private (klass, sizeof (ValaArrayListPrivate));
	((ValaIterableClass *) klass)->get_element_type = vala_array_list_real_get_element_type;
	((ValaIterableClass *) klass)->iterator = vala_array_list_real_iterator;
	((ValaCollectionClass *) klass)->contains = vala_array_list_real_contains;
	((ValaListClass *) klass)->index_of = vala_array_list_real_index_of;
	((ValaListClass *) klass)->get = vala_array_list_real_get;
	((ValaListClass *) klass)->set = vala_array_list_real_set;
	((ValaCollectionClass *) klass)->add = vala_array_list_real_add;
	((ValaListClass *) klass)->insert = vala_array_list_real_insert;
	((ValaCollectionClass *) klass)->remove = vala_array_list_real_remove;
	((ValaListClass *) klass)->remove_at = vala_array_list_real_remove_at;
	((ValaCollectionClass *) klass)->clear = vala_array_list_real_clear;
	VALA_COLLECTION_CLASS (klass)->get_size = vala_array_list_real_get_size;
}


static void vala_array_list_instance_init (ValaArrayList * self) {
	gpointer* _tmp0_ = NULL;
	self->priv = VALA_ARRAY_LIST_GET_PRIVATE (self);
	_tmp0_ = g_new0 (gpointer, 4);
	self->priv->_items = _tmp0_;
	self->priv->_items_length1 = 4;
	self->priv->__items_size_ = self->priv->_items_length1;
	self->priv->_stamp = 0;
}


static void vala_array_list_finalize (ValaIterable* obj) {
	ValaArrayList * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_ARRAY_LIST, ValaArrayList);
	self->priv->_items = (_vala_array_free (self->priv->_items, self->priv->_items_length1, (GDestroyNotify) self->priv->g_destroy_func), NULL);
	VALA_ITERABLE_CLASS (vala_array_list_parent_class)->finalize (obj);
}


/**
 * Arrays of arbitrary elements which grow automatically as elements are added.
 */
GType vala_array_list_get_type (void) {
	static volatile gsize vala_array_list_type_id__volatile = 0;
	if (g_once_init_enter (&vala_array_list_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaArrayListClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_array_list_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaArrayList), 0, (GInstanceInitFunc) vala_array_list_instance_init, NULL };
		GType vala_array_list_type_id;
		vala_array_list_type_id = g_type_register_static (VALA_TYPE_LIST, "ValaArrayList", &g_define_type_info, 0);
		g_once_init_leave (&vala_array_list_type_id__volatile, vala_array_list_type_id);
	}
	return vala_array_list_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static void _vala_array_move (gpointer array, gsize element_size, gint src, gint dest, gint length) {
	g_memmove (((char*) array) + (dest * element_size), ((char*) array) + (src * element_size), length * element_size);
	if ((src < dest) && ((src + length) > dest)) {
		memset (((char*) array) + (src * element_size), 0, (dest - src) * element_size);
	} else if ((src > dest) && (src < (dest + length))) {
		memset (((char*) array) + ((dest + length) * element_size), 0, (src - dest) * element_size);
	} else if (src != dest) {
		memset (((char*) array) + (src * element_size), 0, length * element_size);
	}
}



