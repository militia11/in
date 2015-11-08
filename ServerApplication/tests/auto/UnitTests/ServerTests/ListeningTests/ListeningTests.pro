#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T21:10:05
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += testlib network

TARGET = ListeningTests
CONFIG   += console c++11
CONFIG   -= app_bundle
TEMPLATE = app

INCLUDEPATH += ../../../../../

SOURCES += ListeningTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../testlibs -ltestlibs
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao

