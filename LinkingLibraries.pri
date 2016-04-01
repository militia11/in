unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += litesql


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesqld
else:unix: LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql

INCLUDEPATH += $$PWD/../../../../litesql/include
DEPENDPATH += $$PWD/../../../../litesql/include



HEADERS +=

SOURCES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql_sqlite
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql_sqlited
else:unix: LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql_sqlite

INCLUDEPATH += $$PWD/../../../../litesql/include/litesql
DEPENDPATH += $$PWD/../../../../litesql/include/litesql

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql-util
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql-utild
else:unix: LIBS += -L$$PWD/../../../../litesql/lib/static/ -llitesql-util

INCLUDEPATH += $$PWD/../../../../litesql/include/litesql
DEPENDPATH += $$PWD/../../../../litesql/include/litesql
