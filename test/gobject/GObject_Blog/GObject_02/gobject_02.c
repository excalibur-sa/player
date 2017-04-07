/* A fundamental type.  It has a class structure, but is not instantiable. 
   本例创建了一个仅仅具有 类实例，而没有 对象实例的数据类型，给出数据类型在使用 g_type_register_fundamental 函数注册的参数说明
   这种类型不具有普遍的使用性，且将数据和函数都放在 类结构体中的设置不符合类型系统的设计，仅仅供学习使用。
*/

#include <stdio.h>
#include <glib-object.h>

typedef struct {
    GTypeClass something_as_boilerplate;
    int foo;
    char* bar;
    void (*baz)();
} myclass_t;

void baz_function() { printf("All your type are belong to us!\n"); }

void my_class_init_func(myclass_t* klass, gpointer data) {
    printf("my_class_init_func called!\n");
    klass->foo = 42;
    klass->bar = "Hello world!";
    klass->baz = baz_function;
}

int main() {
    g_type_init();

    GTypeInfo my_type_info = {
        sizeof(myclass_t),  //guint16                class_size;

        NULL,               //GBaseInitFunc          base_init;
        NULL,               //GBaseFinalizeFunc      base_finalize;

        /* classed types, instantiated types */
        (GClassInitFunc)my_class_init_func, //GClassInitFunc         class_init;
        NULL,               //GClassFinalizeFunc     class_finalize;
        NULL,               //gconstpointer          class_data;

        /* instantiated types */
        0,                  //guint16                instance_size;
        0,                  //guint16                n_preallocs;
        NULL,               //GInstanceInitFunc      instance_init;

        /* value handling */
        NULL,               //const GTypeValueTable *value_table;
    };

    GTypeFundamentalInfo my_fundamental_info = {
        G_TYPE_FLAG_CLASSED
    };

    GType my_type_id = g_type_register_fundamental(
            g_type_fundamental_next(),
            "MyClassedFundamentalType",
            &my_type_info,
            &my_fundamental_info,
            0
            );

    printf("%d\n",my_type_id);
    printf("%s\n",g_type_name(my_type_id));

    myclass_t *klass = (myclass_t*)g_type_class_ref(my_type_id);
    
    printf("foo: %d\n", klass->foo);
    printf("bar: %s\n", klass->bar);
    klass->baz();

    g_type_class_unref(klass);

    return 0;
}
