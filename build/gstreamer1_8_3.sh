##########################################
#  compile and install gstreamer 1.8.3   #
##########################################
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

#gstreamer183_config="--disable-check"
#building_function ${CORE_DIR} gstreamer-1.8.3.tar.xz gstreamer-1.8.3 ${PROJECT_PREFIX} 
#${gstreamer183_config}



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
#sudo apt-get install libjpeg-dev
#sudo apt-get install v4l-utils

#TODO for mp4/mkv etc.
#sudo apt-get install zlib1g-dev
#building_function ${CORE_DIR} gst-plugins-good-1.8.3.tar.xz gst-plugins-good-1.8.3 ${PROJECT_PREFIX}


## ************************* for gst-plugins-bad-1.8.3, the dependence as below ************************* 
## gst-plugins-bad-1.8.3.tar.xz

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

#building_function ${CORE_DIR} gst-plugins-bad-1.8.3.tar.xz gst-plugins-bad-1.8.3 ${PROJECT_PREFIX}

## ************************* for gst-plugins-ugly-1.8.3, the dependence as below ************************* 
## gst-plugins-ugly-1.8.3.tar.xz
## ->libmad-0.15.1b.tar.gz
## ->libmpeg2-0.5.1.tar.gz

#building_function ${CORE_DIR} libmpeg2-0.5.1.tar.gz libmpeg2-0.5.1 ${PROJECT_PREFIX}

#TODO
#building_function ${CORE_DIR} mad-0.14.2b.tar.gz mad-0.14.2b ${PROJECT_PREFIX}

#sudo apt-get install libx264-dev

#building_function ${CORE_DIR} gst-plugins-ugly-1.8.3.tar.xz gst-plugins-ugly-1.8.3 ${PROJECT_PREFIX}

## ************************* for gst-libav-1.8.3, the dependence as below ************************* 
## gst-libav-1.8.3.tar.xz

#libav_config="--with-libav-extra-configure=\"--disable-yasm\""
#building_function ${CORE_DIR} gst-libav-1.8.3.tar.xz gst-libav-1.8.3 ${PROJECT_PREFIX} ${libav_config}

##########################################
#         uninstall gstreamer 1.8.3      #
##########################################
#unbuilding_function ${CORE_DIR} gstreamer-1.8.3
#unbuilding_function ${CORE_DIR} gst-plugins-base-1.8.3
#unbuilding_function ${CORE_DIR} gst-plugins-good-1.8.3
#unbuilding_function ${CORE_DIR} gst-plugins-bad-1.8.3
#unbuilding_function ${CORE_DIR} gst-plugins-ugly-1.8.3
#unbuilding_function ${CORE_DIR} gst-libav-1.8.3