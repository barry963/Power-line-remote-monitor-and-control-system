#include <QtGui>

#include "dialog.h"
#include "xbeltree.h"



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    errorMessageDialog = new QErrorMessage(this);

    int frameStyle = QFrame::Sunken | QFrame::Panel;

    integerLabel = new QLabel;
    integerLabel->setFrameStyle(frameStyle);
    QPushButton *integerButton =
            new QPushButton(tr("Variables Number"));


    textLabel = new QLabel;
    textLabel->setFrameStyle(frameStyle);
    QPushButton *textButton = new QPushButton(tr("Function name"));
    QPushButton *ok_button = new QPushButton(tr("OK"));
    QPushButton *exit_button = new QPushButton(tr("Exit"));

    connect(integerButton, SIGNAL(clicked()), this, SLOT(setInteger()));
    connect(textButton, SIGNAL(clicked()), this, SLOT(setText()));
    connect(ok_button, SIGNAL(clicked()), this, SLOT(perform_action()));
    connect(exit_button, SIGNAL(clicked()), this, SLOT(close()));

    QGridLayout *layout = new QGridLayout;
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(1, 150);
    layout->addWidget(textButton, 0, 0);
    layout->addWidget(textLabel, 0, 1);
    layout->addWidget(integerButton, 1, 0);
    layout->addWidget(integerLabel, 1, 1);
    ok_button->setFixedWidth(100);
    exit_button->setFixedWidth(100);
    layout->addWidget(ok_button,3,1,Qt::AlignRight);
    layout->addWidget(exit_button,3,2);
    setLayout(layout);

    setWindowTitle(tr("Input Name and Variables Number"));
}

void Dialog::setInteger()
{
    //! [0]
    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                 tr("Number:"), 2, 0, 100, 1, &ok);
    if (ok)
        integerLabel->setText(tr("%1").arg(i));
    //! [0]
}

void Dialog::setText()
{
    //! [3]
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("Function name"), QLineEdit::Normal,
                                         tr("f4"), &ok);
    if (ok && !text.isEmpty())
        textLabel->setText(text);
    //! [3]
}

void Dialog::perform_action()
{
    QString function_name = textLabel->text();
    xbeltree->add_function(&function_name,integerLabel->text().toInt());
    close();
}

void Dialog::set_xbeltree(XbelTree* xbeltree_)
{
    xbeltree = xbeltree_;
}
