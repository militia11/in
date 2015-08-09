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

HEADERS += \
    CServer.h \
    CServerThread.h

SOURCES += \
    CServer.cc \
    CServerThread.cc
