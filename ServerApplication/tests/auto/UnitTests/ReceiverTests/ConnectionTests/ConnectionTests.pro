#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T20:44:43
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += core gui network testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConnectionTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ServerApplication

SOURCES += ConnectionTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
