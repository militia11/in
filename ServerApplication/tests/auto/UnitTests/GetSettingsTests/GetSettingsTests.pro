#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T15:24:50
#
#-------------------------------------------------
include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../LinkingLibraries.pri)

QT       += widgets testlib core
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GetSettingsTests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../../ServerApplication

SOURCES += GetSettingsTests.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/ui -lui
LIBS += -L../../../../src/libs/dao -ldao
