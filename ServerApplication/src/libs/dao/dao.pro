#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:22:06
#
#-------------------------------------------------

include(../../../../AutogenerowanePoprawka.pri)
include(../../../../BibliotekiLinkowanie.pri)

QT       -= gui
QT	 += core

TARGET = dao
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../..

HEADERS += \
    CRepository.h \
    CCheckSumList.h \
    androidphotosdatabase.hpp

SOURCES += \
    CRepository.cpp \
    CCheckSumList.cpp \
    androidphotosdatabase.cpp

CONFIG += c++11
