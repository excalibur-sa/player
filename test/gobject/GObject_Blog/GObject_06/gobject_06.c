/* A subclass of GObject. 
   本例创建一个继承自 GObject 类的数据类型，注意 类结构体和实例结构体的声明方式，注册函数 g_type_register_static 的使用及参数
   同时 g_object_ref/g_object_unref 函数的使用需要进一步学习，当前释放到 ref_count 为0时仍能访问数据成员，很有可能是野指针，但是检验手段需要规范
*/

#include <stdio.h>
#include <glib-object.h>

typedef struct {
    GObject something_as_boilerplate;
    int an_instance_member;
} myinstance_t;

typedef struct {
    GObjectClass something_as_boilerplate;
} myclass_t;

void my_instance_init_func(myinstance_t *instance, gpointer data) {
    instance->an_instance_member = 42;
}

void my_class_init_func(myclass_t* klass, gpointer data) {
}

GType get_my_typeid() {
    static my_type_id = 0;
    if(my_type_id==0) {
        GTypeInfo my_type_info = {
            sizeof(myclass_t),  //class_size;

            NULL,               //base_init;
            NULL,               //base_finalize;

            /* classed types, instantiated types */
            (GClassInitFunc)my_class_init_func, //class_init;
            NULL,               //class_finalize;
            NULL,               //class_data;

            /* instantiated types */
            sizeof(myinstance_t),//instance_size;
            0,                  //n_preallocs;
            (GInstanceInitFunc)my_instance_init_func, //instance_init;

            /* value handling */
            NULL,               //value_table;
        };

        my_type_id = g_type_register_static(
                G_TYPE_OBJECT,
                "MyClass",
                &my_type_info,
                0
                );
    }
    return my_type_id;
}


void weak_ref_notifying_func(gpointer data, GObject* where_it_was) {
    printf("My object has died.\n");
}

int main() {
    g_type_init();

    printf("Type id: %d\n",get_my_typeid());
    printf("Type name: %s\n",g_type_name(get_my_typeid()));

    myinstance_t *instance = (myinstance_t*)g_object_new(get_my_typeid(),NULL);

    printf("Member: %d\n",instance->an_instance_member);

    printf("Is instance of GObject? %s\n",
            G_TYPE_CHECK_INSTANCE_TYPE(instance, G_TYPE_OBJECT)?"yes":"no");

#if 1
    g_object_weak_ref(
            G_TYPE_CHECK_INSTANCE_CAST(instance,G_TYPE_OBJECT,GObject),
            (GWeakNotify)weak_ref_notifying_func, NULL);
#endif

    printf("Reference Count: %d\n", ((GObject *)instance)->ref_count);
    g_object_ref(instance);
    printf("Member: %d\n",instance->an_instance_member); // 2 refs, valid.

    printf("Reference Count: %d\n", ((GObject *)instance)->ref_count);
    g_object_unref(instance);
    printf("Member: %d\n",instance->an_instance_member); // 1 ref, still valid.

    printf("Reference Count: %d\n", ((GObject *)instance)->ref_count);
    g_object_unref(instance);
    printf("Member: %d\n",instance->an_instance_member); // No longer valid.
    printf("Reference Count: %d\n", ((GObject *)instance)->ref_count);

    return 0;
}
