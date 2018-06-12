/****************************************************************************
** mxChoice_i meta object code from reading C++ file 'mxChoice_i.h'
**
** Created: Tue May 4 12:54:10 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxChoice_i.h"
#include <qmetaobject.h>


const char *mxChoice_i::className() const
{
    return "mxChoice_i";
}

QMetaObject *mxChoice_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxChoice_i(&mxChoice_i::staticMetaObject);

#endif

void mxChoice_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QComboBox::className(), "QComboBox") != 0 )
	badSuperclassWarning("mxChoice_i","QComboBox");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxChoice_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QComboBox::staticMetaObject();
#else

    QComboBox::initMetaObject();
#endif

    typedef void(mxChoice_i::*m1_t0)(int);
    m1_t0 v1_0 = &mxChoice_i::activatedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "activatedEvent(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxChoice_i", "QComboBox",
	slot_tbl, 1,
	0, 0 );
}
