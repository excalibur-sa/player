/* A fundamental type.  Instantiatable. 
   本例创建了一个同时被类实例化和对象实例化的非继承（fundamental）类型，注意 g_type_register_fundamental 函数参数的分析
*/

#include <stdio.h>
#include <glib-object.h>

typedef struct {
    GTypeClass something_as_boilerplate;
} myclass_t;

int a_class_member_of_myclass;

typedef struct {
    GTypeInstance something_as_boilerplate; int an_instance_member;
} myinstance_t;

void my_class_method() {
    printf("The class member is %d\n", a_class_member_of_myclass);
}

void my_instance_method(myinstance_t *instance, int a_parameter) {
    printf("The member is %d\n",instance->an_instance_member);
    printf("The parameter is %d\n",a_parameter);
}

void my_class_init_func(myclass_t* klass, gpointer data) {
    printf("my_class_init_func called!\n");
    a_class_member_of_myclass = 42;
}

void my_instance_init_func(myinstance_t *instance, gpointer data) {
    printf("my_instance_init_func called!\n");
    instance->an_instance_member = 65;
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
        sizeof(myinstance_t),//guint16               instance_size;
        0,                  //guint16                n_preallocs;
        (GInstanceInitFunc)my_instance_init_func, //GInstanceInitFunc      instance_init;

        /* value handling */
        NULL,               //const GTypeValueTable *value_table;
    };

    GTypeFundamentalInfo my_fundamental_info = {
        G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE
    };

    GType my_type_id = g_type_register_fundamental(
            g_type_fundamental_next(),
            "MyInstantiatableFundamentalType",
            &my_type_info,
            &my_fundamental_info,
            0
            );

    printf("%d\n",my_type_id);
    printf("%s\n",g_type_name(my_type_id));

    myinstance_t *instance = (myinstance_t*)g_type_create_instance(my_type_id);
    
    my_instance_method(instance,78);
    my_class_method();

    printf("Is instance of class? %s\n",
            G_TYPE_CHECK_INSTANCE_TYPE(instance, my_type_id)?"yes":"no");
    printf("Is instance of class? %s\n",
            G_TYPE_CHECK_INSTANCE_TYPE(instance, G_TYPE_INT)?"yes":"no");

    return 0;
}
