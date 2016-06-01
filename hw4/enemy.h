#ifndef ENEMY_H
#define ENEMY_H



#include <QGraphicsPixmapItem>
#include <QObject>


/** @class Enemy
@brief represents flying bird enemies

enemies move from the right to the left side
of the screen

*/
class Enemy: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};



#endif // ENEMY_H
