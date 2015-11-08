#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T23:16:49
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += testlib gui network

TARGET = DataMethodsTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../

SOURCES += DataMethodsTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../testlibs -ltestlibs
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
