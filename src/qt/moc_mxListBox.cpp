/****************************************************************************
** mxListBox_i meta object code from reading C++ file 'mxListBox_i.h'
**
** Created: Tue May 4 12:54:16 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxListBox_i.h"
#include <qmetaobject.h>


const char *mxListBox_i::className() const
{
    return "mxListBox_i";
}

QMetaObject *mxListBox_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxListBox_i(&mxListBox_i::staticMetaObject);

#endif

void mxListBox_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QListBox::className(), "QListBox") != 0 )
	badSuperclassWarning("mxListBox_i","QListBox");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxListBox_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QListBox::staticMetaObject();
#else

    QListBox::initMetaObject();
#endif

    typedef void(mxListBox_i::*m1_t0)(int);
    m1_t0 v1_0 = &mxListBox_i::selectedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "selectedEvent(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxListBox_i", "QListBox",
	slot_tbl, 1,
	0, 0 );
}
