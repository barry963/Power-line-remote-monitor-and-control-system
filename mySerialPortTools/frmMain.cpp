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
#include "ui_frmMain.h"

#include "param.h"

//#include "ui_param.h"

#include "QtGui"

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: frmMain
; DESCRIPTION:  The construction function of frmMain
;    Input:
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
frmMain::frmMain(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->InitForm();

}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: ~frmMain
; DESCRIPTION:  The destruction function of frmMain
;    Input: none
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
frmMain::~frmMain()
{
    delete ui;
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: InitForm
; DESCRIPTION:  Initialize the serial port and the user interface
;    Input: none
;    Output: none
;    Used global variables: ReceiveCount,SendCount,IsShow,ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::InitForm()
{
    ReceiveCount=0;
    SendCount=0;
    IsShow=true;

    //read data

    myReadTimer=new QTimer(this);
    connect(myReadTimer, SIGNAL(timeout()), this, SLOT(ReadMyCom()));//20121228

    //send data
    mySendTimer=new QTimer(this);
    mySendTimer->setSingleShot(true);

    //write data

    //save data
    mySaveTimer=new QTimer(this);
    connect(mySaveTimer,SIGNAL(timeout()),this,SLOT(SaveData()));
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
    comList<<"USB0"<<"USB1"<<"USB2"<<"USB3"<<"USB4"<<"USB5"<<"USB6";
    ui->cboxPortName->clear();
    ui->cboxPortName->addItems(comList);
    ui->cboxPortName->setCurrentIndex(0);

     //==modbus port
    comListAll.clear();//please pay attention that the max modbus port num is MAX_MODBUS_PORT
    comListAll=comList;
    ui->cboxPortNameModAll->clear();
    ui->cboxPortNameModAll->addItems(comListAll);
    ui->cboxPortNameModAll->setCurrentIndex(0);
    //==current modbus port
    comListSelect.clear();
    ui->cboxPortNameModSelect->clear();
    connect(ui->btnAddModPort,SIGNAL(clicked()),this,SLOT(onBtnAddClicked()));


    baudList.clear();
    baudList<<"50"<<"75"<<"100"<<"134"<<"150"<<"200"<<"300"<<"600"<<"1200"<<"1800"<<"2400"<<"4800"<<"9600"<<"14400"<<"19200"<<"38400"<<"56000"<<"57600"<<"76800"<<"115200"<<"128000"<<"256000";
    ui->cboxBaudRate->clear();
    ui->cboxBaudRate->addItems(baudList);
    ui->cboxBaudRate->setCurrentIndex(12);

    baudListModbus.clear();
    baudListModbus=baudList;
    ui->cboxBaudRateModbus->clear();
    ui->cboxBaudRateModbus->addItems(baudListModbus);
    ui->cboxBaudRateModbus->setCurrentIndex(12);

    dataBitsList.clear();
    dataBitsList<<"5"<<"6"<<"7"<<"8";
    ui->cboxDataBit->clear();
    ui->cboxDataBit->addItems(dataBitsList);
    ui->cboxDataBit->setCurrentIndex(3);

    dataBitsListModbus.clear();
    dataBitsListModbus=dataBitsList;
    ui->cboxDataBitModbus->clear();
    ui->cboxDataBitModbus->addItems(dataBitsListModbus);
    ui->cboxDataBitModbus->setCurrentIndex(3);


    parityList.clear();
    parityList<<"none"<<"odd"<<"even";
    ui->cboxParity->clear();
    ui->cboxParity->addItems(parityList);
    ui->cboxParity->setCurrentIndex(2);

    parityListModbus.clear();
    parityListModbus=parityList;
    ui->cboxParityModbus->clear();
    ui->cboxParityModbus->addItems(parityListModbus);
    ui->cboxParityModbus->setCurrentIndex(2);


    stopBitsList.clear();
    stopBitsList<<"1"<<"1.5"<<"2";
    ui->cboxStopBit->clear();
    ui->cboxStopBit->addItems(stopBitsList);
    ui->cboxStopBit->setCurrentIndex(0);

    stopBitsListModbus.clear();
    stopBitsListModbus=stopBitsList;
    ui->cboxStopBitModbus->clear();
    ui->cboxStopBitModbus->addItems(stopBitsListModbus);
    ui->cboxStopBitModbus->setCurrentIndex(0);

    ui->cboxSend->clear();
    ui->cboxSave->clear();
    for (int i=1;i<61;i++)
    {
        ui->cboxSend->addItem(QString::number(i)+"second");
        ui->cboxSave->addItem(QString::number(i)+"second");
    }

    ui->cboxSave->setCurrentIndex(9);
    ui->cboxSend->setCurrentIndex(9);


    ui->cboxSend->setEnabled(false);
    ui->cboxSave->setEnabled(false);

    this->ChangeEnable(false);


    //menu
    connect(ui->actionPortConfig,SIGNAL(triggered()),this,SLOT(ParamSet()));

    //add
    connect(ui->cboxPortNameModSelect,SIGNAL(currentIndexChanged ( const QString &)),this,SLOT(ChooseModbusSelect(const QString&)));
    connect(ui->cboxPortNameModAll,SIGNAL(currentIndexChanged ( const QString &)),this,SLOT(ChooseModbusSelect(const QString&)));
    DLAddr.append("0");
    ALAddr.append("0");

    //hex receive&send
    ui->ckHexReceive->setChecked(true);
    ui->ckHexSend->setChecked(true);

}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: OpenSerialPort
; DESCRIPTION:  Open the serial port
;    Input: the warning message
;    Output: IsOpen
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
bool frmMain::OpenSerialPort(QString & s)
{    
        //???? need to open the corresponding port
    QString portName="/dev/tty"+(ui->cboxPortName->currentText());

    //QString portName="/dev/pts/3";//20130101

    myCom=new Posix_QextSerialPort(portName,QextSerialBase::Polling);//20121231

    myCom->setPortName(portName);

    myCom->setBaudRate((BaudRateType)ui->cboxBaudRate->currentIndex());
    myCom->setDataBits((DataBitsType)ui->cboxDataBit->currentIndex());
    myCom->setParity((ParityType)ui->cboxParity->currentIndex());
    myCom->setStopBits((StopBitsType)ui->cboxStopBit->currentIndex());
    //set control mode
    myCom->setFlowControl(FLOW_OFF);
    myCom->setTimeout(TIME_OUT);

    bool temp,IsOpen;
    temp=myCom->open(QIODevice::ReadWrite);
    IsOpen=temp;

    for(int i=0;i<CurrentModbusPort.length();i++)//open the modbus port
    {
        portName="/dev/tty"+CurrentModbusPort[i];
        //portName="/dev/pts/7";
        myComModbus[i]=new Posix_QextSerialPort(portName,QextSerialBase::EventDriven);
        myComModbus[i]->setPortName(portName);
        myComModbus[i]->setBaudRate((BaudRateType)ui->cboxBaudRateModbus->currentIndex());
        myComModbus[i]->setDataBits((DataBitsType)ui->cboxDataBitModbus->currentIndex());
        myComModbus[i]->setParity((ParityType)ui->cboxParityModbus->currentIndex());
        myComModbus[i]->setStopBits((StopBitsType)ui->cboxStopBitModbus->currentIndex());
        //set control mode
        myComModbus[i]->setFlowControl(FLOW_OFF);
        myComModbus[i]->setTimeout(TIME_OUT);
        temp=myComModbus[i]->open(QIODevice::ReadWrite);
        IsOpen&=temp;

        if(temp)
        {           
            qDebug()<<"=============Modbus "+CurrentModbusPort[i]+ " Open";
        }
        else
        {
            s=s+ CurrentModbusPort[i]+" ";
        }

    }
    //==========================20121213


    if (IsOpen)
    {       
    //        connect(myCom, SIGNAL(readyRead()), this, SLOT(ReadMyCom()));//20121228
        //myReadTimer->setSingleShot(true);//20130107

        myReadTimer->start(ReadDataTimerInterval);

        CurrentPort=myCom;
        qDebug()<<"set CURRENTPORT";
        //write data to serial port

        connect(ui->btnSend,SIGNAL(clicked()),this,SLOT(WriteMyCom()));

                qDebug()<<"=============IEC 101 "+ui->cboxPortName->currentText()+" Open" ;
    }
    return IsOpen;//
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: CloseSerialPort
; DESCRIPTION:  Close the serial port
;    Input: none
;    Output: true
;    Used global variables: myCom,CurrentModbusPort,myComModbus
; REMARKS when using this function: none
;*********************************************************************/
bool frmMain::CloseSerialPort()
{
    myCom->close();
    for(int i=0;i<CurrentModbusPort.length();i++)//open the modbus port
    {
        myComModbus[i]->close();
    }
    return true;
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: ChangeEnable
; DESCRIPTION:  change the value of enable or disable for the user interface
;    Input:
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::ChangeEnable(bool b)
{
    ui->cboxBaudRate->setEnabled(!b);
    ui->cboxDataBit->setEnabled(!b);
    ui->cboxParity->setEnabled(!b);
    ui->cboxPortName->setEnabled(!b);
    ui->cboxStopBit->setEnabled(!b);


    ui->btnAddModPort->setEnabled(!b);
    ui->cboxBaudRateModbus->setEnabled(!b);
    ui->cboxDataBitModbus->setEnabled(!b);
    ui->cboxParityModbus->setEnabled(!b);
    ui->cboxPortNameModAll->setEnabled(!b);
    ui->cboxStopBitModbus->setEnabled(!b);


    ui->gbox3->setEnabled(b);
    ui->gbox4->setEnabled(b);
    ui->gbox5->setEnabled(b);
    ui->gbox6->setEnabled(b);

}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: GetTime
; DESCRIPTION:  get the system time and set it in the ui
;    Input: none
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::GetTime()
{
    QTime timeNow=QTime::currentTime();
    ui->labTime->setText(tr("Time:")+timeNow.toString());

    QDate myDate=QDate::currentDate();

    int year=myDate.year();
    int month=myDate.month();
    int day=myDate.day();
    int week=myDate.dayOfWeek();


    ui->labDate->setText(tr("Date:")+QString::number(day)+'/'+QString::number(month)+'/'+QString::number(year)+'.'+this->GetWeek(week));
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: GetWeek
; DESCRIPTION:  get the system time and set it in the ui
;    Input: the value of the weekday
;    Output: the name of the  weekday
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
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


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: GetHexValue
; DESCRIPTION:  convert the string to Hex value
;    Input: string
;    Output: hex value
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
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

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: ConvertHexChar
; DESCRIPTION:  convert the char to Hex value
;    Input: char
;    Output: hex value
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
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

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: ReadMyCom
; DESCRIPTION:  read the data from the serial port and display it in ui
;    Input: none
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
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


        if (ui->ckHexReceive->isChecked())
        {
             IEC101Analyser iec101;
            QString temp=strHex.toUpper();

            ReadData=temp;

            ui->txtDataHex->append(CurrentPort->portName()+" Read "+temp);

            //========
            if((!ReadData.isEmpty())&&(CurrentPort->portName()==myCom->portName()))
            {
               if(!iec101.GenerateModbus(ReadData,&WriteData))
               {
                   //ui->txtDataHex->append("Something wrong with the IEC101 frame:"+iec101.GetIEC101Msg(0)+" "+iec101.GetIEC101MsgType(0));
                  return;
               }

               CurrentPort=0;
               CurrentPort=myComModbus[0];
               myReadTimer->stop();
               //WriteData="010307d800038484";
               //QTest::qSleep(40);
               this->WriteMyCom();
               QTest::qSleep(20);
               mySendTimer->start(SendDataTimerInterval);

               myReadTimer->start(ReadDataTimerInterval);

            }
            else if((!ReadData.isEmpty())&&(CurrentPort->portName()==myComModbus[0]->portName()))
            {
                ModbusAnalyser modbus;
                int ModbusRepeatNum=0;
                if(!mySendTimer->isActive())
                {
                  qDebug()<<"timeout";
                   ModbusAnalyser temp;
//                   WriteData="100E04002316";
//                   this->WriteMyCom();
                    ui->txtDataHex->append("Modbus timeout");
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

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: WriteMyCom
; DESCRIPTION:  write the data through the serial port and display it in ui
;    Input: none
;    Output: none
;    Used global variables: ui,CurrentPort,SendCount
; REMARKS when using this function: none
;*********************************************************************/
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
        ui->txtSend->setFocus();
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

    if (ui->ckHexSend->isChecked())//convert to hex and send
    {
        QByteArray temp=this->GetHexValue(str);
        CurrentPort->write(temp);
        //qDebug()<<(str);
        ui->txtDataHex->append(CurrentPort->portName()+" Write "+str);
    }
    else
    {
        CurrentPort->write(outData);
    }
    //qDebug()<<endl<<this->GetHexValue(str);
    SendCount=SendCount+size;
    ui->labSend->setText(tr("send:%1 byte").arg(SendCount));
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: SendData
; DESCRIPTION:  send the data manually
;    Input: none
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::SendData()
{

    if (ui->ckIsAutoSend->isChecked())
    {
        mySendTimer->setInterval((ui->cboxSend->currentIndex()+1)*1000);
        this->WriteMyCom();
    }
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: SaveMyCom
; DESCRIPTION:  create the file to save the data made by the communication process
;    Input: none
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::SaveMyCom()
{
    QDateTime now=QDateTime::currentDateTime();
    QString name=now.toString("yyyyMMddHHmmss");
    QString fileName=QCoreApplication::applicationDirPath()+"/"+name+".txt";


    if (ui->txtDataHex->document()->toPlainText().length()==0)
    {
        return;
    }
    QFile file(fileName);
    file.open(QFile::WriteOnly);
    QTextStream out(&file);
    out<<ui->txtDataHex->document()->toPlainText();
    file.close();
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:
; DESCRIPTION:  save the data of the ui to the serial port
;    Input: none
;    Output: none
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::SaveData()
{
    if (ui->ckIsAutoSave->isChecked())
    {
        mySaveTimer->setInterval((ui->cboxSave->currentIndex()+1)*1000);
        this->SaveMyCom();
    }
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_btnOpen_clicked
; DESCRIPTION:  if the button open has been clicked, open the serial port and display the corresponding
                message on ui
;    Input: click the button open
;    Output: open the serial port
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_btnOpen_clicked()
{
    QString warning;
    if (ui->btnOpen->text()=="open port")
    {

       if (OpenSerialPort(warning))
        {
            this->ChangeEnable(true);

            ui->btnOpen->setText("close port");
            ui->labIsOpen->setText(tr("state：open"));

        }
        else
        {
            QMessageBox::critical(this,"tip","failue to open the port "+warning+" !",QMessageBox::Ok);
        }
    }
    else
    {
        this->CloseSerialPort();
        this->ChangeEnable(false);
        ui->btnOpen->setText("open port");
        ui->labIsOpen->setText(tr("state：close"));
    }
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_ckIsAutoSend_stateChanged
; DESCRIPTION:  if the button AutoSend has been clicked, send the data automatically
;    Input: click the button AutoSend
;    Output: send the data automatically
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_ckIsAutoSend_stateChanged(int )
{
    ui->cboxSend->setEnabled(ui->ckIsAutoSend->isChecked());
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_ckIsAutoSave_stateChanged
; DESCRIPTION:  if the button AutoSave has been clicked, save the data automatically
;    Input: click the button AutoSave
;    Output: save the data automatically
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_ckIsAutoSave_stateChanged(int )
{
    ui->cboxSave->setEnabled(ui->ckIsAutoSave->isChecked());
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_btnClearSend_clicked
; DESCRIPTION:  if the button ClearSend has been clicked, clear the send data
;    Input: click the button ClearSend
;    Output: clear the send data
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_btnClearSend_clicked()
{
    SendCount=0;
    ui->labSend->setText(tr("send:0 byte"));
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_btnClearReceive_clicked
; DESCRIPTION:  if the button ClearReceive has been clicked, clear the Receive data
;    Input: click the button ClearReceive
;    Output: clear the Receive data
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_btnClearReceive_clicked()
{
    ReceiveCount=0;
    ui->labReceive->setText(tr("receive:0 byte"));
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_btnStopShow_clicked
; DESCRIPTION:  if the button StopShow has been clicked, stop display and change the message on ui to start display
                 vice versa.
;    Input: click the button StopShow
;    Output: stop display
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_btnStopShow_clicked()
{
    if (ui->btnStopShow->text()=="stop display")
    {
        IsShow=false;
        ui->btnStopShow->setText("start display");
    }
    else
    {
        IsShow=true;
        ui->btnStopShow->setText("stop display");
    }
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_btnClearAll_clicked
; DESCRIPTION:  if the button ClearAll has been clicked, clear all the data
;    Input: click the button ClearAll
;    Output:  clear all the data
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_btnClearAll_clicked()
{
    ui->txtDataDecimal->document()->clear();
    ui->txtDataHex->document()->clear();
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: on_btnSave_clicked
; DESCRIPTION:  if the button Save has been clicked, save the data
;    Input: click the button Save
;    Output: save the data
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::on_btnSave_clicked()
{
    this->SaveMyCom();
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: onBtnAddClicked
; DESCRIPTION:  if the button Add has been clicked, add a port for communication and display on ui
;    Input: click the button Add
;    Output: add a port for communication
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::onBtnAddClicked()
{
    QStringList currentport;


    currentport.append(ui->cboxPortNameModAll->currentText());
    ui->label_removeportwarning->clear();

    if(!CurrentModbusPort.contains(currentport[0],Qt::CaseInsensitive))
    {
        CurrentModbusPort.append(currentport);
        ui->cboxPortNameModSelect->addItems(currentport);

    }
    else//add twice=remove
    {

        CurrentModbusPort.removeOne(currentport[0]);
        ui->cboxPortNameModSelect->clear();
        ui->cboxPortNameModSelect->addItems(CurrentModbusPort);

        ui->label_removeportwarning->setText(currentport[0]+" remove!!!");

    }
    currentport.clear();
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: closeEvent
; DESCRIPTION:  if the button close has been clicked, pop up the window to make sure the action of close
;    Input: click the button close
;    Output: close the applicaion
;    Used global variables: ui
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::closeEvent(QCloseEvent *event)
{        
    QMessageBox::StandardButton button;
    
    if(ui->btnOpen->text()=="open port")
    {

         button = QMessageBox::question(this, tr("Warning"),
         QString(tr("Are you sure to Close?")),
         QMessageBox::Yes | QMessageBox::No);

     if (button == QMessageBox::No) {
         event->ignore();  
     }
     else if (button == QMessageBox::Yes) {
         event->accept(); 
     }
 }
    else
    {
     button = QMessageBox::question(this, tr("Warning"),
         QString(tr("Please close the port before closing the program")),
         QMessageBox::Ok | QMessageBox::Ok);
         event->ignore();  

    }
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: ParamSet (discard)
; DESCRIPTION:
;    Input:
;    Output:
;    Used global variables: mainWin
; REMARKS when using this function: none
;*********************************************************************/
void frmMain::ParamSet()
{
    //Param parametermenu(this);
    //QApplication app(argc, argv);
    mainWin.show();
    //mainWin.open();

    //return app.exec();

}

void frmMain::ChooseModbusSelect(const QString &text)
{

}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: GetAddrFromDl
; DESCRIPTION: get the relay name from the frame
;    Input: frame
;    Output: relay name
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
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
