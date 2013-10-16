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
*     xbeltree.cpp
* 2.  DESCRIPTION
*    menu function implementation file
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

#include <QtGui>
#include <QDebug>
#include "xbeltree.h"

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: XbelTree
; DESCRIPTION: creat the label list in xml file
;    Input:
;    Output: none
;    Used global variables: folderIcon,bookmarkIcon
; REMARKS when using this function: none
;*********************************************************************/
XbelTree::XbelTree(QWidget *parent)
    : QTreeWidget(parent)
{
    QStringList labels;
    labels << tr("Number")<< tr("protocol1") << tr("protocol2");

    header()->setResizeMode(QHeaderView::Stretch);
    setHeaderLabels(labels);

    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),
                         QIcon::Normal, QIcon::Off);
    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
                         QIcon::Normal, QIcon::On);
    bookmarkIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: read
; DESCRIPTION: read the xml file
;    Input: xml file
;    Output: none
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
bool XbelTree::read(QIODevice *device)
{
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (!domDocument.setContent(device, true, &errorStr, &errorLine,
                                &errorColumn)) {
        QMessageBox::information(window(), tr("Function Store"),
                                 tr("Parse error at line %1, column %2:\n%3")
                                 .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr));
        return false;
    }

    QDomElement root = domDocument.documentElement();
    if (root.tagName() != "xbel") {
        QMessageBox::information(window(), tr("Function Store"),
                                 tr("The file is not an XBEL file."));
        return false;
    } else if (root.hasAttribute("version")
               && root.attribute("version") != "1.0") {
        QMessageBox::information(window(), tr("DOM Bookmarks"),
                                 tr("The file is not an XBEL version 1.0 "
                                    "file."));
        return false;
    }

    clear();

    disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
               this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    QDomElement child = root.firstChildElement("functions");
    while (!child.isNull()) {
        parseFolderElement(child);
        child = child.nextSiblingElement("functions");
    }

    connect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
            this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    return true;
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: write
; DESCRIPTION: write the changes to xml file and save the file
;    Input: device
;    Output: xml file
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
bool XbelTree::write(QIODevice *device)
{
    const int IndentSize = 4;

    QTextStream out(device);
    domDocument.save(out, IndentSize);
    return true;
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: add_function
; DESCRIPTION: add element to the xml file
;    Input: element name and number
;    Output: added elements in xml file
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
bool XbelTree::add_function(QString *function_name,int variables_number)
{
    int counter = 0;
    const char * variables_matrix[] = {"x1","x2","x3","x4","x5","x6","x7","x8","x9","x10","x11","x12","x13","x2","x3","x4","x5","x6","x7","x8","x9","x10","x11","x12","x13","x2","x3","x4","x5","x6","x7","x8","x9","x10","x11","x12","x13","x2","x3","x4","x5","x6","x7","x8","x9","x10","x11","x12","x13","x2","x3","x4","x5","x6","x7","x8","x9","x10","x11","x12","x13","x2","x3","x4","x5","x6","x7","x8","x9","x10","x11","x12","x13"};
    clear();
    disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
               this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    QDomElement root = domDocument.documentElement();
    QDomElement new_function = domDocument.createElement( "function" );
    new_function.setAttribute("name",*function_name);
    for(counter = 0; counter <variables_number; counter++)
    {
        QDomElement new_node = domDocument.createElement(variables_matrix[counter]);
        new_node.appendChild(domDocument.createElement(tr("protocol1")));
        new_node.appendChild(domDocument.createElement(tr("protocol2")));
        new_function.appendChild(new_node);
    }


    root.firstChildElement().appendChild(new_function);
    QDomElement child = root.firstChildElement("functions");
    while (!child.isNull()) {
        parseFolderElement(child);
        child = child.nextSiblingElement("functions");
    }

    connect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
            this, SLOT(updateDomElement(QTreeWidgetItem*,int)));


    return true;
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: add_item
; DESCRIPTION: add elements under the function element in XML file
;    Input: elements need to be added
;    Output: added elements in xml file
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
bool XbelTree::add_item()
{
    int counter = 0;
    const char * variables_matrix[] = {"x1","x2","x3","x4","x5","x6","x7","x8","x9","x10"};
    clear();
    disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
               this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    QDomElement root = domDocument.documentElement();

        QDomElement new_node = domDocument.createElement(variables_matrix[0]);
       // QDomElement new_node = domDocument.createElement(variables_matrix[counter+1]);
        new_node.appendChild(domDocument.createElement(tr("protocol1")));
        new_node.appendChild(domDocument.createElement(tr("protocol2")));
     //   function.appendChild(new_node);


    root.firstChildElement().firstChildElement().appendChild(new_node);
#if 1
    QDomElement child = root.firstChildElement("functions");
    while (!child.isNull()) {
        parseFolderElement(child);
        child = child.nextSiblingElement("functions");
    }
#endif
    connect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
            this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    return true;

}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: delete_item
; DESCRIPTION: delete the last element under the function element in XML file
;    Input: none
;    Output: none
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
bool XbelTree::delete_item()
{
    clear();
    disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
               this, SLOT(updateDomElement(QTreeWidgetItem*,int)));

    QDomElement root = domDocument.documentElement();
    root.firstChildElement().firstChildElement().removeChild(root.firstChildElement().firstChildElement().lastChildElement());

#if 1
    QDomElement child = root.firstChildElement("functions");
    while (!child.isNull()) {
        parseFolderElement(child);
        child = child.nextSiblingElement("functions");
    }
#endif

    connect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
            this, SLOT(updateDomElement(QTreeWidgetItem*,int)));
}


/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: getCorAddr
; DESCRIPTION: get column  values of the xml file under the function element
;    Input: function value,column,item value
;    Output: the other item value
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
//item: specific format
//item1: specific format
void XbelTree::getCorAddr(QString fun_name,int column,QString item,QString *item1)
{
    QFile file ("project.xbel");
    file.open(QIODevice::ReadOnly);
    QDomDocument document;
    document.setContent(&file);

    QDomElement root = document.documentElement();
    qDebug()<<item;
#if 1
    if(column == 1){

        item=item.right(2)+item.left(2);
        bool b;
        item=QString::number(item.toInt(&b,16),10);
qDebug()<<"ALO "<<item;

        QDomNodeList nodelist = root.elementsByTagName("function");
        for(int i=0; i<nodelist.count(); i++){
            QDomNode node = nodelist.item(i);
            QDomElement element = node.toElement();//function
            QString attribute = element.attribute("name");
            if(attribute == fun_name)
            {
                QDomNodeList nodelist1 = element.childNodes();
                for(int j=0; j<nodelist1.count();j++){
                    QDomNode node1 = nodelist1.item(j);
                    QDomElement element1 = node1.toElement();

                    if(element1.firstChildElement().firstChild().nodeValue() == item)
                    {
                        *item1 = element1.lastChildElement().firstChild().nodeValue();
                        //to the corresponding format 0000
                        bool b;
                         (*item1)=QString::number( (*item1).toInt(&b,10)-1,16);
                        while( (*item1).length()<4)
                        {
                            (*item1).prepend("0");
                        }
                         (*item1)=(*item1).toUpper();
                         if((*item1).isEmpty())
                             (*item1)="0000";
                    }
                }
            }
        }
    }
#endif
#if 1
    if(column == 2){

        bool b;
        item=QString::number(item.right(4).toInt(&b,16)+1,10);

        QDomNodeList nodelist = root.elementsByTagName("function");
        for(int i=0; i<nodelist.count(); i++){
            QDomNode node = nodelist.item(i);
            QDomElement element = node.toElement();
            QString attribute = element.attribute("name");
            if(attribute == fun_name)
            {
                QDomNodeList nodelist1 = element.childNodes();
                for(int j=0; j<nodelist1.count();j++){
                    QDomNode node1 = nodelist1.item(j);
                    QDomElement element1 = node1.toElement();

                    if(element1.lastChildElement().firstChild().nodeValue() == item)
                    {
                        *item1 = element1.firstChildElement().firstChild().nodeValue();

                        //to the corresponding format 00 00(dao)
                        bool b;
                        *item1=QString::number((*item1).toInt(&b,10),16);

                        while((*item1).length()<4)
                        {
                            (*item1).prepend("0");
                        }
                        *item1=(*item1).right(2)+(*item1).left(2);
                         (*item1)=(*item1).toUpper();
                         if((*item1).isEmpty())
                             (*item1)="0000";

                    }
                }
            }
        }
    }
#endif
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: updateDomElement
; DESCRIPTION: update the Dom Element
;    Input: changed item value and its column
;    Output: updated Dom Elements
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
void XbelTree::updateDomElement(QTreeWidgetItem *item, int column)
{
    QDomElement element = domElementForItem.value(item);
    if (!element.isNull()) {
        if (column == 0) {
            if (element.tagName() == "function")
                element.setAttribute("name", item->text(0));
            if (element.tagName() == "x1")
                element.setTagName(item->text(0));
            if (element.tagName() == "x2")
                element.setTagName(item->text(0));
            if (element.tagName() == "x3")
                element.setTagName(item->text(0));

        }
        else if (column == 1)
        {
            QDomElement oldTitleElement = element.firstChildElement("protocol1");
            QDomElement newTitleElement = domDocument.createElement("protocol1");
            QDomText newTitleText = domDocument.createTextNode(item->text(1));
            newTitleElement.appendChild(newTitleText);
            element.replaceChild(newTitleElement, oldTitleElement);

        }
        else
        {
            QDomElement oldTitleElement = element.firstChildElement("protocol2");
            QDomElement newTitleElement = domDocument.createElement("protocol2");
            QDomText newTitleText = domDocument.createTextNode(item->text(2));
            newTitleElement.appendChild(newTitleText);
            element.replaceChild(newTitleElement, oldTitleElement);
        }
    }
}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: parseFolderElement
; DESCRIPTION: parse the folder Element,if the element is folded, parse it
;    Input: none
;    Output: none
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
void XbelTree::parseFolderElement(const QDomElement &element,
                                  QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item = createItem(element, parentItem);

    QString title = element.attribute("name");
    if (title.isEmpty())
        title = QObject::tr("functions");

    item->setFlags(item->flags() | Qt::ItemIsEditable);
    item->setIcon(0, folderIcon);
    item->setText(0, title);

    QDomElement child = element.firstChildElement();
    while (!child.isNull())
    {

        QTreeWidgetItem *childItem = createItem(child, item);

        //QString title = child.firstChildElement("title").text();
        QString function_name = child.attribute("name");
        if (function_name.isEmpty())
            function_name = QObject::tr("function");

        childItem->setFlags(childItem->flags() | Qt::ItemIsEditable);
        childItem->setIcon(0, folderIcon);
        childItem->setText(0, function_name);
        QDomElement function_variables = child.firstChildElement();
        while (!function_variables.isNull())
        {
            QTreeWidgetItem *variables_item = createItem(function_variables, childItem);

#if 1
            QString variable_name = function_variables.tagName();
            if (variable_name.isEmpty())
                title = QObject::tr("some variable");

            variables_item->setFlags(variables_item->flags() | Qt::ItemIsEditable);
            variables_item->setIcon(0, bookmarkIcon);
            variables_item->setText(0, variable_name);
            variables_item->setText(1,function_variables.firstChildElement().text());
            variables_item->setText(2,function_variables.firstChildElement().nextSiblingElement().text());


            bool folded = (function_variables.attribute("folded") != "no");
            setItemExpanded(variables_item, !folded);
#endif
            function_variables = function_variables.nextSiblingElement();
        }

        child = child.nextSiblingElement();
    }

}

/*********************************************************************
;    F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: createItem
; DESCRIPTION: creat the child element
;    Input: parent item
;    Output: child items
;    Used global variables: none
; REMARKS when using this function: none
;*********************************************************************/
QTreeWidgetItem *XbelTree::createItem(const QDomElement &element,
                                      QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item;
    if (parentItem) {
        item = new QTreeWidgetItem(parentItem);
    } else {
        item = new QTreeWidgetItem(this);
    }
    domElementForItem.insert(item, element);
    return item;
}
