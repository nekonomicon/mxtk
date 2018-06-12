/****************************************************************************
** mxTreeView_i meta object code from reading C++ file 'mxTreeView_i.h'
**
** Created: Tue May 4 12:54:24 1999
**      by: The Qt Meta Object Compiler ($Revision: 2.25.2.11 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mxTreeView_i.h"
#include <qmetaobject.h>


const char *mxTreeView_i::className() const
{
    return "mxTreeView_i";
}

QMetaObject *mxTreeView_i::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_mxTreeView_i(&mxTreeView_i::staticMetaObject);

#endif

void mxTreeView_i::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QListView::className(), "QListView") != 0 )
	badSuperclassWarning("mxTreeView_i","QListView");

#if QT_VERSION >= 200
    staticMetaObject();
}

void mxTreeView_i::staticMetaObject()
{
    if ( metaObj )
	return;
    QListView::staticMetaObject();
#else

    QListView::initMetaObject();
#endif

    typedef void(mxTreeView_i::*m1_t0)();
    typedef void(mxTreeView_i::*m1_t1)(QListViewItem*);
    typedef void(mxTreeView_i::*m1_t2)(QListViewItem*,const QPoint&,int);
    m1_t0 v1_0 = &mxTreeView_i::selectionChangedEvent;
    m1_t1 v1_1 = &mxTreeView_i::doubleClickedEvent;
    m1_t2 v1_2 = &mxTreeView_i::rightButtonClickedEvent;
    QMetaData *slot_tbl = new QMetaData[3];
    slot_tbl[0].name = "selectionChangedEvent()";
    slot_tbl[1].name = "doubleClickedEvent(QListViewItem*)";
    slot_tbl[2].name = "rightButtonClickedEvent(QListViewItem*,const QPoint&,int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    metaObj = new QMetaObject( "mxTreeView_i", "QListView",
	slot_tbl, 3,
	0, 0 );
}
