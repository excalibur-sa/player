#include <glib.h>
#include <glib-object.h>

enum
{
OBJECT_PROPERTY_A = 1 << 1,
OBJECT_PROPERTY_B = 1 << 2,
};

#if 0
/* 我们的“实例结构体”定义了所有的数据域，这使得对象将是唯一的 */
typedef struct _SomeObject SomeObject;
struct _SomeObject
{
	GTypeInstance gtype;
	gint m_a;
	gchar* m_b;
	gfloat m_c;
};

/* 我们的“类结构体”定义了所有的方法函数，这是被实例化出来的对象所共享的 */
typedef struct _SomeObjectClass SomeObjectClass;
struct _SomeObjectClass
{
	GTypeClass gtypeclass;
	void (*method1) (SomeObject *self, gint);
	void (*method2) (SomeObject *self, gchar*);
};
#else
/* 我们的“实例结构体”定义了所有的数据域，这使得对象将是唯一的 */
typedef struct _SomeObject SomeObject;
struct _SomeObject
{
	GObject parent_obj;
	/* 新增加的属性 */
	int a;
	float b;
	/* 下面应该是一些数据 */
};

/* 我们的“类结构体”定义了所有的方法函数，这是被实例化出来的对象所共享的 */
typedef struct _SomeObjectClass SomeObjectClass;
struct _SomeObjectClass
{
	GObjectClass parent_class;
	/* 下面应该是一些方法 */
	void (*method1) (SomeObject *self, gint);
	void (*method2) (SomeObject *self, gchar*);
};
#endif

/* 这个方法将返回我们新声明的对象类型所关联的GType类型 */
GType some_object_get_type (void);

/* 类/实例的初始化/销毁函数。它们的标记在gtype.h中定义。 */
void some_object_class_init (SomeObjectClass *g_class, gpointer class_data);
//void some_object_class_final (SomeObjectClass *g_class, gpointer class_data);
void some_object_instance_init (SomeObject *instance, gpointer g_class);

/* 所有这些函数都是SomeObject的方法. */
void some_object_method1 (SomeObject *self, gint); /* virtual */
void some_object_method2 (SomeObject *self, gchar*); /* virtual */
void some_object_method3 (SomeObject *self, gfloat); /* non-virtual */

/* 好用的宏定义 */
#define SOME_OBJECT_TYPE (some_object_get_type())
#define SOME_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOME_OBJECT_TYPE, SomeObject))
#define SOME_OBJECT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), SOME_OBJECT_TYPE, SomeObjectClass))
#define SOME_IS_OBJECT(obj) (G_TYPE_CHECK_TYPE ((obj), SOME_OBJECT_TYPE))
#define SOME_IS_OBJECT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), SOME_OBJECT_TYPE))
#define SOME_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOME_OBJECT_TYPE, SomeObjectClass))
