/****************************************************************************
** Meta object code from reading C++ file 'classify_utils.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/classify_utils/classify_utils.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classify_utils.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Classify_utils_t {
    QByteArrayData data[12];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Classify_utils_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Classify_utils_t qt_meta_stringdata_Classify_utils = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Classify_utils"
QT_MOC_LITERAL(1, 15, 11), // "infoChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "info"
QT_MOC_LITERAL(4, 33, 15), // "progressChanged"
QT_MOC_LITERAL(5, 49, 8), // "progress"
QT_MOC_LITERAL(6, 58, 10), // "upload_set"
QT_MOC_LITERAL(7, 69, 8), // "classify"
QT_MOC_LITERAL(8, 78, 7), // "img_num"
QT_MOC_LITERAL(9, 86, 10), // "loadConfig"
QT_MOC_LITERAL(10, 97, 18), // "setCameraAvailable"
QT_MOC_LITERAL(11, 116, 11) // "isAvailable"

    },
    "Classify_utils\0infoChanged\0\0info\0"
    "progressChanged\0progress\0upload_set\0"
    "classify\0img_num\0loadConfig\0"
    "setCameraAvailable\0isAvailable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Classify_utils[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   50,    2, 0x02 /* Public */,
       7,    1,   51,    2, 0x02 /* Public */,
       9,    0,   54,    2, 0x02 /* Public */,
      10,    1,   55,    2, 0x00 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void Classify_utils::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Classify_utils *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->infoChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->progressChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->upload_set(); break;
        case 3: _t->classify((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->loadConfig(); break;
        case 5: _t->setCameraAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Classify_utils::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Classify_utils::infoChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Classify_utils::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Classify_utils::progressChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Classify_utils *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->info(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->progress(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Classify_utils *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setInfo(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setProgress(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Classify_utils::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Classify_utils.data,
    qt_meta_data_Classify_utils,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Classify_utils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Classify_utils::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Classify_utils.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Classify_utils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Classify_utils::infoChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Classify_utils::progressChanged(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
