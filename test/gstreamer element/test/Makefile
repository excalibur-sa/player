INCLUDE = -I../ \
		  -I$(PREFIX_ROOT)/include \
		  -I$(PLAYER_DIR)/include \
          -I$(PLAYER_DIR)/src/proxy

LDFLAGS = -Wl,--start-group \
                -L$(PREFIX_ROOT)/lib \
                -L$(PREFIX_ROOT)/Sitalib \
                -lfpi_mediaplayer \
                -lsitatv \
				-lpthread \
				-lAndroidToolsetsS \
                -lbinderservicemanager \
                -lStandaloneBinderS \
                -Wl,--end-group

MUSE_BINDER = -DMEDIA_USE_SBINDER
MUSE_BINDER += -DHAVE_ANDROID_OS
MUSE_BINDER += -DHAVE_SYS_UIO_H
MUSE_BINDER += -DHAVE_PTHREADS
MUSE_BINDER += -DHAVE_ENDIAN_H
MUSE_BINDER += -DHAVE_OFF64_T
MUSE_BINDER += -DHAVE_POSIX_FILEMAP
MUSE_BINDER += -DOS_PATH_SEPARATOR='/'
MUSE_BINDER += -DANDROID_SMP=1				
				
CB_CFLAG = -DCOMPILE_DATE_VER="\"$(DATE)\""
CB_CFLAG += -DBINDER_CLIENT
CB_CFLAG += $(MUSE_BINDER)

				
TARGET= MediaTest_client

all:clean bin

bin:
	$(GPLUS) $(CB_CFLAG) -g -o $(TARGET) client.c  ${INCLUDE} ${LDFLAGS} 
	
install:
	cp $(TARGET) ${PREFIX_ROOT}/


clean:
	rm -rvf $(TARGET)


