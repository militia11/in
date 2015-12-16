#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T18:13:33
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../../..

TARGET = ui
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
	MainWindow.cpp

HEADERS += \
	MainWindow.h

FORMS += \
	MainWindow.ui

LIBS += -L../../../ClientApplication/share -lshare

CONFIG += c++11
