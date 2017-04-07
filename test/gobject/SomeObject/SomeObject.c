#include "SomeObject.h"

/* 虚函数的实现 */
void some_object_method1_impl (SomeObject *self, gint a)
{
	self->m_a = a;
	g_print ("Method1: %i\n", self->m_a);
}
void some_object_method2_impl (SomeObject *self, gchar* b)
{
	self->m_b = b;
	g_print ("Method2: %s\n", self->m_b);
}

/* 公有方法 */
void some_object_method1 (SomeObject *self, gint a)
{
	SOME_OBJECT_GET_CLASS (self)->method1 (self, a);
}
void some_object_method2 (SomeObject *self, gchar* b)
{
	SOME_OBJECT_GET_CLASS (self)->method2 (self, b);
}
void some_object_method3 (SomeObject *self, gfloat c)
{
	self->m_c = c;
	g_print ("Method3: %f\n", self->m_c);
}

/* 该函数将在类对象创建时被调用 */
void some_object_class_init (gpointer g_class, gpointer class_data)
{
	SomeObjectClass *this_class = SOME_OBJECT_CLASS (g_class);
	/* fill in the class struct members (in this case just a vtable) */
	this_class->method1 = &some_object_method1_impl;
	this_class->method2 = &some_object_method2_impl;
}

/* 该函数在类对象不再被使用时调用 */
void some_object_class_final (gpointer g_class, gpointer class_data)
{
/* No class finalization needed since the class object holds no
pointers or references to any dynamic resources which would need
to be released when the class object is no longer in use. */
}

/* 该函数在实例对象被创建时调用。系统通过g_class实例的类来传递该实例的类。 */
void some_object_instance_init (GTypeInstance *instance, gpointer g_class)
{
	SomeObject *this_object = SOME_OBJECT (instance);
	/* fill in the instance struct members */
	this_object->m_a = 42;
	this_object->m_b = "Hello";
	this_object->m_c = 3.14;
}

/* 因为该类没有基类，所以基类构造/析构函数是空的 */
GType some_object_get_type (void)
{
	static GType type = 0;
	if (type == 0)
	{
		/* 这是系统用来完整描述类型时如何被创建，构造和析构的结构体。 */
		static const GTypeInfo type_info =
		{
			sizeof (SomeObjectClass),
			NULL, /* 基类构造函数 */
			NULL, /* 基类析构函数 */
			some_object_class_init, /* 类对象构造函数 */
			some_object_class_final, /* 类对象析构函数 */
			NULL, /* 类数据 */
			sizeof (SomeObject),
			0, /* 预分配的字节数 */
			some_object_instance_init /* 实例对象构造函数 */
		};

		/* 因为我们的类没有父类，所以它将被认为是“基础类（fundamental）”，
		所以我们必须要告诉系统，我们的类既是一个复合结构的类（与浮点型，整型，
		或者指针不同），并且时可以被实例化的（系统可以创建实例对象，例如接口
		或者抽象类不能被实例化 */
		static const GTypeFundamentalInfo fundamental_info =
		{
			G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE
		};

		type = g_type_register_fundamental
		(
			g_type_fundamental_next (), /* 下一个可用的GType数 */
			"SomeObjectType", /* 类型的名称 */
			&type_info, /* 上面定义的type_info */
			&fundamental_info, /* 上面定义的fundamental_info */
			0 /* 类型不是抽象的 */
		);
	}
	return type;
}