#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T03:44:25
#
#-------------------------------------------------

QT       += sql testlib

QT       -= gui

TARGET = tst_TestConnectionDB
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
INCLUDEPATH += ../../../../../src

SOURCES += tst_TestConnectionDB.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../src/libs/controllers -lcontrollers

