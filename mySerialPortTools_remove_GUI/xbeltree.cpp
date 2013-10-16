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
*     xbeltree.cpp
* 2.  DESCRIPTION
*    menu function implementation file
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

#include <QDebug>
#include <QString>
#include "xbeltree.h"


XbelTree::XbelTree()
{
    iecaddr<<"2"<<"3"<<"4"<<"15"<<"15"<<"4097"<<"8"<<"0"<<"#"<<"15"<<"16";
    modbusaddr<<"2009"<<"2010"<<"2011"<<"2508"<<"2509"<<"2042"<<"3419"<<"2504"<<"2009"<<"2510"<<"2048";
}

void XbelTree::getCorAddr(QString fun_name,int column,QString item,QString *item1)
{
       if(column==1)
        {
           item=item.right(2)+item.left(2);
           bool b;
           item=QString::number(item.toInt(&b,16),10);

           for(int i=0;i<iecaddr.length();i++)
           {
                if(iecaddr[i]==item)
               {
                                            //to the corresponding format 0000

                                             bool b;
                                             *item1=(QString)modbusaddr[i];
                                            //QString l=QString::number( (*item1).toInt(&b,10)-1,16);
                                             *item1=QString::number( (*item1).toInt(&b,10)-1,16);
                                            while( (*item1).length()<4)
                                            {
                                                (*item1).prepend("0");
                                            }
                                             (*item1)=(*item1).toUpper();
                                             if((*item1).isEmpty())
                                                 (*item1)="0000";
                }
           }
       }
       else
           if(column==2)
       {
                   bool b;
                   item=QString::number(item.right(4).toInt(&b,16)+1,10);

           for(int i=0;i<modbusaddr.length();i++)
           {
                if(modbusaddr[i]==item)
               {
                                            //to the corresponding format 0000
                                             *item1=(QString)iecaddr.at(i);

                                            //to the corresponding format 00 00(dao)
                                            bool b;
                                            *item1=QString::number((*item1).toInt(&b,10),16);

                                            while((*item1).length()<4)
                                            {
                                                (*item1).prepend("0");
                                            }
                                            *item1=(*item1).right(2)+(*item1).left(2);
                                             (*item1)=(*item1).toUpper();
                                             if((*item1).isEmpty())
                                                 (*item1)="0000";
                }
           }
       }
}

