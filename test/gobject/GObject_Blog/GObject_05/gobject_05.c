/* A fundamental type.  Instantiatable and inheritable. 
   定义了基类和子类两个类型，作为 fundamental 的基类注册的参数需要特殊声明
   子类的 类结构体和实例结构体的定义，get_derived_type 函数中注册函数 g_type_register_static 的使用及参数的说明
   对于基类中抽象方法的覆盖/复写，仅仅是指复写 子类类结构体中拷贝自基类的函数指针，并不会影响基类自身的函数指针
   子类中访问拷贝自基类的数据成员时，将子类实例结构体转换为基类实例结构体的方法
   如何在子类复写基类类结构体中函数指针后，调用该复写函数
*/

#include <stdio.h>
#include <glib-object.h>

/*** base class ***/

// Instance structure
typedef struct {
    GTypeInstance something_as_boilerplate;
    int a_base_instance_member;
} mybaseinstance_t;

// Class structure
typedef struct {
    GTypeClass something_as_boilerplate;
    void (*a_virtual_instance_method)(mybaseinstance_t *instance);
} mybaseclass_t;

// A virtual method (to be installed)
void my_base_method(mybaseinstance_t *instance) {
    printf("This is base.\n");
}

// Class init function
void class_init_func_of_base(mybaseclass_t *klass, gpointer data) {
    klass->a_virtual_instance_method = my_base_method;
}

// Instance init function
void instance_init_func_of_base(mybaseinstance_t *instance, gpointer data) {
    instance->a_base_instance_member = 42;
}

// Type registerer.
GType get_base_type() {
    static GType my_type_id=0;
    if(my_type_id==0) {
        static const GTypeInfo my_type_info = {
            sizeof(mybaseclass_t),  //class_size;

            NULL,   //base_init;
            NULL,   //base_finalize;

            /* classed types, instantiated types */
            (GClassInitFunc)class_init_func_of_base, //class_init;
            NULL,   //class_finalize;
            NULL,   //class_data;

            /* instantiated types */
            sizeof(mybaseinstance_t),//instance_size;
            0,      //n_preallocs;
            (GInstanceInitFunc)instance_init_func_of_base, //instance_init;

            /* value handling */
            NULL,   //value_table;
        };

        static const GTypeFundamentalInfo my_fundamental_info = {
            G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE |
                G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE
        };

        my_type_id = g_type_register_fundamental(
                g_type_fundamental_next(),
                "MyBaseClass",
                &my_type_info,
                &my_fundamental_info,
                0
                );
    }

    return my_type_id;
}

/*** derived class ***/

// Instance structure
typedef struct {
    mybaseinstance_t parent;
    int a_derived_instance_member;
} myderivedinstance_t;

// Class structure
typedef struct {
    mybaseclass_t parent_klass;
} myderivedclass_t;

GType get_derived_type(); // A prototype

// A virtual method (will override base virtual method)
void my_derived_method(mybaseinstance_t* instance) {
    myderivedinstance_t *derived = G_TYPE_CHECK_INSTANCE_CAST(
            instance, get_derived_type(), myderivedinstance_t);
    printf("This is derived.\n");
}

// Class init function
void class_init_func_of_derived(myderivedclass_t *klass, gpointer data) {
    mybaseclass_t *klass_as_base =
        G_TYPE_CHECK_CLASS_CAST(klass,get_base_type(),mybaseclass_t);
    klass_as_base->a_virtual_instance_method = my_derived_method;
}

// Instance init function
void instance_init_func_of_derived(myderivedinstance_t *instance, gpointer data) {
    instance->a_derived_instance_member = 65;
}

// Type registerer.
GType get_derived_type() {
    static GType my_type_id=0;
    if(my_type_id==0) {
        static const GTypeInfo my_type_info = {
            sizeof(myderivedclass_t),  //class_size;

            NULL,   //base_init;
            NULL,   //base_finalize;

            /* classed types, instantiated types */
            (GClassInitFunc)class_init_func_of_derived, //class_init;
            NULL,   //class_finalize;
            NULL,   //class_data;

            /* instantiated types */
            sizeof(myderivedinstance_t),//instance_size;
            0,      //n_preallocs;
            (GInstanceInitFunc)instance_init_func_of_derived, //instance_init;

            /* value handling */
            NULL,   //value_table;
        };

        my_type_id = g_type_register_static(
                get_base_type(),
                "MyDerivedClass",
                &my_type_info,
                0
                );
    }

    return my_type_id;
}

int main() {
    g_type_init();

    printf("Base: %d %s\n",get_base_type(), g_type_name(get_base_type()));
    printf("Derived: %d %s\n",get_derived_type(), g_type_name(get_derived_type()));

    /* Test the base class */
    mybaseinstance_t *binstance =
        (mybaseinstance_t*)g_type_create_instance(get_base_type());

    printf("base instance member: %d\n",binstance->a_base_instance_member);


    /* Test the derived class */
    myderivedinstance_t *dinstance =
        (myderivedinstance_t*)g_type_create_instance(get_derived_type());

    printf("derived instance member: %d\n",dinstance->a_derived_instance_member);

    mybaseinstance_t *derived_as_base =
        G_TYPE_CHECK_INSTANCE_CAST(dinstance, get_base_type(), mybaseinstance_t);
    printf("base member in derived: %d\n",
            derived_as_base->a_base_instance_member);


    /* Test polymorphism */
    mybaseinstance_t *instances[2] = { binstance, derived_as_base };
    int i;

    for(i=0;i<2;i++) {
        mybaseinstance_t *inst = instances[i];
        mybaseclass_t *klass =
            G_TYPE_INSTANCE_GET_CLASS(inst, get_base_type(), mybaseclass_t);
        klass->a_virtual_instance_method(inst);
    }

    return 0;
}
