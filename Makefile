#############################################################################
# Makefile for building: QtProcessing.app/Contents/MacOS/QtProcessing
# Generated by qmake (2.01a) (Qt 4.8.5) on: Sat Mar 28 16:01:04 2015
# Project:  QtProcessingStudent.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/local/Qt4.8/mkspecs/macx-g++ CONFIG+=release CONFIG+=x86_64 -o Makefile QtProcessingStudent.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -O2 -msse -msse2 -mtune=native -pipe -fomit-frame-pointer -fprefetch-loop-arrays -I/opt/local/include -O2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Qt4.8/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtNetwork.framework/Versions/4/Headers -I/usr/include/QtNetwork -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/Library/Frameworks/QtOpenGL.framework/Versions/4/Headers -I/usr/include/QtOpenGL -I/usr/include -I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/System/Library/Frameworks/AGL.framework/Headers -I. -F/Library/Frameworks
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/Library/Frameworks -L/Library/Frameworks -lz -lm -L/opt/local/lib -lbz2 -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab -I/opt/local/lib -framework QtOpenGL -framework QtGui -framework QtCore -framework QtNetwork -framework OpenGL -framework AGL 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/playerinterface.cpp \
		src/openglwidget.cpp \
		src/main.cpp \
		src/Image/FImage.cpp \
		src/Image/CVideo.cpp moc_playerinterface.cpp
OBJECTS       = playerinterface.o \
		openglwidget.o \
		main.o \
		FImage.o \
		CVideo.o \
		moc_playerinterface.o
DIST          = /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/release.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/shared.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/opengl.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		QtProcessingStudent.pro
QMAKE_TARGET  = QtProcessing
DESTDIR       = 
TARGET        = QtProcessing.app/Contents/MacOS/QtProcessing

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile QtProcessing.app/Contents/PkgInfo QtProcessing.app/Contents/Resources/empty.lproj QtProcessing.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) QtProcessing.app/Contents/MacOS/ || $(MKDIR) QtProcessing.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: QtProcessingStudent.pro  /usr/local/Qt4.8/mkspecs/macx-g++/qmake.conf /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/release.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/shared.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/opengl.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		/Library/Frameworks/QtOpenGL.framework/QtOpenGL.prl \
		/Library/Frameworks/QtGui.framework/QtGui.prl \
		/Library/Frameworks/QtCore.framework/QtCore.prl \
		/Library/Frameworks/QtNetwork.framework/QtNetwork.prl
	$(QMAKE) -spec /usr/local/Qt4.8/mkspecs/macx-g++ CONFIG+=release CONFIG+=x86_64 -o Makefile QtProcessingStudent.pro
/usr/local/Qt4.8/mkspecs/common/unix.conf:
/usr/local/Qt4.8/mkspecs/common/mac.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf:
/usr/local/Qt4.8/mkspecs/common/g++-base.conf:
/usr/local/Qt4.8/mkspecs/common/g++-macx.conf:
/usr/local/Qt4.8/mkspecs/qconfig.pri:
/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Qt4.8/mkspecs/features/qt_functions.prf:
/usr/local/Qt4.8/mkspecs/features/qt_config.prf:
/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf:
/usr/local/Qt4.8/mkspecs/features/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/release.prf:
/usr/local/Qt4.8/mkspecs/features/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf:
/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf:
/usr/local/Qt4.8/mkspecs/features/shared.prf:
/usr/local/Qt4.8/mkspecs/features/warn_on.prf:
/usr/local/Qt4.8/mkspecs/features/qt.prf:
/usr/local/Qt4.8/mkspecs/features/unix/opengl.prf:
/usr/local/Qt4.8/mkspecs/features/unix/thread.prf:
/usr/local/Qt4.8/mkspecs/features/moc.prf:
/usr/local/Qt4.8/mkspecs/features/mac/rez.prf:
/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf:
/usr/local/Qt4.8/mkspecs/features/resources.prf:
/usr/local/Qt4.8/mkspecs/features/uic.prf:
/usr/local/Qt4.8/mkspecs/features/yacc.prf:
/usr/local/Qt4.8/mkspecs/features/lex.prf:
/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf:
/Library/Frameworks/QtOpenGL.framework/QtOpenGL.prl:
/Library/Frameworks/QtGui.framework/QtGui.prl:
/Library/Frameworks/QtCore.framework/QtCore.prl:
/Library/Frameworks/QtNetwork.framework/QtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Qt4.8/mkspecs/macx-g++ CONFIG+=release CONFIG+=x86_64 -o Makefile QtProcessingStudent.pro

QtProcessing.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) QtProcessing.app/Contents || $(MKDIR) QtProcessing.app/Contents 
	@$(DEL_FILE) QtProcessing.app/Contents/PkgInfo
	@echo "APPL????" >QtProcessing.app/Contents/PkgInfo
QtProcessing.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) QtProcessing.app/Contents/Resources || $(MKDIR) QtProcessing.app/Contents/Resources 
	@touch QtProcessing.app/Contents/Resources/empty.lproj
	
QtProcessing.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) QtProcessing.app/Contents || $(MKDIR) QtProcessing.app/Contents 
	@$(DEL_FILE) QtProcessing.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,QtProcessing,g" -e "s,@TYPEINFO@,????,g" /usr/local/Qt4.8/mkspecs/macx-g++/Info.plist.app >QtProcessing.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/QtProcessing1.0.0 || $(MKDIR) .tmp/QtProcessing1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/QtProcessing1.0.0/ && $(COPY_FILE) --parents src/playerinterface.h src/openglwidget.h src/Image/FImage.h src/Image/CVideo.h .tmp/QtProcessing1.0.0/ && $(COPY_FILE) --parents src/playerinterface.cpp src/openglwidget.cpp src/main.cpp src/Image/FImage.cpp src/Image/CVideo.cpp .tmp/QtProcessing1.0.0/ && (cd `dirname .tmp/QtProcessing1.0.0` && $(TAR) QtProcessing1.0.0.tar QtProcessing1.0.0 && $(COMPRESS) QtProcessing1.0.0.tar) && $(MOVE) `dirname .tmp/QtProcessing1.0.0`/QtProcessing1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/QtProcessing1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r QtProcessing.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_playerinterface.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_playerinterface.cpp
moc_playerinterface.cpp: src/Image/CVideo.h \
		src/Image/FImage.h \
		src/openglwidget.h \
		src/GL/gl.h \
		src/GL/glext.h \
		src/GL/glu.h \
		src/playerinterface.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/playerinterface.h -o moc_playerinterface.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

playerinterface.o: src/playerinterface.cpp src/playerinterface.h \
		src/Image/CVideo.h \
		src/Image/FImage.h \
		src/openglwidget.h \
		src/GL/gl.h \
		src/GL/glext.h \
		src/GL/glu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o playerinterface.o src/playerinterface.cpp

openglwidget.o: src/openglwidget.cpp src/openglwidget.h \
		src/Image/CVideo.h \
		src/Image/FImage.h \
		src/GL/gl.h \
		src/GL/glext.h \
		src/GL/glu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o openglwidget.o src/openglwidget.cpp

main.o: src/main.cpp src/playerinterface.h \
		src/Image/CVideo.h \
		src/Image/FImage.h \
		src/openglwidget.h \
		src/GL/gl.h \
		src/GL/glext.h \
		src/GL/glu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

FImage.o: src/Image/FImage.cpp src/Image/FImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FImage.o src/Image/FImage.cpp

CVideo.o: src/Image/CVideo.cpp src/Image/CVideo.h \
		src/Image/FImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CVideo.o src/Image/CVideo.cpp

moc_playerinterface.o: moc_playerinterface.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_playerinterface.o moc_playerinterface.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
