#-------------------------------------------------
#
# Project created by QtCreator 2015-08-12T08:51:29
#
#-------------------------------------------------

QT       += core network gui

TARGET = controllers
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../../..

SOURCES += \
    CClient.cpp

HEADERS += \
    CClient.h \
    IClient.h

LIBS += -L../src/dao -ldao

CONFIG += c++11
