#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T19:20:40
#
#-------------------------------------------------

QT       += sql testlib gui

include(../../../../../../AutogenerowanePoprawka.pri)
include(../../../../../../BibliotekiLinkowanie.pri)

TARGET = tst_StorePhoto
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ../../../../../src

SOURCES += tst_StorePhoto.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare


