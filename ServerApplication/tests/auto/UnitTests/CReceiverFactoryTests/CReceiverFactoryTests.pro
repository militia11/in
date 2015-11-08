#-------------------------------------------------
#
# Project created by QtCreator 2015-11-03T17:50:48
#
#-------------------------------------------------

include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../LinkingLibraries.pri)

QT       += testlib core network

TARGET = CReceiverFactoryTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../

SOURCES += CReceiverFactoryTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../testlibs -ltestlibs
LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/dao -ldao
