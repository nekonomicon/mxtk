/****************************************************************************
** mxButton_i meta object code from reading C++ file 'mxButton_i.h'
**
** Created: Tue May 4 12:54:08 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxButton_i.h"
#include <qmetaobject.h>


const char *mxButton_i::className() const
{
    return "mxButton_i";
}

QMetaObject *mxButton_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxButton_i(&mxButton_i::staticMetaObject);

#endif

void mxButton_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QPushButton::className(), "QPushButton") != 0 )
	badSuperclassWarning("mxButton_i","QPushButton");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxButton_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QPushButton::staticMetaObject();
#else

    QPushButton::initMetaObject();
#endif

    typedef void(mxButton_i::*m1_t0)();
    m1_t0 v1_0 = &mxButton_i::clickedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "clickedEvent()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxButton_i", "QPushButton",
	slot_tbl, 1,
	0, 0 );
}
