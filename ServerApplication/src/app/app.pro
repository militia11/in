#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T22:25:07
#
#-------------------------------------------------

include(../../../AutogeneratingEmendation.pri)
include(../../../LinkingLibraries.pri)

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += ../..

#LIBS += -L../libs/ui -lui
#LIBS += -L../libs/controllers -lcontrollers
#LIBS += -L../libs/dao -ldao
#LIBS += -L../../share -lshare

CONFIG += c++11

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/ui/release/ -lui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/ui/debug/ -lui

INCLUDEPATH += $$PWD/../libs/ui
DEPENDPATH += $$PWD/../libs/ui

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/ui/release/libui.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/ui/debug/libui.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/ui/release/ui.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/ui/debug/ui.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/controllers/release/ -lcontrollers
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/controllers/debug/ -lcontrollers
else:unix: LIBS += -L$$OUT_PWD/../libs/controllers/ -lcontrollers

INCLUDEPATH += $$PWD/../libs/controllers
DEPENDPATH += $$PWD/../libs/controllers

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/controllers/release/libcontrollers.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/controllers/debug/libcontrollers.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/controllers/release/controllers.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/controllers/debug/controllers.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libs/controllers/libcontrollers.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/dao/release/ -ldao
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/dao/debug/ -ldao
else:unix: LIBS += -L$$OUT_PWD/../libs/dao/ -ldao

INCLUDEPATH += $$PWD/../libs/dao
DEPENDPATH += $$PWD/../libs/dao

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/dao/release/libdao.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/dao/debug/libdao.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/dao/release/dao.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/dao/debug/dao.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libs/dao/libdao.a
