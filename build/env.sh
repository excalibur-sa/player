#!/bin/sh

##########################################
#               environment              #
##########################################
export CURRENT_DIR=`pwd`
export PROJECT_ROOT=${CURRENT_DIR}/../
#export GST_VERSION=gstreamer-1.8.3
export GST_VERSION=gstreamer-1.10.2
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
export LD_LIBRARY_PATH=${PROJECT_LIB}:${PROJECT_LIB}/x86_64-linux-gnu:${PROJECT_LIB}/x86_64-linux-gnu/gstreamer-1.0/:/usr/local/lib/x86_64-linux-gnu/
export PATH=${PROJECT_BIN}:$PATH
export PKG_CONFIG_PATH=${PROJECT_LIB}/pkgconfig:${PROJECT_LIB}/x86_64-linux-gnu/pkgconfig:/usr/lib/pkgconfig:/usr/lib/x86_64-linux-gnu/pkgconfig:/usr/share/pkgconfig:/usr/local/lib/x86_64-linux-gnu/pkgconfig:/usr/lib/openmpi/lib/pkgconfig

##########################################
#            debug environment           #
##########################################
cd ${CURRENT_DIR}
. debug_setting.sh
cd ${PROJECT_ROOT}