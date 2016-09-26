/*
利用 Gstreamer 写简单的MP3播放器
Gstreamer下有着各种各样的组件，只要想搭积木似的就可以构建一个简单的MP3播放器
这里只用到4个最基本的组件，分别为 
pipeline:管道，可以直接由gst_pipeline_new函数创建,所有组件要加入到管道中，这样数据才能更好的流动
source：filesrc工厂创建，功能是读取磁盘文件
decoder：mad工厂创建，MP3解码器
sink：autoaudiosink工厂创建，输出音频流到声卡

把组件加入到管道，并按照 读取->解码->输出 的顺序连接起来

全部代码如下:
(
参考自
    http://gstreamer.freedesktop.org/data/doc/gstreamer/head/manual/html/chapter-helloworld.html
    http://www-128.ibm.com/developerworks/cn/linux/l-gstreamer/index.html
)
*/
#include <gst/gst.h>
#include <glib.h>

//定义消息处理函数,
static gboolean
bus_call(GstBus *bus,
        GstMessage *msg,
        gpointer data)
{
    GMainLoop *loop = (GMainLoop *) data;//这个是主循环的指针，在接受EOS消息时退出循环
    switch (GST_MESSAGE_TYPE(msg)){
        case GST_MESSAGE_EOS:
            g_print("End of stream\n");
            g_main_loop_quit(loop);
            break;
        case GST_MESSAGE_ERROR:{
                           gchar *debug;
                           GError *error;

                           gst_message_parse_error(msg,&error,&debug);
                           g_free(debug);
                           g_printerr("ERROR:%s\n",error->message);
                           g_error_free(error);
                           g_main_loop_quit(loop);
                           break;
                       }
        default:
                       break;
    }
    return TRUE;
}

int 
main(int argc,
        char *argv[])
{
    GMainLoop *loop;
    GstElement *pipeline,*source,*decoder,*sink;//定义组件
    GstBus *bus;

    gst_init(&argc,&argv);
    loop = g_main_loop_new(NULL,FALSE);//创建主循环，在执行 g_main_loop_run后正式开始循环

    if(argc != 2){
        g_printerr("Usage:%s <mp3 filename>\n",argv[0]);
        return -1;
    }
    //创建管道和组件
    pipeline = gst_pipeline_new("audio-player");
    source = gst_element_factory_make("filesrc","file-source");
    decoder = gst_element_factory_make("mad","mad-decoder");
    sink = gst_element_factory_make("autoaudiosink","audio-output");

    if(!pipeline||!source||!decoder||!sink){
        g_printerr("One element could not be created.Exiting.\n");
        return -1;
    }
    //设置 source的location 参数。即 文件地址.
    g_object_set(G_OBJECT(source),"location",argv[1],NULL);
    //得到 管道的消息总线
    bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));
   //添加消息监视器
    gst_bus_add_watch(bus,bus_call,loop);
    gst_object_unref(bus);
    //把组件添加到管道中.管道是一个特殊的组件，可以更好的让数据流动
    gst_bin_add_many(GST_BIN(pipeline),source,decoder,sink,NULL);
   //依次连接组件 
   gst_element_link_many(source,decoder,sink,NULL);
   //开始播放
    gst_element_set_state(pipeline,GST_STATE_PLAYING);
    g_print("Running...\n");
    //开始循环
    g_main_loop_run(loop);
    g_print("Returned,stopping playback\n");
    gst_element_set_state(pipeline,GST_STATE_NULL);
    gst_object_unref(GST_OBJECT(pipeline));
    return 0;
}
/*
static gboolean
bus_call(GstBus *bus,
        GstMessage *msg,
        gpointer data)
回掉函数，填充gst_bus_add_watch函数的第2个参数，即消息处理函数.
gst_bus_add_watch是用来监视总线中的消息，因为 管道 自带了总线，所以不用自己在创建
可以使用 bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline)) 得到管道中的消息总线
gst_bus_add_watch () 的定义如下
gst_bus_add_watch ()
guint               gst_bus_add_watch                   (GstBus *bus,
                                                         GstBusFunc func,
                                                         gpointer user_data);
Adds a bus watch to the default main context with the default priority. This function is used to receive asynchronous messages in the main loop. 
The watch can be removed using g_source_remove() or by returning FALSE from func.
bus :
a GstBus to create the watch for 
func :
A function to call when a message is received. 
user_data :
user data passed to func. 
Returns :
The event source id. MT safe. 

user_data 是传递给回掉函数的参数，这里传送的是 主循环的指针 用来在播放完毕时退出主循环

使用编译命令
gcc -Wall  helloworld.c -o helloworld $(pkg-config --cflags --libs gstreamer-0.10)

然后就可以听歌了
l@l-desktop:~/workspace/gstmu$ ./helloworld "/mnt/mldonkeyfile/incoming/files/孙燕姿.-.[逆光].专辑.(MP3)/02.逆光.mp3" 
Running...
End of stream
Returned,stopping playback

*/
