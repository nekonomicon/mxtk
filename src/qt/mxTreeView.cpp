//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxTreeView.cpp
// implementation: Qt Free Edition
// last modified:  Apr 20 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include "mxTreeView_i.h"



mxTreeView::mxTreeView (mxWindow *parent, int x, int y, int w, int h, int id)
: mxWidget (parent, x, y, w, h)
{
	QWidget *p = 0;
	if (parent)
		p = (QWidget *) parent->getHandle ();
	d_this = new mxTreeView_i (p, this);
	d_this->addColumn ("");
	d_this->setRootIsDecorated (true);
	d_this->connect (d_this, SIGNAL (selectionChanged ()), d_this, SLOT (selectionChangedEvent ()));	
	d_this->connect (d_this, SIGNAL (doubleClicked (QListViewItem *)), d_this, SLOT (doubleClickedEvent (QListViewItem *)));	
	d_this->connect (d_this, SIGNAL (rightButtonClicked (QListViewItem *, const QPoint&, int)), d_this, SLOT (rightButtonClickedEvent (QListViewItem *, const QPoint&, int)));	

	setHandle ((void *) d_this);
	setType (MX_TREEVIEW);
	setParent (parent);
	setId (id);
	setBounds (x, y, w, h);
	setVisible (true);
}



mxTreeView::~mxTreeView ()
{
	remove (0);
	delete d_this;
}



mxTreeViewItem*
mxTreeView::add (mxTreeViewItem *parent, const char *item)
{
	QListViewItem *lvi;

	if (parent)
		lvi = new QListViewItem ((QListViewItem *) parent, item);
	else
		lvi = new QListViewItem ((QListView *) d_this, item);

	return (mxTreeViewItem *) lvi;
}



void
mxTreeView::remove (mxTreeViewItem *item)
{
	if (!item)
		d_this->clear ();
	else
		delete (QListViewItem *) item;
}



mxTreeViewItem *
mxTreeView::getFirstChild (mxTreeViewItem *item) const
{
	if (item)
		return (mxTreeViewItem *) ((QListViewItem *) item)->firstChild ();
	else
		return (mxTreeViewItem *) d_this->firstChild ();
}



mxTreeViewItem *
mxTreeView::getNextChild (mxTreeViewItem *item) const
{
	if (item)
		return (mxTreeViewItem *) ((QListViewItem *) item)->nextSibling ();

	return 0;
}



mxTreeViewItem*
mxTreeView::getSelectedItem () const
{
	return (mxTreeViewItem *) d_this->currentItem ();
}



void
mxTreeView::setLabel (mxTreeViewItem *item, const char *label)
{
	if (item)
		((QListViewItem *) item)->setText (0, label);
}



void
mxTreeView::setUserData (mxTreeViewItem *item, void *userData)
{
}



void
mxTreeView::setOpen (mxTreeViewItem *item, bool b)
{
	if (item)
		((QListViewItem *) item)->setOpen (b);
}



void
mxTreeView::setSelected (mxTreeViewItem *item, bool b)
{
	if (item)
		((QListViewItem *) item)->setSelected (b);
}



const char *
mxTreeView::getLabel (mxTreeViewItem *item) const
{
	if (item)
		return ((QListViewItem *) item)->text (0);
		
	return 0;
}



void *
mxTreeView::getUserData (mxTreeViewItem *item) const
{
	return 0;
}



bool
mxTreeView::isOpen (mxTreeViewItem *item) const
{
	if (item)
		return ((QListViewItem *) item)->isOpen ();

	return false;
}



bool
mxTreeView::isSelected (mxTreeViewItem *item) const
{
	if (item)
		return ((QListViewItem *) item)->isSelected ();
		
	return 0;
}



mxTreeViewItem *
mxTreeView::getParent (mxTreeViewItem *item) const
{
	if (item)
		return (mxTreeViewItem *) ((QListViewItem *) item)->parent ();

	return 0;
}
