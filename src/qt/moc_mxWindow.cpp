/****************************************************************************
** mxWindow_i meta object code from reading C++ file 'mxWindow_i.h'
**
** Created: Tue May 4 12:54:26 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxWindow_i.h"
#include <qmetaobject.h>


const char *mxWindow_i::className() const
{
    return "mxWindow_i";
}

QMetaObject *mxWindow_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxWindow_i(&mxWindow_i::staticMetaObject);

#endif

void mxWindow_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWindow::className(), "QWindow") != 0 )
	badSuperclassWarning("mxWindow_i","QWindow");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxWindow_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QWindow::staticMetaObject();
#else

    QWindow::initMetaObject();
#endif

    typedef void(mxWindow_i::*m1_t0)();
    m1_t0 v1_0 = &mxWindow_i::idleEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "idleEvent()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxWindow_i", "QWindow",
	slot_tbl, 1,
	0, 0 );
}
