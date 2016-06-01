/**@file enemy.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file is contains code regarding flying bird
enemies (typename Enemy). They are harmless towards the main character
and can be captured using (typename Projectile)
*/

#include "Enemy.h"
#include "MyRect.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "stdlib.h"
#include <QDebug>

/*Constructs Enemy
*/
Enemy::Enemy()
{
    //random position
    int r = rand()%300 +100;
    setPos(800+pixmap().width(),r);

    //draw this
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/pics/latias"));

    //connect
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // FRAMERATE/FLuidity of MOVEMENT
    timer->start(20);
}

/* moves enemies from right to left
*/
void Enemy::move()
{
    // up, left
    setPos(x()-2,y()+rand()%2-1);

    //delete if off screen
    if(pos().x()  < 0- pixmap().height()){
        scene()->removeItem(this);
        delete this;
        //qDebug()<< "enemy deleted";
        return;
    }

    //if an enemy touches you, it moves away
    QList<QGraphicsItem*> c = collidingItems();
    for(int i = 0, n = c.size(); i<n; ++i){
        if (typeid(*(c[i]))== typeid(MyRect)){
            //myrect moves
            this->setPos(x()-10,y()-5);
            setTransformOriginPoint(50,50);
            setRotation(rotation()+ rand()%12-6);

            //return;
        }
        else if(typeid(*(c[i]))== typeid(Enemy)){
            this->setPos(x(),y()+9);
            //setTransformOriginPoint(50,50);
            //setRotation(rotation()-5);

        }
    }



}
