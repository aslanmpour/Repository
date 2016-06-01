/**@file enemy2.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file is contains code regarding rolling hedgehog
enemies (typename Enemy2). The game is over if this
enemy touches the main character.
*/

#include "Enemy2.h"
#include "MyRect.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "stdlib.h"
#include <QDebug>

#include <QApplication>
#include <QProcess>

#include <conio.h>
#include <windows.h>
#include <gamebored.h>

extern GameBored* Board;

/* Constructs Enemy2
*/
Enemy2::Enemy2()
{
    //spawn at ground level
    setPos(800+pixmap().width(),410);

    //draw this
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/pics/sonic.gif"));

    //connect
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move2()));

    // FRAMERATE/FLuidity of MOVEMENT
    timer->start(20);

    // hedghog sound effect
    QMediaPlayer* sanik = new QMediaPlayer();
    sanik->setMedia(QUrl("qrc:/audio/speed.wav"));
    sanik->play();

}

/*moves Enemy2 from right to left
*/
void Enemy2::move2()
{
    // left
    setPos(x()-20,y());
    setTransformOriginPoint(50,50);
    setRotation(rotation()-30);

    //delete if moves off screen
    if(pos().x()  < 0- pixmap().height()){
        scene()->removeItem(this);
        delete this;
        //qDebug()<< "enemy2 deleted";
        return;
    }

    //if an enemy2 touches you, game over
    QList<QGraphicsItem*> c = collidingItems();
    for(int i = 0, n = c.size(); i<n; ++i){
        if (typeid(*(c[i]))== typeid(MyRect)){
            //game over screen created

            QGraphicsPixmapItem* gameover= new QGraphicsPixmapItem;
            gameover->setPixmap(QPixmap(":/pics/gameover.jpg"));
            gameover->setPos(0,0);
            scene()->addItem(gameover);
            gameover->setZValue(10000);

            //if mp3player has already been stopped, theres no need to play gameover music
            if(Board->mp3player->state()== QMediaPlayer::PlayingState){
                QMediaPlayer* gameover = new QMediaPlayer();
                gameover->setMedia(QUrl("qrc:/audio/metalgear.mp3"));
                gameover->play();
            }

            Board->mp3player->stop();



            //game will quit after a short pause
            //QTimer* timer = new QTimer(this);
            //connect(timer,SIGNAL(timeout()),this,SLOT(endgame()));
            //timer->start(4000);


            //return;
        }

    }



}

/* restarts program
*/
void Enemy2::endgame()
{

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
}
