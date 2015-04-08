/****************************************************************************
** Meta object code from reading C++ file 'qhexedit_p.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/qhexedit_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhexedit_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHexEditPrivate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   17,   16,   16, 0x05,
      57,   52,   16,   16, 0x05,
      81,   16,   16,   16, 0x05,
     101,   95,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QHexEditPrivate[] = {
    "QHexEditPrivate\0\0address\0"
    "currentAddressChanged(int)\0size\0"
    "currentSizeChanged(int)\0dataChanged()\0"
    "state\0overwriteModeChanged(bool)\0"
    "updateCursor()\0"
};

void QHexEditPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHexEditPrivate *_t = static_cast<QHexEditPrivate *>(_o);
        switch (_id) {
        case 0: _t->currentAddressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->currentSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->dataChanged(); break;
        case 3: _t->overwriteModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->updateCursor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHexEditPrivate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHexEditPrivate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QHexEditPrivate,
      qt_meta_data_QHexEditPrivate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHexEditPrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHexEditPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHexEditPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHexEditPrivate))
        return static_cast<void*>(const_cast< QHexEditPrivate*>(this));
    return QWidget::qt_metacast(_clname);
}

int QHexEditPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QHexEditPrivate::currentAddressChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QHexEditPrivate::currentSizeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QHexEditPrivate::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QHexEditPrivate::overwriteModeChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
