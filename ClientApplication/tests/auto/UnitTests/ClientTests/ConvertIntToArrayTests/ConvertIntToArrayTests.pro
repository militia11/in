#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T20:23:40
#
#-------------------------------------------------

QT       += testlib network gui core

TARGET = ConvertIntToArrayTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ClientApplication

SOURCES += ConvertIntToArrayTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare
