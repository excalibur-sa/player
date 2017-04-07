/* A fundamental type.  Instantiatable.  Has private struct. 
   为实现数据隐藏，屏蔽内部修改对上层应用的影响，本例创建了拥有 私有数据结构的类类型，需要注意的是添加的私有数据会为每个 实例分配相应空间
   Then the private struct will be allocated together with each instance. 
*/

#include <stdio.h>
#include <glib-object.h>

typedef struct {
    GTypeClass something_as_boilerplate;
} myclass_t;

typedef struct {
    GTypeInstance something_as_boilerplate;
    int an_instance_member;
} myinstance_t;

typedef struct {
    int a_private_instance_member;
} myinstance_private_t;

void my_class_init_func(myclass_t* klass, gpointer data) {
    g_type_class_add_private(klass,sizeof(myinstance_private_t));
}

void my_instance_init_func(myinstance_t *instance, gpointer data) {
    myinstance_private_t *priv;
    priv = G_TYPE_INSTANCE_GET_PRIVATE(instance,G_TYPE_FROM_INSTANCE(instance),myinstance_private_t);
    priv->a_private_instance_member = 81;
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
            "MyTypeWithPrivate",
            &my_type_info,
            &my_fundamental_info,
            0
            );

    printf("%d\n",my_type_id);
    printf("%s\n",g_type_name(my_type_id));

    myinstance_t *inst = (myinstance_t*)g_type_create_instance(my_type_id);

    myinstance_private_t *priv = G_TYPE_INSTANCE_GET_PRIVATE(inst,my_type_id,myinstance_private_t);

    printf("%d\n",priv->a_private_instance_member);
    priv->a_private_instance_member = 90;
    printf("%d\n",priv->a_private_instance_member);

    g_type_free_instance((GTypeInstance*)inst);

    return 0;
}
