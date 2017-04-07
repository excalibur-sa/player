#!/bin/bash

#just for SomeObject program
gcc -Wall -g gobject_08.c -o GObject_test.exe $(pkg-config --cflags --libs glib-2.0 gobject-2.0) 
if [ $? == 0 ]
then
	echo "Done..."
else
	echo "file:" $1 ", Compile error!"
	exit 1
fi
