/* GStreamer
 * Copyright (C) 2010 Stefan Kost <stefan.kost@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

/* demo for using gstcontroler with camera capture for e.g. bracketing
 *
 * gcc `pkg-config --cflags --libs gstreamer-0.10 gstreamer-controller-0.10` camctrl.c -o camctrl
 *
 * TODO:
 * - handle stream status and switch capture thread to SCHED_RR/FIFO
 * - the queue-size controls the controler offset
 *   - right now we work with 1 queued picture and thus active settings for next
 *     frame
 * - we want some feedback about how precisely a program can be realized
 *   - we might want to adjust the framerate to handle hardware limmits
 * - we e.g. can't change resolution per frame right now
 */

/*
 * this demo modified from test program for v4l2src.
 * removed the gstreamer controller function.
 */
#include <gst/gst.h>

static void
event_loop (GstElement * bin)
{
  GstBus *bus;
  GstMessage *message = NULL;

  bus = gst_element_get_bus (GST_ELEMENT (bin));

  while (TRUE) {
    message = gst_bus_poll (bus, GST_MESSAGE_ANY, -1);

    switch (message->type) {
      case GST_MESSAGE_EOS:
        gst_message_unref (message);
        return;
      case GST_MESSAGE_WARNING:
      case GST_MESSAGE_ERROR:{
        GError *gerror;
        gchar *debug;

        gst_message_parse_error (message, &gerror, &debug);
        gst_object_default_error (GST_MESSAGE_SRC (message), gerror, debug);
        gst_message_unref (message);
        g_error_free (gerror);
        g_free (debug);
        return;
      }
      default:
        gst_message_unref (message);
        break;
    }
  }
}

gint
main (gint argc, gchar ** argv)
{
  GstElement *bin;
  GstElement *src, *fmt, *dec, *convert, *sink;
  GstCaps *caps;

  /* init gstreamer */
  gst_init (&argc, &argv);

  /* create a new bin to hold the elements */
  bin = gst_pipeline_new ("camera");

  /* create elements */
  if (!(sink = gst_element_factory_make ("ximagesink", NULL))) {
    GST_WARNING ("Can't create element \"ximagesink\"");
    return -1;
  }

  if (!(dec = gst_element_factory_make ("jpegdec", NULL))) {
    GST_WARNING ("Can't create element \"jpegdec\"");
    return -1;
  }

  if (!(fmt = gst_element_factory_make ("capsfilter", NULL))) {
    GST_WARNING ("Can't create element \"capsfilter\"");
    return -1;
  }
  caps =
      gst_caps_from_string("image/jpeg, width=640, height=480");
  g_object_set (fmt, "caps", caps, NULL);

  if (!(src = gst_element_factory_make ("v4l2src", NULL))) {
    GST_WARNING ("Can't create element \"v4l2src\"");
    return -1;
  }

  if (!(convert = gst_element_factory_make ("videoconvert", NULL))) {
    GST_WARNING ("Can't create element \"vdieoconvert\"");
    return -1;
  }

  /* add objects to the main bin */
  gst_bin_add_many (GST_BIN (bin), src, fmt, dec, convert, sink, NULL);

  /* link elements */
  if (!gst_element_link_many (src, fmt, dec, convert, sink, NULL)) {
    GST_WARNING ("Can't link elements");
    return -1;
  }

  /* prepare playback */
  gst_element_set_state (bin, GST_STATE_PAUSED);

  /* play and wait */
  gst_element_set_state (bin, GST_STATE_PLAYING);

  /* mainloop and wait for eos */
  event_loop (bin);

  /* stop and cleanup */
  gst_element_set_state (bin, GST_STATE_NULL);
  gst_object_unref (GST_OBJECT (bin));
  return 0;
}
