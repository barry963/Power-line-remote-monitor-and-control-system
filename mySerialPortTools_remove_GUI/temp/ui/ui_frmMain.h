/********************************************************************************
** Form generated from reading UI file 'frmMain.ui'
**
** Created: Thu Jan 24 13:18:45 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QAction *actionPortConfig;
    QWidget *centralWidget;
    QGroupBox *gbox1;
    QLabel *label;
    QComboBox *cboxPortName;
    QComboBox *cboxBaudRate;
    QLabel *label_2;
    QComboBox *cboxDataBit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *cboxParity;
    QComboBox *cboxStopBit;
    QPushButton *btnOpen;
    QGroupBox *gbox2;
    QTextEdit *txtDataHex;
    QGroupBox *gbox3;
    QCheckBox *ckHexSend;
    QCheckBox *ckHexReceive;
    QCheckBox *ckIsAutoSend;
    QComboBox *cboxSend;
    QCheckBox *ckIsAutoSave;
    QComboBox *cboxSave;
    QGroupBox *gbox4;
    QTextEdit *txtDataDecimal;
    QGroupBox *gbox5;
    QTextEdit *txtSend;
    QPushButton *btnSend;
    QGroupBox *gbox6;
    QPushButton *btnClearSend;
    QPushButton *btnClearReceive;
    QPushButton *btnStopShow;
    QPushButton *btnClearAll;
    QPushButton *btnSave;
    QGroupBox *gbox1_2;
    QLabel *label_11;
    QComboBox *cboxPortNameModSelect;
    QComboBox *cboxBaudRateModbus;
    QLabel *label_12;
    QComboBox *cboxDataBitModbus;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QComboBox *cboxParityModbus;
    QComboBox *cboxStopBitModbus;
    QPushButton *btnAddModPort;
    QComboBox *cboxPortNameModAll;
    QLabel *label_removeportwarning;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labIsOpen;
    QLabel *labSend;
    QLabel *labReceive;
    QLabel *labTime;
    QLabel *labDate;
    QMenuBar *menuBar;
    QMenu *menuParam;

    void setupUi(QMainWindow *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->resize(1029, 625);
        frmMain->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionPortConfig = new QAction(frmMain);
        actionPortConfig->setObjectName(QString::fromUtf8("actionPortConfig"));
        centralWidget = new QWidget(frmMain);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gbox1 = new QGroupBox(centralWidget);
        gbox1->setObjectName(QString::fromUtf8("gbox1"));
        gbox1->setGeometry(QRect(10, 10, 201, 271));
        label = new QLabel(gbox1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 81, 21));
        cboxPortName = new QComboBox(gbox1);
        cboxPortName->setObjectName(QString::fromUtf8("cboxPortName"));
        cboxPortName->setGeometry(QRect(90, 30, 71, 21));
        cboxBaudRate = new QComboBox(gbox1);
        cboxBaudRate->setObjectName(QString::fromUtf8("cboxBaudRate"));
        cboxBaudRate->setGeometry(QRect(90, 60, 71, 21));
        label_2 = new QLabel(gbox1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 61, 16));
        cboxDataBit = new QComboBox(gbox1);
        cboxDataBit->setObjectName(QString::fromUtf8("cboxDataBit"));
        cboxDataBit->setGeometry(QRect(90, 90, 71, 21));
        label_3 = new QLabel(gbox1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 54, 12));
        label_4 = new QLabel(gbox1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 71, 16));
        label_5 = new QLabel(gbox1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 150, 54, 12));
        cboxParity = new QComboBox(gbox1);
        cboxParity->setObjectName(QString::fromUtf8("cboxParity"));
        cboxParity->setGeometry(QRect(90, 120, 71, 21));
        cboxStopBit = new QComboBox(gbox1);
        cboxStopBit->setObjectName(QString::fromUtf8("cboxStopBit"));
        cboxStopBit->setGeometry(QRect(90, 150, 71, 21));
        btnOpen = new QPushButton(gbox1);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(20, 240, 141, 31));
        btnOpen->setCursor(QCursor(Qt::PointingHandCursor));
        gbox2 = new QGroupBox(centralWidget);
        gbox2->setObjectName(QString::fromUtf8("gbox2"));
        gbox2->setGeometry(QRect(510, 10, 511, 221));
        gbox2->setLayoutDirection(Qt::LeftToRight);
        txtDataHex = new QTextEdit(gbox2);
        txtDataHex->setObjectName(QString::fromUtf8("txtDataHex"));
        txtDataHex->setGeometry(QRect(0, 20, 511, 191));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtDataHex->sizePolicy().hasHeightForWidth());
        txtDataHex->setSizePolicy(sizePolicy);
        txtDataHex->setMaximumSize(QSize(16777215, 16777215));
        txtDataHex->setLayoutDirection(Qt::LeftToRight);
        txtDataHex->setAutoFillBackground(false);
        txtDataHex->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        txtDataHex->setFrameShape(QFrame::StyledPanel);
        txtDataHex->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtDataHex->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtDataHex->setLineWrapMode(QTextEdit::WidgetWidth);
        txtDataHex->setReadOnly(true);
        gbox3 = new QGroupBox(centralWidget);
        gbox3->setObjectName(QString::fromUtf8("gbox3"));
        gbox3->setGeometry(QRect(0, 280, 201, 191));
        ckHexSend = new QCheckBox(gbox3);
        ckHexSend->setObjectName(QString::fromUtf8("ckHexSend"));
        ckHexSend->setGeometry(QRect(10, 40, 121, 17));
        ckHexReceive = new QCheckBox(gbox3);
        ckHexReceive->setObjectName(QString::fromUtf8("ckHexReceive"));
        ckHexReceive->setGeometry(QRect(10, 70, 131, 17));
        ckIsAutoSend = new QCheckBox(gbox3);
        ckIsAutoSend->setObjectName(QString::fromUtf8("ckIsAutoSend"));
        ckIsAutoSend->setGeometry(QRect(10, 100, 171, 17));
        cboxSend = new QComboBox(gbox3);
        cboxSend->setObjectName(QString::fromUtf8("cboxSend"));
        cboxSend->setGeometry(QRect(30, 120, 111, 22));
        ckIsAutoSave = new QCheckBox(gbox3);
        ckIsAutoSave->setObjectName(QString::fromUtf8("ckIsAutoSave"));
        ckIsAutoSave->setGeometry(QRect(10, 150, 231, 20));
        cboxSave = new QComboBox(gbox3);
        cboxSave->setObjectName(QString::fromUtf8("cboxSave"));
        cboxSave->setGeometry(QRect(30, 170, 111, 22));
        gbox4 = new QGroupBox(centralWidget);
        gbox4->setObjectName(QString::fromUtf8("gbox4"));
        gbox4->setGeometry(QRect(510, 240, 521, 211));
        txtDataDecimal = new QTextEdit(gbox4);
        txtDataDecimal->setObjectName(QString::fromUtf8("txtDataDecimal"));
        txtDataDecimal->setGeometry(QRect(0, 20, 511, 191));
        sizePolicy.setHeightForWidth(txtDataDecimal->sizePolicy().hasHeightForWidth());
        txtDataDecimal->setSizePolicy(sizePolicy);
        txtDataDecimal->setMaximumSize(QSize(16777215, 16777215));
        txtDataDecimal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"table {border: 1px solid black};"));
        txtDataDecimal->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtDataDecimal->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtDataDecimal->setLineWrapMode(QTextEdit::WidgetWidth);
        txtDataDecimal->setReadOnly(true);
        gbox5 = new QGroupBox(centralWidget);
        gbox5->setObjectName(QString::fromUtf8("gbox5"));
        gbox5->setGeometry(QRect(210, 280, 281, 81));
        txtSend = new QTextEdit(gbox5);
        txtSend->setObjectName(QString::fromUtf8("txtSend"));
        txtSend->setGeometry(QRect(0, 20, 191, 41));
        txtSend->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 201, 255);\n"
"color: rgb(0, 0, 0);"));
        btnSend = new QPushButton(gbox5);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(190, 20, 91, 41));
        btnSend->setCursor(QCursor(Qt::PointingHandCursor));
        gbox6 = new QGroupBox(centralWidget);
        gbox6->setObjectName(QString::fromUtf8("gbox6"));
        gbox6->setGeometry(QRect(230, 530, 611, 61));
        btnClearSend = new QPushButton(gbox6);
        btnClearSend->setObjectName(QString::fromUtf8("btnClearSend"));
        btnClearSend->setGeometry(QRect(10, 20, 131, 31));
        btnClearSend->setCursor(QCursor(Qt::PointingHandCursor));
        btnClearReceive = new QPushButton(gbox6);
        btnClearReceive->setObjectName(QString::fromUtf8("btnClearReceive"));
        btnClearReceive->setGeometry(QRect(160, 20, 141, 31));
        btnClearReceive->setCursor(QCursor(Qt::PointingHandCursor));
        btnStopShow = new QPushButton(gbox6);
        btnStopShow->setObjectName(QString::fromUtf8("btnStopShow"));
        btnStopShow->setGeometry(QRect(310, 20, 91, 31));
        btnStopShow->setCursor(QCursor(Qt::PointingHandCursor));
        btnClearAll = new QPushButton(gbox6);
        btnClearAll->setObjectName(QString::fromUtf8("btnClearAll"));
        btnClearAll->setGeometry(QRect(410, 20, 91, 31));
        btnClearAll->setCursor(QCursor(Qt::PointingHandCursor));
        btnSave = new QPushButton(gbox6);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(520, 20, 91, 31));
        btnSave->setCursor(QCursor(Qt::PointingHandCursor));
        gbox1_2 = new QGroupBox(centralWidget);
        gbox1_2->setObjectName(QString::fromUtf8("gbox1_2"));
        gbox1_2->setGeometry(QRect(230, 10, 271, 261));
        label_11 = new QLabel(gbox1_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 30, 81, 21));
        cboxPortNameModSelect = new QComboBox(gbox1_2);
        cboxPortNameModSelect->setObjectName(QString::fromUtf8("cboxPortNameModSelect"));
        cboxPortNameModSelect->setGeometry(QRect(90, 30, 71, 21));
        cboxBaudRateModbus = new QComboBox(gbox1_2);
        cboxBaudRateModbus->setObjectName(QString::fromUtf8("cboxBaudRateModbus"));
        cboxBaudRateModbus->setGeometry(QRect(90, 60, 71, 21));
        label_12 = new QLabel(gbox1_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 60, 61, 16));
        cboxDataBitModbus = new QComboBox(gbox1_2);
        cboxDataBitModbus->setObjectName(QString::fromUtf8("cboxDataBitModbus"));
        cboxDataBitModbus->setGeometry(QRect(90, 90, 71, 21));
        label_13 = new QLabel(gbox1_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 90, 54, 12));
        label_14 = new QLabel(gbox1_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 120, 71, 16));
        label_15 = new QLabel(gbox1_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 150, 54, 12));
        cboxParityModbus = new QComboBox(gbox1_2);
        cboxParityModbus->setObjectName(QString::fromUtf8("cboxParityModbus"));
        cboxParityModbus->setGeometry(QRect(90, 120, 71, 21));
        cboxStopBitModbus = new QComboBox(gbox1_2);
        cboxStopBitModbus->setObjectName(QString::fromUtf8("cboxStopBitModbus"));
        cboxStopBitModbus->setGeometry(QRect(90, 150, 71, 21));
        btnAddModPort = new QPushButton(gbox1_2);
        btnAddModPort->setObjectName(QString::fromUtf8("btnAddModPort"));
        btnAddModPort->setGeometry(QRect(230, 30, 31, 21));
        btnAddModPort->setCursor(QCursor(Qt::PointingHandCursor));
        cboxPortNameModAll = new QComboBox(gbox1_2);
        cboxPortNameModAll->setObjectName(QString::fromUtf8("cboxPortNameModAll"));
        cboxPortNameModAll->setGeometry(QRect(160, 30, 71, 21));
        label_removeportwarning = new QLabel(gbox1_2);
        label_removeportwarning->setObjectName(QString::fromUtf8("label_removeportwarning"));
        label_removeportwarning->setGeometry(QRect(160, 60, 101, 21));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label_removeportwarning->setFont(font);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 480, 221, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labIsOpen = new QLabel(verticalLayoutWidget);
        labIsOpen->setObjectName(QString::fromUtf8("labIsOpen"));

        verticalLayout->addWidget(labIsOpen);

        labSend = new QLabel(verticalLayoutWidget);
        labSend->setObjectName(QString::fromUtf8("labSend"));

        verticalLayout->addWidget(labSend);

        labReceive = new QLabel(verticalLayoutWidget);
        labReceive->setObjectName(QString::fromUtf8("labReceive"));

        verticalLayout->addWidget(labReceive);

        labTime = new QLabel(verticalLayoutWidget);
        labTime->setObjectName(QString::fromUtf8("labTime"));

        verticalLayout->addWidget(labTime);

        labDate = new QLabel(verticalLayoutWidget);
        labDate->setObjectName(QString::fromUtf8("labDate"));

        verticalLayout->addWidget(labDate);

        frmMain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(frmMain);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1029, 25));
        menuParam = new QMenu(menuBar);
        menuParam->setObjectName(QString::fromUtf8("menuParam"));
        frmMain->setMenuBar(menuBar);

        menuBar->addAction(menuParam->menuAction());
        menuParam->addAction(actionPortConfig);
        menuParam->addSeparator();

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QMainWindow *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "serial port tool 1.0", 0, QApplication::UnicodeUTF8));
        actionPortConfig->setText(QApplication::translate("frmMain", "Port config", 0, QApplication::UnicodeUTF8));
        gbox1->setTitle(QApplication::translate("frmMain", "Serial port IEC101 parameters", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmMain", "Port num", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmMain", "Baudrate", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("frmMain", "Data bit", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("frmMain", "Checksum", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("frmMain", "Stop bit", 0, QApplication::UnicodeUTF8));
        btnOpen->setText(QApplication::translate("frmMain", "open port", 0, QApplication::UnicodeUTF8));
        gbox2->setTitle(QApplication::translate("frmMain", "Receive data", 0, QApplication::UnicodeUTF8));
        gbox3->setTitle(QApplication::translate("frmMain", "set data", 0, QApplication::UnicodeUTF8));
        ckHexSend->setText(QApplication::translate("frmMain", "Hex data send", 0, QApplication::UnicodeUTF8));
        ckHexReceive->setText(QApplication::translate("frmMain", "Hex data receive", 0, QApplication::UnicodeUTF8));
        ckIsAutoSend->setText(QApplication::translate("frmMain", "automatically send data", 0, QApplication::UnicodeUTF8));
        ckIsAutoSave->setText(QApplication::translate("frmMain", "automatically receive data", 0, QApplication::UnicodeUTF8));
        gbox4->setTitle(QApplication::translate("frmMain", "Decimal data", 0, QApplication::UnicodeUTF8));
        gbox5->setTitle(QApplication::translate("frmMain", "send data", 0, QApplication::UnicodeUTF8));
        txtSend->setHtml(QApplication::translate("frmMain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\256\213\344\275\223'; font-size:9pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnSend->setText(QApplication::translate("frmMain", "send data", 0, QApplication::UnicodeUTF8));
        gbox6->setTitle(QApplication::translate("frmMain", "operation", 0, QApplication::UnicodeUTF8));
        btnClearSend->setText(QApplication::translate("frmMain", "clear send counter", 0, QApplication::UnicodeUTF8));
        btnClearReceive->setText(QApplication::translate("frmMain", "clear receive counter", 0, QApplication::UnicodeUTF8));
        btnStopShow->setText(QApplication::translate("frmMain", "stop display", 0, QApplication::UnicodeUTF8));
        btnClearAll->setText(QApplication::translate("frmMain", "clear display", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("frmMain", "save data", 0, QApplication::UnicodeUTF8));
        gbox1_2->setTitle(QApplication::translate("frmMain", "Serial port Modbus parameters", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("frmMain", "Port num", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("frmMain", "Baudrate", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("frmMain", "Data bit", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("frmMain", "Checksum", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("frmMain", "Stop bit", 0, QApplication::UnicodeUTF8));
        btnAddModPort->setText(QApplication::translate("frmMain", "Add", 0, QApplication::UnicodeUTF8));
        label_removeportwarning->setText(QString());
        labIsOpen->setText(QApplication::translate("frmMain", "state: close", 0, QApplication::UnicodeUTF8));
        labSend->setText(QApplication::translate("frmMain", "send:0 Byte", 0, QApplication::UnicodeUTF8));
        labReceive->setText(QApplication::translate("frmMain", "receive:0 Byte", 0, QApplication::UnicodeUTF8));
        labTime->setText(QApplication::translate("frmMain", "time:", 0, QApplication::UnicodeUTF8));
        labDate->setText(QApplication::translate("frmMain", "date:", 0, QApplication::UnicodeUTF8));
        menuParam->setTitle(QApplication::translate("frmMain", "Param", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
