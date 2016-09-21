/****************************************************************************
** Meta object code from reading C++ file 'rrt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rrt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rrt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RRT_t {
    QByteArrayData data[11];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RRT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RRT_t qt_meta_stringdata_RRT = {
    {
QT_MOC_LITERAL(0, 0, 3), // "RRT"
QT_MOC_LITERAL(1, 4, 9), // "updateMap"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 7), // "drawDot"
QT_MOC_LITERAL(4, 23, 7), // "Vertex*"
QT_MOC_LITERAL(5, 31, 6), // "vertex"
QT_MOC_LITERAL(6, 38, 8), // "drawEdge"
QT_MOC_LITERAL(7, 47, 7), // "vertex1"
QT_MOC_LITERAL(8, 55, 7), // "vertex2"
QT_MOC_LITERAL(9, 63, 9), // "removeDot"
QT_MOC_LITERAL(10, 73, 10) // "removeEdge"

    },
    "RRT\0updateMap\0\0drawDot\0Vertex*\0vertex\0"
    "drawEdge\0vertex1\0vertex2\0removeDot\0"
    "removeEdge"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RRT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       6,    2,   43,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
      10,    2,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    7,    8,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    7,    8,

       0        // eod
};

void RRT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RRT *_t = static_cast<RRT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMap(); break;
        case 1: _t->drawDot((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 2: _t->drawEdge((*reinterpret_cast< Vertex*(*)>(_a[1])),(*reinterpret_cast< Vertex*(*)>(_a[2]))); break;
        case 3: _t->removeDot((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 4: _t->removeEdge((*reinterpret_cast< Vertex*(*)>(_a[1])),(*reinterpret_cast< Vertex*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Vertex* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Vertex* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Vertex* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Vertex* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RRT::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RRT::updateMap)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RRT::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RRT.data,
      qt_meta_data_RRT,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RRT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RRT::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RRT.stringdata0))
        return static_cast<void*>(const_cast< RRT*>(this));
    return QObject::qt_metacast(_clname);
}

int RRT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RRT::updateMap()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
