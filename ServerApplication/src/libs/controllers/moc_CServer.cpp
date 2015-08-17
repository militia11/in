/****************************************************************************
** Meta object code from reading C++ file 'CServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CServer_t {
    QByteArrayData data[11];
    char stringdata[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CServer_t qt_meta_stringdata_CServer = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 12),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 13),
QT_MOC_LITERAL(4, 36, 11),
QT_MOC_LITERAL(5, 48, 8),
QT_MOC_LITERAL(6, 57, 8),
QT_MOC_LITERAL(7, 66, 18),
QT_MOC_LITERAL(8, 85, 18),
QT_MOC_LITERAL(9, 104, 15),
QT_MOC_LITERAL(10, 120, 14)
    },
    "CServer\0CreateClient\0\0MessageStatus\0"
    "const char*\0aMessage\0aTimeMsc\0"
    "ChangeServerStatus\0IncomingConnection\0"
    "ResumeAccepting\0PauseAccepting\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06,
       3,    2,   45,    2, 0x06,
       7,    0,   50,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x08,
       9,    0,   52,    2, 0x08,
      10,    0,   53,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CServer *_t = static_cast<CServer *>(_o);
        switch (_id) {
        case 0: _t->CreateClient(); break;
        case 1: _t->MessageStatus((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ChangeServerStatus(); break;
        case 3: _t->IncomingConnection(); break;
        case 4: _t->ResumeAccepting(); break;
        case 5: _t->PauseAccepting(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CServer::CreateClient)) {
                *result = 0;
            }
        }
        {
            typedef void (CServer::*_t)(const char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CServer::MessageStatus)) {
                *result = 1;
            }
        }
        {
            typedef void (CServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CServer::ChangeServerStatus)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_CServer.data,
      qt_meta_data_CServer,  qt_static_metacall, 0, 0}
};


const QMetaObject *CServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CServer.stringdata))
        return static_cast<void*>(const_cast< CServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int CServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CServer::CreateClient()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CServer::MessageStatus(const char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CServer::ChangeServerStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
