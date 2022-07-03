//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxWindow.cpp
// implementation: Qt Free Edition
// last modified:  Mar 19 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include "mxWindow_i.h"



extern QApplication *d_Application;
extern mxWindow *d_mainWindow;



mxWindow::mxWindow (mxWindow *parent, int x, int y, int w, int h, const char
*label, int style)
: mxWidget (parent, x, y, w, h, label)
{
	QWidget *p = 0;
	Qt::WindowFlags flags;

	if (parent)
		p = (QWidget *) parent->getHandle ();

	d_this = new mxWindow_i (p, this);

	setHandle ((void *) d_this);
	setParent (parent);

	if (style == Normal)
		flags = Qt::Widget;
	else if (style == Popup)
		flags = Qt::Popup;
	else if (style == Dialog)
		flags = Qt::Dialog;
	else if (style == ModalDialog)
	{
		d_this->setWindowModality(Qt::WindowModal);
		flags = Qt::Dialog;
	}

	d_this->setWindowFlags(flags);

	if (parent)
	{
		setVisible (true);
	}


	setLabel (label);
	setBounds (x, y, w, h);
	setType (MX_WINDOW);
	
	if (!d_mainWindow)
	{
		d_mainWindow = this;
	}
}



mxWindow::~mxWindow ()
{
	d_this->killTimer (d_this->getTimerId());
	delete d_this;
}



int
mxWindow::handleEvent (mxEvent *event)
{
	return 0;
}



void
mxWindow::redraw ()
{
}



void
mxWindow::setTimer (int milliSeconds)
{
	if (milliSeconds > 0)
	{
		int timerId = d_this->startTimer (milliSeconds);
		d_this->setTimerId (timerId);
	}
	else
		d_this->killTimer (d_this->getTimerId());
}



void
mxWindow::setMenuBar (mxMenuBar *menuBar)
{
	d_this->setMenuBar ((QMenuBar *) menuBar->getHandle ());
}
