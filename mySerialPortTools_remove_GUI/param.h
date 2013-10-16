#ifndef PARAM_H
#define PARAM_H

#include <QDialog>

#include <QMap>

namespace Ui {
    class Param;
}

class Param : public QDialog {
    Q_OBJECT
public:
    Param(QWidget *parent = 0);
    ~Param();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Param *ui;
};

#endif // PARAM_H
