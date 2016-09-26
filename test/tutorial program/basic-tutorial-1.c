/*
 *Play the media file with the upper element playbin. playbin will create elememts needed 
 *and link them to get a whole pipeline automatically.
*/

#include <gst/gst.h>
  
int main(int argc, char *argv[]) 
{
	GstElement *pipeline;
	GstBus *bus;
	GstMessage *msg;
	    
	/* Initialize GStreamer */
	gst_init (&argc, &argv);
		  
	/* Build the pipeline */
	pipeline = gst_parse_launch ("playbin uri=file:///home/shena/share/media_data/1.mp4", NULL);

#if 0
	/* Start playing */
	gst_element_set_state (pipeline, GST_STATE_PLAYING);
#else
	/* At each state, we can do something */
	g_print("change pipeline state to GST_STATE_READY\n");
	gst_element_set_state (pipeline, GST_STATE_READY);
	g_print("change pipeline state to GST_STATE_PAUSED\n");
	gst_element_set_state (pipeline, GST_STATE_PAUSED);
	g_print("change pipeline state to GST_STATE_PLAYING\n");
	gst_element_set_state (pipeline, GST_STATE_PLAYING);
#endif

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
