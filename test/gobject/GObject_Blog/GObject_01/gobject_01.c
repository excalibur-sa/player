/* A fundamental type.  Only its name is significant. 
   本例主要介绍怎样向 GLib 类型系统注册类型，分析 g_type_register_fundamental 函数及参数，同时检测注册后类型的相关信息
*/

#include <stdio.h>
#include <glib-object.h>

int main() {
    g_type_init(); // This is necessary

    GTypeInfo my_type_info = { // This is not important
        0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, NULL};

    GTypeFundamentalInfo my_fundamental_info = {0}; // This is not important

    GType my_type_id = g_type_register_fundamental(
            g_type_fundamental_next(),
            "MyFirstFundamentalType",
            &my_type_info,
            &my_fundamental_info,
            0
            );

    printf("%s\n",g_type_name(my_type_id));
    printf("%s\n",g_type_name(G_TYPE_INT));
    printf("%s\n",g_type_name(G_TYPE_FLOAT));
    printf("%s\n",g_type_name(G_TYPE_OBJECT));

    printf("Type id: %d\n",g_type_from_name("MyFirstFundamentalType"));
    printf("Type name: %s\n",g_type_name(g_type_from_name("MyFirstFundamentalType")));

    printf("Is abstract? %s\n",     G_TYPE_IS_ABSTRACT       (my_type_id)? "yes":"no");
    printf("Is derived? %s\n",      G_TYPE_IS_DERIVED        (my_type_id)? "yes":"no");
    printf("Is fundamental? %s\n",  G_TYPE_IS_FUNDAMENTAL    (my_type_id)? "yes":"no");
    printf("Is value type? %s\n",   G_TYPE_IS_VALUE_TYPE     (my_type_id)? "yes":"no");
    printf("Has value table? %s\n", G_TYPE_HAS_VALUE_TABLE   (my_type_id)? "yes":"no");
    printf("Is classed? %s\n",      G_TYPE_IS_CLASSED        (my_type_id)? "yes":"no");
    printf("Is instantiable? %s\n", G_TYPE_IS_INSTANTIATABLE (my_type_id)? "yes":"no");
    printf("Is derivable? %s\n",    G_TYPE_IS_DERIVABLE      (my_type_id)? "yes":"no");
    printf("Is deep derivable? %s\n",G_TYPE_IS_DEEP_DERIVABLE(my_type_id)? "yes":"no");
    printf("Is interface? %s\n",    G_TYPE_IS_INTERFACE      (my_type_id)? "yes":"no");

    return 0;
}
