/*
 *Use queue to start a new thread to cope data.
 *Use tee to copy the stream to do different operation.
 *Gstreamer version change: ffmpegcolorspace -> videoconvert; tee element src%d -> src_%u.
 */
#include <gst/gst.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#define RUN_LOOP_IN_THREAD 0
typedef struct _CustomData 
{
  GstElement *pipeline;
  GstElement *mpeg_sink;
  GMainLoop *loop;
  gint buffer_probe_cb;
} CustomData;

#if RUN_LOOP_IN_THREAD
/*
 *Thread to run the main loop
 */
static void *cbloop(void* param)
{
  CustomData data = *(CustomData *)param;
  if(data.loop)
    g_main_loop_run (data.loop);
  return NULL;
}
#endif

/* 
 *直接存储内存中的图片数据 
 */
static gboolean buffer_probe_callback(GstElement *image_sink, GstBuffer *buffer, GstPad *pad, CustomData *appdata)
{
  /*获取 buffer 中的数据*/
  GstMapInfo map;
  gst_buffer_map (buffer, &map, GST_MAP_READ);
  unsigned char *data_photo = map.data;
  
  /*拼接文件名字符串*/
  struct tm *newtime;
  char tmpbuf[128];
  time_t lt1;
  lt1 = time(NULL); 
  newtime=localtime(&lt1);
  strftime( tmpbuf, 128, "capture_%Y%m%d_%H%M%S.jpg", newtime);

  /*将 buffer 数据写入文件*/
  FILE* pFile;
  pFile = fopen(tmpbuf , "wb");
  fwrite(data_photo , 1 , map.size, pFile); 
  fclose(pFile); 

  /*重置 fakesink signal_handoffs 属性，以关闭图片抓取*/
  g_object_set (G_OBJECT (appdata->mpeg_sink), "signal_handoffs", FALSE, NULL);
  gst_buffer_unmap (buffer, &map);
 
  return TRUE;
}

/* 
 *Process keyboard input 
 */
static gboolean handle_keyboard (GIOChannel *source, GIOCondition cond, CustomData *data) 
{
  gchar *str = NULL;
  
  if (g_io_channel_read_line (source, &str, NULL, NULL, NULL) != G_IO_STATUS_NORMAL) 
  {
    return TRUE;
  }
  
  switch (g_ascii_tolower (str[0])) 
  {
    case 'c':
      g_print ("Capture current picture ...\n");
      g_object_set (G_OBJECT (data->mpeg_sink), "signal_handoffs", TRUE, NULL);
      break;
    case 'q':
      g_print ("Quit the program\n");
      g_main_loop_quit (data->loop);
      break;  
    default:
      break;
  }
  
  g_free (str);
  return TRUE;
}

int main(int argc, char *argv[]) {
  CustomData data;
  GstElement *pipeline, *video_source, *fmt, *tee, *mpeg_queue, *mpeg_sink;
  GstElement *video_queue, *video_dec, *video_convert, *video_sink;
  GstCaps *caps;
  GstPadTemplate *tee_src_pad_template;
  GstPad *tee_mpeg_pad, *tee_video_pad;
  GstPad *queue_mpeg_pad, *queue_video_pad;
  GIOChannel *io_stdin;
  
  /* Initialize GStreamer */
  gst_init (&argc, &argv);
  
  /* Create the elements */
  if (!(video_source = gst_element_factory_make ("v4l2src", "video_source"))) {
    GST_WARNING ("Can't create element \"video_source\"");
    return -1;
  }

  if (!(fmt = gst_element_factory_make ("capsfilter", NULL))) {
    GST_WARNING ("Can't create element \"capsfilter\"");
    return -1;
  }

  if (!(tee = gst_element_factory_make ("tee", "tee"))) {
    GST_WARNING ("Can't create element \"tee\"");
    return -1;
  }

  if (!(mpeg_queue = gst_element_factory_make ("queue", "mpeg_queue"))) {
    GST_WARNING ("Can't create element \"mpeg_queue\"");
    return -1;
  }

  if (!(mpeg_sink = gst_element_factory_make ("fakesink", "mpeg_sink"))) {
    GST_WARNING ("Can't create element \"mpeg_sink\"");
    return -1;
  }

  if (!(video_queue = gst_element_factory_make ("queue", "video_queue"))) {
    GST_WARNING ("Can't create element \"video_queue\"");
    return -1;
  }

  if (!(video_dec = gst_element_factory_make ("jpegdec", "video_dec"))) {
    GST_WARNING ("Can't create element \"video_dec\"");
    return -1;
  }

  if (!(video_convert = gst_element_factory_make ("videoconvert", "video_convert"))) {
    GST_WARNING ("Can't create element \"video_convert\"");
    return -1;
  }

  if (!(video_sink = gst_element_factory_make ("ximagesink", "video_sink"))) {
    GST_WARNING ("Can't create element \"video_sink\"");
    return -1;
  }
  
  /* Create the empty pipeline */
  if (!(pipeline = gst_pipeline_new ("camera"))) {
    GST_WARNING ("Can't create pipeline \"camera\"");
    return -1;
  }
  
  /* Configure elements */
  //g_object_set (video_source, "num-buffers", 10, NULL);
  caps = gst_caps_from_string("image/jpeg, width=640, height=480");
  g_object_set (fmt, "caps", caps, NULL);

  /* Setting user data */
  data.pipeline = pipeline;
  data.mpeg_sink = mpeg_sink;
  data.buffer_probe_cb = g_signal_connect(G_OBJECT(mpeg_sink), "handoff", G_CALLBACK(buffer_probe_callback), &data);
  
  /* Link all elements that can be automatically linked because they have "Always" pads */
  gst_bin_add_many (GST_BIN (pipeline), video_source, fmt, tee, mpeg_queue, mpeg_sink,
      video_queue, video_dec, video_convert, video_sink, NULL);
  if (gst_element_link_many (video_source, fmt, tee, NULL) != TRUE ||
      gst_element_link_many (mpeg_queue, mpeg_sink, NULL) != TRUE ||
      gst_element_link_many (video_queue, video_dec, video_convert, video_sink, NULL) != TRUE) {
    g_printerr ("Elements could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
  }
  
  /* Manually link the Tee, which has "Request" pads */
  tee_src_pad_template = gst_element_class_get_pad_template (GST_ELEMENT_GET_CLASS (tee), "src_%u");
  if(!tee_src_pad_template) g_printerr("tee_src_pad_template get error!\n");

  tee_mpeg_pad = gst_element_request_pad (tee, tee_src_pad_template, NULL, NULL);
  g_print ("Obtained request pad %s for mpeg branch.\n", gst_pad_get_name (tee_mpeg_pad));
  queue_mpeg_pad = gst_element_get_static_pad (mpeg_queue, "sink");
  tee_video_pad = gst_element_request_pad (tee, tee_src_pad_template, NULL, NULL);
  g_print ("Obtained request pad %s for video branch.\n", gst_pad_get_name (tee_video_pad));
  queue_video_pad = gst_element_get_static_pad (video_queue, "sink");
  if (gst_pad_link (tee_mpeg_pad, queue_mpeg_pad) != GST_PAD_LINK_OK ||
      gst_pad_link (tee_video_pad, queue_video_pad) != GST_PAD_LINK_OK) {
    g_printerr ("Tee could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
  }
  gst_object_unref (queue_mpeg_pad);
  gst_object_unref (queue_video_pad);
  
  /* Print usage map */
  g_print (
    "USAGE: Choose one of the following options, then press enter:\n"
    " 'C' to capture the current picture, store as jpeg\n"
    " 'Q' to quit\n");

  /* Add a keyboard watch so we get notified of keystrokes */
  io_stdin = g_io_channel_unix_new (fileno (stdin));
  g_io_add_watch (io_stdin, G_IO_IN, (GIOFunc)handle_keyboard, &data);
  /* Start playing the pipeline */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);
  
  /* Create a GLib Main Loop and set it to run */
  data.loop = g_main_loop_new (NULL, FALSE);

#if RUN_LOOP_IN_THREAD
  pthread_t th_a;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_create(&th_a, &attr, cbloop, &data);
  pthread_attr_destroy(&attr);
#else
  g_main_loop_run (data.loop);
#endif

  g_signal_handler_disconnect(G_OBJECT(data.mpeg_sink), data.buffer_probe_cb);
  /* Release the request pads from the Tee, and unref them */
  gst_element_release_request_pad (tee, tee_mpeg_pad);
  gst_element_release_request_pad (tee, tee_video_pad);
  gst_object_unref (tee_mpeg_pad);
  gst_object_unref (tee_video_pad);
  
  /* Free resources */
  gst_element_set_state (pipeline, GST_STATE_NULL);
  
  gst_object_unref (pipeline);
  return 0;
}

