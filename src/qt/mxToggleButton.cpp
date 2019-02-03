//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxToggleButton.cpp
// implementation: Win32 API
// last modified:  Apr 28 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include <mx/mxToggleButton.h>
#include <mx/mxWindow.h>


class mxToggleButton_i
{
public:
	int dummy;
};



mxToggleButton::mxToggleButton (mxWindow *parent, int x, int y, int w, int h, const char *label, int id)
: mxWidget (parent, x, y, w, h, label)
{
}



mxToggleButton::~mxToggleButton ()
{
}



void
mxToggleButton::setChecked (bool b)
{
	(void)0;
}



bool
mxToggleButton::isChecked () const
{
	return false;
}
