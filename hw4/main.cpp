/**@file main.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file contains int main, ui is initially set to
mainwindow.ui
*/

#include "mainwindow.h"
#include <QApplication>

GameBored* Board; //global GameBoard item

//initializes main menu
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
