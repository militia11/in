#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:22:53
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../..

TARGET = ui
TEMPLATE = lib
CONFIG += staticlib

SOURCES  += \
    mainwindow.cpp \
    CServerSettingsDialog.cpp

HEADERS  += \
    mainwindow.h \
    CServerSettingsDialog.h

FORMS    += \
    mainwindow.ui \
    CServerSettingsDialog.ui

