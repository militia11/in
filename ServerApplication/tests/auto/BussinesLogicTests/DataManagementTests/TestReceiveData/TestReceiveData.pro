#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T03:50:48
#
#------------------------------------------------

QT       += testlib network

QT       -= gui

TARGET = tst_TestReceiveNewData
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


INCLUDEPATH += ../../../../../src

SOURCES += tst_TestReceiveNewData.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao

