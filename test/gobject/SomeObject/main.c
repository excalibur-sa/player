#include <stdio.h>
#include <glib-object.h>
#include "SomeObject.h"


/* 让我们来编写一个测试用例吧！ */
int main()
{
	SomeObject *testobj = NULL;

	/* 类型系统初始化 */
	g_type_init ();

	/* 让系统创建实例对象 */
	testobj = SOME_OBJECT (g_type_create_instance (some_object_get_type()));

	/* 调用我们定义了的方法 */
	if (testobj)
	{
		g_print ("%d\n", testobj->m_a);
		some_object_method1 (testobj, 32);
		g_print ("%s\n", testobj->m_b);
		some_object_method2 (testobj, "WTF.");
		g_print ("%f\n", testobj->m_c);
		some_object_method3 (testobj, 6.9);
	}
	
	return 0;
}
