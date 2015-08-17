#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T20:50:17
#
#-------------------------------------------------

QT       += network testlib

QT       -= gui

TARGET = tst_TestListeningPortWrongNumberTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_TestListeningPortWrongNumberTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../src/libs/controllers -lcontrollers
