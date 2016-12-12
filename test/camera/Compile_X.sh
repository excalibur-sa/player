#!/bin/bash
if [ $# == 0 ]
then
	echo "Usage: compile_X.sh cname"
	echo "cname: the name of .c file"
else
	echo "Compile" $1 "..." 

#just for basic-tutorial-15.c
#	gcc -Wall -g $1 -o $1.exe $(pkg-config --cflags --libs gstreamer-1.0 clutter-1.0  clutter-gst-1.0 gstreamer-pbutils-0.10 gtk+-2.0 gstreamer-interfaces-0.10) 

#just for basic-tutorial-9.c
#	gcc -Wall -g $1 -o $1.exe $(pkg-config --cflags --libs gstreamer-1.0 clutter-1.0  clutter-gst-1.0 gstreamer-pbutils-1.0 gtk+-2.0 gstreamer-interfaces-1.0) 
	
#just for basic-tutorial-5_GUI.c
#	gcc -Wall -g $1 -o $1.exe $(pkg-config --cflags --libs gstreamer-1.0 gtk+-2.0 gstreamer-interfaces-0.10)

#just for normal program
	gcc -Wall -g $1 -o $1.exe $(pkg-config --cflags --libs gstreamer-1.0) -I/home/shena/share/gstreamer1790/gstreamer1.7.90/src/gstreamer-1.7.90/
	if [ $? == 0 ]
	then
		echo "Done..."
	else
		echo "file:" $1 ", Compile error!"
		exit 1
	fi
fi
