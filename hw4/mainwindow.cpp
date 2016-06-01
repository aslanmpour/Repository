/**@file MainWindow.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file contains code for the class MainWindow.
MainWindow has a function that switches from main menu
to the game (class GameBored)
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamebored.h"
#include <QMediaPlayer>

extern GameBored* Board;

/* MainWindow constructor
 * @param QWidget s the parent widget
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // play music
    menusong= new QMediaPlayer();
    menusong->setMedia(QUrl("qrc:/audio/halotheme.mp3"));
    menusong->play();
}

/* sets ui to global GameBored* Board
*/
void MainWindow::easy_game_begin() {
    menusong->stop();
    Board = new GameBored(this);
    this->setCentralWidget(Board);
}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
}



