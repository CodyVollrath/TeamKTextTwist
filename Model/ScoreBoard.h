
#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "Score.h"

namespace model
{
class ScoreBoard
{
    public:
        enum SORT_ORDER {SCORE, SCORE_AND_TIME};

        ScoreBoard();
        virtual ~ScoreBoard();
        void insert(string name, int score, Score::TIMER_DURATION duration);
        void insert(Score* newScore);
        void reset();
        void setOrder(SORT_ORDER order);
        vector<Score*>* getScores();
    private:
        vector<Score*>* scores;
        SORT_ORDER order;
        void sort();

};
}


#endif // SCOREBOARD_H
