//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxMenu.cpp
// implementation: Qt Free Edition
// last modified:  Mar 19 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include <mx/mxMenu.h>
#include <qpopupmenu.h>
//#include <ostream.h>



class mxMenu_i : public QPopupMenu
{
	mxMenu *d_widget;

public:
	mxMenu_i (mxMenu *menu) : QPopupMenu ()
	{
		d_widget = menu;
	}

	~mxMenu_i ()
	{
	}
};



mxMenu::mxMenu ()
: mxWidget (0, 0, 0, 0, 0)
{
	d_this = new mxMenu_i (this);
	d_this->setCheckable (true);

	setHandle ((void *) d_this);
	setType (MX_MENU);
}



mxMenu::~mxMenu ()
{
	delete d_this;
}



void
mxMenu::add (const char *item, int id)
{
	d_this->insertItem (item, id);
}



void
mxMenu::addMenu (const char *item, mxMenu *menu)
{
	d_this->insertItem (item, (QPopupMenu *) menu->getHandle ());
}



void
mxMenu::addSeparator ()
{
	d_this->insertSeparator ();
}



void
mxMenu::setEnabled (int id, bool b)
{
	d_this->setItemEnabled (id, b);
}



void
mxMenu::setChecked (int id, bool b)
{
	d_this->setItemChecked (id, b);
}



bool
mxMenu::isEnabled (int id) const
{
	return d_this->isItemEnabled (id);
}



bool
mxMenu::isChecked (int id) const
{
	return d_this->isItemChecked (id);
}
