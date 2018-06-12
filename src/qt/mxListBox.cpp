//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxListBoxBox.cpp
// implementation: Qt Free Edition
// last modified:  Mar 19 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include "mxListBox_i.h"



mxListBox::mxListBox (mxWindow *parent, int x, int y, int w, int h, int id, int
style)
: mxWidget (parent, x, y, w, h)
{
	QWidget *p = 0;
	if (parent)
		p = (QWidget *) ((mxWidget *) parent)->getHandle ();
	d_this = new mxListBox_i (p, this);
	if (style == MultiSelection)
		d_this->setMultiSelection (true);
		
	d_this->connect (d_this, SIGNAL (selected (int)), d_this, SLOT (selectedEvent (int)));

	setHandle ((void *) d_this);
	setType (MX_LISTBOX);
	setParent (parent);
	setBounds (x, y, w, h);
	setId (id);
	setVisible (true);
}



mxListBox::~ mxListBox ()
{
	delete d_this;
}



void
mxListBox::add (const char *item)
{
	d_this->insertItem (item);
}



void
mxListBox::select (int index)
{
	QObject::disconnect (d_this, SIGNAL (selected (int)), d_this, SLOT (selectedEvent (int)));
	d_this->setSelected (index, true);
	d_this->connect (d_this, SIGNAL (selected (int)), d_this, SLOT (selectedEvent (int)));
}



void
mxListBox::deselect (int index)
{
	QObject::disconnect (d_this, SIGNAL (selected (int)), d_this, SLOT (selectedEvent (int)));
	d_this->setSelected (index, false);
	d_this->connect (d_this, SIGNAL (selected (int)), d_this, SLOT (selectedEvent (int)));
}



void
mxListBox::remove (int index)
{
	d_this->removeItem (index);
}



void
mxListBox::removeAll ()
{
	d_this->clear ();
}



mxListBox::getItemCount () const
{
	return (int) d_this->count ();
}



int
mxListBox::getSelectedIndex () const
{
	return d_this->currentItem ();
}



bool
mxListBox::isSelected (int index) const
{
	return d_this->isSelected (index);
}
