/*
 *Play the media file with the upper element playbin2. playbin2 will create elememts needed 
 *and link them to get a whole pipeline automatically.
 *update 2016.01.14 : this file check the seek operation between GST_STATE_PAUSED and GST_STATE_PLAYING. In fact, it is work!
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
	pipeline = gst_parse_launch ("playbin2 uri=file:///home/shena/media_data/1.mp4", NULL);

	/*
	GST_STATE_VOID_PENDING        = 0,
	GST_STATE_NULL                = 1,
	GST_STATE_READY               = 2,
	GST_STATE_PAUSED              = 3,
	GST_STATE_PLAYING             = 4
	*/

#if 0
	/* Start playing */
	gst_element_set_state (pipeline, GST_STATE_PLAYING);
#else
  gst_element_set_state (pipeline, GST_STATE_READY);
  gst_element_set_state (pipeline, GST_STATE_PAUSED);

	GstState cur_state;
CHECK:
  gst_element_get_state (pipeline, &cur_state, NULL, 5*GST_SECOND);
  if (cur_state == GST_STATE_PAUSED)
  {
		g_print ("current state GST_STATE_PAUSED\n");
		if(gst_element_seek(pipeline, 1.0, GST_FORMAT_TIME,
				                             GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT | GST_SEEK_FLAG_SKIP,
				                             GST_SEEK_TYPE_SET,  20*GST_SECOND,
				                             GST_SEEK_TYPE_NONE,GST_CLOCK_TIME_NONE))
			g_print ("seek to 20 seconds success\n");
		else
			g_print ("seek to 20 seconds failed\n");
	}
	else
	{
		g_print ("recheck state untill GST_STATE_PAUSED\n");
		goto CHECK;
	}
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
