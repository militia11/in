TEMPLATE = subdirs

SUBDIRS += \
    ServerApplication

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesqld
else:unix: LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql

INCLUDEPATH += $$PWD/../../../../litesql/lib/static
DEPENDPATH += $$PWD/../../../../litesql/lib/static
