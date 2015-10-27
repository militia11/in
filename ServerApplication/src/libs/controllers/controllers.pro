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
    CServer.h \
    CSettings.h \
    CTransaction.h \
    CRetrievePhotoTransaction.h \
    CStorePhotoTransaction.h \
	IReceiver.h \
    IServer.h \
	CReceiver.h

SOURCES += \
    CServer.cpp \
    CSettings.cpp \
    CRetrievePhotoTransaction.cpp \
    CStorePhotoTransaction.cpp \
    CReceiver.cpp

CONFIG += c++11
