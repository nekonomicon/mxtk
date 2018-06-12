/****************************************************************************
** mxLineEdit_i meta object code from reading C++ file 'mxLineEdit_i.h'
**
** Created: Tue May 4 12:54:15 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxLineEdit_i.h"
#include <qmetaobject.h>


const char *mxLineEdit_i::className() const
{
    return "mxLineEdit_i";
}

QMetaObject *mxLineEdit_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxLineEdit_i(&mxLineEdit_i::staticMetaObject);

#endif

void mxLineEdit_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QLineEdit::className(), "QLineEdit") != 0 )
	badSuperclassWarning("mxLineEdit_i","QLineEdit");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxLineEdit_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QLineEdit::staticMetaObject();
#else

    QLineEdit::initMetaObject();
#endif

    typedef void(mxLineEdit_i::*m1_t0)(const char*);
    m1_t0 v1_0 = &mxLineEdit_i::textChangedEvent;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "textChangedEvent(const char*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "mxLineEdit_i", "QLineEdit",
	slot_tbl, 1,
	0, 0 );
}
