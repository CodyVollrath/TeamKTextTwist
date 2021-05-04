#ifndef TEXT_TWIST_CONTROLLER_H
#define TEXT_TWIST_CONTROLLER_H

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
using namespace std;

#include "TextTwister.h"
#include "Timer.h"
#include "Settings.h"
#include "ScoreBoard.h"
using namespace model;


namespace controller
{

class TextTwistController
{

public:
    TextTwistController();
    virtual ~TextTwistController();
    void startGame();
    void pauseGame();
    void resumeGame();
    void twist();
    string* getLetters();
    set<string>* getUsedWords();
    string submit(string* letters);
    int getScore();

    void setDuration(Score::TIMER_DURATION duration);
    void bindTimer(void(*callback)(Timer*, void*), void* data);
    void applySettings();
    char* getTime() const;
    char* formatTime(int milliseconds) const;
    Settings* getSettings();
    ScoreBoard* getScoreBoard();
    Score::TIMER_DURATION getDuration();
    void addScore(string name);

private:
    TextTwister* twister;
    Timer* timer;
    Settings* settings;
    ScoreBoard* scoreboard;


};

}


#endif // TEXT_TWIST_CONTROLLER_H
