#ifndef TEXT_TWIST_CONTROLLER_H
#define TEXT_TWIST_CONTROLLER_H

#include <string>
using namespace std;

#include "TextTwister.h"
#include "Timer.h"
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
    void twist();
    string* getLetters();
    string submit(string* letters);
    int getScore();
    void reset();

    void setDuration(int duration);
    void bindTimer(void(*callback)(void*,chrono::milliseconds,bool), void* caller);

private:
    TextTwister* twister;
    Timer* timer;

};

}


#endif // TEXT_TWIST_CONTROLLER_H
