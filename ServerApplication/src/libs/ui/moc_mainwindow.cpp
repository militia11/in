/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 5),
QT_MOC_LITERAL(4, 30, 15),
QT_MOC_LITERAL(5, 46, 13),
QT_MOC_LITERAL(6, 60, 10),
QT_MOC_LITERAL(7, 71, 11),
QT_MOC_LITERAL(8, 83, 14),
QT_MOC_LITERAL(9, 98, 8),
QT_MOC_LITERAL(10, 107, 9),
QT_MOC_LITERAL(11, 117, 10),
QT_MOC_LITERAL(12, 128, 14),
QT_MOC_LITERAL(13, 143, 26),
QT_MOC_LITERAL(14, 170, 24),
QT_MOC_LITERAL(15, 195, 10),
QT_MOC_LITERAL(16, 206, 12),
QT_MOC_LITERAL(17, 219, 6)
    },
    "MainWindow\0DisplayData\0\0aData\0"
    "ClientConnected\0ClientCreated\0ShowStatus\0"
    "const char*\0aMessageStatus\0aTimeMsc\0"
    "RunServer\0StopServer\0ServerSettings\0"
    "DatabaseConnectionSettings\0"
    "ChangeActionServerStatus\0closeEvent\0"
    "QCloseEvent*\0aEvent\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08,
       4,    0,   67,    2, 0x08,
       5,    0,   68,    2, 0x08,
       6,    2,   69,    2, 0x08,
      10,    0,   74,    2, 0x08,
      11,    0,   75,    2, 0x08,
      12,    0,   76,    2, 0x08,
      13,    0,   77,    2, 0x08,
      14,    0,   78,    2, 0x08,
      15,    1,   79,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->DisplayData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->ClientConnected(); break;
        case 2: _t->ClientCreated(); break;
        case 3: _t->ShowStatus((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->RunServer(); break;
        case 5: _t->StopServer(); break;
        case 6: _t->ServerSettings(); break;
        case 7: _t->DatabaseConnectionSettings(); break;
        case 8: _t->ChangeActionServerStatus(); break;
        case 9: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
