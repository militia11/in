#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T01:51:45
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += testlib gui network

TARGET = CalculateChecksumTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += CalculateChecksumTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../../../../../

LIBS += -L../../testlibs -ltestlibs
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
