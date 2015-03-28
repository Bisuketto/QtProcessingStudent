TEMPLATE = app
TARGET = QtProcessing

win32{
    QMAKE_CXXFLAGS= -O2 \
            -msse -msse2 -mtune=native -pipe -fomit-frame-pointer \
            -fprefetch-loop-arrays -I./ffmpeg-2010-01-19/include/ -I./ffmpeg-2010-01-19
    LIBS += -lavdevice -lavformat -lavcodec -lavutil -lswscale -lm -L./ffmpeg-2010-01-19/lib -lws2_32
} else {
    QMAKE_CXXFLAGS= -O2 \
           -msse -msse2 -mtune=native -pipe -fomit-frame-pointer \
           -fprefetch-loop-arrays -I/opt/local/include
    LIBS += -lz -lm -L/opt/local/lib -lbz2 -lopencv_contrib -lopencv_core \
            -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui \
            -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree \
            -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres \
            -lopencv_ts -lopencv_video -lopencv_videostab -I/opt/local/lib
}
QT       += core gui opengl network

HEADERS += src/playerinterface.h \
    src/openglwidget.h \
    src/Image/FImage.h \
    src/Image/CVideo.h
SOURCES += src/playerinterface.cpp \
    src/openglwidget.cpp \
    src/main.cpp \
    src/Image/FImage.cpp \
    src/Image/CVideo.cpp
RESOURCES +=
FORMS +=
