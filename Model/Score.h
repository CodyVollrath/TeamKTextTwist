#ifndef SCORE_H
#define SCORE_H

#include <string>
using namespace std;

namespace model
{
class Score
{
public:
    enum TIMER_DURATION {ONE_MINUTE=60000, TWO_MINUTES=120000, THREE_MINUTES=180000};
    Score(string name, int score, int duration);
    Score(string name, int score, TIMER_DURATION duration);
    Score(int score, TIMER_DURATION duration);
    virtual ~Score();
    string& getName();
    void setName(string name);
    int getScore();
    TIMER_DURATION getDuration();
    static int durationToMilliseconds(TIMER_DURATION duration);
private:
    string name;
    int score;
    TIMER_DURATION duration;


};
}


#endif // SCORE_H
