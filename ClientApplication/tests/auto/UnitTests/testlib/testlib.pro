#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T14:49:08
#
#-------------------------------------------------

QT       += core network
QT       -=  gui

TARGET = testlib
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../../../../../ClientApplication

HEADERS += \
    CClientWrapper.h

SOURCES += \
    CClientWrapper.cpp

LIBS += -L../../../../src/libs/controllers -lcontrollers
