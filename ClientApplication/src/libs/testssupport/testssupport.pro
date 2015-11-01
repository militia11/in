#-------------------------------------------------
#
# Project created by QtCreator 2015-11-01T12:26:40
#
#-------------------------------------------------

QT       += network core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testssupport
TEMPLATE = lib
CONFIG += staticlib c++11

INCLUDEPATH += ../../..

SOURCES += \
    CClientMock.cpp

HEADERS += \
    CClientMock.h

#LIBS += -L../src/controllers -lcontrollers
#LIBS += -L../dao -ldao
