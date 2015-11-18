#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T10:27:02
#
#-------------------------------------------------

QT       += network testlib gui

TARGET = WriteMethodsTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ClientApplication

SOURCES += WriteMethodsTests.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../testlib -ltestlib
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare


