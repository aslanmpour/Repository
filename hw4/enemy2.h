#ifndef ENEMY2_H
#define ENEMY2_H


#include <QGraphicsPixmapItem>
#include <QObject>



/** @class Enemy2
@brief represents groud hedgehog enemies

hedgehogs move from right to left at ground-level
game over if they touch the main character

*/
class Enemy2: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Enemy2();
public slots:
    void move2();
    void endgame();
};



#endif // ENEMY2_H
