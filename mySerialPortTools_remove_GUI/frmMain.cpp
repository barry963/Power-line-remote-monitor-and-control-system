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
*     frmMain.cpp
* 2.  DESCRIPTION
*     UI function implementation
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

#include "frmMain.h"


#define PortName1 "/dev/ttyUSB0"
#define PortName2 "/dev/ttyUSB1"

frmMain::frmMain()
{
    this->InitForm();
    OpenSerialPort(default1);
}

frmMain::~frmMain()
{

}

void frmMain::InitForm()
{
    ReceiveCount=0;
    SendCount=0;
    IsShow=true;

    //read data

    myReadTimer=new QTimer(this);
    QObject::connect(myReadTimer, SIGNAL(timeout()), this, SLOT(ReadMyCom()));//20121228

    //send data
    mySendTimer=new QTimer(this);
    mySendTimer->setSingleShot(true);


    //mySendTimer->start(1000);

    //write data

    //save data
    mySaveTimer=new QTimer(this);
    QObject::connect(mySaveTimer,SIGNAL(timeout()),this,SLOT(SaveData()));

    mySaveTimer->start(1000);

    QStringList comList;//serial number
    QStringList baudList;//baud rate
    QStringList parityList;//parity list
    QStringList dataBitsList;//data
    QStringList stopBitsList;//stop bit

    //==modbus port
    QStringList comListAll;//all the serial port
    QStringList comListSelect;//select serial number
    QStringList baudListModbus;//baud rate
    QStringList parityListModbus;//parity list
    QStringList dataBitsListModbus;//data
    QStringList stopBitsListModbus;//stop bit

    comList.clear();
    comList<<"USB0"<<"USB1"<<"USB2"<<"USB3"<<"USB4"<<"USB5"<<"USB6";;

     //==modbus port
    comListAll.clear();//please pay attention that the max modbus port num is MAX_MODBUS_PORT
    comListAll=comList;
    //==current modbus port
    comListSelect.clear();



    baudList.clear();
    baudList<<"50"<<"75"<<"100"<<"134"<<"150"<<"200"<<"300"<<"600"<<"1200"<<"1800"<<"2400"<<"4800"<<"9600"<<"14400"<<"19200"<<"38400"<<"56000"<<"57600"<<"76800"<<"115200"<<"128000"<<"256000";

    baudListModbus.clear();
    baudListModbus=baudList;

    dataBitsList.clear();
    dataBitsList<<"5"<<"6"<<"7"<<"8";

    dataBitsListModbus.clear();
    dataBitsListModbus=dataBitsList;


    parityList.clear();
    parityList<<"none"<<"odd"<<"even";

    parityListModbus.clear();
    parityListModbus=parityList;


    stopBitsList.clear();
    stopBitsList<<"1"<<"1.5"<<"2";

    stopBitsListModbus.clear();
    stopBitsListModbus=stopBitsList;


    this->ChangeEnable(false);

}

bool frmMain::OpenSerialPort(QString & s)
{    
        //???? need to open the corresponding port

    QString portName=PortName1;

    //QString portName="/dev/pts/3";//20130101

    myCom=new Posix_QextSerialPort(portName,QextSerialBase::Polling);//20121231

    myCom->setPortName(portName);



    myCom->setBaudRate((BaudRateType)(9600));
    myCom->setDataBits((DataBitsType)(8));
    myCom->setParity((ParityType)(PAR_EVEN));
    myCom->setStopBits((StopBitsType)(1));

    //set control mode
    myCom->setFlowControl(FLOW_OFF);
    myCom->setTimeout(TIME_OUT);

    bool temp,IsOpen;
    temp=myCom->open(QIODevice::ReadWrite);
    IsOpen=temp;

    //==========================20121213
  //20130219
        int i=0;
            portName=PortName2;
            //portName="/dev/pts/7";
            myComModbus[i]=new Posix_QextSerialPort(portName,QextSerialBase::EventDriven);
            myComModbus[i]->setPortName(portName);
            myComModbus[i]->setBaudRate((BaudRateType)(9600));
            myComModbus[i]->setDataBits((DataBitsType)(8));
            myComModbus[i]->setParity((ParityType)(PAR_EVEN));
            myComModbus[i]->setStopBits((StopBitsType)(1));
            //set control mode
            myComModbus[i]->setFlowControl(FLOW_OFF);
            myComModbus[i]->setTimeout(TIME_OUT);
            temp=myComModbus[i]->open(QIODevice::ReadWrite);
            IsOpen&=temp;


    if (IsOpen)
    {       


        myReadTimer->start(ReadDataTimerInterval);

        CurrentPort=myCom;
        qDebug()<<"set CURRENTPORT";
        //write data to serial port
    }
    return IsOpen;//
}

bool frmMain::CloseSerialPort()
{
    myCom->close();
    for(int i=0;i<CurrentModbusPort.length();i++)//open the modbus port
    {
        myComModbus[i]->close();
    }
    return true;
}

void frmMain::ChangeEnable(bool b)
{
}

void frmMain::GetTime()
{
    QTime timeNow=QTime::currentTime();

    QDate myDate=QDate::currentDate();

    int year=myDate.year();
    int month=myDate.month();
    int day=myDate.day();
    int week=myDate.dayOfWeek();

}

QString frmMain::GetWeek(int week)
{
    QString temp;
    switch(week)
    {
    case 1:temp="Mon";break;
    case 2:temp="Tue";break;
    case 3:temp="Wed";break;
    case 4:temp="Thu";break;
    case 5:temp="Fri";break;
    case 6:temp="Sat";break;
    case 7:temp="Sun";break;
    }
    return temp;
}

QByteArray frmMain::GetHexValue(QString str)//==============
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        hstr=str[i].toAscii();
        if(hstr == ' ')//space
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toAscii();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

char frmMain::ConvertHexChar(char ch)//?????????
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

void frmMain::ReadMyCom()
{

    QString strHex;//hex data
    QString strDecimal;//decimal data
    QString strNomal;//normal data
    QByteArray temp=CurrentPort->readAll();

    if (!temp.isEmpty() && IsShow)
    {
        QDataStream out(&temp,QIODevice::ReadWrite);
        while (!out.atEnd())
        {
            qint8 outChar=0;
            out>>outChar;
            QString str1=QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));//hex
            QString str2=QString("%1").arg(outChar&0xFF,2,2,QLatin1Char('0'));//dec to binary20130103

            strHex+=str1;
            strDecimal+=str2;//20130103

        }



        strNomal=temp;


        if (1)
        {
             IEC101Analyser iec101;
            QString temp=strHex.toUpper();

            ReadData=temp;


            //========
            if((!ReadData.isEmpty())&&(CurrentPort->portName()==myCom->portName()))
            {
                qDebug()<<CurrentPort->portName()+" 101\n";
               if(!iec101.GenerateModbus(ReadData,&WriteData))
               {

                  return;
               }

               CurrentPort=0;
               CurrentPort=myComModbus[0];
               myReadTimer->stop();

               this->WriteMyCom();
               QTest::qSleep(20);
               mySendTimer->start(SendDataTimerInterval);

               myReadTimer->start(ReadDataTimerInterval);

            }
            else if((!ReadData.isEmpty())&&(CurrentPort->portName()==myComModbus[0]->portName()))
            {
                qDebug()<<CurrentPort->portName()+" MOdbus\n";

                ModbusAnalyser modbus;
                int ModbusRepeatNum=0;
                if(!mySendTimer->isActive())
                {
                  qDebug()<<"timeout";
                   ModbusAnalyser temp;

                    temp.resetAll();
                    CurrentPort=0;
                    CurrentPort=myCom;
                    myReadTimer->start(ReadDataTimerInterval);
                    return;
                }
             //  CurrentPort=myCom;
                qDebug()<<"read"<<CurrentPort->portName()<<ReadData;
                //modbus.GenerateIEC101(ReadData,&WriteData);
                while(!modbus.GenerateIEC101(ReadData,&WriteData))
                {
                      if(++ModbusRepeatNum<3)
                    {
                      //this->WriteData;
                      this->WriteMyCom();
                      return;
                    }
                      else
                      {
                          break;
                      }
                 }

                  qDebug()<<"write"<<CurrentPort->portName()<<WriteData;
                  //WriteData="100001000116";

                  CurrentPort=0;
                  CurrentPort=myCom;
                  myReadTimer->stop();
                  //if(ModbusRepeatNum<3)//20120124
                    this->WriteMyCom();

                  QTest::qSleep(20);

                  myReadTimer->start(ReadDataTimerInterval);

            }

            //========

        }


    }

}

void frmMain::WriteMyCom()
{
    //CurrentPort=myCom;
    //QString str=ui->txtSend->toPlainText();20130108
    QString str=WriteData;

    QByteArray outData=str.toAscii();

    // test if port is open
    if (!CurrentPort->isOpen())
    {
        return;
    }
    //test if send is empty
    if (outData.isEmpty())
    {
        //ui->txtSend->setFocus();
        return;
    }

    //Qt enter=\n    windows enter=\r\n============not neccessary
    int size=outData.size();
    if (outData[size-1]=='\n')
    {
        qDebug()<<"add the \r";
        outData.resize(size+1);
        outData[size-1]='\r';
        outData[size]='\n';
    }   

    //if (ui->ckHexSend->isChecked())//convert to hex and send
    if (true)//convert to hex and send
    {
        QByteArray temp=this->GetHexValue(str);
        CurrentPort->write(temp);
        //qDebug()<<(str);
        //ui->txtDataHex->append(CurrentPort->portName()+" Write "+str);
    }
    else
    {
        CurrentPort->write(outData);
    }

    SendCount=SendCount+size;

}

void frmMain::SendData()
{

}

void frmMain::SaveMyCom()
{

}

void frmMain::SaveData()
{

}


void frmMain::on_btnOpen_clicked()
{
    QString warning;

    if(true)
    {

       if (OpenSerialPort(warning))
        {
            this->ChangeEnable(true);


        }
        else
        {

        }
    }
    else
    {
        this->CloseSerialPort();
        this->ChangeEnable(false);

    }
}

void frmMain::on_ckIsAutoSend_stateChanged(int )
{

}

void frmMain::on_ckIsAutoSave_stateChanged(int )
{

}

void frmMain::on_btnClearSend_clicked()
{
    SendCount=0;

}

void frmMain::on_btnClearReceive_clicked()
{
    ReceiveCount=0;

}

void frmMain::on_btnStopShow_clicked()
{

}

void frmMain::on_btnClearAll_clicked()
{

}

void frmMain::on_btnSave_clicked()
{
    this->SaveMyCom();
}



void frmMain::onBtnAddClicked()
{
}

void frmMain::closeEvent(QCloseEvent *event)
{        

}


void frmMain::ParamSet()
{


}

void frmMain::ChooseModbusSelect(const QString &text)
{


}
QString frmMain::GetAddrFromDl(QString addr)
{
    QString relayName;
    if(addr.left(2)=="01")
    {
        relayName= "environ2-vamp210";
    }
    else
        if(addr.left(2)=="02")
        {
            relayName= "environ2-vamp255";
        }
    else
        if(addr.left(2)=="03")
        {
            relayName="environ2-vamp265";
        }
    else
        if(addr.left(2)=="04")
        {
            relayName="environ1-ref615";
        }
    else
        if(addr.left(2)=="05")
        {
            relayName="environ1-vamp210";
        }
    else
        relayName="Error";
    //ui->txtDataHex->append("Receive DLAr: "+addr.left(2)+"Relay Name"+relayName);
    qDebug()<<"Receive DLAr: "+addr.left(2)+" Relay Name: "+relayName;
    return relayName;
}
