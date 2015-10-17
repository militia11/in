#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:20:18
#
#-------------------------------------------------

include(../../../../AutogenerowanePoprawka.pri)
include(../../../../BibliotekiLinkowanie.pri)

QT       += network core gui

TARGET = controllers
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../..

HEADERS += \
    CClient.h \
    CServer.h \
    CSettings.h \
    CTransaction.h \
    CRetrievePhotoTransaction.h \
    CStorePhotoTransaction.h \
    IClient.h

SOURCES += \
    CClient.cpp \
    CServer.cpp \
    CSettings.cpp \
    CRetrievePhotoTransaction.cpp \
    CStorePhotoTransaction.cpp

CONFIG += c++11
