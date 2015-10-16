#-------------------------------------------------
#
# Project created by QtCreator 2015-10-14T18:43:35
#
#-------------------------------------------------

include(../../../../../../AutogenerowanePoprawka.pri)
include(../../../../../../BibliotekiLinkowanie.pri)

QT       += testlib gui

TARGET = tst_CheckFileChecksumTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += \
    tst_CheckFileChecksum.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
LIBS += -L../../../../../share -lshare
