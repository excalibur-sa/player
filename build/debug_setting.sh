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
#export GST_DEBUG=2,qtdemux:7

# no debug log
#export GST_DEBUG=

##########################################
#             test command               #
##########################################
#gst-launch-1.0 playbin uri=file:///home/shena/player/test/mediafiles/MJ.mp3

# for MPEG-DASH
# 非加密清流
#gst-launch-1.0 playbin uri=http://yt-dash-mse-test.commondatastorage.googleapis.com/media/car-20120827-manifest.mpd
# 加密流
#gst-launch-1.0 playbin uri=http://dashnetworkten-a.akamaihd.net/2199827728001/2199827728001_5126352611001_5126344803001.mpd
