/**@file gamebored.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file is reposnsible for all the code that holds
the game's many components eg. graphics and audio.
*/

#include "gamebored.h"
#include "mainwindow.h"
#include "ui_gamebored.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>
#include <Enemy.h>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>

/* GameBored contstructor
 * @param QWidget is the parent widget
*/
GameBored::GameBored(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBored)
{
    ui->setupUi(this);

    // make scene
    QGraphicsScene * scene= new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/pics/bg")));


    // make and add item to scene
    MyRect * player = new MyRect();
    scene->addItem(player);

    // focus item so that it can receive keyboard events
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    // add scene to new view
    QGraphicsView * view = new QGraphicsView(scene);

    //turn off scrollbars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    Board= new QWidget;
    //Board->setFixedSize(400,400);

    // add view to new layout
    // add layout to central widget
    QVBoxLayout * vlayout = new QVBoxLayout(Board);
    vlayout->addWidget(view);
    this->setLayout(vlayout);

    //
    this->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2 -player->pixmap().width()/2, -28 /*view->height()- player->pixmap().height()*/);

    // constant creation of enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2400);

    QTimer* timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn2()));
    timer2->start(5000);


    // play music
    mp3player = new QMediaPlayer();
    mp3player->setMedia(QUrl("qrc:/audio/starfox.mp3"));
    mp3player->play();

    // add score class to screen
    score = new Score();
    scene->addItem(score);
}



//destructor
GameBored::~GameBored()
{
    delete ui;
}


