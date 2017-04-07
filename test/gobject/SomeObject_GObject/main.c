#include <stdio.h>
#include <glib-object.h>
#include "SomeObject.h"


/* 让我们来编写一个测试用例吧！ */
int main()
{
	SomeObject *testobj = NULL;

	/* 类型系统初始化 */
	g_type_init ();

	printf("Type id: %d\n",some_object_get_type());
    printf("Type name: %s\n",g_type_name(some_object_get_type()));

	/* 让系统创建实例对象 */
	testobj = (SomeObject *)g_object_new(some_object_get_type(),NULL);
	//SOME_OBJECT (g_type_create_instance (some_object_get_type()));
	//(SomeObject *)g_type_create_instance (some_object_get_type());

	/* 调用我们定义了的方法 */
	if (testobj)
	{
		g_print ("init a = %d\n", testobj->a);
		g_object_set (testobj, "property-a", 52, NULL);
		g_print ("float b = %f\n", testobj->b);
		g_object_set(testobj, "property-b", 5.2, NULL);
	}
	
	return 0;
}
