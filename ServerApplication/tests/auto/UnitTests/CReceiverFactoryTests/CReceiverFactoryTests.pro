#-------------------------------------------------
#
# Project created by QtCreator 2015-11-03T17:50:48
#
#-------------------------------------------------

include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../LinkingLibraries.pri)

QT       += testlib gui network core

TARGET = CReceiverFactoryTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../

SOURCES += CReceiverFactoryTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/dao -ldao
