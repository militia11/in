#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T20:44:43
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += testlib gui network

TARGET = tst_MessageFormatTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += tst_MessageFormatTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
