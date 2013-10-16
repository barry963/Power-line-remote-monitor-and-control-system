# -------------------------------------------------
# Project created by QtCreator 2012-12-02T15:59:14
# -------------------------------------------------
QT += core
TARGET = mySerialPortTools
TEMPLATE = app
CONFIG += qtestlib

# include(./qtpropertybrowser/src/qtpropertybrowser.pri)
SOURCES += main.cpp \
    frmMain.cpp \
    qextserialenumerator.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp \
    iec101analyser.cpp \
    modbusanalyser.cpp \
    xbeltree.cpp
HEADERS += frmMain.h \
    qextserialenumerator.h \
    qextserialbase.h \
    posix_qextserialport.h \
    iec101analyser.h \
    modbusanalyser.h \
    xbeltree.h
FORMS += frmMain.ui
RESOURCES += myResource.qrc
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
win32:RC_FILE = main.rc
OTHER_FILES += main.rc
