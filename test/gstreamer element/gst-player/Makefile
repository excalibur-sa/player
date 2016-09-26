INCLUDE = -I.\
		  -I../ \
          -I$(PREFIX_ROOT)/include/gstreamer-1.0 \
          -I${PREFIX_ROOT}/include/glib-2.0/ \
		  -I${PREFIX_ROOT}/lib/gstreamer-1.0/include \
		  -I${ENV_DIR}/../../../core/include/media/ \
		  -I${ENV_DIR}/../../../porting/include/base \
		  -I${ENV_DIR}/../../../porting/include/fpp \
		  -I${ENV_DIR}/../../../utils/include
		  
VERSIONFLAGS = -DSVN_VER -DCOMPILE_DATE -DMEDIA_DIVX_ENABLED -Wall

LDFLAGS =-Wl,--start-group \
		-L$(PREFIX_ROOT)/lib \
		-lmm_logd \
		-lgstplayer \
		-lgobject-2.0 \
		-lgmodule-2.0 \
		-lxml2 \
		-lgthread-2.0 \
		-lglib-2.0 \
		-liconv \
		-lffi \
		-lgstreamer-1.0 \
		-Wl,--end-group


SRC = gst_media_interface.c

TARGET = libgstplayer.so	

DATE=$(shell date "+%Y%m%d %k:%M:%S")
VER=$(shell svn info | grep Revision: | awk '{print $2}')
COMPILE_DATE=$DATE
SVN_VER=$VER

all:$(TARGET)

$(TARGET):
	$(GCC) -shared -fPIC -g -o $(TARGET) $(SRC) $(INCLUDE) $(VERSIONFLAGS) $(MMCFLAGS) $(LIBS) $(MMLDFLAGS) $(LDFLAGS)

clean:
	rm -rf $(TARGET) *.o

install:
	cp $(TARGET) ${PREFIX_ROOT}/lib
	cp gst_media_interface.h ${PREFIX_ROOT}/include
