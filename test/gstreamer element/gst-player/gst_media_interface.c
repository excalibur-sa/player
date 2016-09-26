#include <gst/gst.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <time.h>
#include "gst_media_interface.h"

#define GSTPLAYER_TIME_INTERVAL 20

#define TAG "gstplayer "

typedef struct _GstMediaPlayer
{
    /* gst_player multi */
    int8_t * url_init;
    media_open_config_s* openConfig;
    GstElement *pipeline;
    GstElement *playbin;
    GstBus *bus;
    GMainLoop *loop;
    GstElement * uridecodebin;
    GstElement * decodebin;
    GstElement * fppvdec;
    GstElement * fppadec;    
    MM_PLAYER_CB cb;
    gint64 duration;//ms
    
    /* gst_player single, temp begin */
    int32_t last_msg;
    int32_t state;
    int32_t network_error_flag;
    pthread_t timeout_thread;
    int32_t timer_run;
    int32_t contextid; 
    /* gst_player single, temp end */
    
} GstMediaPlayer;

static GstMediaPlayer* gst_player_instance[MAX_PLAYER_NUM] = {NULL};

/* gst_player single, temp begin */
#define  MAX_FPP_EVENTS_NUM  256

typedef struct fpp_cb_context_s
{
	pthread_t cb_thread;
	gboolean  task_running;

	u_int8_t		event_type[256];
	u_int64_t	p_event_num;
	u_int64_t	c_event_num;
}fpp_cb_context_t;

static fpp_cb_context_t  *fpp_cb_context = NULL;
/* gst_player single, temp end */

static int32_t gst_find_context(GstElement *bin)
{
    int32_t i;
    for(i=0; i<MAX_PLAYER_NUM; i++)
    {
        if(gst_player_instance[i] != NULL && 
            ( gst_player_instance[i]->playbin == bin || 
              gst_player_instance[i]->uridecodebin == bin ||
              gst_player_instance[i]->decodebin == bin) )
        {           
            return i;
        }
    }
    MMLOGI(TAG"%s(%d) can not find instance.\n", __func__, __LINE__);
    return MM_FAIL;
}

static int32_t gst_find_idle_player(GstMediaPlayer *context)
{
    int32_t i;
    for(i=0; i<MAX_PLAYER_NUM; i++)
    {
        if(gst_player_instance[i] == context)
            return i;
    }
    return MM_FAIL;
}

static void gst_media_context_reset(int32_t playerid)
{
    if(NULL != gst_player_instance[playerid])
    {
        gst_player_instance[playerid]->url_init = NULL;
        gst_player_instance[playerid]->openConfig = NULL;
        gst_player_instance[playerid]->pipeline = NULL;
        gst_player_instance[playerid]->playbin = NULL;
        gst_player_instance[playerid]->bus = NULL;
        gst_player_instance[playerid]->loop = NULL;
        gst_player_instance[playerid]->uridecodebin = NULL;
        gst_player_instance[playerid]->decodebin = NULL;
        gst_player_instance[playerid]->fppvdec = NULL;
        gst_player_instance[playerid]->fppadec = NULL;
        gst_player_instance[playerid]->cb = NULL;
        gst_player_instance[playerid]->duration = 0;
    }
}
static gboolean bus_call(GstBus * bus, GstMessage * msg, gpointer data)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    
    switch (GST_MESSAGE_TYPE (msg))
    {       
        case GST_MESSAGE_EOS:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MESSAGE_EOS ====\n", __func__, __LINE__);
            break;
        }
        case GST_MESSAGE_STATE_CHANGED:
        {                       
            MMLOGI(TAG"%s(%d) ==== GST_MESSAGE_STATE_CHANGED ====\n", __func__, __LINE__);
            break;           
        }
        case  GST_MESSAGE_ERROR:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MESSAGE_ERROR ====\n", __func__, __LINE__);
            break;
        }
#if 0
        /* gstreamer 1.7.1 中暂时未添加下述消息类型 */
        case GST_MEDIA_MSG_VIDEO_ONLY:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MEDIA_MSG_VIDEO_ONLY ====\n", __func__, __LINE__);
            break;
        }
        case GST_MEDIA_MSG_AUDIO_ONLY:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MEDIA_MSG_AUDIO_ONLY ====\n", __func__, __LINE__);
            break;
        }    
        case GST_MEDIA_MSG_HW_VIDEO_NO_SUPPORT:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MEDIA_MSG_HW_VIDEO_NO_SUPPORT ====\n", __func__, __LINE__);
            break;
        }
        case GST_MEDIA_MSG_HW_AUDIO_NO_SUPPORT:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MEDIA_MSG_HW_AUDIO_NO_SUPPORT ====\n", __func__, __LINE__);
            break;
        }
        case GST_MEDIA_MSG_CUSTOM_VIDEO_NO_SUPPORT:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MEDIA_MSG_CUSTOM_VIDEO_NO_SUPPORT ====\n", __func__, __LINE__);
            break;
        }
        case GST_MEDIA_MSG_CUSTOM_AUDIO_NO_SUPPORT:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MEDIA_MSG_CUSTOM_AUDIO_NO_SUPPORT ====\n", __func__, __LINE__);
            break; 
        }
#endif    
        case GST_MESSAGE_ASYNC_DONE:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MESSAGE_ASYNC_DONE ====\n", __func__, __LINE__);
            break;
        }
        case GST_MESSAGE_DURATION:
        {
            MMLOGI(TAG"%s(%d) ==== GST_MESSAGE_DURATION ====\n", __func__, __LINE__);            
            break;
        }          
        default:
            MMLOGI(TAG"%s(%d) ==== Message Type(%d) ====\n", __func__, __LINE__, GST_MESSAGE_TYPE (msg)); 
            break;
    }

    return TRUE;
}

static void playbin_element_added_cb(GstBin * bin, GstElement * element, gpointer data)
{   
    GstElementFactory *factory = gst_element_get_factory(element);
    const char *name = gst_element_factory_get_longname(factory);		
	MMLOGI (TAG"%s(%d) Get the element long name( %s ).\n", __func__, __LINE__, name);

    /* 多实例匹配 */
    int32_t id = gst_find_context((GstElement *)bin);

    if(id >= 0 && id < MAX_PLAYER_NUM)
    {
        char *short_name = NULL;
        short_name = gst_element_get_name(element);
        if(strstr (short_name, "fppvdec"))
        {
            gst_player_instance[id]->fppvdec = element;
            //MMLOGI (TAG"%s(%d) set the fppvdec fppinit property\n", __func__, __LINE__);
            //g_object_set (G_OBJECT (element), "fppinit", TRUE, NULL);
            MMLOGI (TAG"%s(%d) Get the fppvdec\n", __func__, __LINE__);
        }
        
        if(strstr (short_name, "fppadec"))
        {
            gst_player_instance[id]->fppadec = element;
            //MMLOGI (TAG"%s(%d) set the fppadec fppinit property\n", __func__, __LINE__);
            //g_object_set (G_OBJECT (element), "fppinit", TRUE, NULL);
            MMLOGI (TAG"%s(%d) Get the fppadec\n", __func__, __LINE__);
        }

        if(strstr (short_name, "decodebin"))
        {
            if(strstr (short_name, "uri"))
            {
                gst_player_instance[id]->uridecodebin = element;
                MMLOGI (TAG"%s(%d) Get the uridecodebin\n", __func__, __LINE__);  
            }
            else
            {
                gst_player_instance[id]->decodebin = element;
                MMLOGI (TAG"%s(%d) Get the decodebin\n", __func__, __LINE__);
            }
        }
        
#if 1
        /* 对于 BIN 类型的插件注册加载回调函数 */ 
        if(GST_IS_BIN(G_OBJECT(element)))
        {
            MMLOGI (TAG"%s(%d) the element: %s is a BIN element\n",  __func__, __LINE__, short_name);
            g_signal_connect (element, "element-added",G_CALLBACK (playbin_element_added_cb), element);
        } 
#endif 

        if(short_name)
        {
            g_free(short_name);
        }
    }
}

static void gst_fppmedia_set_status( u_int32_t u32decoderID, EN_FPP_DECODER_MODE_T en_mode_type,void * parameter)
{
	u_int32_t event_num = 0;
	fpp_cb_context_t  *cb_context = NULL;

	cb_context = fpp_cb_context;
	if(cb_context == NULL)
	{
        return;
	}
	
	event_num = cb_context->p_event_num%MAX_FPP_EVENTS_NUM;
	
	switch (en_mode_type)
	{
        case EN_FPP_DECODE_VIDEO_EOS:		
        case EN_FPP_DECODE_AUDIO_EOS:
        case EN_FPP_DECODE_AUDIO_UNSUPPORT:
        case EN_FPP_DECODE_VIDEO_UNSUPPORT: 
        case EN_FPP_DECODE_AUDIO_DATA_ERRO:
        case EN_FPP_DECODE_VIDEO_DATA_ERRO:
		case EN_FPP_DECODE_FRIST_IFRAME: 
        case EN_FPP_DECODE_VIDEO_NORMAL:
        case EN_FPP_DECODE_AUDIO_NORMAL:
		case EN_FPP_DECODE_AFD_CHANGE:
			MMLOGI("[%s---%d]---en_mode_type=%d,p_event_num=%lld\n",__func__,__LINE__,en_mode_type,cb_context->p_event_num);
			cb_context->event_type[event_num]= en_mode_type;
			cb_context->p_event_num++;
			break;
		case EN_FPP_DECODE_BUFFERING:
        case EN_FPP_DECODE_BUFFER_OK:
        case EN_FPP_DECODE_AV_SYNC_DONE:
			if(u32decoderID == EN_FPP_VIDEO_DECODER)
			{
				MMLOGI("[%s---%d]---en_mode_type=%d,p_event_num=%lld\n",__func__,__LINE__,en_mode_type,cb_context->p_event_num);
				cb_context->event_type[event_num]= en_mode_type;
				cb_context->p_event_num++;
			}
            break;
        default:
            break;
    }
}

static int32_t gst_create_pipeline(int32_t playerid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);

    /* pipeline */
    if(gst_player_instance[playerid]->pipeline != NULL || gst_player_instance[playerid]->playbin != NULL)
    {
        MMLOGI(TAG"%s(%d) error:media is playing, can't play any more!\n", __func__, __LINE__);
        return  MM_FAIL;
    }

    GstElement *player = gst_pipeline_new ("gstPlayer");
    if(NULL == player)
    {
        MMLOGI(TAG"%s(%d) error:gst_pipeline_new failed.\n", __func__, __LINE__);
    }
    GstElement *bin = gst_element_factory_make ("playbin", "gstPlaybin");
    if(NULL == bin)
    {
        MMLOGI(TAG"%s(%d) error:gst_element_factory_make(playbin) failed.\n", __func__, __LINE__);
    }
    gst_bin_add (GST_BIN (player), bin);

    GstBus *bus;
    bus = gst_pipeline_get_bus (GST_PIPELINE (player));
    if(NULL == bus)
    {
        MMLOGI(TAG"%s(%d) error:gst_pipeline_get_bus failed.\n", __func__, __LINE__);
    }
    GMainLoop *loop = g_main_loop_new (NULL, FALSE);
    if(NULL == loop)
    {
        MMLOGI(TAG"%s(%d) error:g_main_loop_new failed.\n", __func__, __LINE__);
    }
    gst_bus_add_watch (bus, bus_call, loop);
    gst_object_unref (bus);

    gst_player_instance[playerid]->pipeline = player;
    gst_player_instance[playerid]->playbin = bin;
    gst_player_instance[playerid]->bus = bus;
    gst_player_instance[playerid]->loop = loop;

    //playbin 作为bin所具备的signal
    g_signal_connect (bin, "element-added",G_CALLBACK (playbin_element_added_cb), bin);

    int64_t font_color = 0xFFFFFF00;
    g_object_set (G_OBJECT (bin), "uri", gst_player_instance[playerid]->url_init, NULL);
    g_object_set (G_OBJECT (bin), "color", font_color, NULL);
    g_object_set (G_OBJECT (bin), "buffer-duration", 30*GST_SECOND, NULL);
    g_object_set (G_OBJECT (bin), "buffer-size", (gint)500*1024, NULL);
    
    if(NULL != gst_player_instance[playerid]->openConfig)
	{
		media_open_config_s *pConfig = gst_player_instance[playerid]->openConfig;
        MMLOGI(TAG"%s(%d) the pConfig->pre_lang = %s \n", __func__, __LINE__, pConfig->pre_lang);
		MMLOGI(TAG"%s(%d) the pConfig->AudioDescription = %d \n", __func__, __LINE__, pConfig->AudioDescription);
        g_object_set (G_OBJECT (bin), "audio-description", pConfig->AudioDescription, NULL);
        g_object_set (G_OBJECT (bin), "audio-language", pConfig->pre_lang, NULL);
	}

    /* gst_player single, temp */
    if(MM_SUCCESS == fpp_mc_decode_initialize())
    {
        MMLOGI(TAG"%s(%d) media decode init ok\n", __func__, __LINE__);
    }

    fpp_cb_context_t  *cb_context = NULL;
    cb_context = (fpp_cb_context_t*)malloc(sizeof(fpp_cb_context_t));
	if(cb_context == NULL)
	{
	    MMLOGI(TAG"%s(%d) error:no enough memory.\n", __func__, __LINE__);
		return MM_FAIL;
	}
    fpp_cb_context = cb_context;
    memset(cb_context->event_type,0xFF,sizeof(cb_context->event_type));
	cb_context->p_event_num = 0;
	cb_context->c_event_num = 0;
	cb_context->task_running = TRUE;
    
    if(MM_SUCCESS == fpp_mc_decode_register_callback(gst_fppmedia_set_status))
    {
        MMLOGI(TAG"%s(%d) register callback ok\n", __func__, __LINE__);
    }
    /* gst_player single, temp */

    if(player)
    {
        gst_element_set_state(player, GST_STATE_PAUSED);
        MMLOGI (TAG"%s(%d) setting to GST_STATE_PAUSED for container info.\n", __func__, __LINE__);
    }
    
    return MM_SUCCESS;
}

int32_t gst_media_init(int32_t *playerid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    if(!fpp_mc_init())
    {
        MMLOGI(TAG"%s(%d) fpp_mc_init fail.\n", __func__, __LINE__);
        return MM_FAIL;
    }
    
    GstMediaPlayer *gstPlayer = (GstMediaPlayer *)malloc(sizeof(GstMediaPlayer));
    if(NULL == gstPlayer)
    {
        MMLOGI(TAG"%s(%d) error:no enough memory.\n", __func__, __LINE__);
        return MM_FAIL;
    }
    
    int32_t id=-1;
    id = gst_find_idle_player(NULL);
    if(id<0)
    {
        MMLOGI(TAG"%s(%d) error:can't find idle player.\n", __func__, __LINE__);
        free(gstPlayer);
        gstPlayer = NULL;
        return MM_FAIL;
    }
    
    gstPlayer->url_init = NULL;
    gstPlayer->openConfig = NULL;
    gstPlayer->pipeline = NULL;
    gstPlayer->playbin = NULL;
    gstPlayer->bus = NULL;
    gstPlayer->loop = NULL;
    gstPlayer->cb = NULL;
    gstPlayer->uridecodebin = NULL;
    gstPlayer->decodebin = NULL;
    gstPlayer->fppvdec = NULL;
    gstPlayer->fppadec = NULL;
    gstPlayer->duration = 0;
    
    gstPlayer->last_msg = -1;
    gstPlayer->state = 0;
    gstPlayer->timeout_thread = 0;
    gstPlayer->timer_run = 1;
    gstPlayer->network_error_flag = FALSE;    
    gst_player_instance[id]=gstPlayer;

    *playerid = id;
    return MM_SUCCESS;
}

int32_t gst_media_open(int32_t playerid, int8_t *uri, media_open_config_s* openConfig)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);

    if(NULL == uri)
    {
        MMLOGI(TAG"%s(%d) the media file path( NULL ).\n", __func__, __LINE__);
        return MM_FAIL;
    }

    if(NULL != openConfig)
    {
        MMLOGI(TAG"%s(%d) the openConfig->pre_lang( %s ) \n", __func__, __LINE__, openConfig->pre_lang);
    }

    gst_player_instance[playerid]->url_init = (int8_t *)malloc(sizeof(int8_t)*strlen((const char*)uri)+1);
    if(NULL == gst_player_instance[playerid]->url_init)
    {
        MMLOGI(TAG"%s(%d) error:no enough memory.\n", __func__, __LINE__);
        return MM_FAIL;
    }    
    strcpy((char *)(gst_player_instance[playerid]->url_init), (const char*)uri);
    MMLOGI(TAG"%s(%d) the media file path( %s ).\n", __func__, __LINE__, gst_player_instance[playerid]->url_init);

    if(NULL != openConfig)
    {
        gst_player_instance[playerid]->openConfig = (media_open_config_s *)malloc(sizeof(media_open_config_s));
        if(NULL == gst_player_instance[playerid]->openConfig)
        {
            MMLOGI(TAG"%s(%d) error:no enough memory.\n", __func__, __LINE__);
            return MM_FAIL;
        }
        memcpy(gst_player_instance[playerid]->openConfig, openConfig, sizeof(media_open_config_s));
    }
    
    if(MM_SUCCESS != gst_create_pipeline(playerid))
    {
        MMLOGI(TAG"%s(%d) gst_create_pipeline failed.\n", __func__, __LINE__);
        return MM_FAIL;
    }
    
    return MM_SUCCESS;
}

int32_t gst_media_close(int32_t playerid)
{	
    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }
    GstElement *player = gst_player_instance[playerid]->pipeline;

    /* gst_player single, temp */
    if(MM_SUCCESS == fpp_mc_decode_deinitialize())
    {
        MMLOGI(TAG"%s(%d) media decode deinit ok\n", __func__, __LINE__);
    }

    if(fpp_cb_context)
        free(fpp_cb_context);
    fpp_cb_context = NULL;
    /* gst_player single, temp */

    if(NULL != gst_player_instance[playerid]->url_init)
        free(gst_player_instance[playerid]->url_init);

    if(NULL != gst_player_instance[playerid]->openConfig)
        free(gst_player_instance[playerid]->openConfig);

    if(NULL != gst_player_instance[playerid]->loop)
        g_main_loop_quit(gst_player_instance[playerid]->loop);
 
    if(NULL != gst_player_instance[playerid]->pipeline)
        gst_object_unref(GST_OBJECT(player));

    gst_media_context_reset(playerid);
    free(gst_player_instance[playerid]);
    gst_player_instance[playerid] = NULL;
    return MM_SUCCESS;
}

int32_t gst_media_play(int32_t playerid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);

    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }

    GstElement *player = gst_player_instance[playerid]->pipeline;
	GstElementFactory *factory = gst_element_get_factory(player);
	const char *name = gst_element_factory_get_longname(factory);
	const char *elementname=gst_element_get_name(player);
	GST_DEBUG_BIN_TO_DOT_FILE(GST_BIN(player), GST_DEBUG_GRAPH_SHOW_ALL, "gstPlayer");
    MMLOGI (TAG"%s(%d) Get the element name( %s )( %s ).\n", __func__, __LINE__,name, elementname);

    GstStateChangeReturn ret = GST_STATE_CHANGE_FAILURE;
    ret = gst_element_set_state(player, GST_STATE_PLAYING);
    if (GST_STATE_CHANGE_FAILURE == ret)
    {
        MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_PLAYING failed.\n", __func__, __LINE__);
        return  MM_FAIL;
    }
    else
        MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_PLAYING success.\n", __func__, __LINE__);
    
    return MM_SUCCESS;
}

int32_t gst_media_seek(int32_t playerid, int64_t time)
{
    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }

    GstElement *player = gst_player_instance[playerid]->pipeline;
    gboolean ret = FALSE;
    gdouble rate = 1.0;

    if(rate<0)//backward
    {
        ret = gst_element_seek( player,
                                rate, 
                                GST_FORMAT_TIME,
                                GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT | GST_SEEK_FLAG_SKIP,
                                GST_SEEK_TYPE_NONE,
                                GST_CLOCK_TIME_NONE,
                                GST_SEEK_TYPE_SET, 
                                time*1000000 );
    }
    else//forward
    {
        ret = gst_element_seek( player, 
                                rate, 
                                GST_FORMAT_TIME,
                                GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT | GST_SEEK_FLAG_SKIP,
                                GST_SEEK_TYPE_SET, 
                                time*1000000,
                                GST_SEEK_TYPE_NONE,
                                GST_CLOCK_TIME_NONE );
    }
    
    if(ret)
    {
        MMLOGI(TAG"%s(%d) seek to time( %lld )ms success\n", __func__, __LINE__, time);
        return MM_SUCCESS;    
    }
    else
    {
        MMLOGI(TAG"%s(%d) seek to time( %lld ) failed\n", __func__, __LINE__, time);
        return MM_FAIL;
    }
}

int32_t gst_media_pause(int32_t playerid)
{
    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }

    /* gst_player single, temp */
    MMLOGI (TAG"%s(%d) pause the fpp decoder directly.\n", __func__, __LINE__);
    if(gst_player_instance[playerid]->fppadec || gst_player_instance[playerid]->fppvdec)
        fpp_mc_decode_pause();
    /* gst_player single, temp */
    
    GstElement *player = gst_player_instance[playerid]->pipeline;
    GstStateChangeReturn ret = GST_STATE_CHANGE_FAILURE;
    ret = gst_element_set_state(player, GST_STATE_PAUSED);
    if (GST_STATE_CHANGE_FAILURE == ret)
    {
        MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_PAUSED failed.\n", __func__, __LINE__);
        return  MM_FAIL;
    }
    else
        MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_PAUSED success.\n", __func__, __LINE__);

    return MM_SUCCESS;
}

int32_t gst_media_resume(int32_t playerid)
{
    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }

    /* gst_player single, temp */
    MMLOGI (TAG"%s(%d) resume the fpp decoder directly.\n", __func__, __LINE__);
    if(gst_player_instance[playerid]->fppadec || gst_player_instance[playerid]->fppvdec)
        fpp_mc_decode_resume();
    /* gst_player single, temp */
    
    GstElement *player = gst_player_instance[playerid]->pipeline;
    GstStateChangeReturn ret = GST_STATE_CHANGE_FAILURE;
    ret = gst_element_set_state(player, GST_STATE_PLAYING);
    if (GST_STATE_CHANGE_FAILURE == ret)
    {
        MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_PLAYING failed.\n", __func__, __LINE__);
        return  MM_FAIL;
    }
    else
        MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_PLAYING success.\n", __func__, __LINE__);

    return MM_SUCCESS; 
}

int32_t gst_media_stop(int32_t playerid)
{
    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }

    GstElement *player = gst_player_instance[playerid]->pipeline;
    if(player)
    {
        GstState play_state = GST_STATE_VOID_PENDING;
        GstState play_state_pending = GST_STATE_VOID_PENDING;
        gst_element_get_state(player, &play_state, &play_state_pending, 0);
        MMLOGI(TAG"%s(%d) play_state=%d, play_state_pending=%d\n", __FUNCTION__, __LINE__, play_state, play_state_pending);

        GstStateChangeReturn ret = GST_STATE_CHANGE_FAILURE;
        ret = gst_element_set_state(player, GST_STATE_NULL);
        if (GST_STATE_CHANGE_FAILURE == ret)
        {
            MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_NULL failed.\n", __func__, __LINE__);
            return  MM_FAIL;
        }
        else
            MMLOGI (TAG"%s(%d) set the pipeline to GST_STATE_NULL success.\n", __func__, __LINE__);
    }

    return MM_SUCCESS;
}

int64_t gst_media_getPts(int32_t playerid)
{
    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }

    GstElement *player = gst_player_instance[playerid]->pipeline;
    gint64 position_ms = 0;
    gint64 position_ns = 0;
    GstFormat fmt = GST_FORMAT_TIME;
    if (gst_element_query_position(player, fmt, &position_ns))
    {
        position_ms = (gint64)(position_ns * 0.000001);
        MMLOGI(TAG"%s(%d) get pts success, pts( %lld )ms\n", __func__, __LINE__, position_ms);
    }
    else
    {
        MMLOGI(TAG"%s(%d) get pts failed, default pts( %lld )ms\n", __func__, __LINE__, position_ms);
    }
 
    return position_ms;

}

int64_t gst_media_getduration(int32_t playerid, int8_t *fileuri)
{
    /* check the pipeline */
    if(NULL == gst_player_instance[playerid]->pipeline)
    {
        MMLOGI(TAG"%s(%d) error:pipeline of gst_player_instance[%d] is NULL, can't play any more!\n", __func__, __LINE__, playerid);
        return  MM_FAIL;
    }

    GstElement *player = gst_player_instance[playerid]->pipeline;
    gint64 duration_ms = 0;
    gint64 duration_ns = 0;
    GstFormat fmt = GST_FORMAT_TIME;
    if (gst_element_query_duration(player, fmt, &duration_ns))
    {
        duration_ms = (gint64)(duration_ns * 0.000001);
        gst_player_instance[playerid]->duration = duration_ms;
        MMLOGI(TAG"%s(%d) get duration success, duration( %lld )ms\n", __func__, __LINE__, duration_ms);
    }
    else
    {
        MMLOGI(TAG"%s(%d) get duration failed, default duration( %lld )ms\n", __func__, __LINE__, duration_ms);
    }
 
    return duration_ms; 
}

int32_t gst_media_forward(int32_t playerid, int32_t speed)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_media_backward(int32_t playerid, int32_t speed)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_media_slow_motionon(int32_t playerid, float speed)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t  gst_media_gettracknum(int32_t playerid, media_stream_info_s* pInfo)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_media_getVideoResolution()
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t  gst_media_settrack(int32_t playerid, int32_t  trackid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t  gst_video_setdisplay(int32_t playerid, int32_t origin_x, int32_t origin_y,
                           int32_t width, int32_t height)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_getid3info(int32_t playerid, int8_t* filepath, gst_id3info* id3info)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_get_cover(int32_t playerid, int8_t* filepath, int8_t* imagepath)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_video_getthumbnail(int32_t playerid, int8_t* filepath, int8_t* dfilepath, int64_t time, int32_t width, int32_t height)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_subtitles_get_embedded_tracks(int32_t playerid, media_stream_info_s* pInfo)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}



int32_t gst_subtitles_settrack (int32_t playerid, int32_t subid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_media_set_hw_mode (int32_t playerid, int32_t flag)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_media_getcurtrack(int32_t playerid, int32_t *trackid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_subtitles_getcurtrack(int32_t playerid, int32_t *trackid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}



int32_t gst_RegisterCallback(int32_t playerid, MM_PLAYER_CB FuncProc)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);

    /* 本函数仅保存上传注册下来的callback函数，供gstreamer管道监听函数依据playerid进行调用 */
    gst_player_instance[playerid]->cb = FuncProc;
    return MM_SUCCESS; 
}

int32_t gst_media_uninit(int32_t playerid)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);

    /* 进行逆初始化过程 */

    /* 释放本层资源 */
    free(gst_player_instance[playerid]);
    gst_player_instance[playerid] = NULL;

    return MM_SUCCESS; 	
}



int32_t gst_media_set_buffer_threshold(int32_t playerid, FPI_enParaType type, int32_t para)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_media_get_buffer_threshold(int32_t playerid, FPI_enParaType type)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

int32_t gst_media_set_userconfig(int32_t playerid, media_user_config_s *userConfig)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

/*
static int32_t open_input_file(const int8_t *filename)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

static int32_t open_output_file(const int8_t *filename, int32_t width, int32_t height)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

static int32_t init_filter(FilteringContext* fctx, AVCodecContext *dec_ctx,
        AVCodecContext *enc_ctx, const int8_t *filter_spec, int32_t out_width, int32_t out_height)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

static int32_t init_filters(int32_t out_width, int32_t out_height)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

static int32_t encode_write_frame(AVFrame *filt_frame, u_int32_t stream_index, int32_t *got_frame) 
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}

static int32_t filter_encode_write_frame(AVFrame *frame, u_int32_t stream_index)
{
    MMLOGI(TAG"%s(%d) begin.\n", __func__, __LINE__);
    return MM_SUCCESS; 
}
*/

MultiMediaPlayerInterface gst_player =
{
	.init = gst_media_init,
	.registerCallback = gst_RegisterCallback,
	.uninit = gst_media_uninit,
    .open = gst_media_open,
    .play = gst_media_play,
    .pause = gst_media_pause,
    .resume = gst_media_resume,
    .forward = gst_media_forward,
    .backward = gst_media_backward,
    .slowMotionon = gst_media_slow_motionon,
    .seek = gst_media_seek,
    .stop = gst_media_stop,
    .close = gst_media_close,    
    .getPts = gst_media_getPts,
    .getDuration = gst_media_getduration,
    .setDisplaywindow = gst_video_setdisplay,
    .getVideoResolution = gst_media_getVideoResolution,    
    .getId3info = gst_getid3info,
    .getCover = gst_get_cover,
    .getThumbnail = gst_video_getthumbnail,    
    .getAudiotrackinfo = gst_media_gettracknum,
    .setAudiotrack = gst_media_settrack,
    .getAudiocurtrack = gst_media_getcurtrack,     
    .getSubtitlestrackinfo = gst_subtitles_get_embedded_tracks,
    .setSubtitlestrack = gst_subtitles_settrack,
    .getSubtitlescurtrack = gst_subtitles_getcurtrack,    
    .setBufferthreshold = gst_media_set_buffer_threshold,
    .getBufferthreshold = gst_media_get_buffer_threshold,
    .setUserconfig = gst_media_set_userconfig,    
};
