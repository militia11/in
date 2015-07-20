#-------------------------------------------------
#
# Project created by QtCreator 2015-07-20T21:37:00
#
#-------------------------------------------------

QT       -= gui

TARGET = libs
TEMPLATE = lib

DEFINES += LIBS_LIBRARY

SOURCES += libs.cpp

HEADERS += libs.h\
        libs_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
