/*
    use the Element as a G_Objiect to get tht Element attributes
*/
#include <gst/gst.h>

int
main (int   argc,
      char *argv[])
{
  GstElement *element;
  gchar *name;

  /* init GStreamer */
  gst_init (&argc, &argv);

  /* create element */
  element = gst_element_factory_make ("fakesrc", "fakesrc_source_SHENA");

  /* get name */
  g_object_get (G_OBJECT (element), "name", &name, NULL);//参数的顺序和设置
  g_print ("The name of the element is '%s'.\n", name);
  g_free (name);

  gst_object_unref (GST_OBJECT (element));

  return 0;
}
    

