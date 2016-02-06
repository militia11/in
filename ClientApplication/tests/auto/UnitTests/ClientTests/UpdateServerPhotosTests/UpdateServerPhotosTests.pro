#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T20:24:54
#
#-------------------------------------------------

QT       += testlib network

QT       -= gui

TARGET = UpdateServerPhotosTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../../ClientApplication

LIBS += -L../../testlib -ltestlib
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare


SOURCES += UpdateServerPhotosTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
