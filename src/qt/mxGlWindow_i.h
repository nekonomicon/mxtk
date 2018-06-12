//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxGlWindow_i.h
// implementation: Qt Free Edition
// last modified:  Apr 20 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include <mx/mxGlWindow.h>
#include <mx/mx.h>
#include <qgl.h>
//#include <ostream.h>



class mxGlWindow_i : public QGLWidget
{
	Q_OBJECT
	mxGlWindow *d_GlWindow;
	bool d_dragging;
	int d_button;

public:

	mxGlWindow_i (QWidget *parent, mxGlWindow *GlWindow) : QGLWidget (parent)
	{
		d_GlWindow = GlWindow;
		d_dragging = false;
		d_button = 0;
		setMouseTracking (true);
	}

	~mxGlWindow_i ()
	{
	}

public slots:
	void idleEvent ()
	{
		mxEvent event;
		
		event.event = mxEvent::Idle;
		d_GlWindow->handleEvent (&event);
	}
	
protected:
	virtual void paintGL ()
	{
		d_GlWindow->draw ();
	}

	virtual void resizeGL (int w, int h)
	{
		mxEvent event;
		event.event = mxEvent::Size;
		event.width = w;
		event.height = h;
		d_GlWindow->handleEvent (&event);
	}

	virtual void mousePressEvent (QMouseEvent *e)
	{
		QGLWidget::mousePressEvent (e);
		d_dragging = true;
		
		d_button = 0;
		if (e->state () & LeftButton)
			d_button |= mxEvent::MouseLeftButton;
		if (e->state () & RightButton)
			d_button |= mxEvent::MouseRightButton;
		if (e->state () & MidButton)
			d_button |= mxEvent::MouseMiddleButton;

		mxEvent event;
		if (e->state () & ControlButton)
			event.modifiers |= mxEvent::KeyCtrl;
		if (e->state () & ShiftButton)
			event.modifiers |= mxEvent::KeyShift;
		event.event = mxEvent::MouseDown;
		event.buttons = d_button;
		event.x = e->x ();
		event.y = e->y ();
		d_GlWindow->handleEvent (&event);
	}

	virtual void mouseMoveEvent (QMouseEvent *e)
	{
		QGLWidget::mouseMoveEvent (e);
		
		d_button = 0;
		if (e->state () & LeftButton)
			d_button |= mxEvent::MouseLeftButton;
		if (e->state () & RightButton)
			d_button |= mxEvent::MouseRightButton;
		if (e->state () & MidButton)
			d_button |= mxEvent::MouseMiddleButton;

		mxEvent event;
		if (e->state () & ControlButton)
			event.modifiers |= mxEvent::KeyCtrl;
		if (e->state () & ShiftButton)
			event.modifiers |= mxEvent::KeyShift;

		event.buttons = d_button;
		event.x = e->x ();
		event.y = e->y ();

		if (d_dragging)
			event.event = mxEvent::MouseDrag;
		else
			event.event = mxEvent::MouseMove;
			
		d_GlWindow->handleEvent (&event);
	}

	virtual void mouseReleaseEvent (QMouseEvent *e)
	{
		QGLWidget::mouseReleaseEvent (e);
		d_dragging = false;

		d_button = 0;
		if (e->state () & LeftButton)
			d_button |= mxEvent::MouseLeftButton;
		if (e->state () & RightButton)
			d_button |= mxEvent::MouseRightButton;
		if (e->state () & MidButton)
			d_button |= mxEvent::MouseMiddleButton;

		mxEvent event;
		if (e->state () & ControlButton)
			event.modifiers |= mxEvent::KeyCtrl;
		if (e->state () & ShiftButton)
			event.modifiers |= mxEvent::KeyShift;

		event.event = mxEvent::MouseUp;
		event.buttons = d_button;
		event.x = e->x ();
		event.y = e->y ();
		d_button = 0;
	}
	
	virtual void timerEvent (QTimerEvent *e)
	{
		mxEvent event;
		event.event = mxEvent::Timer;
		d_GlWindow->handleEvent (&event);
	}
};
