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
    CClientWrapper.h \
    CQTcpSocketMock.h

SOURCES += \
    CClientWrapper.cpp \
	CQTcpSocketMock.cpp

LIBS += -L../../../../src/libs/controllers -lcontrollers
