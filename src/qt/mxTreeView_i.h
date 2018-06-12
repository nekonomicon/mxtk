//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxTreeView_i.h
// implementation: Qt Free Edition
// last modified:  Apr 20 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include <mx/mxTreeView.h>
#include <mx/mxWindow.h>
#include <qlistview.h>
//#include <ostream.h>



class mxTreeView_i : public QListView
{
	Q_OBJECT
	mxTreeView *d_widget;

public:
	mxTreeView_i (QWidget *parent, mxTreeView *widget) : QListView (parent)
	{
		d_widget = widget;
	}

	~mxTreeView_i ()
	{
	}

protected:
	virtual void resizeEvent (QResizeEvent *event)
	{
		setColumnWidth (0, event->size ().width ());
		QListView::resizeEvent (event);
	}

public slots:
	void selectionChangedEvent ()
	{
		if (d_widget->getId () > 0)
		{
			mxWindow *parent = ((mxWidget *) d_widget)->getParent ();
			mxEvent event;
			event.event = mxEvent::Action;
			event.widget = d_widget;
			event.action = d_widget->getId ();
			while (parent)
			{
				if (parent->handleEvent (&event))
					break;
				parent = parent->getParent ();
			}
		}
	}
	
	void doubleClickedEvent (QListViewItem *lvi)
	{
		if (d_widget->getId () > 0)
		{
			mxWindow *parent = ((mxWidget *) d_widget)->getParent ();
			mxEvent event;
			event.event = mxEvent::Action;
			event.widget = d_widget;
			event.action = d_widget->getId ();
			event.flags = mxEvent::DoubleClicked;
			while (parent)
			{
				if (parent->handleEvent (&event))
					break;
				parent = parent->getParent ();
			}
		}
	}
	
	void rightButtonClickedEvent (QListViewItem *lvi, const QPoint& pos, int column)
	{
		if (d_widget->getId () > 0)
		{
			mxWindow *parent = ((mxWidget *) d_widget)->getParent ();
			mxEvent event;
			event.event = mxEvent::Action;
			event.widget = d_widget;
			event.action = d_widget->getId ();
			event.flags = mxEvent::RightClicked;
			QPoint point = mapFromGlobal (pos);			
			event.x = point.x ();
			event.y = point.y ();
			while (parent)
			{
				if (parent->handleEvent (&event))
					break;
				parent = parent->getParent ();
			}
		}
	}
};
