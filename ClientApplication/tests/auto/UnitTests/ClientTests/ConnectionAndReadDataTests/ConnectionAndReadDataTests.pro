#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T14:20:03
#
#-------------------------------------------------

QT       += network testlib
#gui

TARGET = ConnectionAndReadDataTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ClientApplication

SOURCES += ConnectionAndReadDataTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../testlib -ltestlib
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare
