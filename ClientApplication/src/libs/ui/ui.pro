#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T18:13:33
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../..

TARGET = ui
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    CMainWindow.cpp

HEADERS += \
    CMainWindow.h

FORMS += \
    CMainWindow.ui

LIBS += -L../../../share -lshare

CONFIG += c++11
