/****************************************************************************
** Meta object code from reading C++ file 'SafetyWidget.h'
**
** Created: Sat Dec 24 13:25:37 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SafetyWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SafetyWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SafetyWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   19,   14,   13, 0x05,
      52,   13,   14,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   13,   14,   13, 0x0a,
      84,   13,   14,   13, 0x0a,
     102,   13,   14,   13, 0x0a,
     116,   13,   14,   13, 0x0a,
     141,   13,   14,   13, 0x0a,
     167,   13,   14,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SafetyWidget[] = {
    "SafetyWidget\0\0bool\0language\0"
    "languageChange(QString)\0dismissAction()\0"
    "onSaveClicked()\0onCancelClicked()\0"
    "onOkClicked()\0onSaveChangePinClicked()\0"
    "onSecurityCancelClicked()\0onRetranslate()\0"
};

void SafetyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SafetyWidget *_t = static_cast<SafetyWidget *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->languageChange((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->dismissAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->onSaveClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->onCancelClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->onOkClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->onSaveChangePinClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->onSecurityCancelClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->onRetranslate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SafetyWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SafetyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SafetyWidget,
      qt_meta_data_SafetyWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SafetyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SafetyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SafetyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SafetyWidget))
        return static_cast<void*>(const_cast< SafetyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SafetyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
bool SafetyWidget::languageChange(QString _t1)
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
bool SafetyWidget::dismissAction()
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
