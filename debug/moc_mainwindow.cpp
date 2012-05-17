/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu 17. May 16:28:50 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,
     192,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0updateRender(QImage*)\0"
    "StartStopRender()\0DepthChanged(int)\0"
    "openSceneFile()\0saveImageFile()\0"
    "changeWorldBgColor()\0moveCamUp()\0"
    "moveCamRight()\0moveCamDown()\0moveCamLeft()\0"
    "moveCamBack()\0moveCamForw()\0"
    "changeFocalLength(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updateRender((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 1: _t->StartStopRender(); break;
        case 2: _t->DepthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->openSceneFile(); break;
        case 4: _t->saveImageFile(); break;
        case 5: _t->changeWorldBgColor(); break;
        case 6: _t->moveCamUp(); break;
        case 7: _t->moveCamRight(); break;
        case 8: _t->moveCamDown(); break;
        case 9: _t->moveCamLeft(); break;
        case 10: _t->moveCamBack(); break;
        case 11: _t->moveCamForw(); break;
        case 12: _t->changeFocalLength((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
