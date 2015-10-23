#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:22:53
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../..

TARGET = ui
TEMPLATE = lib
CONFIG += staticlib

SOURCES  += \
    CMainwindow.cpp \
    CServerSettingsDialog.cpp \
    CDatabaseConnectionDialog.cpp

HEADERS  += \
    CMainwindow.h \
    CServerSettingsDialog.h \
    CDatabaseConnectionDialog.h

FORMS    += \
    mainwindow.ui \
    CServerSettingsDialog.ui \
    CDatabaseConnectionDialog.ui

CONFIG += c++11
