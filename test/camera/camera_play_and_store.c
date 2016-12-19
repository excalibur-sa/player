/*
 *Use queue to start a new thread to cope data.
 *Use tee to copy the stream to do different operation.
 *Gstreamer version change: ffmpegcolorspace -> videoconvert; tee element src%d -> src_%u.
 */
#include <gst/gst.h>
  
int main(int argc, char *argv[]) {
  GstElement *pipeline, *video_source, *fmt, *tee, *mpeg_queue, *mpeg_sink;
  GstElement *video_queue, *video_dec, *video_convert, *video_sink;
  GstCaps *caps;
  GstBus *bus;
  GstMessage *msg;
  GstPadTemplate *tee_src_pad_template;
  GstPad *tee_mpeg_pad, *tee_video_pad;
  GstPad *queue_mpeg_pad, *queue_video_pad;
  
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

  if (!(mpeg_sink = gst_element_factory_make ("multifilesink", "mpeg_sink"))) {
    GST_WARNING ("Can't create element \"mpeg_sink\"");
    return -1;
  }
  g_object_set (mpeg_sink, "location", "image%02d.jpg", NULL);

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
  g_object_set (video_source, "num-buffers", 5, NULL);
  caps = gst_caps_from_string("image/jpeg, width=640, height=480");
  g_object_set (fmt, "caps", caps, NULL);
  
  /* Link all elements that can be automatically linked because they have "Always" pads */
  gst_bin_add_many (GST_BIN (pipeline), video_source, tee, mpeg_queue, mpeg_sink,
      video_queue, video_dec, video_convert, video_sink, NULL);
  if (gst_element_link_many (video_source, tee, NULL) != TRUE ||
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
  g_print ("Obtained request pad %s for audio branch.\n", gst_pad_get_name (tee_mpeg_pad));
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
  
  /* Start playing the pipeline */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);
  
  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);
  
  /* Release the request pads from the Tee, and unref them */
  gst_element_release_request_pad (tee, tee_mpeg_pad);
  gst_element_release_request_pad (tee, tee_video_pad);
  gst_object_unref (tee_mpeg_pad);
  gst_object_unref (tee_video_pad);
  
  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  
  gst_object_unref (pipeline);
  return 0;
}

