/****************************************************************************
** Meta object code from reading C++ file 'qhexedit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/qhexedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhexedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHexEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       9,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,
      50,   45,    9,    9, 0x05,
      74,    9,    9,    9, 0x05,
      94,   88,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,    9,    9,    9, 0x0a,
     141,  128,    9,    9, 0x0a,
     174,  162,    9,    9, 0x0a,
     205,  195,    9,    9, 0x0a,
     229,  224,    9,    9, 0x0a,
     251,    9,    9,    9, 0x0a,

 // properties: name, type, flags
     269,  258, 0x0c095103,
     278,  274, 0x02095103,
     299,  292, 0x43095103,
     316,  274, 0x02095103,
     331,  292, 0x43095103,
     349,  292, 0x43095103,
     369,  364, 0x01095103,
     383,  364, 0x01095103,
     398,  392, 0x40095103,

       0        // eod
};

static const char qt_meta_stringdata_QHexEdit[] = {
    "QHexEdit\0\0address\0currentAddressChanged(int)\0"
    "size\0currentSizeChanged(int)\0dataChanged()\0"
    "state\0overwriteModeChanged(bool)\0"
    "redo()\0addressWidth\0setAddressWidth(int)\0"
    "addressArea\0setAddressArea(bool)\0"
    "asciiArea\0setAsciiArea(bool)\0mode\0"
    "setHighlighting(bool)\0undo()\0QByteArray\0"
    "data\0int\0addressOffset\0QColor\0"
    "addressAreaColor\0cursorPosition\0"
    "highlightingColor\0selectionColor\0bool\0"
    "overwriteMode\0readOnly\0QFont\0font\0"
};

void QHexEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHexEdit *_t = static_cast<QHexEdit *>(_o);
        switch (_id) {
        case 0: _t->currentAddressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->currentSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->dataChanged(); break;
        case 3: _t->overwriteModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->redo(); break;
        case 5: _t->setAddressWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setAddressArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setAsciiArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setHighlighting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->undo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHexEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHexEdit::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_QHexEdit,
      qt_meta_data_QHexEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHexEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHexEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHexEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHexEdit))
        return static_cast<void*>(const_cast< QHexEdit*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int QHexEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = data(); break;
        case 1: *reinterpret_cast< int*>(_v) = addressOffset(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = addressAreaColor(); break;
        case 3: *reinterpret_cast< int*>(_v) = cursorPosition(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = highlightingColor(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = selectionColor(); break;
        case 6: *reinterpret_cast< bool*>(_v) = overwriteMode(); break;
        case 7: *reinterpret_cast< bool*>(_v) = isReadOnly(); break;
        case 8: *reinterpret_cast< QFont*>(_v) = font(); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setData(*reinterpret_cast< QByteArray*>(_v)); break;
        case 1: setAddressOffset(*reinterpret_cast< int*>(_v)); break;
        case 2: setAddressAreaColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: setCursorPosition(*reinterpret_cast< int*>(_v)); break;
        case 4: setHighlightingColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: setSelectionColor(*reinterpret_cast< QColor*>(_v)); break;
        case 6: setOverwriteMode(*reinterpret_cast< bool*>(_v)); break;
        case 7: setReadOnly(*reinterpret_cast< bool*>(_v)); break;
        case 8: setFont(*reinterpret_cast< QFont*>(_v)); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QHexEdit::currentAddressChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QHexEdit::currentSizeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QHexEdit::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QHexEdit::overwriteModeChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
