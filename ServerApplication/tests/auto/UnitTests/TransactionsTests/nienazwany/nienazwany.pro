#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T22:47:21
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = nienazwany
TEMPLATE = app

INCLUDEPATH += ..

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

LIBS += -L../data -ldata
