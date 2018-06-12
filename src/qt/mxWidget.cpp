//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxWidget.cpp
// implementation: Qt Free Edition
// last modified:  Mar 19 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include <mx/mxWidget.h>
#include <qwidget.h>
#include <qbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <string.h>
#include <stdlib.h>
//#include <ostream.h>



void mx_addWidget (mxWidget *widget);
void mx_removeWidget (mxWidget *widget);



class mxWidget_i
{
public:
	mxWindow *d_parent_p;
	QWidget *d_widget;
	void *d_userData;

	int d_id;
	int d_type;
};


mxWidget::mxWidget (mxWindow *parent, int x, int y, int w, int h, const char *label)
{
	d_this = new mxWidget_i;

	setHandle (0);
	setType (-1);
	setParent (parent);
	setBounds (x, y, w, h);
	setVisible (true);
	setEnabled (true);
	setUserData (0);
	setLabel (label);
	
	mx_addWidget (this);
}



mxWidget::~mxWidget ()
{
	mx_removeWidget (this);
	delete d_this;
}



void
mxWidget::setHandle (void *handle)
{
	d_this->d_widget = (QWidget *) handle;
}



void
mxWidget::setType (int type)
{
	d_this->d_type = type;
}



void
mxWidget::setParent (mxWindow *parent)
{
	d_this->d_parent_p = parent;
}



void
mxWidget::setBounds (int x, int y, int w, int h)
{
	if (d_this->d_widget)
	{
		d_this->d_widget->setGeometry (x, y, w, h);
	}
}



void
mxWidget::setLabel (const char *label)
{
	if (d_this->d_widget)
	{
		if (d_this->d_widget->inherits ("QButton"))
			((QButton *) d_this->d_widget)->setText (label);
		else if (d_this->d_widget->inherits ("QLineEdit"))
		{
			QLineEdit *le = (QLineEdit *) d_this->d_widget;
			QObject::disconnect (le, SIGNAL(textChanged (const
			char*)), le, SLOT (textChangedEvent (const char*)));
			le->setText (label);
			le->connect (le, SIGNAL(textChanged (const
			char*)), le, SLOT (textChangedEvent (const char*)));
		}
		else if (d_this->d_widget->inherits ("QLabel"))
			((QLabel *) d_this->d_widget)->setText (label);
		else if (d_this->d_widget->inherits ("QGroupBox"))
			((QGroupBox *) d_this->d_widget)->setTitle (label);
		else
			d_this->d_widget->setCaption (label);
	}
}



void
mxWidget::setVisible (bool b)
{
	if (d_this->d_widget)
	{
		 if (b)
			d_this->d_widget->show ();
		else
			d_this->d_widget->hide ();
	}
}



void
mxWidget::setEnabled (bool b)
{
	if (d_this->d_widget)
	{
		d_this->d_widget->setEnabled (b);
	}
}



void
mxWidget::setId (int id)
{
	d_this->d_id = id;
}



void
mxWidget::setUserData (void *userData)
{
	d_this->d_userData = userData;
}



void*
mxWidget::getHandle () const
{
	return (void *) d_this->d_widget;
}



int
mxWidget::getType () const
{
	return d_this->d_type;
}



mxWindow*
mxWidget::getParent () const
{
	return d_this->d_parent_p;
}



int
mxWidget::x () const
{
	return d_this->d_widget->x ();
}



int
mxWidget::y () const
{
	return d_this->d_widget->y ();

}



int
mxWidget::w () const
{
	return d_this->d_widget->width ();
}



int
mxWidget:: h () const
{
	return d_this->d_widget->height ();
}



int
mxWidget::w2 () const
{
	return d_this->d_widget->width ();
}



int
mxWidget:: h2 () const
{
	return d_this->d_widget->height ();
}



const char*
mxWidget::getLabel () const
{
	if (d_this->d_widget)
	{
		if (d_this->d_widget->inherits ("QButton"))
			return ((QButton *) d_this->d_widget)->text ();
		else if (d_this->d_widget->inherits ("QLineEdit"))
			return ((QLineEdit *) d_this->d_widget)->text ();
		else if (d_this->d_widget->inherits ("QLabel"))
			return ((QLabel *) d_this->d_widget)->text ();
		else if (d_this->d_widget->inherits ("QGroupBox"))
			return ((QGroupBox *) d_this->d_widget)->title ();
		else
			return d_this->d_widget->caption ();
	}
	else
		return 0;
}



bool
mxWidget::isVisible () const
{
	return d_this->d_widget->isVisible ();
}



bool
mxWidget::isEnabled () const
{
	return d_this->d_widget->isEnabled ();
}



int
mxWidget::getId () const
{
	return d_this->d_id;
}



void*
mxWidget::getUserData () const
{
	return d_this->d_userData;
}

