/**@file score.cpp
@author Aslan Mohammad pour
@date 5/30/15

this file is contains code for class Score. This
class keeps a tally of how many bird enemies (typename Enemy)
are captured and how many times the (typename Projectile)
fails to capture an enemy and is wawsted.
*/

#include "Score.h"
#include <QFont>

/* constructs scoreboard
 * @param QGraphicsItem is its parent item
*/
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //set score to 0 and add the text to the scene
    score = 0;
    misses = 0;
    setPlainText(QString("Birds Caught: ") + QString::number(score) + QString("\nPokeballs Wasted: ") + QString::number(misses));

    // set font and color
    setDefaultTextColor(Qt::black);
    setFont(QFont("AR JULIAN",14));
    setPos(0,490);
}

/* increases score when bird enemy is caught
*/
void Score::increase(){
    ++score;
    setPlainText(QString("Birds Caught: ") + QString::number(score) + QString("\nPokeballs Wasted: ") + QString::number(misses));

}

/* increases miss tally
*/
void Score::miss(){
    ++misses;
    setPlainText(QString("Birds Caught: ") + QString::number(score) + QString("\nPokeballs Wasted: ") + QString::number(misses));

}

/* Accessor of int score
@return int is the score
*/
int Score::getScore(){
    return score;
}
