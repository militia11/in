#-------------------------------------------------
#
# Project created by QtCreator 2015-08-18T19:20:06
#
#-------------------------------------------------

QT       += network testlib

QT       -= gui

TARGET = tst_TestNoClientConnectedToServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_TestNoClientConnectedToServer.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
