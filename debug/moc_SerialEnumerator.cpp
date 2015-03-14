/****************************************************************************
** Meta object code from reading C++ file 'SerialEnumerator.h'
**
** Created: Sat Dec 24 13:25:49 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SerialEnumerator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialEnumerator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SerialRegistrationWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SerialRegistrationWidget[] = {
    "SerialRegistrationWidget\0"
};

void SerialRegistrationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SerialRegistrationWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SerialRegistrationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialRegistrationWidget,
      qt_meta_data_SerialRegistrationWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SerialRegistrationWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SerialRegistrationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SerialRegistrationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialRegistrationWidget))
        return static_cast<void*>(const_cast< SerialRegistrationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SerialRegistrationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SerialEnumerator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   18,   17,   17, 0x05,
      57,   18,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SerialEnumerator[] = {
    "SerialEnumerator\0\0info\0"
    "deviceDiscovered(PortInformation)\0"
    "deviceRemoved(PortInformation)\0"
};

void SerialEnumerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SerialEnumerator *_t = static_cast<SerialEnumerator *>(_o);
        switch (_id) {
        case 0: _t->deviceDiscovered((*reinterpret_cast< const PortInformation(*)>(_a[1]))); break;
        case 1: _t->deviceRemoved((*reinterpret_cast< const PortInformation(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SerialEnumerator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SerialEnumerator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialEnumerator,
      qt_meta_data_SerialEnumerator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SerialEnumerator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SerialEnumerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SerialEnumerator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialEnumerator))
        return static_cast<void*>(const_cast< SerialEnumerator*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialEnumerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SerialEnumerator::deviceDiscovered(const PortInformation & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialEnumerator::deviceRemoved(const PortInformation & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
