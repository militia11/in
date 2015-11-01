#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T21:10:05
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += testlib gui network core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ListeningTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ClientApplication

SOURCES += ListeningTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
LIBS += -L../../../../../../ServerApplication/src/libs/controllers -lcontrollers
LIBS += -L../../../../../../ClientApplication/src/libs/testssupport -ltestssupport


#LIBS += -L../../../../../src/libs/ui -lui

#LIBS += -L../../../../../src/libs/dao -ldao
