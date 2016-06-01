#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>



/** @class MyRect
@brief represents the main character (the player)

The character contains functions and objects that
allow movement gravity, spawning of enemies, and audio

*/
class MyRect: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyRect();
    void keyPressEvent(QKeyEvent* event);
public slots:
    void jump();
    void fall();
    void spawn();
    void spawn2();
    void stopplayertimer();
    void gravityon();
    void quit();
private:
    QTimer* quickpulses;
    QTimer* longpulses;
    QTimer* gravitytimer;
    QMediaPlayer* throwsound;
    QMediaPlayer* jumpsound;
    QMediaPlayer* fallsound;
};

#endif // MYRECT_H
