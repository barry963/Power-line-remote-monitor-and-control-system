#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>

class XbelTree;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();


public slots:
    void open();
    void add_function();
    void add_item();
    void delete_item();
    void saveAs();
    void about();

private:

    Dialog dialog;
    void createActions();
    void createMenus();

    XbelTree *xbelTree;

    QMenu *fileMenu;
    QMenu *edit_menu;
    QMenu *helpMenu;
    QAction *openAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *add_function_act;
    QAction *add_item_act;
    QAction *delete_item_act;
    QAction *aboutAct;
};

#endif
