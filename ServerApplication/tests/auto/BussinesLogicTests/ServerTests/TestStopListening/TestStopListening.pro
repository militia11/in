#-------------------------------------------------
#
# Project created by QtCreator 2015-08-17T19:03:32
#
#-------------------------------------------------

QT       += network testlib

QT       -= gui

TARGET = tst_TestSrvStopListening
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_TestSrvStopListening.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../src/libs/controllers -lcontrollers
