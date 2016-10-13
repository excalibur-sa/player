#!/bin/sh

##########################################
#               environment              #
##########################################
CURRENT_DIR=`pwd`
PROJECT_ROOT=${CURRENT_DIR}/../
export GST_VERSION=gstreamer-1.8.3
export BUILD_DIR=${PROJECT_ROOT}/build/
export INCLUDE_DIR=${PROJECT_ROOT}/include/
export DOT_DIR=${PROJECT_ROOT}/dot/
export LOG_DIR=${PROJECT_ROOT}/log/

export PACKAGE_DIR=${PROJECT_ROOT}/tar/

export TOOLS_DIR=${PROJECT_ROOT}/tools/

export CORE_DIR=${PROJECT_ROOT}/core/

export SOURCE_DIR=${PROJECT_ROOT}/src/
export PLUGINS_DIR=${SOURCE_DIR}/plugins/
export PLAYER_DIR=${SOURCE_DIR}/player/

export TEST_DIR=${PROJECT_ROOT}/test/

export INSTALL_DIR=${PROJECT_ROOT}/install/
export TOOLS_PREFIX=${INSTALL_DIR}/tools/
export TOOLS_BIN=${TOOLS_PREFIX}/bin/
export TOOLS_LIB=${TOOLS_PREFIX}/lib/
export PROJECT_PREFIX=${INSTALL_DIR}/release/
export PROJECT_BIN=${PROJECT_PREFIX}/bin/
export PROJECT_LIB=${PROJECT_PREFIX}/lib/

##########################################
#              automake dir              #
##########################################
if [ ! -d $DOT_DIR ];then
 mkdir -p $DOT_DIR
fi
if [ ! -d $LOG_DIR ];then
 mkdir -p $LOG_DIR
fi
if [ ! -d $TOOLS_DIR ];then
 mkdir -p $TOOLS_DIR
fi
if [ ! -d $CORE_DIR ];then
 mkdir -p $CORE_DIR
fi
if [ ! -d $INSTALL_DIR ];then
 mkdir -p $INSTALL_DIR
fi
if [ ! -d $TOOLS_PREFIX ];then
 mkdir -p $TOOLS_PREFIX
fi
if [ ! -d $TOOLS_BIN ];then
 mkdir -p $TOOLS_BIN
fi
if [ ! -d $TOOLS_LIB ];then
 mkdir -p $TOOLS_LIB
fi
if [ ! -d $PROJECT_PREFIX ];then
 mkdir -p $PROJECT_PREFIX
fi
if [ ! -d $PROJECT_BIN ];then
mkdir -p $PROJECT_BIN
fi
if [ ! -d $PROJECT_LIB ];then
 mkdir -p $PROJECT_LIB
fi
##########################################
#          compile environment           #
##########################################
export LD_LIBRARY_PATH=${PROJECT_LIB}/
export PATH=${PROJECT_BIN}:$PATH
export PKG_CONFIG_PATH=${PROJECT_LIB}/pkgconfig:/usr/lib/pkgconfig:/usr/lib/x86_64-linux-gnu/pkgconfig:/usr/share/pkgconfig

##########################################
#              function define           #
##########################################
building_function(){
 code_dir=$1
 src_package_name=$2
 building_element=$3
 install_dir=$4

 config_setting=""
 cfg_para_index=5
 cur_count=1
 echo "The amount of the parameters is $# !"
 #echo "cfg_para_index: $cfg_para_index"
 #echo ""
 for arg in "$@"
 do
    #echo "The value of the $cur_count parameter is $arg !"
    if [ $cur_count -ge $cfg_para_index ];then
    config_setting="${config_setting} $arg"
    fi
    let ++cur_count
 done

  #echo ""
  echo "config_setting: $config_setting"
 
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
 cd ${code_dir}/${building_element}
 ./configure --prefix=${install_dir} ${config_setting}
 make && sudo make install
 #make clean

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
 make uninstall

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
cd ${PACKAGE_DIR}/${GST_VERSION}
#building_function ${CORE_DIR} tar dir ${PROJECT_PREFIX}

## ************************* for gstreamer-1.8.3, the dependence as below *************************
## gstreamer-1.8.3.tar.xz
## ->glib-2.50.0.tar.xz (Required)
##   ->pcre-8.39.tar.bz2 (Required)
##   ->util-linux-2.28.2.tar.xz (Required)
##   ->zlib-1.2.8.tar.xz (Required)
##      ->libffi-3.2.1.tar.gz (Required)
## ->gobject-introspection-1.50.0.tar.xz (Recommended)
##   ->bison-3.0.4.tar.xz (Required)
##   ->flex-2.6.0.tar.xz (Required)
##     ->m4-1.4.17.tar.xz (Required)
##     ->byacc.tar (Required)
##   ->Python-2.7.12.tar.xz (Required)
##     ->libffi-3.2.1.tar.gz (Recommended)

#prce_config="--enable-unicode-properties"
#building_function ${CORE_DIR} pcre-8.39.tar.bz2 pcre-8.39 ${PROJECT_PREFIX} ${prce_config}
#building_function ${CORE_DIR} libffi-3.2.1.tar.gz libffi-3.2.1 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} zlib-1.2.8.tar.xz zlib-1.2.8 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} util-linux-2.28.2.tar.xz util-linux-2.28.2 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} glib-2.50.0.tar.xz glib-2.50.0 ${PROJECT_PREFIX}

#python27_config="--enable-shared"
#building_function ${CORE_DIR} Python-2.7.12.tar.xz Python-2.7.12 ${PROJECT_PREFIX} ${python27_config}
#building_function ${CORE_DIR} m4-1.4.17.tar.xz m4-1.4.17 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} byacc.tar byacc-20160606 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} flex-2.6.0.tar.xz flex-2.6.0 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} bison-3.0.4.tar.xz bison-3.0.4 ${PROJECT_PREFIX}

#TODO (compile for source code in the future)
#gi_config="--disable-static"
#building_function ${CORE_DIR} gobject-introspection-1.50.0.tar.xz gobject-introspection-1.50.0 ${PROJECT_PREFIX} ${gi_config}
#sudo apt-get install gobject-introspection

#gstreamer183_config="--with-package-name=\"GStreamer 1.8.3 BLFS\" --with-package-origin=\"http://www.linuxfromscratch.org/blfs/view/svn/\""
#building_function ${CORE_DIR} gstreamer-1.8.3.tar.xz gstreamer-1.8.3 ${PROJECT_PREFIX} ${gstreamer183_config}



## ************************* for gst-plugins-base-1.8.3, the dependence as below *************************
## gst-plugins-base-1.8.3.tar.xz
## ->gstreamer-1.8.3.tar.xz (Required)
## ->alsa-lib-1.1.2.tar.bz2 (Optional)
## ->libogg-1.3.2.tar.xz (Optional)

#TODO
#building_function ${CORE_DIR} alsa-lib-1.1.2.tar.bz2 alsa-lib-1.1.2 ${PROJECT_PREFIX}
#sudo apt-get install libasound2-dev alsa-base alsa-utils alsa-source

#ogg_config="--disable-static"
#building_function ${CORE_DIR} libogg-1.3.2.tar.xz libogg-1.3.2 ${PROJECT_PREFIX} ${ogg_config}

#TODO for x window display
#sudo apt-get install libx11-dev libxv-dev libxt-dev
#building_function ${CORE_DIR} gst-plugins-base-1.8.3.tar.xz gst-plugins-base-1.8.3 ${PROJECT_PREFIX}



## ************************* for gst-plugins-good-1.8.3, the dependence as below *************************
## gst-plugins-good-1.8.3.tar.xz
## ->libsoup-2.56.0.tar.xz
##   ->sqlite-autoconf-3140200.tar.gz
##   ->libxml2-2.9.4.tar.gz
##   ->glib-networking-2.50.0.tar.xz
##     ->gnutls-3.5.4.tar.xz
##       ->nettle-3.2.tar.gz
##     ->gsettings-desktop-schemas-3.22.0.tar.xz
##     ->glib-2.50.0.tar.xz

#TODO
#sudo apt-get install intltool

#building_function ${CORE_DIR} gsettings-desktop-schemas-3.22.0.tar.xz gsettings-desktop-schemas-3.22.0 ${PROJECT_PREFIX}

#TODO
#sudo apt-get install libgmp-dev

#nettle_config="--disable-static"
#building_function ${CORE_DIR} nettle-3.2.tar.gz nettle-3.2 ${PROJECT_PREFIX}

#TODO
#sudo apt-get install autogen

#gnutls_config="--with-included-libtasn1 --without-p11-kit"
#building_function ${CORE_DIR} gnutls-3.5.4.tar.xz gnutls-3.5.4 ${PROJECT_PREFIX} ${gnutls_config}

#building_function ${CORE_DIR} glib-networking-2.50.0.tar.xz glib-networking-2.50.0 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} libxml2-2.9.4.tar.gz libxml2-2.9.4 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} sqlite-autoconf-3140200.tar.gz sqlite-autoconf-3140200 ${PROJECT_PREFIX}
#building_function ${CORE_DIR} libsoup-2.56.0.tar.xz libsoup-2.56.0 ${PROJECT_PREFIX}

#TODO for video sink
#sudo apt-get install v4l-utils

#TODO for mp4/mkv etc.
#sudo apt-get install zlib1g-dev
#building_function ${CORE_DIR} gst-plugins-good-1.8.3.tar.xz gst-plugins-good-1.8.3 ${PROJECT_PREFIX}

## ************************* for gst-plugins-bad-1.8.3, the dependence as below ************************* 
## gst-plugins-bad-1.8.3.tar.xz

#TODO for curl
#sudo apt-get install libcurl4-gnutls-dev
#building_function ${CORE_DIR} gst-plugins-bad-1.8.3.tar.xz gst-plugins-bad-1.8.3 ${PROJECT_PREFIX}

## ************************* for gst-plugins-ugly-1.8.3, the dependence as below ************************* 
## gst-plugins-ugly-1.8.3.tar.xz
## ->libmad-0.15.1b.tar.gz
## ->libmpeg2-0.5.1.tar.gz

#building_function ${CORE_DIR} libmpeg2-0.5.1.tar.gz libmpeg2-0.5.1 ${PROJECT_PREFIX}

#TODO
#building_function ${CORE_DIR} mad-0.14.2b.tar.gz mad-0.14.2b ${PROJECT_PREFIX}

#building_function ${CORE_DIR} gst-plugins-ugly-1.8.3.tar.xz gst-plugins-ugly-1.8.3 ${PROJECT_PREFIX}

## ************************* for gst-libav-1.8.3, the dependence as below ************************* 
## gst-libav-1.8.3.tar.xz

#libav_config="--with-libav-extra-configure=\"--disable-yasm\""
#building_function ${CORE_DIR} gst-libav-1.8.3.tar.xz gst-libav-1.8.3 ${PROJECT_PREFIX} ${libav_config}

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



