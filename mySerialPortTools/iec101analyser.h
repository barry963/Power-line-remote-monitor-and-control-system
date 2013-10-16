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
*     iec101analyser.h
* 2.  DESCRIPTION
*      header file
*       Analysis IEC 101 Protocol Frame and generate corresponding modbus frame
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

#ifndef IEC101ANALYSER_H
#define IEC101ANALYSER_H

#include<QString>
#define ERROR_MSG 0
#define FIXED_MSG 1
#define OPTIONAL_MSG 2
#define MAX_MSG 10
#define DEFAULT_INDEX 0
#define DLALength 2//2 byte 0000
#define ALALength 2//2 byte 0000

class IEC101Analyser
{
private:
    QString *IEC101Msg[MAX_MSG];
    int IEC101MsgType[MAX_MSG];
    int currentMsgIndex;
//    QString GetAddrFromDl(QString addr)
//    {
//        if(addr.left(2)=="01")
//        {
//            return "environ2-vamp210";
//        }
//        else
//            if(addr.left(2)=="02")
//            {
//                return "environ2-vamp255";
//            }
//        else
//            if(addr.left(2)=="03")
//            {
//                return "environ2-vamp265";
//            }
//        else
//            if(addr.left(2)=="04")
//            {
//                return "environ1-ref615";
//            }
//        else
//            if(addr.left(2)=="05")
//            {
//                return "environ1-vamp210";
//            }
//        return "Error";
//    }


public:
    IEC101Analyser();
    ~IEC101Analyser();
    QString GetIEC101Msg(int i);
    int GetIEC101MsgType(int i);
    void CheckGeneral(QString msg);//get the useful messages
    bool CheckSumLength(int i);//checksum & length
    QString GenerateModbusCRC(QString msg);
    void GetCtrandDLAddr(QString *funC,QString *addr,QString msg);//for fixed
    void GetCtrDLAddrALAddrALVa(QString *funC,QString *DLaddr,QString *AlC,QString *ALaddr,QString *ALVa,QString msg);//for optional
    QString DiscardMsgReturn(QString DLAddr);
    bool GenerateModbus(QString msg,QString *object);
    void resetAll();
};

#endif // IEC101ANALYSER_H
