#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "ResourceData.h"

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "PersistenceFileHandler.h"
using namespace fileio;

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
    bool empty() const;
    void loadScoreBoardFromFile();
    void saveScoreBoardToFile();
private:
    vector<Score*>* scores;
    SORT_ORDER order;
    void sort();
    const string SCOREBOARD_FILE = "scoreboard.csv";

};
}


#endif // SCOREBOARD_H
