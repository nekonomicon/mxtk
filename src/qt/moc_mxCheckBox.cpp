/****************************************************************************
** mxCheckBox_i meta object code from reading C++ file 'mxCheckBox_i.h'
**
** Created: Tue May 4 12:54:09 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxCheckBox_i.h"
#include <qmetaobject.h>


const char *mxCheckBox_i::className() const
{
    return "mxCheckBox_i";
}

QMetaObject *mxCheckBox_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxCheckBox_i(&mxCheckBox_i::staticMetaObject);

#endif

void mxCheckBox_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QCheckBox::className(), "QCheckBox") != 0 )
	badSuperclassWarning("mxCheckBox_i","QCheckBox");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxCheckBox_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QCheckBox::staticMetaObject();
#else

    QCheckBox::initMetaObject();
#endif

    typedef void(mxCheckBox_i::*m1_t0)();
    m1_t0 v1_0 = &mxCheckBox_i::clickedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "clickedEvent()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxCheckBox_i", "QCheckBox",
	slot_tbl, 1,
	0, 0 );
}
