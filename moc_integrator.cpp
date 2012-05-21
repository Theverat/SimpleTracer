/****************************************************************************
** Meta object code from reading C++ file 'integrator.h'
**
** Created: Sun May 20 22:21:59 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "integrator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'integrator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Integrator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Integrator[] = {
    "Integrator\0\0passFinished(QVector<QVector<renderPixel> >)\0"
    "stop()\0"
};

void Integrator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Integrator *_t = static_cast<Integrator *>(_o);
        switch (_id) {
        case 0: _t->passFinished((*reinterpret_cast< QVector<QVector<renderPixel> >(*)>(_a[1]))); break;
        case 1: _t->stop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Integrator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Integrator::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Integrator,
      qt_meta_data_Integrator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Integrator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Integrator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Integrator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Integrator))
        return static_cast<void*>(const_cast< Integrator*>(this));
    return QThread::qt_metacast(_clname);
}

int Integrator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void Integrator::passFinished(QVector<QVector<renderPixel> > _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
