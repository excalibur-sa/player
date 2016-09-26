GCC = gcc

CFLAGS = `pkg-config --cflags --libs gstreamer-1.0` -DSVN_VER -DCOMPILE_DATE -DHAVE_CONFIG_H -Wall

SRC = gstfppadec.c

TARGET = libfppadec.so

all:$(TARGET)

$(TARGET):
	$(GCC) -shared -fPIC -g -o $(TARGET) $(SRC) $(CFLAGS)

clean:
	rm -rf $(TARGET) *.o
	
install:
	cp $(TARGET) $(INSTALL_DIR)/lib -rf
