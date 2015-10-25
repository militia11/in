#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T17:36:59
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)
include(../../../../LinkingLibraries.pri)

QT       += network core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testssupport
TEMPLATE = lib
CONFIG += staticlib c++11

INCLUDEPATH += ../..

HEADERS += \
    CClientWrapper.h \
    CDatabaseConnectionDialogWrapper.h \
    CServerSettingsDialogWrapper.h \
    CClientMock.h \
    CServerMock.h

SOURCES += \
    CClientWrapper.cpp \
    CDatabaseConnectionDialogWrapper.cpp \
    CServerSettingsDialogWrapper.cpp \
    CClientMock.cpp \
    CServerMock.cpp

LIBS += -L../../src/libs/ui -lui
LIBS += -L../../src/libs/controllers -lcontrollers
