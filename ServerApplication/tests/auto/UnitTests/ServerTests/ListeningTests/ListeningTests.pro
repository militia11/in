#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T21:10:05
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../BibliotekiLinkowanie.pri)

QT       += testlib gui network

TARGET = ListeningTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += ListeningTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
