/****************************************************************************
** mxPopupMenu_i meta object code from reading C++ file 'mxPopupMenu_i.h'
**
** Created: Tue May 4 12:54:19 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxPopupMenu_i.h"
#include <qmetaobject.h>


const char *mxPopupMenu_i::className() const
{
    return "mxPopupMenu_i";
}

QMetaObject *mxPopupMenu_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxPopupMenu_i(&mxPopupMenu_i::staticMetaObject);

#endif

void mxPopupMenu_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QPopupMenu::className(), "QPopupMenu") != 0 )
	badSuperclassWarning("mxPopupMenu_i","QPopupMenu");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxPopupMenu_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QPopupMenu::staticMetaObject();
#else

    QPopupMenu::initMetaObject();
#endif

    typedef void(mxPopupMenu_i::*m1_t0)(int);
    m1_t0 v1_0 = &mxPopupMenu_i::activatedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "activatedEvent(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxPopupMenu_i", "QPopupMenu",
	slot_tbl, 1,
	0, 0 );
}
