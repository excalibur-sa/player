/*
	仅仅验证本地 GObject 开发环境及编译运行方式。
*/
#include <glib-object.h>

int main() {
    g_type_init(); // This is necessary

    g_print ("g_type_init succeed!\n");
    return 0;
}
