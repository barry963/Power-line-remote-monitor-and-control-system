/****************************************************************************
** Meta object code from reading C++ file 'frmMain.h'
**
** Created: Fri Mar 1 23:49:30 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmMain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_frmMain[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      30,    8,    8,    8, 0x08,
      55,    8,    8,    8, 0x08,
      80,    8,    8,    8, 0x08,
     109,    8,    8,    8, 0x08,
     135,    8,    8,    8, 0x08,
     145,    8,    8,    8, 0x08,
     157,    8,    8,    8, 0x08,
     170,    8,    8,    8, 0x08,
     182,    8,    8,    8, 0x08,
     193,    8,    8,    8, 0x08,
     204,    8,    8,    8, 0x08,
     238,    8,    8,    8, 0x08,
     272,    8,    8,    8, 0x08,
     293,    8,    8,    8, 0x08,
     311,    8,    8,    8, 0x08,
     327,  322,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_frmMain[] = {
    "frmMain\0\0on_btnSave_clicked()\0"
    "on_btnClearAll_clicked()\0"
    "on_btnStopShow_clicked()\0"
    "on_btnClearReceive_clicked()\0"
    "on_btnClearSend_clicked()\0GetTime()\0"
    "ReadMyCom()\0WriteMyCom()\0SaveMyCom()\0"
    "SendData()\0SaveData()\0"
    "on_ckIsAutoSave_stateChanged(int)\0"
    "on_ckIsAutoSend_stateChanged(int)\0"
    "on_btnOpen_clicked()\0onBtnAddClicked()\0"
    "ParamSet()\0text\0ChooseModbusSelect(QString)\0"
};

const QMetaObject frmMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_frmMain,
      qt_meta_data_frmMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmMain))
        return static_cast<void*>(const_cast< frmMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int frmMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnSave_clicked(); break;
        case 1: on_btnClearAll_clicked(); break;
        case 2: on_btnStopShow_clicked(); break;
        case 3: on_btnClearReceive_clicked(); break;
        case 4: on_btnClearSend_clicked(); break;
        case 5: GetTime(); break;
        case 6: ReadMyCom(); break;
        case 7: WriteMyCom(); break;
        case 8: SaveMyCom(); break;
        case 9: SendData(); break;
        case 10: SaveData(); break;
        case 11: on_ckIsAutoSave_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: on_ckIsAutoSend_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_btnOpen_clicked(); break;
        case 14: onBtnAddClicked(); break;
        case 15: ParamSet(); break;
        case 16: ChooseModbusSelect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
