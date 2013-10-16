/***************************************************************************
 *   Copyright (C) 2013 by RIP Project Group 							   *
 *   																	   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************
*
* 1.  NAME
*     mainwindow.cpp
* 2.  DESCRIPTION
*     the menu UI implementation file
* 3.  VERSIONS
*       Original:
*         21.2.2013 / RIP Project Group
*
*       Version history:
*       $Log$
*
**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <QtGui>

#include "mainwindow.h"
#include "xbeltree.h"

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: MainWindow
; DESCRIPTION: the construct function of the main window
;    Input: none
;    Output: none
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
MainWindow::MainWindow()
{
    xbelTree = new XbelTree;
    setCentralWidget(xbelTree);

    createActions();
    createMenus();

    statusBar()->showMessage(tr("Ready"));

    setWindowTitle(tr("DOM Bookmarks"));
    resize(480, 320);

    QToolBar *toolBar =  addToolBar(tr("&Add item"));
    toolBar->addAction(add_item_act);
    QToolBar *toolBar1 =  addToolBar(tr("&Delete item"));
    toolBar1->addAction(delete_item_act);
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: open
; DESCRIPTION: open the xml file
;    Input: none
;    Output: none
;    Used global variables: xbelTree
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::open()
{
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Bookmark File"),
                                         QDir::currentPath(),
                                         tr("XBEL Files (*.xbel *.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("SAX Bookmarks"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    if (xbelTree->read(&file))
        statusBar()->showMessage(tr("File loaded"), 2000);
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: add_function
; DESCRIPTION: add the elements of function
;    Input: none
;    Output: none
;    Used global variables: xbelTree
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::add_function()
{
    dialog.set_xbeltree(xbelTree);
    dialog.show();

}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: add_item
; DESCRIPTION: add the elements of item
;    Input: none
;    Output: none
;    Used global variables: xbelTree
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::add_item()
{
    xbelTree->add_item();
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: delete_item
; DESCRIPTION: delete the elements of item
;    Input: none
;    Output: none
;    Used global variables: xbelTree
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::delete_item()
{
    xbelTree->delete_item();
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: saveAs
; DESCRIPTION: save the xml file
;    Input: none
;    Output: none
;    Used global variables: xbelTree
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::saveAs()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Save Bookmark File"),
                                         QDir::currentPath(),
                                         tr("XBEL Files (*.xbel *.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("SAX Bookmarks"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    if (xbelTree->write(&file))
        statusBar()->showMessage(tr("File saved"), 2000);
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: about
; DESCRIPTION: the about message of the application
;    Input: none
;    Output: none
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::about()
{
   QMessageBox::about(this, tr("About Project"),
                      tr(" "));
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: createActions
; DESCRIPTION: create the actions
;    Input: none
;    Output: none
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAsAct = new QAction(tr("&Save As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    add_function_act = new QAction(tr("Add &Function"), this);
    connect(add_function_act, SIGNAL(triggered()), this, SLOT(add_function()));

    add_item_act = new QAction(tr("Add &Item"), this);
    connect(add_item_act, SIGNAL(triggered()), this, SLOT(add_item()));

    delete_item_act = new QAction(tr("&Delete Item"), this);
    connect(delete_item_act, SIGNAL(triggered()), this, SLOT(delete_item()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: createMenus
; DESCRIPTION: create the menu bar
;    Input: none
;    Output: none
;    Used global variables: fileMenu,edit_menu,helpMenu
; REMARKS when using this function: none
;*********************************************************************/
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(exitAct);

    menuBar()->addSeparator();

    edit_menu = menuBar()->addMenu(tr("&Edit"));
    edit_menu->addAction(add_function_act);
    edit_menu->addAction(add_item_act);
    edit_menu->addAction(delete_item_act);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}
