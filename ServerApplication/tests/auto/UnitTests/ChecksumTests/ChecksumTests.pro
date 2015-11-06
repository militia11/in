#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T12:30:04
#
#-------------------------------------------------

include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../LinkingLibraries.pri)

QT       += testlib gui testlib network core

TARGET = ChecksumTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../ServerApplication

SOURCES += ChecksumTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/dao -ldao
LIBS += -L../../../../share -lshare
