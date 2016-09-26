#ifndef __GST_FPP_ADEC_H__
#define __GST_FPP_ADEC_H__

#include <gst/gst.h>
#include <gst/tag/tag.h>
#include <gst/audio/gstaudiodecoder.h>

G_BEGIN_DECLS

#define GST_TYPE_FPPADEC \
  (gst_fppadec_get_type())
#define GST_FPPADEC(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_FPPADEC,GstFppAdec))
#define GST_FPPADEC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_FPPADEC,GstFppAdecClass))
#define GST_FPPADEC_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS((obj),GST_TYPE_FPPADEC,GstFppAdecClass))  
#define GST_IS_FPPADEC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_FPPADEC))
#define GST_IS_FPPADEC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_FPPADEC))

typedef struct _GstFppAdec GstFppAdec;
typedef struct _GstFppAdecClass GstFppAdecClass;

struct _GstFppAdec
{
    GstAudioDecoder element;

    //basic audio info
    gint mimeID;
    gint samplerate;
    gint channels;
    gint bitrate;
    gint bitspersample;
    gint u32BlockAlign;
    char reserve[128];

    //analyse audio info and set caps fack data 
    gboolean caps_set;

    //segment
    GstSegment segment;

    //pts
    GstClockTime lastRunningTime;

    //data pushing
    gboolean silent;

    //fpp init
    gboolean fpp_init;

    //audio info
    gboolean audioInfo_set;

    //play rate
    gint playrate;

    //fpp audio decoder id
    gint decoder_id;
    
};

struct _GstFppAdecClass
{
    GstAudioDecoderClass parent_class;

    GstStateChangeReturn (*parent_change_state)          (GstElement *element, GstStateChange transition);
    gboolean             (*parent_sink_event)            (GstAudioDecoder *dec, GstEvent *event);
    gboolean             (*parent_src_event)             (GstAudioDecoder *dec, GstEvent *event);
};

GType                   gst_fppadec_get_type (void);
gboolean                gst_fppadec_register (GstPlugin * plugin);

G_END_DECLS
    
#endif /* __GST_FPP_ADEC_H__ */
