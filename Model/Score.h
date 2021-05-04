
#ifndef SCORE_H
#define SCORE_H

#include <string>
using namespace std;

namespace model
{
class Score
{
    public:
        enum TIMER_DURATION {ONE_MINUTE, TWO_MINUTES, THREE_MINUTES};
        Score(string name, int score, int duration);
        Score(string name, int score, TIMER_DURATION duration);
        Score(int score, TIMER_DURATION duration);
        virtual ~Score();
        string& getName();
        void setName(string name);
        int getScore();
        TIMER_DURATION getDuration();

    private:
        string name;
        int score;
        TIMER_DURATION duration;


};
}


#endif // SCORE_H
