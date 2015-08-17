#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T03:39:44
#
#-------------------------------------------------

QT       += network testlib

QT       -= gui

TARGET = tst_TestInitServerTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_TestInitServerTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../src/libs/controllers -lcontrollers
