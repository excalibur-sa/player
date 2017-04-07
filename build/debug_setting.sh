#!/bin/bash

##########################################
#             debug setting              #
##########################################
# debug log color setting
export GST_DEBUG_NO_COLOR=1

# dot file generation setting
export GST_DEBUG_DUMP_DOT_DIR=${DOT_DIR}
#export GST_DEBUG_DUMP_DOT_DIR=

# delete dot files
cd ${DOT_DIR}
rm *.dot

# change dot file to png
#sudo apt-get install graphviz
#dot -Tpng xxx.dot > xxx.png

# debug log level
export GST_DEBUG=2

# for MPEG-DASH
export GST_DEBUG=dashdemux:7,qtdemux:7
export GST_DEBUG=basesrc:4,v4l2src:7,v4l2:7
export GST_DEBUG=2,playbin:2,glframebuffer:7

# no debug log
#export GST_DEBUG=

# core dump
# ulimit -c unlimited

##########################################
#             test command               #
##########################################
#gst-launch-1.0 playbin uri=file:///home/shena/work/player/test/mediafiles/MJ.mp3
#gst-launch-1.0 playbin uri="https://gstreamer.freedesktop.org/data/media/large/PSPGO_FINAL.MP4"
#gst-launch-1.0 playbin uri=file:///home/shena/work/player/test/mediafiles/720x576i_AVC_french_english.mp4

# for MPEG-DASH
# 非加密清流，缺少DRM实现
#gst-launch-1.0 playbin uri=http://yt-dash-mse-test.commondatastorage.googleapis.com/media/car-20120827-manifest.mpd
#gst-launch-1.0 playbin uri="http://www-itec.uni-klu.ac.at/ftp/datasets/mmsys12/RedBullPlayStreets/redbull_4s/RedBullPlayStreets_4s_isoffmain_DIS_23009_1_v_2_1c2_2011_08_30.mpd"
#gst-launch-1.0 playbin uri="http://videoaupmd.sbs.com.au/dash/2016/09/30/512887/512887.mpd" //浏览器 403 forbidden

# 加密流
#gst-launch-1.0 playbin uri=http://dashnetworkten-a.akamaihd.net/2199827728001/2199827728001_5126352611001_5126344803001.mpd

# for Camera data play, Record Camera data in mp4 file, Record Camera data in jpg file. Note that the output format of v4l2src is image/jpeg, different device has different output format.
#gst-launch-1.0 v4l2src  ! image/jpeg, width=640, height=480 !  jpegdec ! videoconvert ! ximagesink
#gst-launch-1.0 v4l2src norm=255 do-timestamp="true" ! image/jpeg, width=640, height=480 !  jpegdec ! videoconvert ! autovideosink
#gst-launch-1.0 v4l2src  do-timestamp="true" ! image/jpeg, width=640, height=480 !  jpegdec ! avenc_mpeg4 ! filesink location=file.mp4
#gst-launch-1.0 v4l2src  do-timestamp="true" num-buffers=100 ! image/jpeg, width=640, height=480 ! tee name=t ! queue ! jpegdec ! videoconvert ! autovideosink t. ! queue ! jpegdec ! videoconvert ! autovideosink t. ! queue ! jpegdec ! videoconvert ! autovideosink t. ! queue ! multifilesink location="image%02d.jpg"

# 视频特效
#gst-launch-1.0 v4l2src  ! image/jpeg, width=640, height=480 !  jpegdec  ! videoconvert ! mirror ! ximagesink

# for Screen capture, Shown in screen, Record in mp4 file
#gst-launch-1.0 -v  ximagesrc  ! tee name=t ! queue ! videoconvert ! ximagesink
#gst-launch-1.0 -v  ximagesrc  ! videoconvert ! avenc_mpeg4 ! filesink location=screen.mp4

# for send Camera data tp RTSP server, check in the VLC player, failed currently.
#gst-launch-1.0 v4l2src  ! image/jpeg, width=640, height=480 !  jpegdec ! videoconvert ! x264enc ! rtph264pay name=pay0 pt=96
#gst-launch-1.0 videotestsrc is-live=1 ! x264enc ! rtph264pay name=pay0 pt=96

#udp Sender
#gst-launch-1.0 videotestsrc ! x264enc ! rtph264pay ! udpsink host=127.0.0.1    port=5000
#gst-launch-1.0 videotestsrc ! x264enc ! rtph264pay ! udpsink host=10.120.16.42 port=5000
#gst-launch-1.0  v4l2src do-timestamp="true"  ! image/jpeg, width=640, height=480 ! jpegdec ! x264enc ! rtph264pay ! udpsink host=10.120.16.42 port=5000
#udp Reciever
#gst-launch-1.0 udpsrc port=5000 caps = "application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264, payload=(int)96" ! rtph264depay ! decodebin ! videoconvert ! autovideosink

#udp Sender
#gst-launch-1.0  filesrc location="/home/shena/work/player/test/mediafiles/ad.mp4" ! decodebin !  x264enc ! rtph264pay ! udpsink host=192.168.2.106 port=5000
#udp Reciever
#gst-launch-1.0 udpsrc port=5000 caps = "application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264, payload=(int)96" ! rtph264depay ! decodebin ! videoconvert ! autovideosink
