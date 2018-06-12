/****************************************************************************
** mxSlider_i meta object code from reading C++ file 'mxSlider_i.h'
**
** Created: Tue May 4 12:54:22 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxSlider_i.h"
#include <qmetaobject.h>


const char *mxSlider_i::className() const
{
    return "mxSlider_i";
}

QMetaObject *mxSlider_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxSlider_i(&mxSlider_i::staticMetaObject);

#endif

void mxSlider_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QSlider::className(), "QSlider") != 0 )
	badSuperclassWarning("mxSlider_i","QSlider");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxSlider_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QSlider::staticMetaObject();
#else

    QSlider::initMetaObject();
#endif

    typedef void(mxSlider_i::*m1_t0)(int);
    m1_t0 v1_0 = &mxSlider_i::valueChangedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "valueChangedEvent(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxSlider_i", "QSlider",
	slot_tbl, 1,
	0, 0 );
}
