#include <QtGui>

#include "mainwindow.h"
#include "xbeltree.h"

MainWindow::MainWindow()
{
    xbelTree = new XbelTree;
    setCentralWidget(xbelTree);

    createActions();
    createMenus();

    statusBar()->showMessage(tr("Ready"));

    setWindowTitle(tr("DOM Bookmarks"));
    resize(480, 320);

    QToolBar *toolBar =  addToolBar(tr("&Add item"));
    toolBar->addAction(add_item_act);
    QToolBar *toolBar1 =  addToolBar(tr("&Delete item"));
    toolBar1->addAction(delete_item_act);
}

void MainWindow::open()
{
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Bookmark File"),
                                         QDir::currentPath(),
                                         tr("XBEL Files (*.xbel *.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("SAX Bookmarks"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    if (xbelTree->read(&file))
        statusBar()->showMessage(tr("File loaded"), 2000);
}
void MainWindow::add_function()
{
    dialog.set_xbeltree(xbelTree);
    dialog.show();

}

void MainWindow::add_item()
{
    xbelTree->add_item();
}

void MainWindow::delete_item()
{
    xbelTree->delete_item();
}

void MainWindow::saveAs()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Save Bookmark File"),
                                         QDir::currentPath(),
                                         tr("XBEL Files (*.xbel *.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("SAX Bookmarks"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    if (xbelTree->write(&file))
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Project"),
                      tr(" "));
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAsAct = new QAction(tr("&Save As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    add_function_act = new QAction(tr("Add &Function"), this);
    connect(add_function_act, SIGNAL(triggered()), this, SLOT(add_function()));

    add_item_act = new QAction(tr("Add &Item"), this);
    connect(add_item_act, SIGNAL(triggered()), this, SLOT(add_item()));

    delete_item_act = new QAction(tr("&Delete Item"), this);
    connect(delete_item_act, SIGNAL(triggered()), this, SLOT(delete_item()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(exitAct);

    menuBar()->addSeparator();

    edit_menu = menuBar()->addMenu(tr("&Edit"));
    edit_menu->addAction(add_function_act);
    edit_menu->addAction(add_item_act);
    edit_menu->addAction(delete_item_act);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}
