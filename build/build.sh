#!/bin/sh
##########################################
#               environment              #
##########################################
. env.sh
cd ${CURRENT_DIR}

##########################################
#              function define           #
##########################################
building_function(){
 code_dir=$1
 src_package_name=$2
 building_element=$3
 
 if [ ! -d ${code_dir}/${building_element} ];then
  tar xvf ${PACKAGE_DIR}/${GST_VERSION}/${src_package_name} -C $code_dir

  if [ $? -eq 0 ]; then
    echo "<<< unzip ${building_element} success >>>"
  else
    echo "<<< unzip ${building_element} failed, Please check the message and your environment >>>"
    #exit 0
  fi  
 fi

 echo "<<< begin compile ${building_element} >>>"
 cp -rf ${PACKAGE_DIR}/${GST_VERSION}/configure/${building_element}/*  ${code_dir}/${building_element}
 cd ${code_dir}/${building_element}
 chmod 755 ${code_dir}/${building_element}/configure_compile_install
 ./configure_compile_install

 if [ $? -eq 0 ]; then
    echo "<<< compile ${building_element} success >>>"
 else
    echo "<<< compile ${building_element} failed, Please check the message and your environment >>>"
    #exit 0
 fi
 cd ${PROJECT_ROOT}
}

unbuilding_function(){
 code_dir=$1	
 unbuilding_element=$2
 echo "<<< begin uninstall ${unbuilding_element} >>>"
 cd ${code_dir}/${unbuilding_element}
 sudo make uninstall

 if [ $? -eq 0 ]; then
    echo "<<< uninstall ${unbuilding_element} success >>>"
 else
    echo "<<< uninstall ${unbuilding_element} failed, Please check the message and your environment >>>"
    #exit 0
 fi
 cd ${PROJECT_ROOT}
}

##########################################
#         unzip and compile tools        #
##########################################
#none

##########################################
#         unzip and compile core         #
##########################################
echo "### begin unzip and compile core ###"
#building_function ${CORE_DIR} tar dir

##########################################
#  compile and install gstreamer 1.10.2  #
##########################################

## ************************* for gstreamer-1.10.2, the dependence as below *************************
#GLib-2.50.2
#Required
# libffi-3.2.1 and Python-2.7.13 or Python-3.5.2
#Recommended
# PCRE-8.39 (built with Unicode properties)
#Optional
# dbus-1.10.14 (required for some tests), elfutils-0.168, GTK-Doc-1.25, FAM library, and GNU Indent

#gobject-introspection-1.50.0
#Required
# GLib-2.50.2 and Python-2.7.13
#Optional
# Cairo-1.14.8 (required for the tests), GTK-Doc-1.25 and Mako-1.0.4

#gstreamer-1.10.2
#Required
# GLib-2.50.2
#Recommended
# gobject-introspection-1.50.0
#Optional
# GTK+-3.22.5 (for examples), Gsl-2.3, GTK-Doc-1.25, and Valgrind-3.12.0

#sudo apt install libbz2-dev
#building_function ${CORE_DIR} pcre-8.39.tar.bz2 pcre-8.39 
#building_function ${CORE_DIR} libffi-3.2.1.tar.gz libffi-3.2.1 
#building_function ${CORE_DIR} Python-2.7.13.tar.xz Python-2.7.13
#sudo apt install libmount-dev
#building_function ${CORE_DIR} glib-2.50.2.tar.xz glib-2.50.2

#sudo apt install libbison-dev
#building_function ${CORE_DIR} gobject-introspection-1.50.0.tar.xz gobject-introspection-1.50.0

#building_function ${CORE_DIR} gstreamer-1.10.2.tar.xz gstreamer-1.10.2

## ************************* for gst-plugins-base-1.10.2, the dependence as below *************************
#gst-plugins-base-1.10.2
#Required
# gstreamer-1.10.2
#Recommended
# alsa-lib-1.1.2, CDParanoia-III-10.2 (for building the CDDA plugin), gobject-introspection-1.50.0, ISO Codes-3.72, libogg-1.3.2, libtheora-1.1.1, libvorbis-1.3.5, and Xorg Libraries
#Optional
# GTK+-3.22.5 (for examples), GTK-Doc-1.25, Opus-1.1.3, Qt-5.7.1 (for examples), Valgrind-3.12.0, libvisual, Orc, and Tremor

#sudo apt-get install libasound2-dev alsa-base alsa-utils alsa-source
#building_function ${CORE_DIR} libogg-1.3.2.tar.xz libogg-1.3.2

#sudo apt-get install libx11-dev libxv-dev libxt-dev
#building_function ${CORE_DIR} gst-plugins-base-1.10.2.tar.xz gst-plugins-base-1.10.2

## ************************* for gst-plugins-good-1.10.2, the dependence as below *************************
#GnuTLS-3.5.7
#Required
# Nettle-3.3
#Recommended
# Certificate Authority Certificates, libunistring-0.9.7, libtasn1-4.9, and p11-kit-0.23.2
#Optional
# Doxygen-1.8.12, GTK-Doc-1.25, Guile-2.0.13, libidn-1.33, Net-tools-CVS_20101030 (used during the test suite), texlive-20160523b or install-tl-unx, Unbound-1.6.0 (to build the DANE library), Valgrind-3.12.0 (used during the test suite), autogen, cmocka, datefudge (used during the test suite), and Trousers (Trusted Platform Module support)

#glib-networking-2.50.0
#Required
# GLib-2.50.2, GnuTLS-3.5.7 and gsettings-desktop-schemas-3.22.0
#Recommended
# Certificate Authority Certificates and p11-kit-0.23.2
#Optional
# libproxy

#libsoup-2.56.0
#Required
# glib-networking-2.50.0, libxml2-2.9.4 and SQLite-3.15.2
#Recommended
# gobject-introspection-1.50.0 and Vala-0.34.4
#Optional
# Apache-2.4.25 (required to run the test suite), cURL-7.52.1 (required to run the test suite), MIT Kerberos V5-1.15 (required to run the test suite), GTK-Doc-1.25, PHP-7.1.0 compiled with XMLRPC-EPI support (only used for the XMLRPC regression tests) and Samba-4.5.3 (ntlm_auth is required to run the test suite).

#gst-plugins-good-1.10.2
#Required
# gst-plugins-base-1.10.2
#Recommended
# Cairo-1.14.8, FLAC-1.3.1, gdk-pixbuf-2.36.2, libjpeg-turbo-1.5.1, libpng-1.6.26, libsoup-2.56.0, libvpx-1.6.0, and Xorg Libraries
#Optional
# AAlib-1.4rc5, ALSA OSS-1.0.28, GTK+-3.22.5 (for examples), GTK-Doc-1.25, libdv-1.0.0, libgudev-230, PulseAudio-9.0, Speex-1.2rc2, taglib-1.11.1, Valgrind-3.12.0, v4l-utils-1.10.1, JACK, libcaca, libiec61883, libraw1394, libshout, Orc, and WavPack

#building_function ${CORE_DIR} nettle-3.3.tar.gz nettle-3.3
#building_function ${CORE_DIR} gnutls-3.5.7.tar.xz gnutls-3.5.7
#building_function ${CORE_DIR} gsettings-desktop-schemas-3.22.0.tar.xz gsettings-desktop-schemas-3.22.0
#building_function ${CORE_DIR} glib-networking-2.50.0.tar.xz glib-networking-2.50.0
#building_function ${CORE_DIR} libxml2-2.9.4.tar.gz libxml2-2.9.4
#building_function ${CORE_DIR} sqlite-autoconf-3150200.tar.gz sqlite-autoconf-3150200
#building_function ${CORE_DIR} vala-0.34.4.tar.xz vala-0.34.4
#building_function ${CORE_DIR} libsoup-2.56.0.tar.xz libsoup-2.56.0

#TODO for video sink
#sudo apt-get install libjpeg-dev
#sudo apt-get install v4l-utils

#TODO for mp4/mkv etc.
#sudo apt-get install zlib1g-dev
#building_function ${CORE_DIR} gst-plugins-good-1.10.2.tar.xz gst-plugins-good-1.10.2


## ************************* for gst-plugins-bad-1.10.2, the dependence as below ************************* 
## gst-plugins-bad-1.10.2
#Required
# gst-plugins-base-1.10.2
#Recommended
# libdvdread-5.0.3, libdvdnav-5.0.3, LLVM-3.9.1, and SoundTouch-1.9.2
#Optional
# BlueZ-5.43, Clutter-1.26.0, cURL-7.52.1, FAAC-1.28, FAAD2-2.7, GnuTLS-3.5.7, GTK-Doc-1.25, GTK+-2.24.31 or GTK+-3.22.5, libass-0.13.5, libexif-0.6.21, libgcrypt-1.7.5, libmpeg2-0.5.1, libvdpau-1.1.1, libwebp-0.5.2, Mesa-13.0.2, mpg123-1.23.8, neon-0.30.2, Nettle-3.3, opencv-3.2.0 (with additional modules), OpenJPEG-1.5.2 or OpenJPEG-2.1.2, Opus-1.1.3, Qt-5.7.1 (for examples), SDL-1.2.15, Valgrind-3.12.0, Wayland-1.12.0, x265-2.2, Xorg Libraries, bs2b, Chromaprint, daala, Flite, Game Music Emu, GSM, libmimic, libmms, libofa, MJPEG Tools, OpenAL, Orc, VO AAC, VO AMRWB, and ZBAR

#TODO for curl
#sudo apt-get install libcurl4-gnutls-dev

#@@@@ FOR VR
#TODO for opengl
#安装OpenGL Library
#$ sudo apt-get install libgl1-mesa-dev
#安装OpenGL Utilities
#$ sudo apt-get install libglu1-mesa-dev OpenGL Utilities 是一组建构于 OpenGL Library 之上的工具组，提供许多很方便的函式，使 OpenGL 更强大且更容易使用。
#安装OpenGL Utility Toolkit
#$ sudo apt-get install libglut-dev OpenGL Utility Toolkit 是建立在 OpenGL Utilities 上面的工具箱，除了强化了 OpenGL Utilities 的不足之外，也增加了 OpenGL 对于视窗介面支援。 注意：在这一步的时候，可能会出现以下情况，shell提示： Reading package lists... Done Building dependency tree Reading state information... Done E: Unable to locate package libglut-dev
#将上述$ sudo apt-get install libglut-dev命令改成$ sudo apt-get install freeglut3-dev即可。

#@@@@ FOR VR
#sudo apt-get install meson
#下载 编译 OpendHMD 的工具
#sudo apt-get install autotools-dev m4 autoconf2.13  autoconf-archive gnu-standards autoconf-doc libtool
#sudo apt-get install libhidapi-dev
#下载 OpenHMD
#git clone https://github.com/excalibur-sa/OpenHMD.git
#按照文档编译安装 OpenHMD
#下载 libfreenect2 的依赖
#sudo apt-get install libusb-1.0-0-dev
#sudo apt-get install libturbojpeg
#sudo apt-get install libglfw3-dev
#sudo apt-get install beignet-dev
#sudo apt-get install libva-dev libjpeg-dev
#sudo apt-get install libopenni2-dev
#下载 libfreenect2
#git clone https://github.com/excalibur-sa/libfreenect2.git
#按照文档编译安装 libfreenect2

#下载 graphene 依赖
#sudo apt install libboost-dev
#sudo apt install libboost1.58-all-dev
#sudo apt-get install libssl-dev
#sudo apt-get install openssl 

#下载 graphene
#git clone https://github.com/excalibur-sa/graphene.git
#下载 python3-all-dev
#sudo apt install python3-all-dev
#下载 libgtk-3-dev
#sudo apt install libgtk-3-dev

#building_function ${CORE_DIR} gst-plugins-bad-1.10.2.tar.xz gst-plugins-bad-1.10.2

## ************************* for gst-plugins-ugly-1.10.2, the dependence as below ************************* 
#gst-plugins-ugly-1.10.2
#Required
# gst-plugins-base-1.10.2
#Recommended
# LAME-3.99.5, liba52-0.7.4 (needed to play DVD's), libdvdread-5.0.3, and x264-20160827-2245
#Optional
# libmad-0.15.1b, libmpeg2-0.5.1, libcdio-0.94 (for CD-ROM drive access), mpg123-1.23.8, Valgrind-3.12.0, libsidplay, OpenCore AMR, Orc, and TwoLame

#building_function ${CORE_DIR} libmpeg2-0.5.1.tar.gz libmpeg2-0.5.1

#TODO
#sudo apt-get install libmad0-dev
#building_function ${CORE_DIR} mad-0.14.2b.tar.gz mad-0.14.2b ${PROJECT_PREFIX}

#sudo apt-get install libx264-dev

building_function ${CORE_DIR} gst-plugins-ugly-1.10.2.tar.xz gst-plugins-ugly-1.10.2

## ************************* for gst-libav-1.10.2, the dependence as below ************************* 
## gst-libav-1.10.2
#building_function ${CORE_DIR} gst-libav-1.10.2.tar.xz gst-libav-1.10.2

##########################################
#         uninstall gstreamer 1.10.2      #
##########################################
#unbuilding_function ${CORE_DIR} gstreamer-1.10.2
#unbuilding_function ${CORE_DIR} gst-plugins-base-1.10.2
#unbuilding_function ${CORE_DIR} gst-plugins-good-1.10.2
#unbuilding_function ${CORE_DIR} gst-plugins-bad-1.10.2
#unbuilding_function ${CORE_DIR} gst-plugins-ugly-1.10.2
#unbuilding_function ${CORE_DIR} gst-libav-1.10.2

echo "compile core end."

:<<eof
##########################################
#     other preinstall softwares         #
##########################################
echo "<<< begin preinstall software >>>"

########## below softwares for gstreamer
sudo apt-get install gettext
sudo apt-get install flex

########## below softwares for gst-plugins-base
sudo apt-get install libcdparanoia-dev
sudo apt-get install libvorbisidec-dev
sudo apt-get install libvorbis-dev
sudo apt-get install libvisual-0.4-dev 
sudo apt-get install libpango1.0-dev
sudo apt-get install libtheora-dev
sudo apt-get install liborc-0.4-dev

########## below softwares for gst-plugins-good
sudo apt-get install build-essential

########## below softwares for gst-libav
sudo apt-get install yasm

########## below softwares for gst-plugins
sudo apt-get install libmad0-dev
sudo apt-get install mpeg2dec
sudo apt-get install libmpeg2-4-dev
sudo apt-get install libx264-dev

if [ $? -eq 0 ]; then
 echo "<<< preinstall software success >>>"
else
 echo "<<< preinstall software failed, Please check the message and your environment >>>"
eof

##########################################
#           compile source code          #
##########################################



