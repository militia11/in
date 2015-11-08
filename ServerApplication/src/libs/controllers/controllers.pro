#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:20:18
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)
include(../../../../LinkingLibraries.pri)

QT       += network core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = controllers
TEMPLATE = lib
CONFIG += staticlib c++11

INCLUDEPATH += ../../..

HEADERS += \
    CServer.h \
    CSettings.h \
    CTransaction.h \
    CRetrievePhotoTransaction.h \
    CStorePhotoTransaction.h \
    IReceiver.h \
    IServer.h \
    CReceiver.h \
    IReceiverFactory.h \
    CReceiverFactoryImplementation.h \
    CReceiverMock.h \
    CReceiverMockFactory.h \
    CServerWrapper.h \
    CReceiverWrapper.h

SOURCES += \
    CServer.cpp \
    CSettings.cpp \
    CRetrievePhotoTransaction.cpp \
    CStorePhotoTransaction.cpp \
    CReceiver.cpp \
    CReceiverFactoryImplementation.cpp \
    CReceiverMock.cpp \
    CReceiverMockFactory.cpp \
    CServerWrapper.cc \
    CReceiverWrapper.cpp
