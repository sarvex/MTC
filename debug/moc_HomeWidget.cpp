/****************************************************************************
** Meta object code from reading C++ file 'HomeWidget.h'
**
** Created: Sat Dec 24 13:25:33 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HomeWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HomeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HomeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   12,   11, 0x05,
      34,   11,   12,   11, 0x05,
      48,   11,   12,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   65,   12,   11, 0x0a,
      93,   65,   12,   11, 0x0a,
     136,  116,   12,   11, 0x0a,
     165,  116,   12,   11, 0x0a,
     194,   11,   12,   11, 0x0a,
     226,  220,   12,   11, 0x0a,
     254,  220,   12,   11, 0x0a,
     276,   11,   12,   11, 0x0a,
     301,   11,   12,   11, 0x0a,
     329,   11,   12,   11, 0x0a,
     357,   11,   12,   11, 0x0a,
     388,   11,   12,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HomeWidget[] = {
    "HomeWidget\0\0bool\0activateAction()\0"
    "closeAction()\0minimizeAction()\0status\0"
    "onModemPlugged(bool)\0onModemConnected(bool)\0"
    "uploaded,downloaded\0onSpeedUpdate(double,double)\0"
    "onUsageUpdate(double,double)\0"
    "onSettingsButtonClicked()\0value\0"
    "onSignalStrengthUpdate(int)\0"
    "onDateRateUpdate(int)\0onConnectButtonClicked()\0"
    "onConnectingButtonClicked()\0"
    "onDisconnectButtonClicked()\0"
    "onDisconnectingButtonClicked()\0"
    "onRetranslate()\0"
};

void HomeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HomeWidget *_t = static_cast<HomeWidget *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->activateAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->closeAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->minimizeAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->onModemPlugged((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->onModemConnected((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->onSpeedUpdate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->onUsageUpdate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->onSettingsButtonClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->onSignalStrengthUpdate((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->onDateRateUpdate((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->onConnectButtonClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->onConnectingButtonClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->onDisconnectButtonClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->onDisconnectingButtonClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->onRetranslate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HomeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HomeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HomeWidget,
      qt_meta_data_HomeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HomeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HomeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HomeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HomeWidget))
        return static_cast<void*>(const_cast< HomeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int HomeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
bool HomeWidget::activateAction()
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
bool HomeWidget::closeAction()
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
bool HomeWidget::minimizeAction()
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
