//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxMenuBar.cpp
// implementation: Qt Free Edition
// last modified:  May 04 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include "mxMenuBar_i.h"



mxMenuBar::mxMenuBar (mxWindow *parent)
: mxWidget (parent, 0, 0, 0, 0)
{
	QWidget *p = 0;
	if (parent)
		p = (QWidget *) ((mxWidget *) parent)->getHandle ();

	d_this = new mxMenuBar_i (p, this);
	d_this->connect (d_this, SIGNAL (activated (int)), d_this, SLOT (activatedEvent (int)));

	setHandle ((void *) d_this);
	setType (MX_MENUBAR);
	setParent (parent);
	setVisible (true);
}



mxMenuBar::~mxMenuBar ()
{
	delete d_this;
}



void
mxMenuBar::addMenu (const char *item, mxMenu *menu)
{
	d_this->insertItem (item, (QPopupMenu *) ((mxWidget *) menu)->getHandle ());
}



void
mxMenuBar::setEnabled (int id, bool b)
{
	d_this->setItemEnabled (id, b);
}



void
mxMenuBar::setChecked (int id, bool b)
{
	d_this->setItemChecked (id, b);
}



void
mxMenuBar::modify (int id, int newId, const char *newItem)
{
	d_this->changeItem (newItem, id);
	int index = d_this->indexOf (id);
	if (index != -1)
		d_this->setId (index, newId);
}



bool
mxMenuBar::isEnabled (int id) const
{
	return d_this->isItemEnabled (id);
}



bool
mxMenuBar::isChecked (int id) const
{
	return d_this->isItemChecked (id);
}



int
mxMenuBar::getHeight () const
{
	mxWindow *window = getParent ();

	if (window)
		return d_this->heightForWidth (window->w ());

	return 0;
}
