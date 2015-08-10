#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T18:43:51
#
#-------------------------------------------------

QT       -= core gui

TARGET = dao
TEMPLATE = lib
CONFIG += staticlib

SOURCES +=

HEADERS +=
unix {
    target.path = /usr/lib
    INSTALLS += target
}
