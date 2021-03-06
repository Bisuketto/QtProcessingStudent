TEMPLATE = app
TARGET = QtProcessing

QMAKE_CXXFLAGS= -O2 \
       -march=native -mtune=native -pipe -fomit-frame-pointer \
       -fprefetch-loop-arrays -I/opt/local/include

LIBS += -lz -lm -L/opt/local/lib -lopencv_contrib -lopencv_core \
        -lopencv_features2d -lopencv_flann -lopencv_highgui \
        -lopencv_imgproc -lopencv_legacy -lopencv_ml  \
        -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres \
        -lopencv_ts -lopencv_video -lopencv_videostab -I/opt/local/lib

QT       += core gui opengl network

HEADERS += src/playerinterface.h \
    src/openglwidget.h \
    src/Image/FImage.h \
    src/Image/CVideo.h \
    src/Filter/filter.hpp \
    src/Filter/canalfilter.hpp \
    src/Filter/inversefilter.hpp \
    src/Filter/nofilter.hpp \
    src/Filter/filtermanager.hpp \
    src/Filter/greyfilter.hpp \
    src/Filter/simplegreyfilter.hpp \
    src/Filter/liablegreyfilter.hpp \
    src/Filter/automaticcolorlevelfilter.hpp \
    src/Filter/downsamplefilterlin.hpp \
    src/Filter/downsamplefilterpick.hpp \
    src/Filter/downsamplefiltersqr.hpp \
    src/Filter/filterb.hpp \
    src/Filter/filterg.hpp \
    src/Filter/filterr.hpp \
    src/Filter/upsamplefilter.hpp \
    src/Filter/convolutionfilter.hpp \
    src/Filter/detectionfilter3p1.hpp \
    src/Filter/detectionfilter2p1.hpp \
    src/Filter/detectionfilter3p3.hpp \
    src/Filter/complexfilterex4.hpp \
    src/Filter/complexfilterex3.hpp \
    src/Filter/complexfilterex2.hpp \
    src/Filter/complexfilterex1.hpp \
    src/Filter/complexfilter.hpp \
    src/Filter/motionblurfilter.hpp \
    src/addfilterdialog.hpp \
    src/Filter/pow2normblurfilter.hpp \
    src/Filter/notpow2normblurfilter.hpp
SOURCES += src/playerinterface.cpp \
    src/openglwidget.cpp \
    src/main.cpp \
    src/Image/FImage.cpp \
    src/Image/CVideo.cpp \
    src/Filter/filter.cpp \
    src/Filter/canalfilter.cpp \
    src/Filter/inversefilter.cpp \
    src/Filter/nofilter.cpp \
    src/Filter/filtermanager.cpp \
    src/Filter/greyfilter.cpp \
    src/Filter/simplegreyfilter.cpp \
    src/Filter/liablegreyfilter.cpp \
    src/Filter/automaticcolorlevelfilter.cpp \
    src/Filter/downsamplefilterlin.cpp \
    src/Filter/downsamplefilterpick.cpp \
    src/Filter/downsamplefiltersqr.cpp \
    src/Filter/filterb.cpp \
    src/Filter/filterg.cpp \
    src/Filter/filterr.cpp \
    src/Filter/upsamplefilter.cpp \
    src/Filter/convolutionfilter.cpp \
    src/Filter/detectionfilter3p1.cpp \
    src/Filter/detectionfilter2p1.cpp \
    src/Filter/detectionfilter3p3.cpp \
    src/Filter/complexfilterex4.cpp \
    src/Filter/complexfilterex3.cpp \
    src/Filter/complexfilterex2.cpp \
    src/Filter/complexfilterex1.cpp \
    src/Filter/motionblurfilter.cpp \
    src/Filter/complexfilter.cpp \
    src/addfilterdialog.cpp \
    src/Filter/pow2normblurfilter.cpp \
    src/Filter/notpow2normblurfilter.cpp

RESOURCES +=
FORMS +=
