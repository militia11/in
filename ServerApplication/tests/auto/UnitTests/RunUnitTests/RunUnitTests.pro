#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T20:43:28
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = RunUnitTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
INCLUDEPATH += ../../../../../ServerApplication

LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/dao -ldao
LIBS += -L../../../../share -lshare
