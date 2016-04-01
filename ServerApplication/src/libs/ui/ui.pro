#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:22:53
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)
include(../../../../LinkingLibraries.pri)

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../../..

#LIBS += -L../../share -lshare

TARGET = ui
TEMPLATE = lib
CONFIG += staticlib

SOURCES  += \
    CMainwindow.cpp \
    CServerSettingsDialog.cpp \
    CDatabaseConnectionDialog.cpp \
    CAboutProgramDialog.cpp

HEADERS  += \
    CMainwindow.h \
    CServerSettingsDialog.h \
    CDatabaseConnectionDialog.h \
    CAboutProgramDialog.h

FORMS    += \
    mainwindow.ui \
    CServerSettingsDialog.ui \
    CDatabaseConnectionDialog.ui \
    CAboutProgramDialog.ui

CONFIG += c++11
