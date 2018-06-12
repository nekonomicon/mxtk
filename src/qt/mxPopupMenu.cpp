//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxPopupMenu.cpp
// implementation: Qt Free Edition
// last modified:  Mar 19 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include "mxPopupMenu_i.h"
#include <qapplication.h>



mxPopupMenu::mxPopupMenu ()
: mxWidget (0, 0, 0, 0, 0)
{
	d_this = new mxPopupMenu_i (this);
	d_this->setCheckable (true);
	d_this->connect (d_this, SIGNAL (activated (int)), d_this, SLOT (activatedEvent (int)));

	setHandle ((void *) d_this);
	setType (MX_POPUPMENU);
}



mxPopupMenu::~mxPopupMenu ()
{
	delete d_this;
}



int
mxPopupMenu::popup (mxWidget *widget, int x, int y)
{
	QPoint p (x, y);
	QWidget *w = (QWidget *) widget->getHandle ();
	p = w->mapToGlobal (p);
	d_this->popup (p);

	while (d_this->d_lastItemId == -1)
		qApp->processEvents ();

	int id = d_this->d_lastItemId;
	d_this->d_lastItemId = -1;

	return id;
}



void
mxPopupMenu::add (const char *item, int id)
{
	d_this->insertItem (item, id);
}



void
mxPopupMenu::addMenu (const char *item, mxPopupMenu *menu)
{
	d_this->insertItem (item, (QPopupMenu *) menu->getHandle ());
}



void
mxPopupMenu::addSeparator ()
{
	d_this->insertSeparator ();
}



void
mxPopupMenu::setEnabled (int id, bool b)
{
	d_this->setItemEnabled (id, b);
}



void
mxPopupMenu::setChecked (int id, bool b)
{
	d_this->setItemChecked (id, b);
}



bool
mxPopupMenu::isEnabled (int id) const
{
	return d_this->isItemEnabled (id);
}



bool
mxPopupMenu::isChecked (int id) const
{
	return d_this->isItemChecked (id);
}
