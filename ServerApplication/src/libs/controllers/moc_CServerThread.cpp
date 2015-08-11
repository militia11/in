/****************************************************************************
** Meta object code from reading C++ file 'CServerThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CServerThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CServerThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CServerThread_t {
    QByteArrayData data[10];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CServerThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CServerThread_t qt_meta_stringdata_CServerThread = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 5),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 23),
QT_MOC_LITERAL(4, 45, 12),
QT_MOC_LITERAL(5, 58, 8),
QT_MOC_LITERAL(6, 67, 11),
QT_MOC_LITERAL(7, 79, 5),
QT_MOC_LITERAL(8, 85, 9),
QT_MOC_LITERAL(9, 95, 16)
    },
    "CServerThread\0Error\0\0QTcpSocket::SocketError\0"
    "aSocketError\0ReadData\0QByteArray*\0"
    "aData\0ReadyRead\0ConnectionLosted\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CServerThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,
       5,    1,   37,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       8,    0,   40,    2, 0x0a,
       9,    0,   41,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CServerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CServerThread *_t = static_cast<CServerThread *>(_o);
        switch (_id) {
        case 0: _t->Error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->ReadData((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 2: _t->ReadyRead(); break;
        case 3: _t->ConnectionLosted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CServerThread::*_t)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CServerThread::Error)) {
                *result = 0;
            }
        }
        {
            typedef void (CServerThread::*_t)(QByteArray * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CServerThread::ReadData)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CServerThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CServerThread.data,
      qt_meta_data_CServerThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *CServerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CServerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CServerThread.stringdata))
        return static_cast<void*>(const_cast< CServerThread*>(this));
    return QObject::qt_metacast(_clname);
}

int CServerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CServerThread::Error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CServerThread::ReadData(QByteArray * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
