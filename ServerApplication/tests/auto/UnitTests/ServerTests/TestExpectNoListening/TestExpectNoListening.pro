#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T20:36:21
#
#-------------------------------------------------

QT       += network testlib gui

include(../../../../../../AutogeneratingEmendation.pri)
include(../../../../../../LinkingLibraries.pri)

TARGET = tst_TestExpectListeningFail
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../src

SOURCES += \
    tst_ExpectNoListening.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../../src/libs/ui -lui
LIBS += -L../../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../../src/libs/dao -ldao

