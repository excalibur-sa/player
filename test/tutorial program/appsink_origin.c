#include <gst/gst.h>
gint dot_file_counter = 0;  
int main(int argc, char *argv[]) {
  GstElement *pipeline;
  
  GstBus *bus;
  GstMessage *msg;
  
  /* Initialize GStreamer */
  gst_init (&argc, &argv);
  
  /* Build the pipeline */
  pipeline = gst_parse_launch ("playbin2 uri=file:///home/shena/media_data/1.mp4", NULL);
 
  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  gint ret;
  GstState play_state;
  GstState play_state_pending;
	
RE_GET:
  ret = gst_element_get_state (pipeline, &play_state, &play_state_pending, 1 * GST_SECOND);
  if (ret != GST_STATE_CHANGE_SUCCESS) {
    g_print ("Couldn't set GST_STATE_PLAYING\n");
    goto RE_GET;
  }
  else
  {
     if(play_state != GST_STATE_PLAYING)
	goto RE_GET;
#if 1
  /* dump graph for (some) pipeline state changes */
  {
    gchar *dump_name = g_strconcat ("playback-tutorial-7.", "PLAYING", NULL);
    if (dot_file_counter < 1)
    {
      GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (GST_BIN (pipeline), GST_DEBUG_GRAPH_SHOW_ALL, dump_name);
      dot_file_counter++;
    }
    g_free (dump_name);
  }
#endif
  }
  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);
  
  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
  return 0;
}

