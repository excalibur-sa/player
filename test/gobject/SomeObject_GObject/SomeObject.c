/* 
   本例希望在前一个例子（自己设计基础类）的基础上， 尝试继承 GObject类来实现自己的数据类型，但是程序在编译运行时出现错误
   待解决！
   问题已经解决，继承自 GObject 类失败是由于 some_object_class_final 函数不正确，造成 type 注册失败
   */
#include "SomeObject.h"

#if 0
/* 这些是GObject的构造和析构方法，它们的声明在gobject.h中 */
void some_object_constructor (GType this_type, guint n_properties, GObjectConstructParam *properties)
{
	/* 如果有子类要继承我们的对象，那么this_type将不是SOME_OBJECT_TYPE，
	g_type_peek_parent再是SOME_OBJECT_TYPE的话，将会造成无穷循环 */
	GObjectClass *parent_class = g_type_class_peek (g_type_peek_parent (SOME_OBJECT_TYPE));
	parent_class-> constructor (this_type, n_properties, properties);
	/* 这里很少需要再做其它工作 */
}
void some_object_dispose (GObject *self)
{
	GObjectClass *parent_class = g_type_class_peek (g_type_peek_parent(SOME_OBJECT_TYPE));
	static gboolean first_run = TRUE;
	if (first_run)
	{
		first_run = FALSE;
		/* 对我们持有引用的所有GObject调用g_object_unref，但是不要破坏这个对象 */
		parent_class-> dispose (self);
	}
}
void some_object_finalize (GObject *self)
{
	GObjectClass *parent_class = g_type_class_peek (g_type_peek_parent(SOME_OBJECT_TYPE));
	/* 释放内存和关闭文件 */
	parent_class-> finalize (self);
}
#endif

#if 0
/* 该函数将在类对象创建时被调用 */
void some_object_class_init (gpointer g_class, gpointer class_data)
{
	SomeObjectClass *this_class = SOME_OBJECT_CLASS (g_class);
	/* fill in the class struct members (in this case just a vtable) */
	this_class->method1 = &some_object_method1_impl;
	this_class->method2 = &some_object_method2_impl;
}
#else
/* 这是GObject的Get和Set方法，它们的声明在gobject.h中 */
void some_object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
	SomeObject *self = SOME_OBJECT (object);
	switch (property_id)
	{
		case OBJECT_PROPERTY_A:
		g_value_set_int (value, self->a);		
		break;
		case OBJECT_PROPERTY_B:
		g_value_set_float (value, self->b);
		break;
		default: /* 没有属性用到这个ID！！ */
		break;
	}
}

void some_object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
	SomeObject *self = SOME_OBJECT (object);
	switch (property_id)
	{
		case OBJECT_PROPERTY_A:
		self->a = g_value_get_int (value);
		g_print ("set a = %d\n", self->a);
		break;
		case OBJECT_PROPERTY_B:
		self->b = g_value_get_float (value);
		g_print ("set b = %f\n", self->b);
		break;
		default: /* 没有属性用到这个ID！！ */
		break;
	}
}

/* 这里是我们覆盖函数的地方，因为我们没有定义属性或者任何域，下面都是不需要的 */
void some_object_class_init (SomeObjectClass * g_class, gpointer class_data)
{
	GObjectClass *this_class = (GObjectClass *) (g_class);
	//this_class-> constructor = &some_object_constructor;
	//this_class-> dispose = &some_object_dispose;
	//this_class-> finalize = &some_object_finalize;
	this_class-> set_property = &some_object_set_property;
	this_class-> get_property = &some_object_get_property;
	GParamSpec *spec;
	spec = g_param_spec_int
	(
		"property-a", /* 属性名称 */
		"a", /* 属性昵称 */
		"Mysterty value 1", /* 属性描述 */
		1, /* 属性最小值 */
		100, /* 属性最大值 */
		25, /* 属性默认值 */
		G_PARAM_READABLE |G_PARAM_WRITABLE /* GParamSpecFlags */
	);
	g_object_class_install_property (this_class, OBJECT_PROPERTY_A, spec);
	spec = g_param_spec_float
	(
		"property-b", /* 属性名称 */
		"b", /* 属性昵称 */
		"Mysterty value 2", /* 属性描述 */
		0.0, /* 属性最小值 */
		100.0, /* 属性最大值 */
		3.14, /* 属性默认值 */
		G_PARAM_READABLE |G_PARAM_WRITABLE /* GParamSpecFlags */
	);
	g_object_class_install_property (this_class, OBJECT_PROPERTY_B, spec);
}
#endif

#if 0
/* 该函数在类对象不再被使用时调用 */
void some_object_class_final (SomeObjectClass * g_class, gpointer class_data)
{
/* No class finalization needed since the class object holds no
pointers or references to any dynamic resources which would need
to be released when the class object is no longer in use. */
}
#endif

/* 该函数在实例对象被创建时调用。系统通过g_class实例的类来传递该实例的类。 */
void some_object_instance_init (SomeObject *instance, gpointer g_class)
{
	SomeObject *this_object = SOME_OBJECT (instance);
	/* fill in the instance struct members */
	this_object->a = 25;
	this_object->b = 3.14;
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
			NULL, /* 类对象析构函数 */
			NULL, /* 类数据 */
			sizeof (SomeObject),
			0, /* 预分配的字节数 */
			some_object_instance_init /* 实例对象构造函数 */
		};

#if 0
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
#else
		
		type = g_type_register_static (
			G_TYPE_OBJECT,
        	"SomeObjectType", 
        	&type_info, 
        	0
        );
#endif

	}
	return type;
}