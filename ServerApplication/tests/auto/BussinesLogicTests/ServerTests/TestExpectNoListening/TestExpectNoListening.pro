#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T20:36:21
#
#-------------------------------------------------

QT       += network testlib

QT       -= gui

TARGET = tst_TestExpectListeningFail
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_TestExpectListeningFail.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../../../../../src
LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../src/libs/controllers -lcontrollers
