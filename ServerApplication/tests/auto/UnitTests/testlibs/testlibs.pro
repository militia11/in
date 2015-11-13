#-------------------------------------------------
#
# Project created by QtCreator 2015-11-08T10:47:52
#
#-------------------------------------------------

include(../../../../../AutogeneratingEmendation.pri)
include(../../../../../LinkingLibraries.pri)

QT       += network core gui

TARGET = testlibs
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += \
    CServerWrapper.cc \
    CReceiverWrapper.cpp \
    CReceiverMock.cpp \
    CReceiverMockFactory.cpp \
    QTcpSocketMock.cpp

HEADERS += \
    CServerWrapper.h \
    CReceiverWrapper.h \
    CReceiverMock.h \
    CReceiverMockFactory.h \
    QTcpSocketMock.h

INCLUDEPATH += ../../../../

LIBS += -L../../../../src/libs/controllers -lcontrollers
LIBS += -L../../../../src/libs/dao -ldao
LIBS += -L../testlibs -ltestlibs
