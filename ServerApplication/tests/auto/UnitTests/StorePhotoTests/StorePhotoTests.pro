#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T19:20:40
#
#-------------------------------------------------

QT       += sql testlib gui

include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../LinkingLibraries.pri)

TARGET = StorePhotoTests
CONFIG   += console c++11
CONFIG   -= app_bundle

INCLUDEPATH += ../../../../../ServerApplication

SOURCES += \
    StorePhotoTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/dao -ldao
LIBS += -L../../../../share -lshare
