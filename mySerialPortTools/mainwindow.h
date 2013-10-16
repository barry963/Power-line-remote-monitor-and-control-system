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
*     mainwindow.h
* 2.  DESCRIPTION
*     the menu UI implementation header file
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>

class XbelTree;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();


public slots:
    void open();
    void add_function();
    void add_item();
    void delete_item();
    void saveAs();
    void about();

private:

    Dialog dialog;
    void createActions();
    void createMenus();

    XbelTree *xbelTree;

    QMenu *fileMenu;
    QMenu *edit_menu;
    QMenu *helpMenu;
    QAction *openAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *add_function_act;
    QAction *add_item_act;
    QAction *delete_item_act;
    QAction *aboutAct;
};

#endif
