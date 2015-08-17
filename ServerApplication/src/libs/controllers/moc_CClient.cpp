/****************************************************************************
** Meta object code from reading C++ file 'CClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CClient_t {
    QByteArrayData data[14];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CClient_t qt_meta_stringdata_CClient = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 10),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 5),
QT_MOC_LITERAL(4, 26, 23),
QT_MOC_LITERAL(5, 50, 12),
QT_MOC_LITERAL(6, 63, 8),
QT_MOC_LITERAL(7, 72, 5),
QT_MOC_LITERAL(8, 78, 13),
QT_MOC_LITERAL(9, 92, 11),
QT_MOC_LITERAL(10, 104, 8),
QT_MOC_LITERAL(11, 113, 8),
QT_MOC_LITERAL(12, 122, 7),
QT_MOC_LITERAL(13, 130, 12)
    },
    "CClient\0Disconnect\0\0Error\0"
    "QTcpSocket::SocketError\0aSocketError\0"
    "ReadData\0aData\0MessageStatus\0const char*\0"
    "aMessage\0aTimeMsc\0NewData\0Disconnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06,
       3,    1,   45,    2, 0x06,
       6,    1,   48,    2, 0x06,
       8,    2,   51,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    0,   56,    2, 0x0a,
      13,    0,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CClient *_t = static_cast<CClient *>(_o);
        switch (_id) {
        case 0: _t->Disconnect(); break;
        case 1: _t->Error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->ReadData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->MessageStatus((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->NewData(); break;
        case 5: _t->Disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CClient::Disconnect)) {
                *result = 0;
            }
        }
        {
            typedef void (CClient::*_t)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CClient::Error)) {
                *result = 1;
            }
        }
        {
            typedef void (CClient::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CClient::ReadData)) {
                *result = 2;
            }
        }
        {
            typedef void (CClient::*_t)(const char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CClient::MessageStatus)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CClient.data,
      qt_meta_data_CClient,  qt_static_metacall, 0, 0}
};


const QMetaObject *CClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CClient.stringdata))
        return static_cast<void*>(const_cast< CClient*>(this));
    return QObject::qt_metacast(_clname);
}

int CClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CClient::Disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CClient::Error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CClient::ReadData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CClient::MessageStatus(const char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
