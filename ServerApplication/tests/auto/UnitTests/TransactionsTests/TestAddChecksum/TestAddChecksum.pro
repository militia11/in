#-------------------------------------------------
#
# Project created by QtCreator 2015-10-14T18:44:08
#
#-------------------------------------------------

QT       += testlib gui

include(../../../../../../AutogenerowanePoprawka.pri)
include(../../../../../../BibliotekiLinkowanie.pri)

TARGET = tst_AddChecksum
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
INCLUDEPATH += ../../../../../src

SOURCES += tst_AddChecksum.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
#LIBS += -L../../../../../share -lshare
