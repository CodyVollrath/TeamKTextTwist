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
    void reset();

    void setDuration(int duration);
    void bindTimer(void(*callback)(void*,chrono::milliseconds,bool), void* caller);
    void changeSettings(Settings* settings);
    char* getTime() const;
    char* getTime(chrono::milliseconds remainingTime) const;

private:
    TextTwister* twister;
    Timer* timer;
    Settings* settings;
    void applySettings();

};

}


#endif // TEXT_TWIST_CONTROLLER_H
