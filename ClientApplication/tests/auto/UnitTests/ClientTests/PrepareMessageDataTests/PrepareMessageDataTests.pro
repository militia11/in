#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T20:54:25
#
#-------------------------------------------------

QT       += testlib network gui core

TARGET	  = PrepareMessageDataTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ClientApplication

SOURCES += PrepareMessageDataTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare
