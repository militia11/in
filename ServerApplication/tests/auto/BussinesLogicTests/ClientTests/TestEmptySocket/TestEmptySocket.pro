#-------------------------------------------------
#
# Project created by QtCreator 2015-08-18T19:44:39
#
#-------------------------------------------------

QT       += testlib network

QT       -= gui

TARGET = tst_TestEmptySocketTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

TEMPLATE = app
INCLUDEPATH += ../../../../../src

SOURCES += tst_TestEmptySocketTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
