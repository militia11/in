#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:25:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app
TRANSLATIONS += sa_en_SE.ts
SOURCES += main.cc

INCLUDEPATH += ..

LIBS += -L../libs/ui -lui
LIBS += -L../libs/dao -ldao
LIBS += -L../libs/controllers -lcontrollers

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += litesql
