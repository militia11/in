#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T21:10:05
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += testlib gui network core

TARGET = ListeningTests
CONFIG   += console c++11
CONFIG   -= app_bundle
TEMPLATE = app

INCLUDEPATH += ../../../../../../ServerApplication

SOURCES += ListeningTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
