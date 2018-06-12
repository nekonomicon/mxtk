/****************************************************************************
** mxRadioButton_i meta object code from reading C++ file 'mxRadioButton_i.h'
**
** Created: Tue May 4 12:54:21 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxRadioButton_i.h"
#include <qmetaobject.h>


const char *mxRadioButton_i::className() const
{
    return "mxRadioButton_i";
}

QMetaObject *mxRadioButton_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxRadioButton_i(&mxRadioButton_i::staticMetaObject);

#endif

void mxRadioButton_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QRadioButton::className(), "QRadioButton") != 0 )
	badSuperclassWarning("mxRadioButton_i","QRadioButton");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxRadioButton_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QRadioButton::staticMetaObject();
#else

    QRadioButton::initMetaObject();
#endif

    typedef void(mxRadioButton_i::*m1_t0)();
    m1_t0 v1_0 = &mxRadioButton_i::clickedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "clickedEvent()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxRadioButton_i", "QRadioButton",
	slot_tbl, 1,
	0, 0 );
}
