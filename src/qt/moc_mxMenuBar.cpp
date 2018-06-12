/****************************************************************************
** mxMenuBar_i meta object code from reading C++ file 'mxMenuBar_i.h'
**
** Created: Tue May 4 14:12:00 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxMenuBar_i.h"
#include <qmetaobject.h>


const char *mxMenuBar_i::className() const
{
    return "mxMenuBar_i";
}

QMetaObject *mxMenuBar_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxMenuBar_i(&mxMenuBar_i::staticMetaObject);

#endif

void mxMenuBar_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QMenuBar::className(), "QMenuBar") != 0 )
	badSuperclassWarning("mxMenuBar_i","QMenuBar");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxMenuBar_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QMenuBar::staticMetaObject();
#else

    QMenuBar::initMetaObject();
#endif

    typedef void(mxMenuBar_i::*m1_t0)(int);
    m1_t0 v1_0 = &mxMenuBar_i::activatedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "activatedEvent(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxMenuBar_i", "QMenuBar",
	slot_tbl, 1,
	0, 0 );
}
