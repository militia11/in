#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T17:36:59
#
#-------------------------------------------------

include(../../../../AutogenerowanePoprawka.pri)
include(../../../../BibliotekiLinkowanie.pri)
QT       += network core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testssupport
TEMPLATE = lib
CONFIG += staticlib

HEADERS += \
    CClientWrapper.h \
    CDatabaseConnectionDialogWrapper.h \
    CServerSettingsDialogWrapper.h

SOURCES += \
    CClientWrapper.cpp \
    CDatabaseConnectionDialogWrapper.cpp \
    CServerSettingsDialogWrapper.cpp

INCLUDEPATH += ../..

LIBS += -L../../src/libs/ui -lui
LIBS += -L../../src/libs/controllers -lcontrollers
#LIBS += -L../../src/libs/dao -ldao
#LIBS += -L../../share -lshare
