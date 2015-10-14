#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T20:54:25
#
#-------------------------------------------------

QT       += testlib network gui

TARGET	  = tst_PrepareMessageData
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_PrepareMessageData.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/controllers -lcontrollers
