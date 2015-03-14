/****************************************************************************
** Meta object code from reading C++ file 'LanguageWidget.h'
**
** Created: Sat Dec 24 13:25:42 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LanguageWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LanguageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LanguageWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   21,   16,   15, 0x05,
      54,   15,   16,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   15,   16,   15, 0x0a,
      86,   15,   16,   15, 0x0a,
     104,   15,   16,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LanguageWidget[] = {
    "LanguageWidget\0\0bool\0language\0"
    "languageChange(QString)\0dismissAction()\0"
    "onSaveClicked()\0onCancelClicked()\0"
    "onRetranslate()\0"
};

void LanguageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LanguageWidget *_t = static_cast<LanguageWidget *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->languageChange((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->dismissAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->onSaveClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->onCancelClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->onRetranslate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LanguageWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LanguageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LanguageWidget,
      qt_meta_data_LanguageWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LanguageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LanguageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LanguageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageWidget))
        return static_cast<void*>(const_cast< LanguageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LanguageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
bool LanguageWidget::languageChange(QString _t1)
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
bool LanguageWidget::dismissAction()
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
