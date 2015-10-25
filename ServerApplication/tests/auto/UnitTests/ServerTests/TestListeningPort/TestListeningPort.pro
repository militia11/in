#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T04:18:26
#
#-------------------------------------------------

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

QT       += network testlib gui

TARGET = tst_TestListeningSpecifyPort
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app\

INCLUDEPATH += ../../../../../src

SOURCES += tst_TestListeningSpecifyPort.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao
