#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T20:32:59
#
#-------------------------------------------------

include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../BibliotekiLinkowanie.pri)

QT       += testlib gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SettingsTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../src

SOURCES += SettingsTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/testssupport -ltestssupport
LIBS += -L../../../../src/libs/dao -ldao
