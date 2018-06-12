/****************************************************************************
** mxGlWindow_i meta object code from reading C++ file 'mxGlWindow_i.h'
**
** Created: Tue May 4 12:54:13 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxGlWindow_i.h"
#include <qmetaobject.h>


const char *mxGlWindow_i::className() const
{
    return "mxGlWindow_i";
}

QMetaObject *mxGlWindow_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxGlWindow_i(&mxGlWindow_i::staticMetaObject);

#endif

void mxGlWindow_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QGLWidget::className(), "QGLWidget") != 0 )
	badSuperclassWarning("mxGlWindow_i","QGLWidget");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxGlWindow_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QGLWidget::staticMetaObject();
#else

    QGLWidget::initMetaObject();
#endif

    typedef void(mxGlWindow_i::*m1_t0)();
    m1_t0 v1_0 = &mxGlWindow_i::idleEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "idleEvent()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxGlWindow_i", "QGLWidget",
	slot_tbl, 1,
	0, 0 );
}
