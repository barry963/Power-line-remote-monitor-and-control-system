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
*     modbusanalyser.cpp
* 2.  DESCRIPTION
*     Analysis and generate Modbus Protocol Frame
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

#include "modbusanalyser.h"
#include "iec101analyser.h"
#include "xbeltree.h"
#include "frmMain.h"

#include <QtCore>
extern int IEC101ModbusFlag;//1:don't need to care about the return value
extern QString IEC101SAddr;
extern int IEC101RWFlag;
extern QString ModbusAddr;
extern QString SelectOperateFlag;
extern QString SelectOperateValidFlag;
extern int jumpFlag2;
extern int jumpFlag3;
extern QString relayAddrForBreaker;

ModbusAnalyser::ModbusAnalyser()
{
    for(int i=0;i<MAX_MOD_MSG;i++)
    {
        ModbusMsg[i]=0;
    }
    currentModbusMsgIndex=-1;
}

ModbusAnalyser::~ModbusAnalyser()
{
    for(int i=0;i<currentModbusMsgIndex;i++)
    {
         delete ModbusMsg[i];
    }
    currentModbusMsgIndex=-1;
}

void ModbusAnalyser::resetAll()
{
    IEC101ModbusFlag=0;//1:don't need to care about the return value
    IEC101RWFlag=0;
    IEC101SAddr="#";
    ModbusAddr="#";
    SelectOperateFlag="#";
    SelectOperateValidFlag="#";
}

QString ModbusAnalyser::GetModbusMsg(int i)
{

}

//int GetIEC101MsgType(int i);
void ModbusAnalyser::CheckGeneral(QString msg)//get the useful messages
{

}

bool ModbusAnalyser::CheckCRC(QString Msg)//checksum & length
{

    QString OMsg;
    OMsg=Msg;
    QString CRCBit="FFFF",CRCMsgHex=OMsg.right(4),temp;//FourBit,CRCFourBit;
    //QString OneString="1010000000000001";
    bool b;
    //unsigned int FourBitBin,CRCFourBitBin;

    if((Msg.length()/2.0-Msg.length()/2)!=0)
        return false;

    if((Msg.left(4).right(2)!="06")&&((Msg.length()/2-5)!=Msg.left(6).right(2).toInt(&b,16)))
        return false;

     IEC101Analyser iec;
     CRCBit=iec.GenerateModbusCRC(Msg.left(Msg.length()-4));
    qDebug()<<CRCBit;

    if(CRCBit.toUpper()==CRCMsgHex.toUpper())
    {
        return true;
    }
    else
    {
        return false;
    }
}


//1 FIXED 2 OPTIONAL
void ModbusAnalyser::GenerateIEC101Checksum(QString Msg,QString *Length,QString *CheckSum,int TypeFlag)
{
    QString temp=Msg;
    QString TwoCh;
    QString TwoChBin;
    int TwoChDec;
    int sum=0;
    bool b;
    QString sumHex;

        for(int j=0;j<temp.length();j=j+2)
            {
                TwoCh=temp[j];
                TwoCh.append(temp[j+1]);
                //TwoChBin=QString::number( TwoCh.toInt(&b,16), 2 );
                TwoChDec=TwoCh.toInt(&b,16);
                //qDebug()<<TwoChDec;
                sum+=TwoChDec;
            }
        sumHex=QString::number( sum, 16 );

        if(sumHex.length()>3)
        {
            sumHex=sumHex.right(2);
        }

        if(sumHex.length()==1)
            sumHex.prepend("0");

        *CheckSum=sumHex.right(2).toUpper();


            if(TypeFlag==2)//OPTIONAL_FLAG
            {
                *Length=QString::number(Msg.length()/2,16);
                if(Length->length()==1)
                {
                    Length->prepend("0");
                }
            }
}

void ModbusAnalyser::GetCtrandDLAddr(QString *funC,QString *addr,QString msg)//for fixed
{
    *addr=msg.left(2);
    *funC=msg.right(4).right(2);
}


bool ModbusAnalyser::GenerateIEC101(QString msg,QString *object)
{
    qDebug()<<"get message: "<<msg;
    if((!CheckCRC(msg)))
    {
        if((IEC101ModbusFlag!=4))
        {
        qDebug()<<"CRC false";
        return false;
        }
    }
    QString funCModbus,addrModbus;
    GetCtrandDLAddr(&funCModbus,&addrModbus,msg);


    QString addr=msg.left(2),CheckSum,Length;//DLaddr

    //20130214
    if(jumpFlag3==1)
    {
        addr=relayAddrForBreaker;
        qDebug()<<"reponse to the breaker control"<<addr;
    }


    QString relayName=GetAddrFromDl(addr);
    QString ALOaddr;



    if(DLALength==2)
        addr.append("00");

    if(IEC101ModbusFlag==1)
    {
        GenerateIEC101Checksum(addr,&Length,&CheckSum,1);
        *object="1000"+addr+CheckSum+"16";
        IEC101ModbusFlag=0;
        return true;
    }
    else
        if(IEC101ModbusFlag==7)//status
        {
        GenerateIEC101Checksum("2B"+addr,&Length,&CheckSum,1);
        *object="102B"+addr+CheckSum+"16";
        IEC101ModbusFlag=0;
        return true;
        }
    else
        if(IEC101ModbusFlag==2)//for class 1
    {     
        //modbus 02030602B902B802B82933
        //QStringList value; 3 phrase current
        QString temp=msg.right(16).left(12),temp1=temp.left(4),temp2=temp.left(8).right(4),temp3=temp.right(4);


        QString objectAddr="0200";

        //objectAddr=objectAddr.right(2)+objectAddr.left(2);

        *object="08"+addr+"0C"+"03"+"03"+addr+objectAddr+temp1.right(2)+temp1.left(2)+"00"+GenerateTimeForIEC(0)+"0300"+temp2.right(2)+temp.left(2)+"00"+GenerateTimeForIEC(0)+"0400"+temp3.right(2)+temp3.left(2)+"00"+GenerateTimeForIEC(0);

           //*object="0802000b 01 0x05 0x01 0x00 0x01 0x40 0x00 0x00 0x00 0x5c 0x16
        GenerateIEC101Checksum(*object,&Length,&CheckSum,2);
        *object="68"+Length+Length+"68"+*object;
        *object+=CheckSum+"16";


        IEC101ModbusFlag=0;

        return true;
    }
    else
        if(IEC101ModbusFlag==3)//class 2,double,breaker
        {
        QString temp3=msg.right(8).left(4);//20130212

        QString breakerstatus;//20130214
        QString objectAddr;

        if(jumpFlag2)//20130214
        {//breaker status
         jumpFlag2=0;
         objectAddr="0110";         //vamp breaker status address

        if(temp3.right(2)=="00")//open20130212
        {
            breakerstatus="01";
            //breakerstatus="1";
        }
        else
            if(temp3.right(2)=="01")//close
            {
                //breakerstatus="0";
                 breakerstatus="02";

            }
        else//undefined
        {
            breakerstatus="00";
            //breakerstatus="2";
        }
        }
    else
        {//remote local status
          objectAddr="1000";//vamp local remote address
        jumpFlag2=1;
          breakerstatus=temp3.right(2);
        }


//breakerstatus="02";


        //objectAddr=objectAddr.right(2)+objectAddr.left(2);           
        //*object="08"+addr+"0C"+"01"+"03"+addr+objectAddr+breakerstatus+"00"+GenerateTimeForIEC(0);//20120212

        *object="08"+addr+"03"+"01"+"05"+addr+objectAddr+breakerstatus;

        GenerateIEC101Checksum(*object,&Length,&CheckSum,2);
        *object="68"+Length+Length+"68"+*object;
        *object+=CheckSum+"16";

        IEC101ModbusFlag=0;

        return true;
        }
    else
        if(IEC101ModbusFlag==4)
        {

                qDebug()<<"IEC101ModbusFlag 4";
                //*object="1020"+addr+CheckSum+"16";
                if(IEC101RWFlag==4)//20130212
                {
                GenerateIEC101Checksum("00"+addr,&Length,&CheckSum,1);
                    *object="1000"+addr+CheckSum+"16";//20130211
                }
                else
                {
                GenerateIEC101Checksum("20"+addr,&Length,&CheckSum,1);
                     *object="1020"+addr+CheckSum+"16";
                 }
                //IEC101SAddr=objectAddrM;

                IEC101ModbusFlag=0;
                return true;
        }
    else
        if(IEC101ModbusFlag==5)//return the corresponding data
        {


        *object="08"+addr+"670107"+addr+"0000"+GenerateTimeForIEC(1);
        GenerateIEC101Checksum(*object,&Length,&CheckSum,2);
        *object="68"+Length+Length+"68"+*object;
        *object+=CheckSum+"16";
        return true;

        }
    else
        if((IEC101ModbusFlag==6)&&(IEC101RWFlag==1))//read data
        {
        //ALOaddr;
        *object="08"+addr+"0c0105"+addr+IEC101SAddr+msg.right(8).left(4).right(2)+msg.right(8).left(4).left(2)+GenerateTimeForIEC(1);//scaled value with time tag
        GenerateIEC101Checksum(*object,&Length,&CheckSum,2);
        *object="68"+Length+Length+"68"+*object;
        *object+=CheckSum+"16";
        IEC101SAddr="#";
        IEC101RWFlag=0;
        return true;
        }
    else
        if((IEC101ModbusFlag==6)&&(IEC101RWFlag==2))//write data
    {
    //ALOaddr;

    *object="08"+addr+"2d012f"+addr+IEC101SAddr+msg.right(8).left(4).right(2)+msg.right(8).left(4).left(2)+GenerateTimeForIEC(1);//scaled value with time tag
    GenerateIEC101Checksum(*object,&Length,&CheckSum,2);
    *object="68"+Length+Length+"68"+*object;
    *object+=CheckSum+"16";
    IEC101SAddr="#";
    IEC101RWFlag=0;
    return true;
    }
    else
        if((IEC101ModbusFlag==6)&&(IEC101RWFlag==3))//interrogation
    {
    //ALOaddr;
    qDebug()<<"interrogation response";
    *object="28"+addr+"640107"+addr+IEC101SAddr+msg.right(8).left(4).right(2)+msg.right(8).left(4).left(2)+"14";//scaled value with time tag
    GenerateIEC101Checksum(*object,&Length,&CheckSum,2);
    *object="68"+Length+Length+"68"+*object;
    *object+=CheckSum+"16";
    IEC101SAddr="#";
    IEC101RWFlag=0;
    IEC101ModbusFlag=0;
    return true;
    }
    else
        if((IEC101ModbusFlag==6)&&(IEC101RWFlag==4))//write data double
    {
    //ALOaddr;
    qDebug()<<"select or operate response";
    QString value=msg.right(8).left(4).right(1);
     bool b;
    if(SelectOperateFlag=="off")//off 81
    {
        value="8"+value;
    }
    else
        if(SelectOperateFlag=="on")//on 82
        {
        value="8"+QString::number(value.toInt(&b,16)+1,16);
        }
    else
        if(SelectOperateFlag=="operateoff")//20130212 off 01
        {
            //value="0"+value;
            value="01";
            SelectOperateFlag="#";//20130212
            jumpFlag3=0;//20130214
        }
    else
        if(SelectOperateFlag=="operateon")//20130212 on 02
        {
            //value="0"+QString::number(value.toInt(&b,16)+1,16);
           value="02";
           SelectOperateFlag="#";//20130212
           jumpFlag3=0;//20130214
        }

    //*object="08"+addr+"2e0147"+addr+IEC101SAddr+value;//scaled value with time tag20130212
    *object="28"+addr+"2e0107"+addr+IEC101SAddr+value;//scaled value with time tag

    GenerateIEC101Checksum(*object,&Length,&CheckSum,2);
    *object="68"+Length+Length+"68"+*object;
    *object+=CheckSum+"16";
    IEC101SAddr="#";
    IEC101RWFlag=0;
    return true;
    }
}




//0:3,1:7
QString ModbusAnalyser::GenerateTimeForIEC(int formatflag)
{
    QTime time=QTime::currentTime();
    QDate date=QDate::currentDate();
    QString minisec=QString::number(time.msec(),16);

    while(minisec.length()<4)
    {
        minisec.prepend("0");
    }

    minisec=minisec.right(2)+minisec.left(2);
    QString minute=QString::number(time.minute(),16);
    while(minute.length()<2)
    {
        minute.prepend("0");
    }
    QString hour=QString::number(time.hour(),16);
    while(hour.length()<2)
    {
        hour.prepend("0");
    }
    QString day=QString::number(date.dayOfWeek()*32+date.day(),16);
    while(day.length()<2)
    {
        day.prepend("0");
    }
    QString month=QString::number(date.month(),16);
    while(month.length()<2)
    {
        month.prepend("0");
    }
    bool b;
    QString year=QString::number(date.year()-2000,16);
    while(year.length()<2)
    {
        year.prepend("0");
    }
    if(formatflag==0)
    {
        return minisec+minute;
    }
    else
        if(formatflag==1)
        {
            return minisec+minute+hour+day+month+year;
        }
}

//Msg: modbus message FirstADAddr: Low+High
QString ModbusAnalyser::GenerateADValue(QString Msg,QString FirstADAddr)
{
    bool b;
    int length=Msg.left(6).right(2).toInt(&b,16);
    QString data=Msg.right(length*2+4).left(length*2);
    for(int i=0;i<length;i++)
    {

    }

}
