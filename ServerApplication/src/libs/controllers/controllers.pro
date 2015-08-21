#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:20:18
#
#-------------------------------------------------

include(../../../../AutogenerowanePoprawka.pri)

QT       -= gui
QT       += network core

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

CONFIG += c++11
