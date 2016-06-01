#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>



/** @class Score
@brief represents score board

keeps track of how many bird enemies are captured
as well as how many projectiles failed to capture
enemies

*/
class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem* parent=0);
    void increase();
    void miss();
    int getScore();
private:
    int score;
    int misses;
};

#endif // SCORE_H
