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
*     dialog.cpp
* 2.  DESCRIPTION
*     xbeltree function implementation file
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

#include "dialog.h"
#include "xbeltree.h"


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: Dialog
; DESCRIPTION: create the dialog for the add function action
;    Input: click the add function
;    Output: pop up the add function window
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    errorMessageDialog = new QErrorMessage(this);

    int frameStyle = QFrame::Sunken | QFrame::Panel;

    integerLabel = new QLabel;
    integerLabel->setFrameStyle(frameStyle);
    QPushButton *integerButton =
            new QPushButton(tr("Variables Number"));


    textLabel = new QLabel;
    textLabel->setFrameStyle(frameStyle);
    QPushButton *textButton = new QPushButton(tr("Function name"));
    QPushButton *ok_button = new QPushButton(tr("OK"));
    QPushButton *exit_button = new QPushButton(tr("Exit"));

    connect(integerButton, SIGNAL(clicked()), this, SLOT(setInteger()));
    connect(textButton, SIGNAL(clicked()), this, SLOT(setText()));
    connect(ok_button, SIGNAL(clicked()), this, SLOT(perform_action()));
    connect(exit_button, SIGNAL(clicked()), this, SLOT(close()));

    QGridLayout *layout = new QGridLayout;
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(1, 150);
    layout->addWidget(textButton, 0, 0);
    layout->addWidget(textLabel, 0, 1);
    layout->addWidget(integerButton, 1, 0);
    layout->addWidget(integerLabel, 1, 1);
    ok_button->setFixedWidth(100);
    exit_button->setFixedWidth(100);
    layout->addWidget(ok_button,3,1,Qt::AlignRight);
    layout->addWidget(exit_button,3,2);
    setLayout(layout);

    setWindowTitle(tr("Input Name and Variables Number"));
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: setInteger
; DESCRIPTION: enable the user to write integer
;    Input: none
;    Output: none
;    Used global variables: integerLabel
; REMARKS when using this function: none
;*********************************************************************/
void Dialog::setInteger()
{
    //! [0]
    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                 tr("Number:"), 2, 0, 100, 1, &ok);
    if (ok)
        integerLabel->setText(tr("%1").arg(i));
    //! [0]
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: setText
; DESCRIPTION: enable the user to write text
;    Input: none
;    Output: none
;    Used global variables: textLabel
; REMARKS when using this function: none
;*********************************************************************/
void Dialog::setText()
{
    //! [3]
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("Function name"), QLineEdit::Normal,
                                         tr("f4"), &ok);
    if (ok && !text.isEmpty())
        textLabel->setText(text);
    //! [3]
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: perform_action
; DESCRIPTION: add function to xml tree
;    Input: none
;    Output: none
;    Used global variables: textLabel,xbeltree
; REMARKS when using this function: none
;*********************************************************************/
void Dialog::perform_action()
{
    QString function_name = textLabel->text();
    xbeltree->add_function(&function_name,integerLabel->text().toInt());
    close();
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: set_xbeltree
; DESCRIPTION: set the xbeltree
;    Input: none
;    Output: none
;    Used global variables: textLabel
; REMARKS when using this function: none
;*********************************************************************/
void Dialog::set_xbeltree(XbelTree* xbeltree_)
{
    xbeltree = xbeltree_;
}
