#include <gst/gst.h>
gint dot_file_counter = 0;  
int main(int argc, char *argv[]) {
  GstElement *pipeline, *bin, *equalizer, *convert, *sink;
  GstPad *pad, *ghost_pad;
  GstBus *bus;
  GstMessage *msg;
  
  /* Initialize GStreamer */
  gst_init (&argc, &argv);
  
  /* Build the pipeline */
  pipeline = gst_parse_launch ("playbin2 uri=file:///home/shena/media_data/1.mp4", NULL);
  
  /* Create the elements inside the sink bin */
  equalizer = gst_element_factory_make ("equalizer-3bands", "equalizer");
  convert = gst_element_factory_make ("audioconvert", "convert");
  sink = gst_element_factory_make ("autoaudiosink", "audio_sink");
  if (!equalizer || !convert || !sink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }
  
  /* Create the sink bin, add the elements and link them */
  bin = gst_bin_new ("audio_sink_bin");
  gst_bin_add_many (GST_BIN (bin), equalizer, convert, sink, NULL);
  gst_element_link_many (equalizer, convert, sink, NULL);
  pad = gst_element_get_static_pad (equalizer, "sink");
  ghost_pad = gst_ghost_pad_new ("sink", pad);
  gst_pad_set_active (ghost_pad, TRUE);
  gst_element_add_pad (bin, ghost_pad);
  gst_object_unref (pad);
  
  /* Configure the equalizer */
  g_object_set (G_OBJECT (equalizer), "band1", (gdouble)-24.0, NULL);
  g_object_set (G_OBJECT (equalizer), "band2", (gdouble)-24.0, NULL);
  
  /* Set playbin2's audio sink to be our sink bin */
  g_object_set (GST_OBJECT (pipeline), "audio-sink", bin, NULL);
  
  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  gint ret;
  GstState play_state;
  GstState play_state_pending;
	
RE_GET:
  ret = gst_element_get_state (bin, &play_state, &play_state_pending, 10 * GST_SECOND);
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

