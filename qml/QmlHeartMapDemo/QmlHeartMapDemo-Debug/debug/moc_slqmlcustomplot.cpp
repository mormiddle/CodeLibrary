/****************************************************************************
** Meta object code from reading C++ file 'slqmlcustomplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../slqmlcustomplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slqmlcustomplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SlQmlCustomPlot_t {
    QByteArrayData data[7];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SlQmlCustomPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SlQmlCustomPlot_t qt_meta_stringdata_SlQmlCustomPlot = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SlQmlCustomPlot"
QT_MOC_LITERAL(1, 16, 12), // "graphClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "QCPAbstractPlottable*"
QT_MOC_LITERAL(4, 52, 9), // "plottable"
QT_MOC_LITERAL(5, 62, 14), // "onCustomReplot"
QT_MOC_LITERAL(6, 77, 20) // "updateCustomPlotSize"

    },
    "SlQmlCustomPlot\0graphClicked\0\0"
    "QCPAbstractPlottable*\0plottable\0"
    "onCustomReplot\0updateCustomPlotSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlQmlCustomPlot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SlQmlCustomPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SlQmlCustomPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->graphClicked((*reinterpret_cast< QCPAbstractPlottable*(*)>(_a[1]))); break;
        case 1: _t->onCustomReplot(); break;
        case 2: _t->updateCustomPlotSize(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SlQmlCustomPlot::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_SlQmlCustomPlot.data,
    qt_meta_data_SlQmlCustomPlot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SlQmlCustomPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlQmlCustomPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SlQmlCustomPlot.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int SlQmlCustomPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_CustomPlotItem_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomPlotItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomPlotItem_t qt_meta_stringdata_CustomPlotItem = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CustomPlotItem"
QT_MOC_LITERAL(1, 15, 14), // "initCustomPlot"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "CustomPlotItem\0initCustomPlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomPlotItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void CustomPlotItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomPlotItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initCustomPlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustomPlotItem::staticMetaObject = { {
    QMetaObject::SuperData::link<SlQmlCustomPlot::staticMetaObject>(),
    qt_meta_stringdata_CustomPlotItem.data,
    qt_meta_data_CustomPlotItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomPlotItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomPlotItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomPlotItem.stringdata0))
        return static_cast<void*>(this);
    return SlQmlCustomPlot::qt_metacast(_clname);
}

int CustomPlotItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlQmlCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_CustomPlotBarItem_t {
    QByteArrayData data[6];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomPlotBarItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomPlotBarItem_t qt_meta_stringdata_CustomPlotBarItem = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CustomPlotBarItem"
QT_MOC_LITERAL(1, 18, 15), // "barColorChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "color"
QT_MOC_LITERAL(4, 41, 14), // "initCustomPlot"
QT_MOC_LITERAL(5, 56, 8) // "barColor"

    },
    "CustomPlotBarItem\0barColorChanged\0\0"
    "color\0initCustomPlot\0barColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomPlotBarItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QColor, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void CustomPlotBarItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomPlotBarItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->barColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->initCustomPlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CustomPlotBarItem::*)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CustomPlotBarItem::barColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CustomPlotBarItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->barColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CustomPlotBarItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBarColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CustomPlotBarItem::staticMetaObject = { {
    QMetaObject::SuperData::link<SlQmlCustomPlot::staticMetaObject>(),
    qt_meta_stringdata_CustomPlotBarItem.data,
    qt_meta_data_CustomPlotBarItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomPlotBarItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomPlotBarItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomPlotBarItem.stringdata0))
        return static_cast<void*>(this);
    return SlQmlCustomPlot::qt_metacast(_clname);
}

int CustomPlotBarItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlQmlCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CustomPlotBarItem::barColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CustomKLine_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomKLine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomKLine_t qt_meta_stringdata_CustomKLine = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CustomKLine"
QT_MOC_LITERAL(1, 12, 14), // "initCustomPlot"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "CustomKLine\0initCustomPlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomKLine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void CustomKLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomKLine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initCustomPlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustomKLine::staticMetaObject = { {
    QMetaObject::SuperData::link<SlQmlCustomPlot::staticMetaObject>(),
    qt_meta_stringdata_CustomKLine.data,
    qt_meta_data_CustomKLine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomKLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomKLine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomKLine.stringdata0))
        return static_cast<void*>(this);
    return SlQmlCustomPlot::qt_metacast(_clname);
}

int CustomKLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlQmlCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_CustomColorMap_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomColorMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomColorMap_t qt_meta_stringdata_CustomColorMap = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CustomColorMap"
QT_MOC_LITERAL(1, 15, 14), // "initCustomPlot"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "CustomColorMap\0initCustomPlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomColorMap[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void CustomColorMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomColorMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initCustomPlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustomColorMap::staticMetaObject = { {
    QMetaObject::SuperData::link<SlQmlCustomPlot::staticMetaObject>(),
    qt_meta_stringdata_CustomColorMap.data,
    qt_meta_data_CustomColorMap,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomColorMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomColorMap::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomColorMap.stringdata0))
        return static_cast<void*>(this);
    return SlQmlCustomPlot::qt_metacast(_clname);
}

int CustomColorMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlQmlCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_CustomBarChart_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomBarChart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomBarChart_t qt_meta_stringdata_CustomBarChart = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CustomBarChart"
QT_MOC_LITERAL(1, 15, 13), // "iniCustomPlot"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "CustomBarChart\0iniCustomPlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomBarChart[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void CustomBarChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomBarChart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iniCustomPlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustomBarChart::staticMetaObject = { {
    QMetaObject::SuperData::link<SlQmlCustomPlot::staticMetaObject>(),
    qt_meta_stringdata_CustomBarChart.data,
    qt_meta_data_CustomBarChart,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomBarChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomBarChart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomBarChart.stringdata0))
        return static_cast<void*>(this);
    return SlQmlCustomPlot::qt_metacast(_clname);
}

int CustomBarChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlQmlCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
