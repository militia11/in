#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:25:07
#
#-------------------------------------------------

include(../../../AutogenerowanePoprawka.pri)
include(../../../BibliotekiLinkowanie.pri)

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = app
TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += ..

LIBS += -L../libs/ui -lui
LIBS += -L../libs/dao -ldao
LIBS += -L../libs/controllers -lcontrollers

CONFIG += c++11
