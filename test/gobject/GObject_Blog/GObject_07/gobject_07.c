/* A subclass of GObject with a property. 
   本例实现继承自 GObject 类的数据类型，并且实现了属性的安装和读取/设置
   需要注意的是 name 属性在安装时使用的 G_PARAM_CONSTRUCT 标志位，使得默认值在创建时就被赋值，而 number 属性则没有
   属性获取和设置的正确方式，GValue 的使用方式
*/

#include <stdio.h>
#include <glib-object.h>

#define PROPERTY_ID_OF_NAME 1
#define PROPERTY_ID_OF_NUMBER 2

typedef struct {
    GObject something_as_boilerplate;
    char *private_name;
    int private_number;
} myinstance_t;

typedef struct {
    GObjectClass something_as_boilerplate;
} myclass_t;

GType get_my_typeid();

void my_getter(GObject *object, guint property_id,
        GValue *value, GParamSpec *pspec) {
    myinstance_t *instance = G_TYPE_CHECK_INSTANCE_CAST(
            object,get_my_typeid(), myinstance_t);

    switch(property_id) {
        case PROPERTY_ID_OF_NAME:
            g_value_set_string(value,instance->private_name);
            break;
        case PROPERTY_ID_OF_NUMBER:
            g_value_set_int(value,instance->private_number);
            printf("instance->private_number : %d\n",instance->private_number);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object,property_id,pspec);
            break;
    }

}

void my_setter(GObject *object, guint property_id,
        const GValue *value, GParamSpec *pspec) {
    myinstance_t *instance = G_TYPE_CHECK_INSTANCE_CAST(
            object,get_my_typeid(), myinstance_t);

    switch(property_id) {
        case PROPERTY_ID_OF_NAME:
            g_free(instance->private_name);
            instance->private_name = g_value_dup_string(value);
            break;
        case PROPERTY_ID_OF_NUMBER:
            instance->private_number = g_value_get_int(value);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object,property_id,pspec);
            break;
    }
}

void my_instance_init_func(myinstance_t *instance, gpointer data) {
}

void my_class_init_func(myclass_t* klass, gpointer data) {
    G_OBJECT_CLASS(klass)->get_property = &my_getter;
    G_OBJECT_CLASS(klass)->set_property = &my_setter;

    GParamSpec *my_param_spec;

    // Property "name"
    my_param_spec = g_param_spec_string(
            "name",
            "Name property",
            "The name property of my class.  Can be used on constructing.",
            "All your property are belong to us.",
            G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT
            );
    g_object_class_install_property(
            G_OBJECT_CLASS(klass),
            PROPERTY_ID_OF_NAME,
            my_param_spec
            );

    // Property "number"
    my_param_spec = g_param_spec_int(
            "number",
            "Number property",
            "The number property of my class.",
            G_MININT,
            G_MAXINT,
            20,
            G_PARAM_READABLE | G_PARAM_WRITABLE 
            );
    g_object_class_install_property(
            G_OBJECT_CLASS(klass),
            PROPERTY_ID_OF_NUMBER,
            my_param_spec
            );
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


int main() {
    g_type_init();

    printf("Type id: %d\n",get_my_typeid());
    printf("Type name: %s\n",g_type_name(get_my_typeid()));

    printf("G_MININT : %d\n",G_MININT);
    printf("G_MAXINT : %d\n",G_MAXINT);
    GValue *val = g_new0(GValue,1);

    // the first object

    myinstance_t *instance = (myinstance_t*)g_object_new(get_my_typeid(),NULL);

    g_value_init(val,G_TYPE_STRING);
    g_object_get_property(G_OBJECT(instance),"name",val);
    printf("Property \"name\": [%s]\n",g_value_get_string(val));
    g_value_unset(val);

    g_value_init(val,G_TYPE_INT);
    g_object_get_property(G_OBJECT(instance),"number",val);
    printf("Property \"number\": [%d]\n",g_value_get_int(val));
    g_value_unset(val);

    g_object_unref(instance);

    // the second object

    instance = (myinstance_t*)g_object_new(get_my_typeid(),
            "name","blahblah",
            "number",75,
            NULL);

    g_value_init(val,G_TYPE_STRING);
    g_object_get_property(G_OBJECT(instance),"name",val);
    printf("Property \"name\": [%s]\n",g_value_get_string(val));
    g_value_unset(val);

    g_value_init(val,G_TYPE_INT);
    g_object_get_property(G_OBJECT(instance),"number",val);
    printf("Property \"number\": [%d]\n",g_value_get_int(val));
    g_value_unset(val);

    g_value_init(val,G_TYPE_INT);
    g_value_set_int(val,81);
    g_object_set_property(G_OBJECT(instance),"number",val);
    g_value_unset(val);

    g_value_init(val,G_TYPE_INT);
    g_object_get_property(G_OBJECT(instance),"number",val);
    printf("Property \"number\": [%d]\n",g_value_get_int(val));
    g_value_unset(val);

    g_object_unref(instance);

    g_free(val);

    return 0;
}
