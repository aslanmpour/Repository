#ifndef PROJECTILE_H
#define PROJECTILE_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>



/** @class Projectile
@brief represents thrown capturing devices

These are thrown by the main character to capture
bird enemies (class Enemy)

*/
class Projectile: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Projectile();
public slots:
    void move();

};

#endif // PROJECTILE_H
