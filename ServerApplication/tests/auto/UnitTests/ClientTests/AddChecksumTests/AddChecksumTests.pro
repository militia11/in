#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T01:58:11
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../BibliotekiLinkowanie.pri)

QT       += testlib gui

TARGET = AddChecksumTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += AddChecksumTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare
