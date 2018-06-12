# simple Makefile for QT implementation of mxToolKit

CC = g++
CFLAGS = -O2
QTDIR = /usr/local/qt
IFLAGS = -I$(QTDIR)/include -I../../include
LFLAGS =
LIBS = $(QTDIR)/lib/libqt.so $(QTDIR)/lib/libqgl.a -lGL -lGLU -lXaw
MOC = /usr/local/qt/bin/moc
DEST_LIB = /usr/local/lib
DEST_INC = /usr/local/include

LIB = ../../lib/libmxtk-qt.a
OBJS = \
	mx.o \
	mxButton.o \
	mxCheckBox.o \
	mxChoice.o \
	mxChooseColor.o \
	mxFileDialog.o \
	mxGlWindow.o \
	mxGroupBox.o \
	mxLabel.o \
	mxLineEdit.o \
	mxListBox.o \
	mxMenu.o \
	mxMenuBar.o \
	mxMessageBox.o \
	mxPopupMenu.o \
	mxProgressBar.o \
	mxRadioButton.o \
	mxSlider.o \
	mxTab.o \
	mxToolTip.o \
	mxTreeView.o \
	mxWidget.o \
	mxWindow.o \
	mxBmp.o \
	mxTga.o \
	mxPcx.o \
	mxpath.o \
	mxstring.o \

all: $(LIB)

$(LIB): $(OBJS)
	ar rs $(LIB) $(OBJS) moc_*.o

mx.o: mx.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mx.cpp

mxButton.o: mxButton.cpp mxButton_i.h
	$(MOC) mxButton_i.h -o moc_mxButton.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxButton.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxButton.cpp

mxCheckBox.o: mxCheckBox.cpp mxCheckBox_i.h
	$(MOC) mxCheckBox_i.h -o moc_mxCheckBox.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxCheckBox.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxCheckBox.cpp

mxChoice.o: mxChoice.cpp mxChoice_i.h
	$(MOC) mxChoice_i.h -o moc_mxChoice.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxChoice.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxChoice.cpp

mxChooseColor.o: mxChooseColor.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxChooseColor.cpp

mxFileDialog.o: mxFileDialog.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxFileDialog.cpp

mxGlWindow.o: mxGlWindow.cpp mxGlWindow_i.h
	$(MOC) mxGlWindow_i.h -o moc_mxGlWindow.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxGlWindow.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxGlWindow.cpp	

mxGroupBox.o: mxGroupBox.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxGroupBox.cpp

mxLabel.o: mxLabel.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxLabel.cpp

mxLineEdit.o: mxLineEdit.cpp mxLineEdit_i.h
	$(MOC) mxLineEdit_i.h -o moc_mxLineEdit.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxLineEdit.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxLineEdit.cpp

mxListBox.o: mxListBox.cpp mxListBox_i.h
	$(MOC) mxListBox_i.h -o moc_mxListBox.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxListBox.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxListBox.cpp

mxMenu.o: mxMenu.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxMenu.cpp

mxMenuBar.o: mxMenuBar.cpp mxMenuBar_i.h
	$(MOC) mxMenuBar_i.h -o moc_mxMenuBar.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxMenuBar.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxMenuBar.cpp

mxMessageBox.o: mxMessageBox.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxMessageBox.cpp

mxPopupMenu.o: mxPopupMenu.cpp mxPopupMenu_i.h
	$(MOC) mxPopupMenu_i.h -o moc_mxPopupMenu.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxPopupMenu.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxPopupMenu.cpp

mxProgressBar.o: mxProgressBar.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxProgressBar.cpp

mxRadioButton.o: mxRadioButton.cpp mxRadioButton_i.h
	$(MOC) mxRadioButton_i.h -o moc_mxRadioButton.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxRadioButton.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxRadioButton.cpp

mxSlider.o: mxSlider.cpp mxSlider_i.h
	$(MOC) mxSlider_i.h -o moc_mxSlider.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxSlider.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxSlider.cpp

mxTab.o: mxTab.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxTab.cpp

mxToolTip.o: mxToolTip.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxToolTip.cpp

mxTreeView.o: mxTreeView.cpp mxTreeView_i.h
	$(MOC) mxTreeView_i.h -o moc_mxTreeView.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxTreeView.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxTreeView.cpp

mxWidget.o: mxWidget.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxWidget.cpp

mxWindow.o: mxWindow.cpp mxWindow_i.h
	$(MOC) mxWindow_i.h -o moc_mxWindow.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) mxWindow.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) moc_mxWindow.cpp

mxTga.o: ../common/mxTga.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) ../common/mxTga.cpp

mxBmp.o: ../common/mxBmp.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) ../common/mxBmp.cpp

mxPcx.o: ../common/mxPcx.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) ../common/mxPcx.cpp

mxpath.o: ../common/mxpath.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) ../common/mxpath.cpp

mxstring.o: ../common/mxstring.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) ../common/mxstring.cpp

# clean

clean:
	rm *.o
	rm moc_*.*

# install

install:
	cp $(LIB) $(DEST_LIB)
	cp -r ../../include/mx $(DEST_INC)
