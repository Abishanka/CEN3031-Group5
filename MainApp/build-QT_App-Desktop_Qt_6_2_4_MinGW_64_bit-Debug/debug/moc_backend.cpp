/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QT_App/backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackEnd_t {
    const uint offsetsAndSize[42];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BackEnd_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BackEnd_t qt_meta_stringdata_BackEnd = {
    {
QT_MOC_LITERAL(0, 7), // "BackEnd"
QT_MOC_LITERAL(8, 11), // "QML.Element"
QT_MOC_LITERAL(20, 4), // "auto"
QT_MOC_LITERAL(25, 15), // "DefaultProperty"
QT_MOC_LITERAL(41, 7), // "content"
QT_MOC_LITERAL(49, 12), // "countChanged"
QT_MOC_LITERAL(62, 0), // ""
QT_MOC_LITERAL(63, 5), // "count"
QT_MOC_LITERAL(69, 6), // "append"
QT_MOC_LITERAL(76, 1), // "o"
QT_MOC_LITERAL(78, 6), // "insert"
QT_MOC_LITERAL(85, 1), // "i"
QT_MOC_LITERAL(87, 3), // "get"
QT_MOC_LITERAL(91, 13), // "backEndAppend"
QT_MOC_LITERAL(105, 26), // "QQmlListProperty<QObject>*"
QT_MOC_LITERAL(132, 4), // "list"
QT_MOC_LITERAL(137, 1), // "e"
QT_MOC_LITERAL(139, 12), // "backEndCount"
QT_MOC_LITERAL(152, 9), // "backEndAt"
QT_MOC_LITERAL(162, 12), // "backEndClear"
QT_MOC_LITERAL(175, 25) // "QQmlListProperty<QObject>"

    },
    "BackEnd\0QML.Element\0auto\0DefaultProperty\0"
    "content\0countChanged\0\0count\0append\0o\0"
    "insert\0i\0get\0backEndAppend\0"
    "QQmlListProperty<QObject>*\0list\0e\0"
    "backEndCount\0backEndAt\0backEndClear\0"
    "QQmlListProperty<QObject>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackEnd[] = {

 // content:
      10,       // revision
       0,       // classname
       2,   14, // classinfo
       8,   18, // methods
       2,   96, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   66,    6, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   69,    6, 0x0a,    5 /* Public */,
      10,    2,   72,    6, 0x0a,    7 /* Public */,
      12,    1,   77,    6, 0x0a,   10 /* Public */,
      13,    2,   80,    6, 0x0a,   12 /* Public */,
      17,    1,   85,    6, 0x0a,   15 /* Public */,
      18,    2,   88,    6, 0x0a,   17 /* Public */,
      19,    1,   93,    6, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    9,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::Int,    9,   11,
    QMetaType::QObjectStar, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QObjectStar,   15,   16,
    QMetaType::LongLong, 0x80000000 | 14,   15,
    QMetaType::QObjectStar, 0x80000000 | 14, QMetaType::LongLong,   15,   11,
    QMetaType::Void, 0x80000000 | 14,   15,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00015001, uint(0), 0,
       4, 0x80000000 | 20, 0x00015009, uint(-1), 0,

       0        // eod
};

void BackEnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BackEnd *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->countChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->append((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 2: _t->insert((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: { QObject* _r = _t->get((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 4: _t->backEndAppend((*reinterpret_cast< std::add_pointer_t<QQmlListProperty<QObject>*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[2]))); break;
        case 5: { qlonglong _r = _t->backEndCount((*reinterpret_cast< std::add_pointer_t<QQmlListProperty<QObject>*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< qlonglong*>(_a[0]) = std::move(_r); }  break;
        case 6: { QObject* _r = _t->backEndAt((*reinterpret_cast< std::add_pointer_t<QQmlListProperty<QObject>*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->backEndClear((*reinterpret_cast< std::add_pointer_t<QQmlListProperty<QObject>*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackEnd::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::countChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BackEnd *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< QQmlListProperty<QObject>*>(_v) = _t->content(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject BackEnd::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_BackEnd.offsetsAndSize,
    qt_meta_data_BackEnd,
    qt_static_metacall,
    nullptr,
qt_metaTypeArray<
int, QQmlListProperty<QObject>, BackEnd, void, int
, void, QObject *, void, QObject *, int, QObject *, int, void, QQmlListProperty<QObject> *, QObject *, long long int, QQmlListProperty<QObject> *, QObject *, QQmlListProperty<QObject> *, long long int, void, QQmlListProperty<QObject> *


>,
    nullptr
} };


const QMetaObject *BackEnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackEnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackEnd.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int BackEnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BackEnd::countChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
