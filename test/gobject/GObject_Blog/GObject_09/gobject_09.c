/* A subclass of GObject implementing a interface. 
   继承 GObject 类，实现接口 interface
   涉及 接口类型的定义和注册，将接口绑定到将要实现接口中函数的类型，判定类型是否包含特定类型的接口并执行接口函数的本地实现
*/

#include <stdio.h>
#include <glib-object.h>

/* My Interface */
typedef struct myinterface myinterface_t;
struct myinterface {
    GTypeInterface something_as_boilerplate;

    void (*greet)(void *instance);
};

GType get_my_interface_typeid() {
    static my_type_id = 0;
    if(my_type_id==0) {
        GTypeInfo my_type_info = {
            sizeof(myinterface_t),  //class_size;

            NULL,               //base_init;
            NULL,               //base_finalize;

            /* classed types, instantiated types */
            NULL,               //class_init;
            NULL,               //class_finalize;
            NULL,               //class_data;

            /* instantiated types */
            0,                  //instance_size;
            0,                  //n_preallocs;
            NULL,               //instance_init;

            /* value handling */
            NULL,               //value_table;
        };

        my_type_id = g_type_register_static(
                G_TYPE_INTERFACE,
                "MyInterface",
                &my_type_info,
                0
                );
    }
    return my_type_id;
}

/* My Class */
typedef struct {
    GObject something_as_boilerplate;
    char* name;
} myinstance_t;

typedef struct {
    GObjectClass something_as_boilerplate;
} myclass_t;

void say_hello(myinstance_t *instance) { // a method of myinstance
    printf("Hello, %s!\n",instance->name);
}

void my_instance_init_func(myinstance_t *instance, gpointer data) {
    instance->name = "blahblah";
}

void my_class_init_func(myclass_t* klass, gpointer data) {
}

void init_my_interface_on_my_class(myinterface_t* iface, gpointer iface_data) {
    iface->greet = say_hello;
}

GType get_my_class_typeid() {
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

        /* Add interface */

        GInterfaceInfo my_interface_info = {
            (GInterfaceInitFunc)init_my_interface_on_my_class, // interface_init
            NULL,   // interface_finalize
            NULL,   // interface_data
        };

        g_type_add_interface_static(
                my_type_id,
                get_my_interface_typeid(),
                &my_interface_info
                );
    }

    return my_type_id;
}


/* main function */

int main() {
    g_type_init();

    printf("Class type id: %d\n",get_my_class_typeid());
    printf("Class type name: %s\n",g_type_name(get_my_class_typeid()));
    printf("Interface type id: %d\n",get_my_interface_typeid());
    printf("Interface type name: %s\n",g_type_name(get_my_interface_typeid()));

    myinstance_t *instance = (myinstance_t*)g_object_new(
            get_my_class_typeid(),NULL);

    GObject *obj = g_object_new(g_object_get_type(),NULL);

    GObject *objs[2] = {instance,obj};

    int i;
    for(i=0;i<2;i++) {
        myinterface_t *iface = G_TYPE_INSTANCE_GET_INTERFACE(
                objs[i],get_my_interface_typeid(),myinterface_t);

        if(iface != NULL) {
            iface->greet(instance);
        } else {
            printf("This object does not implement myinterface.\n");
        }
    }

    return 0;
}
