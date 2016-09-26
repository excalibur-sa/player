/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <string.h>
#include <gst/audio/audio.h>
#include "gstfppadec.h"
#include "fpp_decoder.h"
#include "fpp_media_manager.h"


#define AUDIO_FAKESIZE 2304

GST_DEBUG_CATEGORY_STATIC (fppadec_debug);
#define GST_CAT_DEFAULT fppadec_debug

enum
{
    PROP_NONE,
    PROP_DECEDER_ID,
    PROP_PLAY_RATE,
    PROP_SILENT
};

static GstStaticPadTemplate fppadec_src_template_factory =
GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,    
    GST_STATIC_CAPS ("audio/x-raw")     
    );

static GstStaticPadTemplate fppadec_sink_template_factory =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("audio/mpeg; " 
                     "audio/x-m4a; " 
                     "audio/AMR-WB; " 
                     "audio/AMR; " 
                     "audio/x-wma,"
                     "wmaversion = (int) {1,2,3}; " 
                     "audio/x-dts; " 
                     "audio/x-private1-dts; " 
                     "audio/x-ac3; " 
                     "audio/aac; " 
                     "audio/x-adpcm; " 
                     "audio/x-flac; " 
                     "audio/x-pn-realaudio; " 
                     "audio/x-eac3; " 
                     "audio/x-vorbis; " 
                     "audio/x-tcl-pcm")
    );

static void
gst_fppadec_check_caps_reset (GstFppAdec * fppadec);
static gint 
gst_fppadec_mime_audioID(GstAudioDecoder * dec, const gchar *mime, GstCaps * caps);
static gboolean 
gst_fppadec_start (GstAudioDecoder * dec);
static gboolean 
gst_fppadec_stop (GstAudioDecoder * dec);
static GstFlowReturn 
gst_fppadec_handle_frame (GstAudioDecoder * dec, GstBuffer * buffer);
static void 
gst_fppadec_flush (GstAudioDecoder * dec, gboolean hard);
static void 
gst_fppadec_set_property (GObject * object, guint prop_id, 
    const GValue * value, GParamSpec * pspec);
static void 
gst_fppadec_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec);
static GstStateChangeReturn
gst_fppadec_change_state (GstElement * element, GstStateChange transition);
static gboolean
gst_fppadec_sink_eventfunc (GstAudioDecoder * dec, GstEvent * event);
static gboolean
gst_fppadec_src_eventfunc (GstAudioDecoder * dec, GstEvent * event);
static void 
gst_fppadec_parse_segment_event(GstAudioDecoder* dec, GstEvent* event);
static void 
gst_fppadec_fpp_events_process( uint32_t u32decoderID, EN_FPP_DECODER_MODE_T en_mode_type, void * parameter);

#define gst_fppadec_parent_class parent_class
G_DEFINE_TYPE (GstFppAdec, gst_fppadec, GST_TYPE_AUDIO_DECODER);

static void
gst_fppadec_class_init (GstFppAdecClass * klass)
{
    GObjectClass *gobject_class = (GObjectClass *) klass;
    GstElementClass *element_class = (GstElementClass *) klass;
    GstAudioDecoderClass *base_class = (GstAudioDecoderClass *) klass;

    gobject_class->set_property = gst_fppadec_set_property;
    gobject_class->get_property = gst_fppadec_get_property;

    /* init properties */
    g_object_class_install_property (
        gobject_class, 
        PROP_DECEDER_ID,
        g_param_spec_uint ( "fpp-audio-decoder-id", 
                            "audio decoder id get from fpp level",
                            "The audio decoder id to operate directly",
                            0, G_MAXUINT, 0, 
                            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

    g_object_class_install_property (
        gobject_class, 
        PROP_PLAY_RATE,
        g_param_spec_uint ( "audio-play-rate", 
                            "paly rate to control play of audio decoder",
                            "The audio play rate to control decoder",
                            0, G_MAXUINT, 0, 
                            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

    g_object_class_install_property (
        gobject_class, 
        PROP_SILENT,
        g_param_spec_boolean (  "silent", 
                                "silent", 
                                "Push data to fpp audio decoder, or not?",
                                FALSE, G_PARAM_READWRITE));
    
    gst_element_class_add_pad_template (element_class,
    gst_static_pad_template_get (&fppadec_sink_template_factory));
    gst_element_class_add_pad_template (element_class,
    gst_static_pad_template_get (&fppadec_src_template_factory));

    gst_element_class_set_static_metadata (
        element_class,   
        "fpp audio decoder(gstreamer v1.7)",
        "Codec/Decoder/Audio",
        "Uses fpp to decode specific audio streams",
        "Eison <shena@tcl.com>");

    base_class->start = GST_DEBUG_FUNCPTR (gst_fppadec_start);
    base_class->stop = GST_DEBUG_FUNCPTR (gst_fppadec_stop);
    base_class->handle_frame = GST_DEBUG_FUNCPTR (gst_fppadec_handle_frame);
    base_class->flush = GST_DEBUG_FUNCPTR (gst_fppadec_flush);

    element_class->change_state =
      GST_DEBUG_FUNCPTR (gst_fppadec_change_state);

    base_class->sink_event =
      GST_DEBUG_FUNCPTR (gst_fppadec_sink_eventfunc);

    base_class->src_event =
      GST_DEBUG_FUNCPTR (gst_fppadec_src_eventfunc);
    
}

static void
gst_fppadec_init (GstFppAdec * fppadec)
{
    GstAudioDecoder *dec;
    dec = GST_AUDIO_DECODER (fppadec);
    gst_audio_decoder_set_tolerance (dec, 20 * GST_MSECOND);
    gst_audio_decoder_set_use_default_pad_acceptcaps (dec, TRUE);
    GST_PAD_SET_ACCEPT_TEMPLATE (GST_AUDIO_DECODER_SINK_PAD (dec)); 

    fppadec->mimeID = -1;
    fppadec->samplerate = 0;
    fppadec->channels = 1;
    fppadec->bitrate = 0;
    fppadec->bitspersample = 0;
    fppadec->u32BlockAlign = 0;
    fppadec->caps_set = FALSE;
    gst_segment_init(&fppadec->segment, GST_FORMAT_TIME);
    fppadec->lastRunningTime = 0;
    fppadec->silent = TRUE;
    fppadec->fpp_init = TRUE;
    fppadec->audioInfo_set = FALSE;
    fppadec->playrate = 1;
    fppadec->decoder_id = -1;
    
}

static void
gst_fppadec_check_caps_reset (GstFppAdec * fppadec)
{
    guint nchannels = fppadec->channels;
    guint rate = fppadec->samplerate;

    GstAudioInfo info;
    static const GstAudioChannelPosition chan_pos[2][2] = {
        {GST_AUDIO_CHANNEL_POSITION_MONO},
        {GST_AUDIO_CHANNEL_POSITION_FRONT_LEFT,
        GST_AUDIO_CHANNEL_POSITION_FRONT_RIGHT}
    };
    
    gst_audio_info_init (&info);
    gst_audio_info_set_format (&info,
        GST_AUDIO_FORMAT_S32, rate, nchannels, chan_pos[nchannels - 1]);

    GST_DEBUG ("gst_audio_decoder_set_output_format for fake data.");
    gst_audio_decoder_set_output_format (GST_AUDIO_DECODER (fppadec), &info);
}

static gint 
gst_fppadec_mime_audioID(GstAudioDecoder * dec, const gchar *mime, GstCaps * caps)
{
    GST_DEBUG_OBJECT(dec, "Looking Audio MimeID for '%s'\n", mime);
    gint atype = -1;
    GstStructure *s = gst_caps_get_structure(caps, 0);    

    if(!strncmp(mime, "audio/x-m4a", 11))
        atype = EN_ES_AUDIO_MP4A;
    else if(!strncmp(mime, "audio/mpeg", 10))
    {
        gint ver = 0, layer = 0;
        gst_structure_get_int(s, "mpegversion", &ver);
        GST_DEBUG_OBJECT(dec, "ver %d \n", ver);
        switch(ver)
        {
            case 1:
                gst_structure_get_int(s, "layer", &layer);
                GST_DEBUG_OBJECT(dec, "layer %d \n", layer);
                switch (layer)
                {
                    case 1:
                    case 2:
                        GST_DEBUG_OBJECT(dec, "MPEG-1 Layer %d (MP%d)\n", layer, layer);
                        atype = EN_ES_AUDIO_MPEG;
                        break;
                    case 3:
                        GST_DEBUG_OBJECT(dec, "MPEG-1 Layer %d (MP%d)\n", layer, layer);
                        atype = EN_ES_AUDIO_MP3;
                        break;
                    default:
                        GST_DEBUG_OBJECT(dec, "Unexpected MPEG-1 layer in %" GST_PTR_FORMAT, caps);
                        break;
                }
                break;
            case 2:
            case 4:
                GST_DEBUG_OBJECT(dec, "AAC\n");
                atype = EN_ES_AUDIO_AAC;
                break;
            /* case 4:
            MMLOGI ("MPEG-4 AAC (mp4a)\n");
            atype = EN_ES_AUDIO_MP4A;
            break;*/
            default:
                GST_DEBUG_OBJECT(dec, "Unexpected audio mpegversion in %" GST_PTR_FORMAT, caps);
                break;
        }
    }
    else if(!strncmp(mime, "audio/AMR-WB", 12))
        atype = EN_ES_AUDIO_AMR_WB;
    else if(!strncmp(mime, "audio/AMR", 9))
        atype = EN_ES_AUDIO_AMR_NB;
    else if(!strncmp(mime, "audio/x-wma", 11))
    {
        gint version;
        gst_structure_get_int(s, "wmaversion", &version);
        switch(version)
        {
            case 1:
                atype = EN_ES_AUDIO_WMA;
                break;
            case 2:
                atype = EN_ES_AUDIO_WMA2;
                break;
            case 3:
                atype = EN_ES_AUDIO_WMA3;
                break;
            default:
                break;
        }
    }
    else if(!strncmp(mime, "audio/x-dts", 11) || !strncmp(mime, "audio/x-private1-dts", 20))
        atype = EN_ES_AUDIO_DTS;
    else if(!strncmp(mime, "audio/x-ac3", 11) || !strncmp(mime, "audio/x-private1-ac3", 20))
        atype = EN_ES_AUDIO_AC3;
    else if(!strncmp(mime, "audio/x-eac3", 12))
        atype = EN_ES_AUDIO_AC3_PLUS;
    else if(!strncmp(mime, "audio/aac", 9))
        atype = EN_ES_AUDIO_AAC;
    else if(!strncmp(mime, "audio/x-private1-lpcm", 21) || !strncmp(mime, "audio/x-lpcm", 12))
        atype = EN_ES_AUDIO_PCM;
    else if(!strncmp(mime, "audio/x-adpcm", 13))
        atype = EN_ES_AUDIO_ADPCM;
    else if(!strncmp(mime, "audio/xxx", 12))
        atype = EN_ES_AUDIO_RAAC;
    else if(!strncmp(mime, "audio/x-pn-realaudio", 20))
        atype = EN_ES_AUDIO_COOK;
    else if(!strncmp(mime, "audio/x-flac", 12))
        atype = EN_ES_AUDIO_FLAC;
    else if(!strncmp(mime, "audio/x-vorbis", 14))
        atype = EN_ES_AUDIO_VORBIS;
    else if(!strncmp(mime, "audio/x-tcl-pcm", 15))
    {
        int pcm_width = 0;
        gboolean pcm_sign = FALSE;
        int pcm_endian = 0;
        gst_structure_get_int(s, "width", &pcm_width);
        gst_structure_get_boolean(s, "signed", &pcm_sign);
        gst_structure_get_int(s, "endianness", &pcm_endian);
        if(pcm_width == 16 && pcm_sign && pcm_endian == G_BIG_ENDIAN)
        {
            atype = EN_ES_AUDIO_PCM_S16BE;
        }
        if(pcm_width == 16 && pcm_sign && pcm_endian == G_LITTLE_ENDIAN)
        {
            atype = EN_ES_AUDIO_PCM_S16LE;//set MIME ID as EN_ES_AUDIO_PCM_S16BE temporarily
        }
        if(pcm_width == 16 && !pcm_sign && pcm_endian == G_LITTLE_ENDIAN)
        {
            atype = EN_ES_AUDIO_PCM_U16LE;
        }
        if(pcm_width == 16 && !pcm_sign && pcm_endian == G_BIG_ENDIAN)
        {
            atype = EN_ES_AUDIO_PCM_U16BE;
        }
    }	
    else
    {
        GST_DEBUG_OBJECT(dec, "Do not support the audio codec!\n");
    }
    GST_DEBUG_OBJECT(dec, "Got the Audio MimeID : %d\n", atype);
    return atype;
}

static gboolean
gst_fppadec_start (GstAudioDecoder * dec)
{
    GstFppAdec *fppadec = GST_FPPADEC (dec);

    /* fpp decoder initialization */
    GST_DEBUG_OBJECT (fppadec, "TODO: start");
    
    return TRUE;
}

static gboolean
gst_fppadec_stop (GstAudioDecoder * dec)
{
    GstFppAdec *fppadec = GST_FPPADEC (dec);

    /* fpp decoder deinitialization */
    GST_DEBUG_OBJECT (fppadec, "TODO: stop");

    return TRUE;
}

static GstFlowReturn
gst_fppadec_handle_frame (GstAudioDecoder * dec, GstBuffer * buffer)
{
    GstFppAdec *fppadec = NULL;
    GstBuffer *outbuffer = NULL;
    GstFlowReturn ret = GST_FLOW_EOS;    

    fppadec = GST_FPPADEC (dec);
    if (G_UNLIKELY (!buffer))
    return GST_FLOW_OK;

    /* fppadec analyse audio info and record it, set caps for fake data */
    if(!fppadec->caps_set)
    {
        GstCaps * sink_pad_caps = gst_pad_get_current_caps(GST_AUDIO_DECODER_SINK_PAD (dec));

        gchar *caps_str = gst_caps_to_string(sink_pad_caps);
        GST_DEBUG_OBJECT (dec, "fppadec sink caps string: %s", caps_str );
        g_free (caps_str);
        
        GstStructure *structure = gst_caps_get_structure(sink_pad_caps, 0);
        const gchar *mime = gst_structure_get_name(structure);

        gint u32BlockAlign = 0;
        gint mimeID = -1, samplerate = 0, channels = 1, bitrate = 0, reserve = 1;
        gst_structure_get_int (structure, "rate",     &samplerate);
        gst_structure_get_int (structure, "channels", &channels);
        gst_structure_get_int (structure, "bitrate",  &bitrate);
        gst_structure_get_int (structure, "block_align", &u32BlockAlign);
            
        mimeID = gst_fppadec_mime_audioID(dec, mime, sink_pad_caps);
        if(mimeID < 0)
        {
            GST_DEBUG_OBJECT (dec, "fppadec do not support the audio codec(%s)!!!", mime);
            return GST_FLOW_ERROR;
        }
    	else
    		GST_DEBUG_OBJECT (dec, "fppadec audio codec(%s) ID: %d \n", mime, mimeID);
#if 0
        GstBuffer* buf_value = NULL;
        GValue *value = (GValue*)gst_structure_get_value(structure, "codec_data");
        if(value)
            buf_value = gst_value_get_buffer(value);
#endif
        // release resource
        if (sink_pad_caps)
            gst_caps_unref(sink_pad_caps);
        
        // record audio info
        fppadec->mimeID         = mimeID;
        fppadec->samplerate     = samplerate;
        fppadec->channels       = channels;
        fppadec->bitspersample  = 16;
        fppadec->bitrate        = (bitrate == 0 ? 128000 : bitrate);
        fppadec->u32BlockAlign  = u32BlockAlign;
        memcpy (fppadec->reserve, &reserve, sizeof(reserve));

        // set caps for fake data
        gst_fppadec_check_caps_reset (fppadec);

        fppadec->caps_set = TRUE;
    }

    /* cope with fpp decoder */
    if(FALSE == fppadec->silent)
    {     
        if(TRUE == fppadec->fpp_init)
        {
            if(FALSE == fppadec->audioInfo_set)
            {
                /* set audio info to fpp level */
                ST_FPP_DECODER_ACODEC_INFO_T audioInfo;
                memset(&audioInfo, 0, sizeof(ST_FPP_DECODER_ACODEC_INFO_T));
                
                audioInfo.u32AudioType     = fppadec->mimeID;
                audioInfo.u32BitsPerSample = 16;
                audioInfo.u32SampleRate    = fppadec->samplerate;
                audioInfo.u32Channel       = fppadec->channels;
                audioInfo.u32BitRate       = (fppadec->bitrate == 0 ? 128000 : fppadec->bitrate);
                audioInfo.u32BlockAlign    = (uint32_t)fppadec->u32BlockAlign;
                memcpy (audioInfo.reserve, &fppadec->reserve, sizeof(fppadec->reserve));
                GST_DEBUG_OBJECT (dec, "fppadec audio info : %d, bitrate : %d, bps : %d, sr : %d, ch : %d, BlockAlign : %d\n",
                                  audioInfo.u32AudioType, audioInfo.u32BitRate, audioInfo.u32BitsPerSample, audioInfo.u32SampleRate, audioInfo.u32Channel, audioInfo.u32BlockAlign);
                
                GST_DEBUG_OBJECT (dec, "fppadec set audio info to fpp level and get the fpp decoder id, and play\n");
                //fpp_mc_decode_set_audio_info(&audioInfo, TRUE);
                if(FPI_ERROR_SUCCESS != fpp_mm_decode_set_audio_info(&fppadec->decoder_id, &audioInfo, TRUE))
                {
                    GST_DEBUG ("fpp_mm_decode_set_audio_info failed\n");
                }
                else
                {
                    GST_DEBUG ("register callback function\n");                    
                    if(FPI_ERROR_SUCCESS != fpp_mm_decode_register_callback(fppadec->decoder_id, gst_fppadec_fpp_events_process, (void *)fppadec))
                    {
                        GST_DEBUG ("register callback failed\n");
                    }                   
                }

                fppadec->audioInfo_set = TRUE;
            }

            /* push real es data(inbuf) to fpp level */
            ST_FPP_DECODER_BLOCK_T inbuf;
            memset(&inbuf, 0, sizeof(ST_FPP_DECODER_BLOCK_T));

            uint8_t *p_buf = NULL;
            guint	buf_len = 0;
            GstMapInfo mapinfo;
            GstMapFlags mapflags = GST_MAP_READ;
            gst_buffer_map(buffer, &mapinfo, mapflags);
            p_buf = (uint8_t *) (mapinfo.data);
            buf_len = mapinfo.size;
            gst_buffer_unmap (buffer, &mapinfo);
            
            GstClockTime running_time;
            GstClockTime timestamp;
            timestamp = GST_BUFFER_TIMESTAMP (buffer);
            running_time =
                gst_segment_to_stream_time (&fppadec->segment, GST_FORMAT_TIME, timestamp);

            if (GST_CLOCK_TIME_IS_VALID (running_time))
            {
                fppadec->lastRunningTime = running_time;
            }
            else
            {
                running_time = fppadec->lastRunningTime;
                GST_DEBUG ("invalid running_time( %lld ), buffer timestamp( %lld ), reuse  fppadec->lastRunningTime( %lld )", running_time, timestamp, fppadec->lastRunningTime);
            }
           
            inbuf.u8pBuff  = p_buf;
            inbuf.u32Size  = buf_len;
            inbuf.u32Pts   = running_time /1000000;

            //GST_DEBUG_OBJECT(dec,"Push Audio es frame, pts = %08x, datasize = %08x, extraHeader = %08x\n",inbuf.u32Pts,inbuf.u32Size,inbuf.u32ExtraHeaderSize);
            //fpp_mc_audio_decode_pushData(&inbuf);
            if( -1 != fppadec->decoder_id)
                fpp_mm_audio_decode_pushData(fppadec->decoder_id, &inbuf);
            else
                GST_DEBUG ("invalid fppadec->decoder_id\n");
            
        }
    }

    /* push fake es data(outbuffer) to element behind */        
    outbuffer = gst_buffer_new_and_alloc(AUDIO_FAKESIZE);
    GST_BUFFER_DURATION (outbuffer) = GST_BUFFER_DURATION (buffer);
    GST_BUFFER_PTS  (outbuffer) = 0;

    ret = gst_audio_decoder_finish_frame (dec, outbuffer, 1);

    return ret;
}

static void
gst_fppadec_flush (GstAudioDecoder * dec, gboolean hard)
{
    GstFppAdec *fppadec;

    fppadec = GST_FPPADEC (dec);
    if (hard) 
    {
        GST_DEBUG_OBJECT (fppadec, "fppadec do flush");
        //fpp_mc_decode_flush_type(EN_FPP_AUDIO_DECODER);
        fpp_mm_decode_flush_type(fppadec->decoder_id);
    }
}

static void
gst_fppadec_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
    GstFppAdec *fppadec;
    fppadec = GST_FPPADEC (object);  

    switch (prop_id) 
    {
        case PROP_DECEDER_ID:            
            break;
        case PROP_PLAY_RATE:
            fppadec->playrate = g_value_get_uint(value);
            if(fppadec->playrate != 1)
            {
                /* not push data to fpp audio decoder any more */
                GST_DEBUG ("play rate changed( %d ), not push data to decoder any more", fppadec->playrate);
            }
            else
            {
                /* continue to push data to fpp audio decoder */
                GST_DEBUG ("play rate changed( %d ), push data to decoder", fppadec->playrate);
            }
            break;
        case PROP_SILENT:            
            break;   
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
            break;
    }
}

static void
gst_fppadec_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
    GstFppAdec *fppadec;
    fppadec = GST_FPPADEC (object);

    switch (prop_id) 
    {
        case PROP_DECEDER_ID:
            g_value_set_uint (value, fppadec->decoder_id);
            break;
        case PROP_PLAY_RATE:
            g_value_set_uint (value, fppadec->playrate);
            break;
        case PROP_SILENT:
            g_value_set_boolean (value, fppadec->silent);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
            break;
    }
}

static GstStateChangeReturn
gst_fppadec_change_state (GstElement * element, GstStateChange transition)
{
    GstFppAdec *fppadec = NULL;
    fppadec = GST_FPPADEC (element);
        
    GstStateChangeReturn ret = GST_STATE_CHANGE_FAILURE;
    switch (transition) 
    {
        case GST_STATE_CHANGE_NULL_TO_READY:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec change state GST_STATE_CHANGE_NULL_TO_READY =====");
            break;
        case GST_STATE_CHANGE_READY_TO_PAUSED:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec change state GST_STATE_CHANGE_READY_TO_PAUSED =====");
            break;
        case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec change state GST_STATE_CHANGE_PAUSED_TO_PLAYING =====");

            if(fppadec->audioInfo_set == TRUE && fppadec->decoder_id != -1)
            {
                GST_DEBUG_OBJECT (fppadec, "fppadec begin resume fpp decoder\n");
                fpp_mm_decode_resume(fppadec->decoder_id);
            }
            //GST_DEBUG_OBJECT (fppadec, "fppadec begin play fpp decoder\n");
            //fpp_mm_decode_play(fppadec->decoder_id);
            break;
        default:
            break;
    }
    
    ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
    if (G_UNLIKELY (ret == GST_STATE_CHANGE_FAILURE))
        GST_DEBUG_OBJECT (fppadec, "===== do parent_class change_state failed =====");
    else
        GST_DEBUG_OBJECT (fppadec, "===== do parent_class change_state success =====");

    switch (transition)
    {
        case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec change state GST_STATE_CHANGE_PLAYING_TO_PAUSED =====");
            if(fppadec->audioInfo_set == TRUE && fppadec->decoder_id != -1)
            {
                GST_DEBUG_OBJECT (fppadec, "fppadec begin pause fpp decoder\n");    
                fpp_mm_decode_pause(fppadec->decoder_id);
            }
            break;
        case GST_STATE_CHANGE_PAUSED_TO_READY:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec change state GST_STATE_CHANGE_PAUSED_TO_READY =====");
            break;
        case GST_STATE_CHANGE_READY_TO_NULL:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec change state GST_STATE_CHANGE_READY_TO_NULL =====");
            GST_DEBUG ("Do fpp decoder flush & stop");
            fpp_mm_decode_flush_type(fppadec->decoder_id);
            fpp_mm_decode_close(fppadec->decoder_id);
            break;
        default:
            break;
    }

    return ret;
}

static gboolean
gst_fppadec_sink_eventfunc (GstAudioDecoder * dec, GstEvent * event)
{
    gboolean ret;
    GstFppAdec *fppadec = NULL;
    fppadec = GST_FPPADEC (dec);
    
    /* local processing */
    switch (GST_EVENT_TYPE (event)) 
    {
        case GST_EVENT_STREAM_START:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_STREAM_START =====");
            break;
        case GST_EVENT_SEGMENT:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_SEGMENT =====");
            gst_fppadec_parse_segment_event(dec, event);
            break;
        case GST_EVENT_GAP:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_GAP =====");
            break;
        case GST_EVENT_FLUSH_START:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_FLUSH_START =====");
            break;
        case GST_EVENT_FLUSH_STOP:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_FLUSH_STOP =====");
            break;
        case GST_EVENT_SEGMENT_DONE:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_SEGMENT_DONE =====");
            break;
        case GST_EVENT_EOS:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_EOS =====");
            break;
        case GST_EVENT_CAPS:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_CAPS =====");
            break;
        case GST_EVENT_TAG:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event GST_EVENT_TAG =====");
            break;
        default:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec sink event default msgID(%s) =====", gst_event_type_get_name (GST_EVENT_TYPE (event)));
            break;
    }

    ret = GST_AUDIO_DECODER_CLASS (parent_class)->sink_event(dec, event);
    if (G_UNLIKELY (ret == GST_STATE_CHANGE_FAILURE))
        GST_DEBUG_OBJECT (fppadec, "===== do parent_class sink_event failed =====");
    else
        GST_DEBUG_OBJECT (fppadec, "===== do parent_class sink_event success =====");

    return ret;
}

static gboolean
gst_fppadec_src_eventfunc (GstAudioDecoder * dec, GstEvent * event)
{
    gboolean ret;
    GstFppAdec *fppadec = NULL;
    fppadec = GST_FPPADEC (dec);
    
    /* local processing */
    switch (GST_EVENT_TYPE (event)) 
    {
        case GST_EVENT_SEEK:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec src event GST_EVENT_SEEK =====");
            break;

        case GST_EVENT_CUSTOM_UPSTREAM:
        {
            if (gst_event_has_name (event, "application/x-custom-stream-select"))
            {
                GST_DEBUG ("===== fppadec src event GST_EVENT_CUSTOM_UPSTREAM(stream-select) =====");
                
                /* fpp decoder initialization£¬gstplayer do it temporarily */
                fppadec->silent = FALSE;
            }
            else if (gst_event_has_name (event, "application/x-custom-stream-unselect"))
            {
                GST_DEBUG ("===== fppadec src event GST_EVENT_CUSTOM_UPSTREAM(stream-unselect) =====");

                fppadec->silent = TRUE;
                /* fpp decoder deinitialization£¬gstplayer do it temporarily */
            }
            else
            {
                GST_DEBUG ("===== fppadec src event GST_EVENT_CUSTOM_UPSTREAM(unknown) =====");
            }
            break;
        }            
        default:
            GST_DEBUG_OBJECT (fppadec, "===== fppadec src event default msgID(%s) =====", gst_event_type_get_name (GST_EVENT_TYPE (event)));
            break;
    }

    ret = GST_AUDIO_DECODER_CLASS (parent_class)->src_event(dec, event);
    if (G_UNLIKELY (ret == GST_STATE_CHANGE_FAILURE))
        GST_DEBUG_OBJECT (fppadec, "===== do parent_class src_event failed =====");
    else
        GST_DEBUG_OBJECT (fppadec, "===== do parent_class src_event success =====");
    
    return ret;
}

static void 
gst_fppadec_parse_segment_event(GstAudioDecoder* dec, GstEvent* event)
{
    GstFppAdec *fppadec = NULL;
    fppadec = GST_FPPADEC (dec);

    const GstSegment *segment;
    gst_event_parse_segment (event, &segment);

    if (segment->format == GST_FORMAT_TIME) 
    {
        GST_DEBUG ("audio segment before parsing: %" GST_SEGMENT_FORMAT, &fppadec->segment);
        gst_segment_copy_into (segment, &fppadec->segment);
        GST_DEBUG ("audio segment after parsing: %" GST_SEGMENT_FORMAT, &fppadec->segment);
        fppadec->lastRunningTime = fppadec->segment.start;
    } 
    else 
    {
        GST_DEBUG ("received non-TIME newsegment event, not update audio segment : %" GST_SEGMENT_FORMAT, &fppadec->segment);
    }
    
    GST_DEBUG ( "parse new segment: rate %g "
                "format %d, start: %" G_GINT64_FORMAT ", stop: %" G_GINT64_FORMAT
                ", time: %" G_GINT64_FORMAT " \n", fppadec->segment.rate, fppadec->segment.format, fppadec->segment.start, fppadec->segment.stop, fppadec->segment.time);

}

static void gst_fppadec_fpp_events_process( uint32_t u32decoderID, EN_FPP_DECODER_MODE_T en_mode_type, void * parameter)
{
    GstFppAdec *fppadec = NULL;
    if(NULL != parameter)
    {
        GST_DEBUG ("the callback element pointer( %p )", parameter);
        fppadec = GST_FPPADEC (parameter);
    }
    
    switch (en_mode_type)
    {
        case EN_FPP_DECODE_VIDEO_EOS:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_VIDEO_EOS IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_AUDIO_EOS:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_AUDIO_EOS IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_AUDIO_UNSUPPORT:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_AUDIO_UNSUPPORT IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_VIDEO_UNSUPPORT:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_VIDEO_UNSUPPORT IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_AUDIO_DATA_ERRO:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_AUDIO_DATA_ERRO IN============\n", __func__, __LINE__);				
            break;

        case EN_FPP_DECODE_VIDEO_DATA_ERRO:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_VIDEO_DATA_ERRO IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_FRIST_IFRAME: 
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_FRIST_IFRAME IN============\n", __func__, __LINE__);
            break; 

        case EN_FPP_DECODE_BUFFERING:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_BUFFERING IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_BUFFER_OK:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_BUFFER_OK IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_VIDEO_NORMAL:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_VIDEO_NORMAL IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_AUDIO_NORMAL:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_AUDIO_NORMAL IN============\n", __func__, __LINE__);
            if(NULL != fppadec)
            {
                gst_element_post_message (GST_ELEMENT_CAST (fppadec),
                                          gst_message_new_custom (GST_MESSAGE_FPP_DECODE_AUDIO_NORMAL, GST_OBJECT(fppadec), NULL));
            }
            break;

        case EN_FPP_DECODE_AV_SYNC_DONE:
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_AV_SYNC_DONE IN============\n", __func__, __LINE__);
            break;

        case EN_FPP_DECODE_AFD_CHANGE: 
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_AFD_CHANGE IN============\n", __func__, __LINE__);
            break;
        case EN_FPP_DECODE_CAPACITY_INSUFFICIENT: 
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_CAPACITY_INSUFFICIENT IN============\n", __func__, __LINE__);
            break;
        case EN_FPP_DECODE_VIDEO_ASPECT_CHANGE: 
            GST_DEBUG ("%s(%d) ===========EN_FPP_DECODE_VIDEO_ASPECT_CHANGE IN============\n", __func__, __LINE__);
            break;    
        default:
            break;
    } 

    return ;
}

static gboolean
plugin_init (GstPlugin * plugin)
{
    GST_DEBUG_CATEGORY_INIT (fppadec_debug, "fppadec", 0, "fppadec decoding");

    return gst_element_register (plugin, "fppadec", GST_RANK_PRIMARY,
        gst_fppadec_get_type ());
}

GST_PLUGIN_DEFINE (
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    fppadec,
    "audio decoding based on the fppadec library",
    plugin_init,
    VERSION,
    "GPL",
    "GStreamer",
    "http://gstreamer.net/");
