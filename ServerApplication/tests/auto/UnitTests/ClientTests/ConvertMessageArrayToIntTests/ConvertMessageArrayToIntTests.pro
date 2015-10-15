#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T00:05:25
#
#-------------------------------------------------

include(../../../../../../AutogenerowanePoprawka.pri)
include(../../../../../../BibliotekiLinkowanie.pri)

QT       += testlib gui network

TARGET = ConvertMessageArrayToIntTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += ConvertMessageArrayToIntTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
