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
*     frmMain.h
* 2.  DESCRIPTION
*     UI header file
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
#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QtTest/QtTest>
#include <QMainWindow>
#include <QCloseEvent>


#include "posix_qextserialport.h"
#include "qextserialenumerator.h"

#include "iec101analyser.h"
#include "modbusanalyser.h"
#include "mainwindow.h"

//read and write delay
#define TIME_OUT 10
#define MAX_MODBUS_PORT 6
//delay when reading serial port buffer
#define ReadDataTimerInterval 100

//continous send delay
#define SendDataTimerInterval 1000

namespace Ui {
    class frmMain;
}

class frmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();
    void closeEvent(QCloseEvent *event);
        QString GetAddrFromDl(QString addr);
private:
    Ui::frmMain *ui;

private:

    Posix_QextSerialPort *myCom;//IEC 101
    Posix_QextSerialPort *myComModbus[MAX_MODBUS_PORT];//Modbus side
    Posix_QextSerialPort *CurrentPort;

    QTimer *myTimer;
    QTimer *myReadTimer;//read serial data
    QTimer *mySendTimer;//send serial data
    QTimer *mySaveTimer;//save serial data


    int SendCount;//send data count
    int ReceiveCount;//receive data count
    bool IsShow;//whether show the data
    QStringList CurrentModbusPort;//store the current modbus port
    QString DLAddr;
    QString ALAddr;
    QString ReadData;
    QString WriteData;

    void InitForm();
    bool OpenSerialPort(QString &s);
    bool CloseSerialPort();
    void ChangeEnable(bool b);
    QString GetWeek(int week);
    QByteArray GetHexValue(QString str);
    char ConvertHexChar(char ch);
    MainWindow mainWin;//20130109


private slots:
//    void on_btnAbout_clicked();
    void on_btnSave_clicked();
    void on_btnClearAll_clicked();
    void on_btnStopShow_clicked();
    void on_btnClearReceive_clicked();
    void on_btnClearSend_clicked();
    void GetTime();
    void ReadMyCom();
    void WriteMyCom();
    void SaveMyCom();
    void SendData();
    void SaveData();
    void on_ckIsAutoSave_stateChanged(int );
    void on_ckIsAutoSend_stateChanged(int );
    void on_btnOpen_clicked();
    void onBtnAddClicked();
    void ParamSet();
    void ChooseModbusSelect(const QString &text);

};

#endif // FRMMAIN_H
