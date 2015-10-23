#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:22:06
#
#-------------------------------------------------

include(../../../../AutogeneratingEmendation.pri)
include(../../../../BibliotekiLinkowanie.pri)

QT	 += core
QT       -= gui

TARGET = dao
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../..

HEADERS += \
    CRepository.h \
    CChecksumList.h \
    androidphotosdatabase.hpp

SOURCES += \
    CRepository.cpp \
    CChecksumList.cpp \
    androidphotosdatabase.cpp

CONFIG += c++11
