#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:20:18
#
#-------------------------------------------------

QT       -= core gui
QT       += network

TARGET = controllers
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../..

HEADERS += \
    CClient.h \
    CServer.h \
    CSettings.h

SOURCES += \
    CClient.cpp \
    CServer.cpp \
    CSettings.cpp
