#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T20:23:40
#
#-------------------------------------------------

QT       += testlib network gui

TARGET = tst_ConvertIntToArrayTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_ConvertIntToArrayTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/controllers -lcontrollers
