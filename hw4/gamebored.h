#ifndef GAMEBORED_H
#define GAMEBORED_H

#include <QWidget>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QObject>
#include "Score.h"

namespace Ui {
class GameBored;
}



/** @class GameBored
@brief represents the gameboard

GameBoard initializes all objects involved in the
game.

*/
class GameBored : public QWidget{
    Q_OBJECT

public:
    explicit GameBored(QWidget *parent = 0);
    ~GameBored();
    Score* score;

    QMediaPlayer *mp3player;
private:
    Ui::GameBored *ui;


    QWidget *Board;
};

#endif // GAMEBORED_H
