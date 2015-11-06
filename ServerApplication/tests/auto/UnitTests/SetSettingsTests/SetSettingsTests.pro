#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T15:24:50
#
#-------------------------------------------------
include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../LinkingLibraries.pri)

QT       += widgets sql testlib network core testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SetSettingsTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../

SOURCES += SetSettingsTests.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/dao -ldao
