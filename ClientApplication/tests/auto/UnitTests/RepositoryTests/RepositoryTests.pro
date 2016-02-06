#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T20:01:48
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = RepositoryTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../ClientApplication

LIBS += -L../testlib -ltestlib
LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/dao -ldao
LIBS += -L../../../../share -lshare

SOURCES += RepositoryTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
