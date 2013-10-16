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

#ifndef MODBUSANALYSER_H
#define MODBUSANALYSER_H


#define MAX_MOD_MSG 10
#include<QString>

class ModbusAnalyser
{
private:
    QString *ModbusMsg[MAX_MOD_MSG];
   // int IEC101MsgType[MAX_MOD_MSG];
    int currentModbusMsgIndex;
    QString GetAddrFromDl(QString addr)
    {
        if(addr.left(2)=="01")
        {
            return "environ2-vamp210";
        }
        else
            if(addr.left(2)=="02")
            {
                return "environ2-vamp255";
            }
        else
            if(addr.left(2)=="03")
            {
                return "environ2-vamp265";
            }
        else
            if(addr.left(2)=="04")
            {
                return "environ1-ref615";
            }
        else
            if(addr.left(2)=="05")
            {
                return "environ1-vamp210";
            }
        return "Error";
    }

public:
    ModbusAnalyser();
    ~ModbusAnalyser();
    QString GenerateTimeForIEC(int formatflag);
    QString GetModbusMsg(int i);
   //int GetIEC101MsgType(int i);
    void CheckGeneral(QString msg);//get the useful messages
    bool CheckCRC(QString Msg);
    void GenerateIEC101Checksum(QString Msg,QString *Length,QString *CheckSum,int TypeFlag);
    void GetCtrandDLAddr(QString *funC,QString *addr,QString msg);//for fixed
    bool GenerateIEC101(QString msg,QString *object);
    QString GenerateADValue(QString Msg,QString FirstADAddr);
    void resetAll();
};

#endif // MODBUSANALYSER_H
