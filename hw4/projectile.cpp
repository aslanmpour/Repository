/**@file projectile.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file is contains code for class projectile.
the main character can throw projectiles to capture
enemy birds (typename Enemy)
*/

#include "Projectile.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "GameBored.h"

extern GameBored* Board;

/* Costructor for projectiles
initializes timer for incremental movement of projectile
*/
Projectile::Projectile()
{
    //draw this
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/pics/Pokeball.gif"));

    //connect
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // FRAMERATE/FLuidity of MOVEMENT
    timer->start(25);
}

/*  moves the projectile from left to right
 * deleted if collides with bird Enemy
*/
void Projectile::move()
{
    //projectiles capture birds
    QList<QGraphicsItem*> c = collidingItems();
    for(int i = 0, n = c.size(); i<n; ++i){
        if (typeid(*(c[i]))== typeid(Enemy)){
            // add to score
            Board->score->increase();


            //remove from scene and delete colliding items
            scene()->removeItem(c[i]);
            scene()->removeItem(this);
            // projectile sound effect
            QMediaPlayer* caught = new QMediaPlayer();
            caught->setMedia(QUrl("qrc:/audio/catch.wav"));
            caught->play();

            delete c[i];
            delete this;
            return;
        }
    }

    //rotate
    setTransformOriginPoint(-10,-10);
    setRotation(rotation()+15);


    //to the right and up
    setPos(x()+5,y()-1);

    //if off the screen to the right delete and count as a miss
    if(pos().x() > 800){
        //add a miss to the score
        Board->score->miss();


        scene()->removeItem(this);
        delete this;
    }
}
