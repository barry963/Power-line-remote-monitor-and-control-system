#############################################################################
# Makefile for building: mySerialPortTools
# Generated by qmake (2.01a) (Qt 4.6.2) on: ?? 2? 19 14:01:09 2013
# Project:  mySerialPortTools.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile mySerialPortTools.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/usr/include/qt4/QtTest -Itemp/moc -Itemp/ui
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtTest -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = temp/obj/

####### Files

SOURCES       = main.cpp \
		frmMain.cpp \
		qextserialenumerator.cpp \
		qextserialbase.cpp \
		posix_qextserialport.cpp \
		iec101analyser.cpp \
		modbusanalyser.cpp \
		xbeltree.cpp temp/moc/moc_frmMain.cpp \
		temp/moc/moc_qextserialbase.cpp \
		temp/moc/moc_xbeltree.cpp \
		temp/rcc/qrc_myResource.cpp
OBJECTS       = temp/obj/main.o \
		temp/obj/frmMain.o \
		temp/obj/qextserialenumerator.o \
		temp/obj/qextserialbase.o \
		temp/obj/posix_qextserialport.o \
		temp/obj/iec101analyser.o \
		temp/obj/modbusanalyser.o \
		temp/obj/xbeltree.o \
		temp/obj/moc_frmMain.o \
		temp/obj/moc_qextserialbase.o \
		temp/obj/moc_xbeltree.o \
		temp/obj/qrc_myResource.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qtestlib.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		mySerialPortTools.pro
QMAKE_TARGET  = mySerialPortTools
DESTDIR       = 
TARGET        = mySerialPortTools

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

all: Makefile $(TARGET)

$(TARGET): temp/ui/ui_frmMain.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: mySerialPortTools.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qtestlib.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtTest.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile mySerialPortTools.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/qtestlib.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtTest.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile mySerialPortTools.pro

dist: 
	@$(CHK_DIR_EXISTS) temp/obj/mySerialPortTools1.0.0 || $(MKDIR) temp/obj/mySerialPortTools1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) temp/obj/mySerialPortTools1.0.0/ && $(COPY_FILE) --parents frmMain.h qextserialenumerator.h qextserialbase.h posix_qextserialport.h iec101analyser.h modbusanalyser.h xbeltree.h temp/obj/mySerialPortTools1.0.0/ && $(COPY_FILE) --parents myResource.qrc temp/obj/mySerialPortTools1.0.0/ && $(COPY_FILE) --parents main.cpp frmMain.cpp qextserialenumerator.cpp qextserialbase.cpp posix_qextserialport.cpp iec101analyser.cpp modbusanalyser.cpp xbeltree.cpp temp/obj/mySerialPortTools1.0.0/ && $(COPY_FILE) --parents frmMain.ui temp/obj/mySerialPortTools1.0.0/ && (cd `dirname temp/obj/mySerialPortTools1.0.0` && $(TAR) mySerialPortTools1.0.0.tar mySerialPortTools1.0.0 && $(COMPRESS) mySerialPortTools1.0.0.tar) && $(MOVE) `dirname temp/obj/mySerialPortTools1.0.0`/mySerialPortTools1.0.0.tar.gz . && $(DEL_FILE) -r temp/obj/mySerialPortTools1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: temp/moc/moc_frmMain.cpp temp/moc/moc_qextserialbase.cpp temp/moc/moc_xbeltree.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) temp/moc/moc_frmMain.cpp temp/moc/moc_qextserialbase.cpp temp/moc/moc_xbeltree.cpp
temp/moc/moc_frmMain.cpp: posix_qextserialport.h \
		qextserialbase.h \
		qextserialenumerator.h \
		iec101analyser.h \
		modbusanalyser.h \
		mainwindow.h \
		dialog.h \
		xbeltree.h \
		frmMain.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) frmMain.h -o temp/moc/moc_frmMain.cpp

temp/moc/moc_qextserialbase.cpp: qextserialbase.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) qextserialbase.h -o temp/moc/moc_qextserialbase.cpp

temp/moc/moc_xbeltree.cpp: xbeltree.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) xbeltree.h -o temp/moc/moc_xbeltree.cpp

compiler_rcc_make_all: temp/rcc/qrc_myResource.cpp
compiler_rcc_clean:
	-$(DEL_FILE) temp/rcc/qrc_myResource.cpp
temp/rcc/qrc_myResource.cpp: myResource.qrc \
		1.ico
	/usr/bin/rcc -name myResource myResource.qrc -o temp/rcc/qrc_myResource.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: temp/ui/ui_frmMain.h
compiler_uic_clean:
	-$(DEL_FILE) temp/ui/ui_frmMain.h
temp/ui/ui_frmMain.h: frmMain.ui
	/usr/bin/uic-qt4 frmMain.ui -o temp/ui/ui_frmMain.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

temp/obj/main.o: main.cpp frmMain.h \
		posix_qextserialport.h \
		qextserialbase.h \
		qextserialenumerator.h \
		iec101analyser.h \
		modbusanalyser.h \
		mainwindow.h \
		dialog.h \
		xbeltree.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/main.o main.cpp

temp/obj/frmMain.o: frmMain.cpp frmMain.h \
		posix_qextserialport.h \
		qextserialbase.h \
		qextserialenumerator.h \
		iec101analyser.h \
		modbusanalyser.h \
		mainwindow.h \
		dialog.h \
		xbeltree.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/frmMain.o frmMain.cpp

temp/obj/qextserialenumerator.o: qextserialenumerator.cpp qextserialenumerator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/qextserialenumerator.o qextserialenumerator.cpp

temp/obj/qextserialbase.o: qextserialbase.cpp qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/qextserialbase.o qextserialbase.cpp

temp/obj/posix_qextserialport.o: posix_qextserialport.cpp posix_qextserialport.h \
		qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/posix_qextserialport.o posix_qextserialport.cpp

temp/obj/iec101analyser.o: iec101analyser.cpp iec101analyser.h \
		modbusanalyser.h \
		xbeltree.h \
		frmMain.h \
		posix_qextserialport.h \
		qextserialbase.h \
		qextserialenumerator.h \
		mainwindow.h \
		dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/iec101analyser.o iec101analyser.cpp

temp/obj/modbusanalyser.o: modbusanalyser.cpp modbusanalyser.h \
		iec101analyser.h \
		xbeltree.h \
		frmMain.h \
		posix_qextserialport.h \
		qextserialbase.h \
		qextserialenumerator.h \
		mainwindow.h \
		dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/modbusanalyser.o modbusanalyser.cpp

temp/obj/xbeltree.o: xbeltree.cpp xbeltree.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/xbeltree.o xbeltree.cpp

temp/obj/moc_frmMain.o: temp/moc/moc_frmMain.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/moc_frmMain.o temp/moc/moc_frmMain.cpp

temp/obj/moc_qextserialbase.o: temp/moc/moc_qextserialbase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/moc_qextserialbase.o temp/moc/moc_qextserialbase.cpp

temp/obj/moc_xbeltree.o: temp/moc/moc_xbeltree.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/moc_xbeltree.o temp/moc/moc_xbeltree.cpp

temp/obj/qrc_myResource.o: temp/rcc/qrc_myResource.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp/obj/qrc_myResource.o temp/rcc/qrc_myResource.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

