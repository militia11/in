#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T20:09:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

INCLUDEPATH += ../..

SOURCES += \
    main.cpp

LIBS += -L../libs/ui -lui
LIBS += -L../libs/controllers -lcontrollers
LIBS += -L../libs/dao -ldao

CONFIG += c++11

DISTFILES += \
    android-sources/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
