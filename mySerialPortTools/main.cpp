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
*     main.cpp
* 2.  DESCRIPTION
*     main function of the whole project
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
#include <QtGui/QApplication>
#include "frmMain.h"
#include <QTextCodec>
#include <QDesktopWidget>
#include <QStyleFactory>

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: main
; DESCRIPTION: create a instance for the whole project
;    Input: none
;    Output: none
; REMARKS when using this function: none
;*********************************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Chinese words
    QTextCodec *codec=QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    //window in center
    QDesktopWidget *desktop=QApplication::desktop();
    int width=desktop->width();
    int height=desktop->height();

    frmMain w;

    w.move((width-w.width())/2,(height-w.height())/2);
    w.setFixedSize(w.width(),w.height());
    w.show();

    return a.exec();
}
