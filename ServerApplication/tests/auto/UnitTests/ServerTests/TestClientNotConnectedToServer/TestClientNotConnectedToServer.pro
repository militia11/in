#-------------------------------------------------
#
# Project created by QtCreator 2015-08-18T19:20:06
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += network testlib

TARGET = tst_TestNoClientConnectedToServer
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../

SOURCES += \
    tst_ClientNotConnectedToServer.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../testlibs -ltestlibs
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
