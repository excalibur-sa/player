#ifndef _H_GST_MEDIA_INTERFACE_H_
#define _H_GST_MEDIA_INTERFACE_H_

/******************************************************************************
    "Function:RegisterCallback",
    "Description: for registering the callback function. If not registered callback function,
                           call the gst_media_play function does not get proper response.",
    "Input parameters FuncProc£ºThe CALLBACK type, a pointer to a callback function.",
    "Output parameters: none",
    "Return: ",
    "    0:  regist callback success",
    "  -1:  regist callback  error",
    ""
******************************************************************************/
int32_t  RegisterCallback(int32_t playerid,void* FuncProc);

int32_t  gst_media_init(int32_t *playerid);

int32_t gst_RegisterCallback(int32_t playerid,MM_PLAYER_CB FuncProc);

int32_t gst_media_uninit(int32_t playerid);

/******************************************************************************
    "Function:gst_media_play",
    "Description: load the video file to start playing",
    "Input parameters videoinfo£ºThe video/audio paths, If it is a local file,
                                    using file:/// format to describe,
                                    network audio/video according to the corresponding protocol type to distinguish.",
    "Output parameters: none",
    "Return: ",
    "    0:  play success",
    "  -1:  no regist before playing",
    "  -:  now is picture playing , can not play media",
    "  -3:  now is other media playing , must stop current media before you want play new media",
    "  -4:  file is not exist",
    "  -5:  gstreamer init error",
    ""
******************************************************************************/
int32_t gst_media_play(int32_t playerid);

int32_t gst_media_open(int32_t playerid, int8_t *uri, media_open_config_s* openConfig);

/******************************************************************************
    "Function:gst_media_pause",
    "Description: pause the playback of audio and video",
    "Input parameters: none",
    "Output parameters: none",
    "Return: ",
    "    0: pause success",
    "   -1: pause error",
    ""
******************************************************************************/
int32_t gst_media_pause(int32_t playerid);

/******************************************************************************
    "Function:gst_media_resume",
    "Description: resume playing the audio and video from the paused state",
    "Input parameters: none",
    "Output parameters: none",
    "Return: ",
    "    0:  resume success",
    "   -1: resume error",
******************************************************************************/
int32_t gst_media_resume(int32_t playerid);

/******************************************************************************
    "Function:gst_media_stop",
    "Description: stop the playback of audio and video",
    "Input parameters: none",
    "Output parameters: none",
    "Return: ",
    "    0:  stop success",
    "   -1: stop error",
******************************************************************************/
int32_t gst_media_stop(int32_t playerid);

int32_t gst_media_close(int32_t playerid);
/******************************************************************************
    "Function:gst_media_seek",
    "Description: jump to any valid time point to play the audio and video. Besides that, if jump position is not within the range of the A-B when the current video is playing in the A-B loop repeat mode, terminate the A-B playback mode and jump.",
    "Input parameter pos: the time length which needs to jump",
    "Output parameters: none",
    "Return: ",
    "    0:  seek success",
    "   -1: seek error",
    ""
******************************************************************************/
int32_t gst_media_seek(int32_t playerid,int64_t time);

/******************************************************************************
    "Function:gst_media_getPts",
    "Description: Get the current display time of the media file being played",
    "Input parameters: none",
    "Output parameters: none",
    "Return: the display time of the current decoded video frames",
    "-1: getPts error",
    ""
******************************************************************************/
int64_t gst_media_getPts(int32_t playerid);

/******************************************************************************
    "Function:gst_media_getduration",
    "Description: Get the total duration of the media file being played",
    "Input parameters fileuri: the int8_t* type, and point to the uri path string of the video file,example: file:///xxx",
    "Output parameters: none",
    "Return: the total duration of the video being played, or return -1 if any exception occurs",
    ""
******************************************************************************/
int64_t gst_media_getduration(int32_t playerid,int8_t *fileuri);

/******************************************************************************
    "Function:gst_media_gettracknum",
    "Description: get the number of video tracks",
    "Input parameters fileuri: the int8_t* type, and point to the uri path string of the video file,example: file:///xxx",
    "Output parameters: none",
    "Return: the number of tracks of the video file. If the file does not exist or the file is not a video file, return -1",
    ""
******************************************************************************/
int32_t  gst_media_gettracknum (int32_t playerid, media_stream_info_s* pInfo);

/******************************************************************************
    "Function:gst_media_picture_getZoomRegion",
    "Description: get the width and height of video",
    "Input parameters fileuri: none",
    "Output parameters: none",
    "Return: the number of joint of width and height of the video file. ",
    ""
******************************************************************************/

int32_t gst_media_getVideoResolution();


/******************************************************************************
    "Function:gst_media_settrack",
    "Description: switch the tracks according to track id",
    "Input parameters tackid: the id of track",
    "Output parameters: none",
    "Return: ",
    "    0:  settrack success",
    "  -1:  settrack error",
    ""
******************************************************************************/
int32_t  gst_media_settrack(int32_t playerid,int32_t  trackid);

/******************************************************************************
    "Function:gst_video_setdisplay",
    "Description: scale to a specified size window to display the video",
    "Input parameters:",
    "    origin_x: the abscissa of the origin",
    "    origin_y: the ordinate of the origin",
    "    width: the scaled width",
    "    height: the scaled height",
    "Output parameters: none",
    "Return: ",
    "    0:  setdisplay success",
    "  -1:  setdisplay error",
    ""
******************************************************************************/
int32_t gst_video_setdisplay(int32_t playerid,int32_t origin_x, int32_t origin_y,
                          int32_t width, int32_t height);

/******************************************************************************
    "Function:gst_picture_stop",
    "Description: stop to play slideshow, and display the current playing picture, no longer changing. It doesn¡¯t work to call the function when the state is not playing slideshow.",
    "Input parameters: none",
    "Output parameters: none",
    "Return: ",
    "    0:  set picture stop success",
    "  -1:  set picture stop error",
    ""
******************************************************************************/
int32_t  gst_picture_stop(int32_t playerid);

/******************************************************************************
    "Function:gst_picture_setanimation",
    "Description: set the picture switching method. Whether playing slideshow or play single picture, it will immediate effect after set successfully.",
    "Input parameters:",
    "    type: animation type, including, 0 indicates the shutter effect, 1 indicates the sliding effect",
    "    direction: the direction of animation effect, including,",
    "        1, from left to right",
    "        , from right to left",
    "        3, from up to down",
    "        4, from down to up",
    "Output parameters: none",
    "Return: none",
    ""
******************************************************************************/
int32_t gst_picture_setanimation(int32_t playerid,int32_t type, int32_t direction);

/******************************************************************************
    "Function:gst_picture_showfile",
    "Description: display the specified valid picture",
    "Input parameters filepath: the absolute directory of the specified picture. Default in case that without changing the length, width and proportion to fill the entire window",
    "Output parameters: none",
    "Return:",
    "    0, play slideshow successfully",
    "    1, no picture exists under the specified directory",
    "    , the picture is invalid",
    ""
******************************************************************************/
int32_t gst_picture_showfile(int32_t playerid,int8_t*  filepath);

/******************************************************************************
    "Function:gst_audio_getid3info",
    "Description: get the ID3 information of wma/mp3 audio, only allow to transfer the audio file",
    "Input parameters filepath: the int8_t* type, the absolute path name",
    "Output parameters id3info: the ID3 information of wma/mp3 audio",
    "Return:",
	"    1: indicates that the file cotaining the id3 tag information",
	"   -1: indicates that the file does not exist or don not contain the id3 info",
    ""
******************************************************************************/
int32_t gst_getid3info(int32_t playerid,int8_t * filepath, gst_id3info * id3info);

/******************************************************************************
    "Function:gst_get_cover",
    "Description: get the CD cover from the audio file",
    "Input parameters:"
    "    filepath:the int8_t* type, and point to the uri path string of the audio file,example: file:///xxx",
    "    imagepath: the path to save the image",
    "Output parameters:none",
    "Return:",
    "    0:  svae image success",
    "  -1:  svae image error",
    ""
******************************************************************************/
int32_t gst_get_cover(int32_t playerid,int8_t * filepath, int8_t * imagepath);

/******************************************************************************
    "Function:gst_video_getthumbnail",
    "Description: get the video thumbnails",
    "Input parameters:",
    "    filepath:the int8_t* type, and point to the uri path string of the video file,example: file:///xxx",
    "    Dfilepath: the path to save the thumbnail",
    "    width: the width of the thumbnail image",
    "    height: the height of the thumbnail image",
    "Output parameters: none",
    "Return:",
    "    0:  svae image success",
    "  -1:  svae image error",
    ""
******************************************************************************/
int32_t gst_video_getthumbnail(int32_t playerid,int8_t* filepath, int8_t* dfilepath,int64_t time,   int32_t width, int32_t height);

/******************************************************************************
    "Function:gst_setplaymode",
    "Description: set the player decode mode",
    "Input parameters:",
    "    playmode: the decode mode",
    "        0: use hardware decode",
    "        1: use software decode",
    "Output parameters: none",
    "Return: the player decode mode",
    "    0: use hardware decode",
    "    1: use software decode",
    ""
******************************************************************************/
/*int32_t  gst_setplaymode(int32_t playmode);*/

/******************************************************************************
    "Function:gst_media_forward",
    "Description: fast-forward to play the audio and video at the set speed. It¡¯s silent and will directly terminate playback to the end of the media files when playing in fast-forward mode. Fast-forward function and A-B repeat function are mutually exclusive.",
    "Input parameter speed: multiples of the speed, only x, 4x, 8x, 16x, 3x are valid.",
    "Output parameters: none",
    "Return: ",
    "    0:  forward success",
    "  -1:  forward error",
    ""
******************************************************************************/
int32_t gst_media_forward(int32_t playerid,int32_t speed);

/******************************************************************************
    "Function:gst_media_backward",
    "Description: fast- backward to play the audio and video at the set speed. It¡¯s silent and will directly terminate playback to the head of the media files when playing in fast-backward mode. Fast-backward function and A-B repeat function are mutually exclusive.",
    "Input parameter speed: multiples of the speed, only x, 4x, 8x, 16x, 3x are valid.",
    "Output parameters: none",
    "Return: ",
    "    0:  backward success",
    "  -1:  backward error",
    ""
******************************************************************************/
int32_t gst_media_backward(int32_t playerid,int32_t speed);

/******************************************************************************
    "Function:gst_media_slow_motionon",
    "Description: slow- motion to play the audio and video at the set speed, whose valid values is 0.5x. It¡¯s silent and will directly terminate playback to the end of the media files when playing in slow- motion mode. Slow- motion function and A-B repeat function are mutually exclusive.",
    "Input parameter speed: multiples of the speed, only 0.5x is valid.",
    "Output parameters: none",
    "Return: ",
    "    0:  slow_motionon success",
    "  -1:  slow_motionon error",
    ""
******************************************************************************/
int32_t gst_media_slow_motionon(int32_t playerid,float speed);

/******************************************************************************
    "Function:gst_subtitles_get_embedded_tracks",
    "Description: get the number of subtitle tracks in a video file",
    "Input parameters fileuri: the int8_t* type, and point to the uri path string of the video file,example: file:///xxx",
    "Output parameters: none",
    "Return: the subtitle track number in a video file. If error occurs, return -1",
    ""
******************************************************************************/
int32_t  gst_subtitles_get_embedded_tracks(int32_t playerid , media_stream_info_s* pInfo);

/******************************************************************************
    "Function:gst_subtitles_settrack",
    "Description: switch the subtitle according to the subtitle track id",
    "Input parameters: ",
    "    Subid: the subtitle track id",
    "Output parameters: none",
    "Return: ",
    "    0:  set subtitle track success",
    "  -1:  set subtitle track  error",
    ""
******************************************************************************/
int32_t gst_subtitles_settrack (int32_t playerid,int32_t subid);

/******************************************************************************
    "Function:gst_media_getcurtrack",
    "Description: get current audio track id ",
    "Input parameters : none",
    "Output parameters trackid: get current audio track id success",
    "    0:  get current audio track id success",
    "  -1:  get current audio track id success error",
    ""
******************************************************************************/
int32_t gst_media_getcurtrack(int32_t playerid,int32_t *trackid);

/******************************************************************************
    "Function:gst_subtitles_getcurtrack",
    "Description: get current subtitle track id ",
    "Input parameters : none",
    "Output parameters trackid: get current subtitle track id success",
    "    0:  get current subtitle track id success",
    "  -1:  get current subtitle track id success error",
    ""
******************************************************************************/
int32_t gst_subtitles_getcurtrack(int32_t playerid,int32_t *trackid);

int32_t gst_media_set_buffer_threshold(int32_t playerid, FPI_enParaType type, int32_t para);

int32_t gst_media_get_buffer_threshold(int32_t playerid, FPI_enParaType type);

int32_t gst_media_set_userconfig(int32_t playerid, media_user_config_s *userConfig);

#endif
