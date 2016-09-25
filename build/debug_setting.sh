#!/bin/bash

##########################################
#             debug setting              #
##########################################
# debug log color setting
#export GST_DEBUG_NO_COLOR=1

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
#export GST_DEBUG=

##########################################
#             test command               #
##########################################
#gst-launch-1.0 playbin uri=file:///home/shena/player/test/mediafiles/MJ.mp3