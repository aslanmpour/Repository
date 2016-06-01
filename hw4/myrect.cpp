/**@file myrect.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file contains code involving the main character
(class MyRect).
*/

#include "MyRect.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QGraphicsScene>
#include <Enemy2.h>
#include <Enemy.h>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QMediaPlayer>
#include <QApplication>
#include <QProcess>

/* cosntructs MyRect
*/
MyRect::MyRect()
{    
    //draw the player
    setPixmap(QPixmap(":/pics/boo.png"));

    //enable gravity
    gravitytimer = new QTimer(this);
    connect(gravitytimer,SIGNAL(timeout()),this,SLOT(fall()));
    gravitytimer->start(15);

    //initialize sound effects
    throwsound = new QMediaPlayer();
    throwsound->setMedia(QUrl("qrc:/audio/throw2.wav"));

    jumpsound = new QMediaPlayer();
    jumpsound->setMedia(QUrl("qrc:/audio/jump.wav"));

    fallsound = new QMediaPlayer();
    fallsound->setMedia(QUrl("qrc:/audio/falling.wav"));

}

/** repsonds when a key is pressed
 * @param QKeyEvent is the key event detected
 */
void MyRect::keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Left)
    {
        if(pos().x()>0){
        setPos(x()-9,y()-1);}


    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x()+ 100 < 800){
        setPos(x()+11,y()-2);

        setTransformOriginPoint(15,15);
        setRotation(rotation()-4);
        }

    }
    else if(event->key() == Qt::Key_Up)
    {
        //if not already in the air
        if(y()>=410){
            //disconnect gravitytimer from falling(gravity off)
            disconnect(gravitytimer,SIGNAL(timeout()),this,SLOT(fall()));
            //reconnect gravitytimer to jumping
            connect(gravitytimer,SIGNAL(timeout()),this,SLOT(jump()));


            //connect longpulse to member function (gravityon) that will later
            //disconnect gravitytimer from jumping and reconnect falling
            longpulses= new QTimer(this);
            connect(longpulses,SIGNAL(timeout()),this,SLOT(gravityon()));
            longpulses->start(300);


            // jump sound effect
            // restart if already playing
            if(jumpsound->state()== QMediaPlayer::PlayingState){
                jumpsound->setPosition(0);
            }
            // play if not playing
            else if (jumpsound->state()==QMediaPlayer::StoppedState){
                jumpsound->play();
            }

        }

    }
    else if(event->key() == Qt::Key_Down)
    {
        //if not already in the air
        if(y()>=410){
            //teleport into the sky
            setPos(x(), -28 /*view->height()- player->pixmap().height()*/);

            // falling sound effect
            // restart if already playing
            if(fallsound->state()== QMediaPlayer::PlayingState){
                fallsound->setPosition(0);
            }
            // play if not playing
            else if (fallsound->state()==QMediaPlayer::StoppedState){
                fallsound->play();
            }
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        // make projectile
        Projectile* p = new Projectile();
        p->setPos(x(),y());
        scene()->addItem(p);

        // projectile sound effect
        // restart if already playing
        if(throwsound->state()== QMediaPlayer::PlayingState){
            throwsound->setPosition(0);
        }
        // play if not playing
        else if (throwsound->state()==QMediaPlayer::StoppedState){
            throwsound->play();
        }



    }
    else if(event->key() == Qt::Key_Escape){
        this->quit();;

    }
}

/* spawns class type Enemy
*/
void MyRect::spawn()
{
        //add enemy to scene
        Enemy* e = new Enemy();
        scene()->addItem(e);
}

/* spawns class type Enemy2
*/
void MyRect::spawn2()
{
        //add enemy2 to scene
        Enemy2* e2 = new Enemy2();
        scene()->addItem(e2);
}

//disregard
void MyRect::stopplayertimer()
{
    //stop jumping after 250ms
    //playertimer->stop();
    //jumptimer->stop();
}

/* causes main character to fall periodically
 * using the fall() method
*/
void MyRect::gravityon()
{
    //disconnect gravitytimer from jumping and reconnect falling
    disconnect(gravitytimer,SIGNAL(timeout()),this,SLOT(jump()));
    connect(gravitytimer,SIGNAL(timeout()),this,SLOT(fall()));

    //disconnect long pulse and stop it
    longpulses->stop();
    disconnect(longpulses,SIGNAL(timeout()),this,SLOT(gravityon()));

}

/* restarts qt application
*/
void MyRect::quit()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
}

/* moves main character upwards to represent
 * a jumping motion and turns off gravity to
 * do this successfully
*/
void MyRect::jump(){
        setPos(x(),y()-9);
        setTransformOriginPoint(15,15);
        setRotation(rotation()-4);
}

/* moves main character down to represent falling
stops the falling motion when you reach ground level
*/
void MyRect::fall(){
    if(y()<410){
        setPos(x(),y()+5);
        setTransformOriginPoint(15,15);//do a backflip
        setRotation(rotation()-8);

    }
    //stand up straight
    else if(rotation()<0){

        setTransformOriginPoint(15,15);
        setRotation(0);
    }

}
