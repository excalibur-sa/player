#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "fpi_mediaplayer.h"
#include "mm_media_type.h"
#include "mm_base_type.h"
#include "mm_player_proxy.h"

#define TAG "MEDIA_TEST:"


#define MAP_SIZE 	37

typedef void (*FUNC)(tp_handle_t handle);
typedef struct
{
	int8_t name[128];
	FUNC func;
}FUNC_MAP_S;

typedef struct Client_Context
{
	tp_handle_t g_handle;
	int8_t g_url[256];
}Client_Context;

Client_Context *Context[MAX_PLAYER_NUM]={NULL};

int32_t find_idle_player(Client_Context *context)
{
    int32_t i;

    for(i=0; i<MAX_PLAYER_NUM; i++)
    {
        if (Context[i] == context)
            return i;
    }

    return -1;
}
int32_t  tcp_player_event_proc(tp_event_t eventType,u_int8_t *data,void *user_data);


int32_t test_func_create()
{
	int32_t ret=-1;
	int32_t player_type=-1;
	printf("Please input:  player type (0-gst player,1-ffmpeg player,default-gst player)\n");
	
	scanf("%d",&player_type);
	
	int32_t id=-1;
	id=find_idle_player(NULL);
	if(id==-1)
	{
		printf("find idle player fail!");
	}
	Context[id]=(Client_Context *)malloc(sizeof(Client_Context));
	
    switch(player_type)
    {
        case 0:
        	printf(TAG"%s MSG_GST_PLAYER\n", __func__);
        	ret = fpi_mediaplayer_init(&Context[id]->g_handle, GST_PLAYER);             
            break;
        case 1:
             printf(TAG"%s MSG_FFMPEG_PLAYER\n", __func__);
             ret = fpi_mediaplayer_init(&Context[id]->g_handle, FFMPEG_PLAYER);
             break;
        default:
             printf(TAG"%s MSG_GST_PLAYER\n", __func__);
             ret = fpi_mediaplayer_init(&Context[id]->g_handle, GST_PLAYER);
             break;
     }
	 if(ret==MM_FAIL)
	 {
	 	printf(TAG"%s init FAIL \n", __func__);
		return MM_FAIL;
	 }
	 
	fpi_mediaplayer_registerCallback(Context[id]->g_handle, tcp_player_event_proc, NULL);
  	printf(TAG"%s init success(0x%x)\n", __func__, Context[id]->g_handle);
  if( MM_SUCCESS == fpi_mediaplayer_register_MonitorCallback(Context[id]->g_handle, NULL))
  printf(TAG"%s fpi_mediaplayer_register_MonitorCallback success(handle=0x%x,id=%d)\n", __func__, Context[id]->g_handle,id);
 	return id;
  
}

void test_func_open(tp_handle_t handle)
{
    int8_t buff[256];
    int8_t *pStr=buff;
    int32_t ret=-1;
	
      while(1)
	{		
		printf(TAG"please input file path>>:");
		fflush(stdout);
		gets((char*)pStr);
		ret = strlen((const char*)pStr);
		if (ret <=0)
			continue;
        else
            break;
      }
    
 //   memcpy(pStr,"file:///test",sizeof("file:///test"));
	int32_t i=0;
	for(i=0;i<MAX_PLAYER_NUM;i++)
	{
		if(Context[i]!=NULL)
		{
			if(Context[i]->g_handle==handle)
				break;
		}
	}
	memset(Context[i]->g_url, 0, sizeof(Context[i]->g_url));
    memcpy(Context[i]->g_url, pStr, strlen((const char*)pStr));

	ret = fpi_mediaplayer_open(handle, Context[i]->g_url, NULL);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
	}
}

void test_func_close(tp_handle_t handle)
{
	int32_t ret;
	ret = fpi_mediaplayer_close(handle);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
	}
}

void test_func_play(tp_handle_t handle)
{
	int32_t ret;
	ret = fpi_mediaplayer_play(handle);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
	}
}

void test_func_stop(tp_handle_t handle)
{
	int32_t ret;
	ret = fpi_mediaplayer_stop(handle);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
	}
}

void test_func_getstate(tp_handle_t handle)
{
	int32_t ret;
	tp_state_t state;
    ret = fpi_mediaplayer_getState(handle, &state);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
	}
    printf(TAG"fpi_mediaplayer_getState state=%d\n", state);
}

void test_func_pause(tp_handle_t handle)
{
	int32_t ret;
	ret = fpi_mediaplayer_pause(handle); 
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
	}
}

void test_func_resume(tp_handle_t handle)
{
	int32_t ret;
	ret = fpi_mediaplayer_resume(handle); 
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
	}
}

void test_func_setvideowindow(tp_handle_t handle)
{
	int32_t ret;
	printf(TAG"the parameter to choose:\n");
	printf(TAG"\t window 0:input the window\n");	
	printf(TAG"\t window 1:(0,0,400,300)\n");
	printf(TAG"\t window 2:(0,0,500,500)\n");
	printf(TAG"\t window 3:(0,0,1366,768)\n");

	printf(TAG"please select(1 or 2):");
	int32_t choose_num=3;
    //scanf("%d", &choose_num);
    printf(TAG"select(%d)\n", choose_num);

	tp_rect_t win0,win1,win2,win3;
	win1.origin_x = 0;
	win1.origin_y = 0;
	win1.width 	  = 400;
	win1.height   = 300;

	win2.origin_x = 100;
	win2.origin_y = 100;
	win2.width    = 500;
	win2.height   = 500;

	win3.origin_x = 0;
	win3.origin_y = 0;
	win3.width    = 1366;
	win3.height   = 768;

	if(choose_num == 0)
	{
		printf(TAG"the origin_x,origin_y,width,height:");
		scanf("%d,%d,%d,%d", &(win0.origin_x),&(win0.origin_y),&(win0.width),&(win0.height));
		printf(TAG"\n\n");
		
		ret = fpi_mediaplayer_setVideoWindow(handle,&win0);
		if (ret==MM_FAIL)
		{
		    printf(TAG"%s failed\n",__func__);
			return;
		}
		else
			printf(TAG"%s success\n",__func__);
	}

	//int32_t fpi_mediaplayer_setVideoWindow(tp_handle_t handle,tp_rect_t *rect)
	if(choose_num == 3)
	{
	    ret = fpi_mediaplayer_setVideoWindow(handle,&win3);
		if (ret==MM_FAIL)
		{
		    printf(TAG"%s failed\n",__func__);
			return;
		}
		else
			printf(TAG"%s success\n",__func__);
	}
	
	if(choose_num == 1)
	{
	    ret = fpi_mediaplayer_setVideoWindow(handle,&win1);
		if (ret==MM_FAIL)
		{
		    printf(TAG"%s failed\n",__func__);
			return;
		}
		else
			printf(TAG"%s success\n",__func__);
	}

	if(choose_num == 2)
	{
	    ret = fpi_mediaplayer_setVideoWindow(handle,&win2);
		if (ret==MM_FAIL)
		{
		    printf(TAG"%s failed\n",__func__);
			return;
		}
		else
			printf(TAG"%s success\n",__func__);

	}	
}

void test_func_getvthumnail(tp_handle_t handle)
{
	int32_t ret;

    int8_t buff0[256];
    int8_t *filepath=buff0;
    
    while(1)
	{		
		printf(TAG"please input file path>>:");
		fflush(stdout);
		gets((char*)filepath);
		ret = strlen((const char*)filepath);
		if (ret <=0)
			continue;
        else
            break;
    }
    
//	 memcpy(filepath,"file:///testthumnail",sizeof("file:///testthumnail"));
    int8_t dsturl[512];
	int8_t name[64];
	memset(dsturl,0, sizeof(dsturl));
	
	printf(TAG"Please input outfilename:");
    scanf("%s", &name);
    
 //   memcpy(name,"vthumnail",10);
    sprintf((char*)dsturl, "/data/%s.png", (char*)name);
    int32_t time=0;;
    printf(TAG" dstrul=%s\n   Please input time:", dsturl);
    scanf("%d", &time);          
    ret = fpi_mediaplayer_get_thumbnail(handle,filepath, dsturl, time, 100, 100);
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
		return;
	}
    printf(TAG"fpi_mediaplayer_get_video_thumbnail(time=%d,dsturl=%s)\n",time, dsturl);
}

void test_func_getpicthumnail(tp_handle_t handle)
{
	int32_t ret;
	int8_t url[512];
    int8_t dsturl[512];
	int8_t name[64];
	memset(dsturl,0, sizeof(dsturl));
	printf(TAG"Please input outfilename:");
    //scanf("%s", &name);
   memcpy(name,"picthumnail",12);
    sprintf((char*)dsturl, "/data/%s.png", (char*)name);
     int32_t i=0;
	for(i=0;i<MAX_PLAYER_NUM;i++)
	{
		if(Context[i]!=NULL)
		{
			if(Context[i]->g_handle==handle)
				break;
		}
	}   
	ret = fpi_mediaplayer_get_thumbnail(handle,Context[i]->g_url, dsturl, 0, 100, 100);
	if (ret==MM_FAIL)
	{
	    printf(TAG"%s failed\n",__func__);
		return;
	}
    printf(TAG"fpi_mediaplayer_get_pic_thumbnail(dsturl=%s)\n", dsturl);
}


void test_func_get_sub_track_info(tp_handle_t handle)
{
	int32_t ret, i;
	int32_t trackNum=0;
	media_stream_info_s info;
	memset(&info, 0, sizeof(media_stream_info_s));
	for(i=0;i<MAX_PLAYER_NUM;i++)
	{
		if(Context[i]!=NULL)
		{
			if(Context[i]->g_handle==handle)
				break;
		}
	}
    ret = fpi_mediaplayer_subtitles_get_embedded_tracks(handle, &info);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_play failed\n");
		return;
	}
	//trackNum = info.nb_streams;
	trackNum=0;
    printf(TAG"get_embedded_tracks nums=%d\n", trackNum);
	for (i=0; i<trackNum;i++)
		if (strlen((const char*)info.st_info_nodes[i].language)>0)
			printf(TAG"	%d:%s\n", i, info.st_info_nodes[i].language);
}

void test_func_get_track_info(tp_handle_t handle)
{
	int32_t ret,i;
	int32_t trackNum=0;
	media_stream_info_s info;
	memset(&info, 0, sizeof(media_stream_info_s));
	for(i=0;i<MAX_PLAYER_NUM;i++)
	{
		if(Context[i]!=NULL)
		{
			if(Context[i]->g_handle==handle)
				break;
		}
	}
    ret =fpi_mediaplayer_audio_get_track_info(handle, &info);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_audio_get_track_info failed\n");
		return;
	}

	trackNum = info.nb_streams;
    printf(TAG"get_audio_track_nums=%d\n", trackNum);
	for (i=0; i<trackNum;i++)
		printf(TAG"	%d:%s\n", i, info.st_info_nodes[i].language);
}


void test_func_set_sub_track(tp_handle_t handle)
{
	int32_t ret;
	int32_t trackNum=0;
	printf(TAG"Please input sub track:");
    //scanf("%d", &trackNum);
    ret = fpi_mediaplayer_subtitles_set_track(handle, trackNum);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_subtitles_set_track failed\n");
		return;
	}

    printf(TAG"set_embedded_tracks nums=%d\n", trackNum);
}

void test_func_set_audio_track(tp_handle_t handle)
{
	int32_t ret;
	int32_t trackNum=0;
	printf(TAG"Please input audio track:");
    //scanf("%d", &trackNum);
    //int32_t fpi_mediaplayer_set_track(tp_handle_t handle,int32_t  trackid)
    ret = fpi_mediaplayer_set_track(handle, trackNum);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_set_track failed\n");
		return;
	}

    printf(TAG"set_embedded_tracks nums=%d\n", trackNum);
}

void test_func_get_cur_sub_track(tp_handle_t handle)
{
	int32_t ret;
	int32_t trackNum=0;
    ret = fpi_mediaplayer_subtitles_get_cur_track(handle, &trackNum);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_subtitles_get_cur_tracks failed\n");
		return;
	}

    printf(TAG"get_cur_embedded_tracks nums=%d\n", trackNum);
}


void test_func_get_duration(tp_handle_t handle)
{
	int32_t ret;
	int64_t durtion;
	int32_t i=0;
	for(i=0;i<MAX_PLAYER_NUM;i++)
	{
		if(Context[i]!=NULL)
		{
			if(Context[i]->g_handle==handle)
				break;
		}
	}
    ret = fpi_mediaplayer_getDuration(handle,Context[i]->g_url, &durtion);
	 if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_getDuration failed\n");
		return;
	}
    printf(TAG"fpi_mediaplayer_getDuration(durtion=%lld)\n", durtion/1000);
}


void test_func_get_postion(tp_handle_t handle)
{
	int32_t ret;
	int64_t time;
	ret = fpi_mediaplayer_getPosition(handle, &time);
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_getPosition failed\n");
		return;
	}
    printf(TAG"fpi_mediaplayer_getPosition(time=%llu)\n", time/1000);
}




void test_func_seek(tp_handle_t handle)
{
	int32_t ret;
	int32_t time=0;
	printf(TAG"Please input seek time(ms):");
    scanf("%d", &time);
    ret = fpi_mediaplayer_seek(handle, time);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_seek failed\n");
		return;
	}

    printf(TAG"fpi_mediaplayer_seek time=%d\n", time);
}
void test_func_set_useragent(tp_handle_t handle)
{
	int32_t ret = MM_FAIL;
	char* useragent = "useragent:http://drm.tv.ipla.pl/wmdrm/License.ashx";
	//ret = fpi_mediaplayer_set_useragent(handle, useragent,MSG_DRM_UA);
	if (ret==MM_FAIL)
	{
	    printf(TAG"test_func_set_useragent failed\n");
		return;
	}

    printf(TAG"test_func_set_useragent success!\n");
}

void test_func_slowbk(tp_handle_t handle)
{
	int32_t ret;
	int32_t speed=0;
	printf(TAG"Please input backward speed(0.5 only):FIXME!!!");
    //scanf("%d", &speed);
	
	//int32_t fpi_mediaplayer_backward(tp_handle_t handle,int32_t speed);
    ret = fpi_mediaplayer_backward(handle, speed);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_backward failed\n");
		return;
	}

    printf(TAG"fpi_mediaplayer_backward ok\n");
}

void test_func_slowfw(tp_handle_t handle)
{
	int32_t ret;
	float speed=0;
	printf(TAG"Please input slow_motion speed(0.5 only):");
  // scanf("%f", &speed);
	
	//int32_t fpi_mediaplayer_slow_motion_on(tp_handle_t handle,float speed);
    ret = fpi_mediaplayer_slow_motion_on(handle, speed);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_slow_motion_on failed\n");
		return;
	}

    printf(TAG"fpi_mediaplayer_slow_motion_on ok\n");
}

void test_func_fastbk(tp_handle_t handle)
{
	int32_t ret;
	int32_t speed=0;
	printf(TAG"Please input fast backward speed(2/4/8/16/32):");
   // scanf("%d", &speed);
	
	//int32_t fpi_mediaplayer_backward(tp_handle_t handle,int32_t speed);
    ret = fpi_mediaplayer_backward(handle, speed);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_backward failed\n");
		return;
	}

    printf(TAG"fpi_mediaplayer_backward ok\n");
}

void test_func_fastfw(tp_handle_t handle)
{
	int32_t ret;
	int32_t speed=0;
	printf(TAG"Please input fast forward speed(2/4/8/16/32):");
  //  scanf("%d", &speed);
	
	//int32_t fpi_mediaplayer_forward(tp_handle_t handle,int32_t speed);
    ret = fpi_mediaplayer_forward(handle, speed);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_forward failed\n");
		return;
	}

    printf(TAG"fpi_mediaplayer_forward ok\n");
}



void test_func_get_subtitles_embedded_tracks(tp_handle_t handle)
{
	int32_t ret,i;
	int32_t test_subtitles=0;
	media_stream_info_s info;
	memset(&info, 0, sizeof(media_stream_info_s));
	for(i=0;i<MAX_PLAYER_NUM;i++)
	{
		if(Context[i]!=NULL)
		{
			if(Context[i]->g_handle==handle)
				break;
		}
	}
    ret = fpi_mediaplayer_subtitles_get_embedded_tracks(handle, &info);   
	if (ret==MM_FAIL)
	{
	    printf(TAG"fpi_mediaplayer_subtitles_get_embedded_tracks failed\n");
		return;
	}
#if 0
	test_subtitles = info.nb_streams;
    printf(TAG"hebinhan  test_subtitles=%d\n", test_subtitles);
	for(i = 0 ; i < test_subtitles; i++)
	{
		printf(TAG"st_info_nodes[%d]: channel = %d ,isSupported = %d,strStreamName = %s, strCodecName = %s, language = %s\n ",
			info.st_info_nodes[i].channels,info.st_info_nodes[i].isSupported,info.st_info_nodes[i].strStreamName,
			info.st_info_nodes[i].strCodecName,info.st_info_nodes[i].language);
	}
#endif
}

void test_func_get_id3info(tp_handle_t handle)
{
    int8_t buff[256];
    int8_t *pStr=buff;
    int32_t ret;
	gst_id3info id3info;
	
    while(1)
	{		
		printf(TAG"please input file path>>:");
		fflush(stdout);
		gets((char*)pStr);
		ret = strlen((const char*)pStr);
		if (ret <=0)
			continue;
        else
            break;
    }
    
//	memcpy(pStr,"file:///testid3info",sizeof("file:///testid3info"));
	memset(&id3info, 0, sizeof(id3info));

	ret = fpi_mediaplayer_get_audio_id3info(handle, pStr, &id3info);
	if (ret != MM_SUCCESS)
	{
	    printf(TAG"fpi_mediaplayer_get_audio_id3info failed\n");
		return;
	}

	{
		printf(TAG"[%s] id3info.Identify:%s\n", __FUNCTION__, id3info.Identify);
		printf(TAG"[%s] id3info.Album:%s\n", __FUNCTION__, id3info.Album);
		printf(TAG"[%s] id3info.Artist:%s\n", __FUNCTION__, id3info.Artist);
		printf(TAG"[%s] id3info.genre:%s\n", __FUNCTION__, id3info.genre);
		printf(TAG"[%s] id3info.Title:%s\n", __FUNCTION__, id3info.Title);
		printf(TAG"[%s] id3info.Year:%s\n", __FUNCTION__, id3info.Year);
		printf(TAG"[%s] id3info.Comment:%s\n", __FUNCTION__, id3info.Comment);
    }

    printf(TAG"fpi_mediaplayer_get_audio_id3info ok\n");
}

void test_func_uninit(tp_handle_t handle)
{
    int32_t ret = -1;

    printf("fpi_mediaplayer_uninit handle = (0x%x).\n", handle);
    ret = fpi_mediaplayer_uninit(&handle);   
    if (ret==MM_FAIL)
    {
        printf("fpi_mediaplayer_uninit failed\n");
        return;
    }

    printf("fpi_mediaplayer_uninit success\n");
}

void test_func_get_cover(tp_handle_t handle)
{
    int32_t ret = -1;

    int8_t buff0[256];
    int8_t *filepath=buff0;
    
    while(1)
	{		
		printf(TAG"please input file path>>:");
		fflush(stdout);
		gets((char*)filepath);
		ret = strlen((const char*)filepath);
		if (ret <=0)
			continue;
        else
            break;
    }

//	memcpy(filepath,"file:///testgetcoverfile",sizeof("file:///testgetcoverfile"));
    int8_t buff1[256];
    int8_t *imagepath=buff1;
    
    while(1)
	{		
		printf(TAG"please input image path>>:");
		fflush(stdout);
		gets((char*)imagepath);
		ret = strlen((const char*)imagepath);
		if (ret <=0)
			continue;
        else
            break;
    }

//    memcpy(imagepath,"file:///testgetcoverimage",sizeof("file:///testgetcoverimage"));
    printf("fpi_mediaplayer_get_cover handle = (0x%x).\n", handle);
    ret = fpi_mediaplayer_get_cover(handle, filepath, imagepath);   
    if (ret==MM_FAIL)
    {
        printf("fpi_mediaplayer_get_cover failed\n");
        return;
    }

    printf("fpi_mediaplayer_get_cover success\n");
}

void test_func_help(tp_handle_t handle);

FUNC_MAP_S g_func_map[MAP_SIZE]=
{
  	//basic playback control
  	{"create", 			NULL		  },
	{"open",  			test_func_open},	
	{"play",  			test_func_play},		
	{"pause",  			test_func_pause},
	{"resume",  		test_func_resume},
	{"seek",  			test_func_seek},
	{"slowbk",  		test_func_slowbk},
	{"slowfw",  		test_func_slowfw},
	{"fastbk",  		test_func_fastbk},
	{"fastfw",  		test_func_fastfw},
	{"stop",  			test_func_stop},
	{"close",  			test_func_close},
	
  	//basic information
  	{"getstate",  		test_func_getstate},
  	{"getdur",  		test_func_get_duration},
	{"getpos",  		test_func_get_postion},

  	//audio related
	{"gettrackinfo",  	test_func_get_track_info},
	{"setaudiotrack", 	test_func_set_audio_track},

  	//video related
	{"getvthum",  		test_func_getvthumnail},	
	{"setVideoWd", 		test_func_setvideowindow},
	
  	//subtitle related
	{"getsubinfo",  		test_func_get_sub_track_info},
	{"subtitles_embedded",	test_func_get_subtitles_embedded_tracks},
	{"getcursubtrack",  	test_func_get_cur_sub_track},
  	{"setsubtrack",  		test_func_set_sub_track},
	
  	//other
  	{"setua",				test_func_set_useragent},
  	{"getcover",			test_func_get_cover},
	{"getid3info",				test_func_get_id3info},
    {"uninit",				test_func_uninit},
    
  	//help information
  	{"help",  				test_func_help},
  	{"all",					NULL		  },
	{"END", 				NULL}
};

void test_func_help(tp_handle_t handle)
{
	int32_t i = 0;
	printf(TAG" list of register func:\n", g_func_map[i].name);
	for (i=0; i<sizeof(g_func_map); i++)
	{
		if (0==strncmp("END", (const char*)g_func_map[i].name, 3))
    	{
			break;     		
		}
	
		if (strlen((const char*)g_func_map[i].name)>0)
    	{
			printf(TAG" ---->%s\n", g_func_map[i].name);        		
		}
	}
}

int32_t  tcp_player_event_proc(tp_event_t eventType,u_int8_t *data,void *user_data)
{   
	int32_t ret;
    int32_t msg_type = *((int32_t *)data);
	printf(TAG"%s(%d), Recieve msg_type(%d).\n", __func__, __LINE__, msg_type);
    printf(TAG"%s(%d), Recieve eventType(%d).\n", __func__, __LINE__, eventType);
    return MM_SUCCESS;
}

void paused()
{
    printf(TAG"press any key to continue:");
    fflush(stdout);
    getchar(); 
}

void *thread_recv_cmd()
{
    int32_t ret;	
	int32_t id= -1;
    int8_t buff[256];
    int8_t *pStr=buff;
	int32_t i,j;

    while(1)
	{		
		printf(TAG"please input command>>:");
		fflush(stdout);
		gets((char*)(char*)pStr);
		ret = strlen((const char*)(const char*)pStr);
		if (ret <=0)
			continue;
		if(0==strncmp("create", (const char*)pStr, 6))
        {        		
			id=test_func_create();
			continue;
        }
		if (0==strncmp("all",(const char*)pStr, 3))
		{
			id=test_func_create();
			printf(TAG"sizeof(g_func_map) %d\n", sizeof(g_func_map));
			for (j=1; j<MAP_SIZE; j++)
			{				
				if(g_func_map[j].func!=NULL)
				{
					printf(TAG"execute %s function[%d]!!!!\n",g_func_map[j].name, j);
					g_func_map[j].func(Context[id]->g_handle); 
				}
				else
				{
					printf(TAG"not execute %s function(NULL)!!!!\n",g_func_map[j].name);
				}
			}
			break;
		}
		for(i=1;i<MAP_SIZE;i++)
		{
			if ((NULL != g_func_map[i].func)&&
		   (0==strncmp((const char*)pStr,(const char*) g_func_map[i].name, strlen((const char*)(const char*)(g_func_map[i].name)))))
       		 {
        		
				if(id<0)
				{
					break;
				}
				g_func_map[i].func(Context[id]->g_handle);      
				
			}
		}
			
  }	
}

int32_t main(int32_t argc, char **argv)
{
	int32_t ret=0;
	pthread_t threadId;
    int32_t player_type = 0;//0-gst,1-picture,2-ffmpeg
    mm_player_proxy_init();
	printf("Sbinder Client Start!!!\n");
#if 1
	thread_recv_cmd();
#else
    if(ret = pthread_create(&threadId, NULL, (void *)thread_recv_cmd, player_type))
    {
        printf(TAG"%s  create thread failed", __func__);
        return -1;
    }
	
	while(1)
	{	sleep(5);}
	printf(TAG"exit thread \n");
#endif
	printf("thread_recv_cmd end!\n");
    return 0;	
}
