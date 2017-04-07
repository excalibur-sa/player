/*
	本例主要是介绍用推荐的方式使用 GObject，以及 自动代码生成宏的使用及注意事项
*/
#include <glib-object.h>
#include "maman-bar.h"

int main() {
    g_type_init();  /* NOTE: Don't forget this!!!! */

    MamanBar *bar = g_object_new(MAMAN_TYPE_BAR, NULL);

    g_object_unref(bar);

    return 0;
}
