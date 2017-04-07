/* A subclass of GObject with a property. 
   Signal 的使用时非常有用的，本例仅仅是简单的示例，参考开源工程来使用
*/

#include <stdio.h>
#include <glib-object.h>

typedef struct {
    GObject something_as_boilerplate;
    char *name;
} myinstance_t;

typedef struct {
    GObjectClass something_as_boilerplate;
} myclass_t;

GType get_my_typeid();

void my_instance_init_func(myinstance_t *instance, gpointer data) {
    instance->name = "AnInstance";
}

void my_class_init_func(myclass_t* klass, gpointer data) {
    int signal_id = g_signal_new(
            "my-signal",
            get_my_typeid(),
            G_SIGNAL_RUN_LAST,
            0,
            NULL,
            NULL,
            g_cclosure_marshal_VOID__STRING,
            G_TYPE_NONE,
            1,
            G_TYPE_STRING,
            NULL
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

void hello(GObject *sender, char* name, gpointer data) {
    printf("Hello world, [%s]!\n",name);
}

void goodbye(GObject *sender, char* name, gpointer data) {
    myinstance_t *instance = G_TYPE_CHECK_INSTANCE_CAST(
            sender,get_my_typeid(),myinstance_t);
    printf("Goodbye world, [%s]! Message from [%s]. data is [%d]\n",
            name, instance->name, *(int*)data);
}

int main() {
    g_type_init();

    printf("Type id: %d\n",get_my_typeid());
    printf("Type name: %s\n",g_type_name(get_my_typeid()));

    GValue *val = g_new0(GValue,1);

    // the first object

    myinstance_t *instance = (myinstance_t*)g_object_new(get_my_typeid(),NULL);

    int tmpvar = 42;

    g_signal_connect(instance,"my-signal",G_CALLBACK(hello),NULL);
    g_signal_connect(instance,"my-signal",G_CALLBACK(goodbye),&tmpvar);

    g_signal_emit_by_name(instance,"my-signal","cloverprince");

    g_object_unref(instance);

    g_free(val);

    return 0;
}
