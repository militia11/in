#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T11:12:13
#
#-------------------------------------------------

QT       += testlib gui network

TARGET	  = ConvertBetweenQImageAndQByteArrayTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ClientApplication

SOURCES += ConvertBetweenQImageAndQByteArrayTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../testlib -ltestlib
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare
