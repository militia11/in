#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:20:18
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)
include(../../../../LinkingLibraries.pri)

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
    IClient.h \
    IServer.h

SOURCES += \
    CClient.cpp \
    CServer.cpp \
    CSettings.cpp \
    CRetrievePhotoTransaction.cpp \
    CStorePhotoTransaction.cpp

CONFIG += c++11
