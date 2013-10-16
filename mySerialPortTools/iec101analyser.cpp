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
*     iec101analyser.cpp
* 2.  DESCRIPTION
*     Analysis IEC 101 Protocol Frame and generate corresponding modbus frame
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

#include "iec101analyser.h"
#include "modbusanalyser.h"
#include "xbeltree.h"
#include "frmMain.h"

#include <QtCore>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES                                                *
*--------------------------------------------------------------------*/

int IEC101ModbusFlag=0;//1:don't need to care about the return value
int IEC101RWFlag=0;
QString IEC101SAddr="#";
QString ModbusAddr="#";
QString SelectOperateFlag="#";
QString SelectOperateValidFlag="#";
QString relayAddrForBreaker;

bool jumpFlag=true;
int jumpFlag2=1;//for local remote
int jumpFlag3=0;//for response of operation frame

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: IEC101Analyser()
; DESCRIPTION: Constructor
; Input : None
; Output: None
; Used global variables: MAX_MSG, IEC101Msg, IEC101MsgType,
                                                 currentMsgIndex
; REMARKS when using this function: None
;*********************************************************************/
IEC101Analyser::IEC101Analyser()
{
    for(int i=0;i<MAX_MSG;i++)
    {
        IEC101Msg[i]=0;
        IEC101MsgType[i]=-1;
    }
    currentMsgIndex=-1;
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:~IEC101Analyser()
; DESCRIPTION: Destructor
; Input : None
; Output: None
; Used global variables: currentMsgIndex, IEC101Msg, currentMsgIndex
; REMARKS when using this function: None
;*********************************************************************/
IEC101Analyser::~IEC101Analyser()
{
    for(int i=0;i<currentMsgIndex;i++)
    {
         delete IEC101Msg[i];
    }
    currentMsgIndex=-1;
       // delete [] IEC101Msg;
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:resetAll()
; DESCRIPTION: Initial all variables
; Input : None
; Output: None
; Used global variables: IEC101ModbusFlag, IEC101RWFlag, IEC101SAddr
                                                 ModbusAddr, SelectOperateFlag,
                                                 SelectOperateValidFlag
; REMARKS when using this function: None
;*********************************************************************/
void IEC101Analyser::resetAll()
{
    IEC101ModbusFlag=0;//1:don't need to care about the return value
    IEC101RWFlag=0;
    IEC101SAddr="#";
    ModbusAddr="#";
    SelectOperateFlag="#";
    SelectOperateValidFlag="#";
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:GetIEC101Msg(int i)
; DESCRIPTION: Get IEC101 Protocol frame messages
; Input : i
; Output: IEC101Msg
; Used global variables: IEC101Msg
; REMARKS when using this function: None
;*********************************************************************/
QString IEC101Analyser::GetIEC101Msg(int i)
{
    return *IEC101Msg[i];
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:GetIEC101MsgType(int i)
; DESCRIPTION: Get IEC 101 Protocol message type
; Input : i
; Output: IEC101MsgType
; Used global variables: IEC101MsgType
; REMARKS when using this function: None
;*********************************************************************/
int IEC101Analyser::GetIEC101MsgType(int i)
{
    return IEC101MsgType[i];
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:CheckGeneral(QString msg)
; DESCRIPTION: Check general
; Input : msg
; Output: None
; Used global variables: currentMsgIndex, IEC101Msg, IEC101MsgType
; REMARKS when using this function: None
;*********************************************************************/
void IEC101Analyser::CheckGeneral(QString msg)
{
    int i=0,StartIndex=-1,EndIndex=-1,TypeFlag=-1,m=0;
    QString TwoCh;
    msg.append("0");
    qDebug()<<msg;
    for(int j=0;j<msg.length()-1;j=j+2)
    {
        TwoCh=msg[j];
        TwoCh.append(msg[j+1]);

        if((TwoCh=="10")&&(TypeFlag==-1))
        {
            StartIndex=j;
            TypeFlag=FIXED_MSG;
            //qDebug()<<TypeFlag;
            continue;
        }
        if((TwoCh=="68")&&(TypeFlag==-1))
        {
            StartIndex=j;
            TypeFlag=OPTIONAL_MSG;
            continue;
        }

        if((TwoCh=="16")&&(StartIndex!=-1)&&(j>3))
        {
            EndIndex=j+1;
            QString temp1=msg.left(EndIndex+1);
            QString temp2=temp1.right(EndIndex-StartIndex+1);
            currentMsgIndex++;

            IEC101Msg[i]=new QString(temp2);
            //qDebug()<<temp1;
            //qDebug()<<temp2;
            IEC101MsgType[i]=TypeFlag;
            //qDebug()<<IEC101MsgType[0];
            i++;
            TypeFlag=-1;
            continue;
        }
    }
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:CheckSumLength(int index)
; DESCRIPTION:Generate the checksum length
; Input : index
; Output: true or false
; Used global variables: IEC101Msg, IEC101MsgType, FIXED_MSG,
                                                 OPTIONAL_MSG
; REMARKS when using this function: None
;*********************************************************************/
bool IEC101Analyser::CheckSumLength(int index)
{
    QString temp=*IEC101Msg[index];
    QString TwoCh;
    QString TwoChBin;
    int TwoChDec;
    int sum=0;
    bool b;
    QString sumHex;

    if(IEC101MsgType[index]==-1)
        return false;
    else
        if(IEC101MsgType[index]==FIXED_MSG)
    {
        temp.remove(0,2);
        int l=temp.length();
        temp.remove(l-2,l-1);
        //qDebug()<<temp;

        for(int j=0;j<temp.length()-3;j=j+2)
            {
                TwoCh=temp[j];
                TwoCh.append(temp[j+1]);
                //TwoChBin=QString::number( TwoCh.toInt(&b,16), 2 );
                TwoChDec=TwoCh.toInt(&b,16);
                //qDebug()<<TwoChDec;
                sum+=TwoChDec;
            }
        sumHex=QString::number( sum, 16 );
        TwoChBin=QString::number( sum, 2);

        while(TwoChBin.length()>8)
        {
//            sumHex=QString::number(((TwoChBin.left(TwoChBin.length()-8)).toInt(&b,2)+ (TwoChBin.right(8)).toInt(&b,2)),16);
//            TwoChBin=QString::number(sumHex.toInt(&b,16), 2);
            sumHex=QString::number(((TwoChBin.right(8)).toInt(&b,2)),16);
            TwoChBin=QString::number(sumHex.toInt(&b,16), 2);
        }
        qDebug()<<"Fixed Frame Checksum"<<sumHex;

        if((sumHex.toUpper()==temp.right(2).toUpper())||(temp.right(2).toUpper().contains(sumHex.toUpper())))
        {
            QString s1,s2;
            //GetCtrandDLAddr(&s1,&s2,*IEC101Msg[index]);
            //qDebug()<<s1<<s2;

            return true;
        }
        else
        {
            qDebug()<<"Fixed frame checksum incorrect";
            return false;
        }
    }
    else
        if(IEC101MsgType[index]==OPTIONAL_MSG)
        {
        QString lengthHex1,lengthHex2,checksum;
        int lengthHex;

        bool lengthBool;
        temp.remove(0,2);
        lengthHex1=temp.left(2);
        temp.remove(0,2);
        lengthHex2=temp.left(2);
        temp.remove(0,4);
        int l=temp.length();
        temp.remove(l-2,l-1);
        checksum=temp.right(2);
        //temp.remove(0,8);

        if((lengthHex1!=lengthHex2)&&(temp.length()/2-1!=(lengthHex1.toInt(&b,16))))
        {
            return false;
        }
        qDebug()<<temp;
        qDebug()<<temp.length()/2-1;
        for(int j=0;j<temp.length()-3;j=j+2)
            {
                TwoCh=temp[j];
                TwoCh.append(temp[j+1]);
                TwoChDec=TwoCh.toInt(&b,16);
               // qDebug()<<TwoChDec;
                sum+=TwoChDec;
            }
        //
        sumHex=QString::number( sum, 16 );
        sumHex=sumHex.toUpper();
        TwoChBin=QString::number( sum, 2);
        //qDebug()<<sum<<sumHex;
        while(TwoChBin.length()>8)
        {
            //qDebug()<<(TwoChBin.left(TwoChBin.length()-8)).toInt(&b,2)<<(TwoChBin.right(8)).toInt(&b,2);
            sumHex=QString::number(((TwoChBin.right(8)).toInt(&b,2)),16);
            TwoChBin=QString::number(sumHex.toInt(&b,16), 2);
        }
        sumHex=sumHex.toUpper();
        //qDebug()<<sumHex;
        qDebug()<<"Optional Frame Checksum"<<sumHex;
        if((sumHex.toUpper()==checksum.toUpper())||(checksum.toUpper().contains(sumHex.toUpper())))
        {

            return true;
        }
        else
             return false;

        }
    else
    {

    }
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:GenerateModbusCRC(QString Msg)
; DESCRIPTION: Generate Modbus Protocol frame CRC
; Input : Msg
; Output: None
; Used global variables: None
; REMARKS when using this function: None
;*********************************************************************/
QString IEC101Analyser::GenerateModbusCRC(QString Msg)
{
    QString OMsg;
    OMsg=Msg;
    QString CRCBit="FFFF",temp;//FourBit,CRCFourBit;
    QString OneString="1010000000000001";
    bool b;
    //unsigned int FourBitBin,CRCFourBitBin;


    //int j=0;

    for(int i=0;i<OMsg.length();i=i+2)
    {
        temp=QString::number((Msg.left(2).toInt(&b,16))^(CRCBit.right(2).toInt(&b,16)),16);
        Msg.remove(0,2);
        if(temp.length()<2)
        {
            temp.prepend("0");
        }
        CRCBit=CRCBit.left(2)+temp;

        for(int j=0;j<8;j++)
        {
         QString one;

         QString p=QString::number(CRCBit.toInt(&b,16),2);
         one=p.right(1);

         while(p.length()<16)
          {
              p.prepend("0");
          }
         CRCBit=QString::number(p.left(15).toInt(&b,2),16);


        if(one=="1")
        {
            CRCBit=QString::number((CRCBit.toInt(&b,16)^(OneString.toInt(&b,2))),16);
        }
        while(CRCBit.length()<4)
        {
            CRCBit.prepend("0");
        }
    }

    }
    CRCBit=CRCBit.right(2)+CRCBit.left(2);
    return CRCBit.toUpper();
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:GetCtrandDLAddr(QString* Ctr, QString *addr,QString msg)
; DESCRIPTION:Get data link address
; Input : Ctr, addr, msg
; Output: None
; Used global variables: DLALength
; REMARKS when using this function: None
;*********************************************************************/
void IEC101Analyser::GetCtrandDLAddr(QString* Ctr, QString *addr,QString msg)
{
        *Ctr=msg.left(4).right(2);
        *addr=msg.left(4+DLALength*2).right(DLALength*2);
        *addr=(*addr).left(2);//for Modbus, just 1 byte

}

/*******************************************************************************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:GetCtrDLAddrALAddrALVa(QString *Ctr,QString *DLaddr,QString *AlC,QString *ALOaddr,QString *ALVa,QString msg)
; DESCRIPTION: Generate data link layer address, appliction link layer address,
                           application layer data value, and the control code
; Input : Ctr, DLaddr, AlC, ALOaddr, ALVa, msg
; Output: None
; Used global variables: DLALength,
; REMARKS when using this function: None
;*******************************************************************************************************************************/
//problem default al ob number 1
void IEC101Analyser::GetCtrDLAddrALAddrALVa(QString *Ctr,QString *DLaddr,QString *AlC,QString *ALOaddr,QString *ALVa,QString msg)
{
    *Ctr=msg.left(10).right(2);
    *DLaddr=msg.left(12).right(2);
    *AlC=msg.left(12+DLALength*2).right(2);
    *ALOaddr=msg.left(12+DLALength*2+4+ALALength*2+4).right(4);
    QString temp=msg.right(msg.length()-(12+DLALength*2+4+ALALength*2+4));
    *ALVa=temp.left(temp.length()-4);
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:DiscardMsgReturn(QString DLAddr)
; DESCRIPTION: Generate the discard message ACK
; Input : DLAddr
; Output: "1021"+DLAddr+"2116"
; Used global variables: DLAddr
; REMARKS when using this function: None
;*********************************************************************/
QString IEC101Analyser::DiscardMsgReturn(QString DLAddr)
{
    return "1021"+DLAddr+"2116";
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:DiscardMsgReturn(QString DLAddr)
; DESCRIPTION: Generate IEC101 Protocol frame data and converting
                           IEC 101 frames into Modbus Protocol frame
; Input : msg, object
; Output: true or false
; Used global variables: IEC101MsgType, DEFAULT_INDEX, IEC101Msg
                                                 IEC101ModbusFlag, jumpFlag2, relayAddrForBreaker
                                                 IEC101SAddr, ModbusAddr, jumpFlag, IEC101RWFlag

; REMARKS when using this function: None
;*********************************************************************/
bool IEC101Analyser::GenerateModbus(QString msg,QString *object)
{

    CheckGeneral(msg);
    qDebug()<<IEC101MsgType[DEFAULT_INDEX];
    if((IEC101MsgType[DEFAULT_INDEX]==-1)||((*IEC101Msg[DEFAULT_INDEX]).isEmpty()))
    {
        return false;
    }
    else
    if((IEC101MsgType[DEFAULT_INDEX]==FIXED_MSG)&&(CheckSumLength(DEFAULT_INDEX)))
        {
            QString Ctr,Addr;
            GetCtrandDLAddr(&Ctr,&Addr,*IEC101Msg[DEFAULT_INDEX]);
            qDebug()<<*IEC101Msg[DEFAULT_INDEX];
            if((Ctr.right(1)=="0"))//reset
            {
                IEC101ModbusFlag=1;
                *object=Addr+"0307D80003"+GenerateModbusCRC(Addr+"0307D80003");

            }
            else
                if(Ctr.right(1)=="9")//request status
            {
                qDebug()<<"request status";
                IEC101ModbusFlag=7;
                *object=Addr+"0307D80003"+GenerateModbusCRC(Addr+"0307D80003");
            }
            else
                if((Ctr.right(1).toUpper()=="B")||(Ctr.right(1).toUpper()=="A"))//class 1,2 data
                {
                if(jumpFlag)
                {
                    //20130214
                    if(jumpFlag3==1)
                    {
                        Addr=relayAddrForBreaker;
                        qDebug()<<"reponse to the breaker control 101 1"<<Addr;
                    }

                 jumpFlag=false;
                IEC101ModbusFlag=3;
                frmMain temp1;
                QString relayName=temp1.GetAddrFromDl(Addr);

                QString objectAddrM;
                QString objectAddrI;

                if(jumpFlag2)//20130214
                {
                 qDebug()<<"breaker status";
                objectAddrI="0110";//vamp breaker status address
                }
                else
                {
                    qDebug()<<"remote local";
                    objectAddrI="1000";//vamp locol remote status address
                }

                XbelTree temp2;
                if(IEC101SAddr!="#")
                  {
                    QString objectAddrModebus;
                    temp2.getCorAddr(relayName,1,IEC101SAddr,&objectAddrModebus);

                    if(IEC101SAddr=="0000")
                    {
                        //objectAddrM=IEC101SAddr;
                        IEC101SAddr="#";
                        IEC101ModbusFlag=5;

                        *object=Addr+"03"+objectAddrModebus+"0001";
                        *object+=GenerateModbusCRC(*object);
                    }
                    else
                        {
                        //objectAddrM=IEC101SAddr;
                        //IEC101SAddr="#";
                        temp2.getCorAddr(relayName,1,objectAddrI,&objectAddrModebus);
                        IEC101ModbusFlag=6;

                        //20130214

                        if(ModbusAddr!="#")
                        {
                            objectAddrModebus=ModbusAddr;
                            ModbusAddr="#";
                        }
                        else
                        {

                        }

                        if(objectAddrModebus.isEmpty())//20130213
                        {
                            objectAddrModebus="07D8";//vamp current address
                        }

                         *object=Addr+"03"+objectAddrModebus+"0001";
                         *object+=GenerateModbusCRC(*object);
                         qDebug()<<"Ask data specifically"<<IEC101ModbusFlag<<IEC101RWFlag;

                        }

                        qDebug()<<"Modbus Addr: "+objectAddrModebus+" IEC101 Addr: "+objectAddrI;
                 }
                else
                {

                temp2.getCorAddr(relayName,1,objectAddrI,&objectAddrM);

                qDebug()<<"Modbus Addr: "+objectAddrM+" IEC101 Addr: "+objectAddrI;

                *object=Addr+"03"+objectAddrM+"0001";
                *object=*object+GenerateModbusCRC(*object);
                }
            }
            else
              //  if(((Ctr.right(1).toUpper()=="A")))//class 1 2 data
            {
                qDebug()<<"current value";
                jumpFlag=true;
                IEC101ModbusFlag=2;
                frmMain temp1;
                QString relayName=temp1.GetAddrFromDl(Addr);

                QString objectAddrM;
                QString objectAddrI="0200";//==========================
                XbelTree temp2;

                //20130214
                if(jumpFlag3==1)
                {
                    Addr=relayAddrForBreaker;
                    qDebug()<<"reponse to the breaker control 101 2"<<Addr;
                            jumpFlag3=0;//20130218
                }


                if(IEC101SAddr!="#")
                  {
                    QString objectAddrModebus;
                    temp2.getCorAddr(relayName,1,IEC101SAddr,&objectAddrModebus);

                    if(IEC101SAddr=="0000")
                    {
                        //objectAddrM=IEC101SAddr;
                        IEC101SAddr="#";
                        IEC101ModbusFlag=5;

                        *object=Addr+"03"+objectAddrModebus+"0001";
                        *object+=GenerateModbusCRC(*object);
                    }
                    else
                        {
                        //objectAddrM=IEC101SAddr;
                        //IEC101SAddr="#";
                        temp2.getCorAddr(relayName,1,IEC101SAddr,&objectAddrModebus);
                        IEC101ModbusFlag=6;
                        if(ModbusAddr!="#")
                        {
                            objectAddrModebus=ModbusAddr;
                            ModbusAddr="#";
                        }
                        else
                        {

                        }

                        if(objectAddrModebus.isEmpty())//20130213
                        {
                            objectAddrModebus="07D8";//vamp address
                        }

                         *object=Addr+"03"+objectAddrModebus+"0001";
                         *object+=GenerateModbusCRC(*object);
                         qDebug()<<"Ask data specifically"<<IEC101ModbusFlag<<IEC101RWFlag;
                        }

                        qDebug()<<"Modbus Addr: "+objectAddrModebus+" IEC101 Addr: "+objectAddrI;
                 }


                else
                {
                temp2.getCorAddr(relayName,1,objectAddrI,&objectAddrM);

                qDebug()<<"Modbus Addr: "+objectAddrM+" IEC101 Addr: "+objectAddrI;

                *object=Addr+"03"+objectAddrM+"0003"+GenerateModbusCRC(Addr+"0307D80003");
                }
            }
        }
                return true;
        }
    else
        if((IEC101MsgType[DEFAULT_INDEX]==OPTIONAL_MSG)&&(CheckSumLength(DEFAULT_INDEX)))
        {
            QString Ctr,DLaddr,AlC,ALOaddr,ALVa;

            GetCtrDLAddrALAddrALVa(&Ctr,&DLaddr,&AlC,&ALOaddr,&ALVa,*IEC101Msg[DEFAULT_INDEX]);

            relayAddrForBreaker=DLaddr;//20130214

            frmMain temp1;
            QString relayName=temp1.GetAddrFromDl(DLaddr);

            QString objectAddrM;
            XbelTree temp2;
            temp2.getCorAddr(relayName,1,ALOaddr,&objectAddrM);//0000 <=> minute register
            qDebug()<<"Modbus Addr: "+objectAddrM+" IEC101 Addr: "+ALOaddr;

            if(((Ctr.right(1).toUpper()=="3")))//send data
            {

                if(AlC=="67")//clock synchronisation
                {
                    qDebug()<<"clock synchronisation";
                    IEC101ModbusFlag=4;
                    bool b;
                    QString second=QString::number(ALVa.left(4).toInt(&b,16)/1000,16),minute=ALVa.left(6).right(2),hour=ALVa.left(8).right(2),day=QString::number(QString::number(ALVa.left(10).right(2).toInt(&b,16),2).right(5).toInt(&b,2),16),month=ALVa.right(4).left(2),year=QString::number(ALVa.right(2).toInt(&b,16)+2000,16);

                    while(second.length()<4)
                    {
                        second.prepend("0");
                    }
                    if(minute.length()<2)
                    {
                        minute.prepend("0");
                    }
                    if(day.length()<2)
                    {
                        day.prepend("0");
                    }
                    if(hour.length()<2)
                    {
                        hour.prepend("0");
                    }
                    if(month.length()<2)
                    {
                        month.prepend("0");
                    }
                    if(year.length()<4)
                    {
                        year.prepend("0");
                    }

                   *object=DLaddr+"10"+objectAddrM+"0004"+"08"+second+minute+hour+day+month+year;//+ALVa.left(6).right(2);//write minute
                    //*object=DLaddr+"10"+objectAddrM+"0004"+"08"+"0003551122012013";
                    *object=*object+GenerateModbusCRC(*object);
                    IEC101SAddr=ALOaddr;
                }
                else
                    if(AlC=="66")//read data
                    {
                          qDebug()<<"read command";
                          IEC101ModbusFlag=4;
                          IEC101RWFlag=1;//read data
                          *object=DLaddr+"03"+objectAddrM+"0001";//+ALVa.left(6).right(2);//read data
                          *object=*object+GenerateModbusCRC(*object);
                           IEC101SAddr=ALOaddr;
                    }
                else
                    if(AlC.toUpper()=="2D")//single command
                    {
                    qDebug()<<"single command";
                    IEC101ModbusFlag=4;
                    IEC101RWFlag=2;//write data
                    *object=DLaddr+"06"+objectAddrM+"00"+ALVa;//+ALVa.left(6).right(2);//read data
                    *object=*object+GenerateModbusCRC(*object);
                     IEC101SAddr=ALOaddr;
                    }
                else
                    if(AlC.toUpper()=="2E")//double command
                    {
                        jumpFlag3=1;//20130214

                         qDebug()<<"double command";
                         IEC101ModbusFlag=4;
                         IEC101RWFlag=4;//write data double
                         bool b;
                         QString SelectOperate=ALVa.left(1);
                         QString Value=ALVa.right(1);
                         Value=QString::number((Value.toInt(&b,16)-1),16);//double command conversion!!!!!!!!!!!!!!!!!
                         //Value.prepend("0");
                         if(SelectOperate=="8")//select
                         {
                             if(Value=="0")//open
                             {
                                 SelectOperateFlag="off";
                                 qDebug()<<"open";
                                 objectAddrM=QString::number((objectAddrM.toInt(&b,16)-2),16);
                            }
                             else
                                 if(Value=="1")//on close
                                 {
                                 SelectOperateFlag="on";
                                     qDebug()<<"close";
                                      objectAddrM=QString::number((objectAddrM.toInt(&b,16)-1),16);
                                }
                             while(objectAddrM.length()<4)
                             {
                                 objectAddrM.prepend("0");
                             }
                         }
                         else
                         if(SelectOperate=="0")//operate
                          {
                                if(SelectOperateFlag=="on")//20130212
                                SelectOperateFlag="operateon";
                                else
                                    if(SelectOperateFlag=="off")
                                        SelectOperateFlag="operateoff";


                                qDebug()<<"operate";
                                //nothing need to do
                          }
                              Value="01";
                             *object=DLaddr+"06"+objectAddrM+"00"+Value;//+ALVa.left(6).right(2);//read data
                             *object=*object+GenerateModbusCRC(*object);
                             IEC101SAddr=ALOaddr;
                             ModbusAddr=objectAddrM;
                             qDebug()<<"Modbus Addr: "+objectAddrM+" IEC101 Addr: "+ALOaddr;
                    }
                else
                    if(AlC.toUpper()=="64")//interrogation
                    {
                    qDebug()<<"interrogation";
                    IEC101ModbusFlag=4;
                    IEC101RWFlag=3;
                    *object=DLaddr+"03"+"0000"+"0001";//+ALVa.left(6).right(2);//read data
                    *object=*object+GenerateModbusCRC(*object);
                     IEC101SAddr="0100";
                    }

            }
            return true;
        }
    else
    {
        qDebug()<<"Generate return false";
        return false;
    }
}
