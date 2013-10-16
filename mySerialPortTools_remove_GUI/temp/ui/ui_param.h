/********************************************************************************
** Form generated from reading UI file 'param.ui'
**
** Created: Fri Dec 14 22:39:20 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAM_H
#define UI_PARAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Param
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *Param)
    {
        if (Param->objectName().isEmpty())
            Param->setObjectName(QString::fromUtf8("Param"));
        Param->resize(400, 416);
        horizontalLayoutWidget = new QWidget(Param);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 271, 401));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonCancel = new QPushButton(Param);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(310, 250, 85, 27));
        pushButtonOK = new QPushButton(Param);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(310, 220, 85, 27));

        retranslateUi(Param);

        QMetaObject::connectSlotsByName(Param);
    } // setupUi

    void retranslateUi(QDialog *Param)
    {
        Param->setWindowTitle(QApplication::translate("Param", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("Param", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("Param", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Param: public Ui_Param {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAM_H
