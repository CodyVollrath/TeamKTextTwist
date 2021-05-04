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
/**
* Keeps track of scores
* @author Furichous Jones
*/
class ScoreBoard
{
public:

    /**
    * Keeps track of the sort order
    */
    enum SORT_ORDER {SCORE, SCORE_AND_TIME};

    /**
    * Creates a Scoreboard object
    */
    ScoreBoard();

    /**
    * Destroys the ScoreBoard object
    */
    virtual ~ScoreBoard();

    /**
    * Inserts the score by the fields
    * @param name the name of the person that scored
    * @param score the score
    * @param duration the timer duration
    */
    void insert(string name, int score, Score::TIMER_DURATION duration);

    /**
    * Inserts the score by the actual score
    * @param newScore the new score to be added
    */
    void insert(Score* newScore);

    /**
    * Resets the scoreboard and empties it
    * @post empty() == true
    */
    void reset();

    /**
    * Changes the sort order
    * @param order the order of the scoreboard
    */
    void setOrder(SORT_ORDER order);

    /**
    * Gets the scores
    * @return scores
    */
    vector<Score*>* getScores();

    /**
    * Determines if the scoreboard is empty
    * @return true if scoreboard is empty, false otherwise
    */
    bool empty() const;

    /**
    * Loads the score board from the file
    */
    void loadScoreBoardFromFile();

    /**
    * Saves the scoreboard to filemilliseconds
    */
    void saveScoreBoardToFile();
private:
    vector<Score*>* scores;
    SORT_ORDER order;
    void sort();
    const string SCOREBOARD_FILE = "scoreboard.csv";

};
}


#endif // SCOREBOARD_H
