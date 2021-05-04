#ifndef SCORE_H
#define SCORE_H

#include <string>
using namespace std;

namespace model
{
/**
* This class keeps track of a score for an individual player
* @author Furichous Jones
*/
class Score
{
    public:
        /**
        * TIMER_DURATION indicates the times available for the score to be evaluated
        */
        enum TIMER_DURATION {ONE_MINUTE=60000, TWO_MINUTES=120000, THREE_MINUTES=180000};

        /**
        * Creates a Score object
        * @param name the name of the person that made the score
        * @param score the score the person had
        * @param duration the duration as an int which corresponds to the TIMER_DURATION
        * @pre none
        * @post getName() == name && getScore() == score && getDuration() == TIMER_DURATION(duration)
        */
        Score(string name, int score, int duration);


        /**
        * Creates a Score object
        * @param name the name of the person that made the score
        * @param score the score the person had
        * @param duration the duration as an actual TIMER_DURATION enum
        * @pre none
        * @post getName() == name && getScore() == score && getDuration() == duration
        */
        Score(string name, int score, TIMER_DURATION duration);


        /**
        * Creates a Score object
        * @param score the score the person had
        * @param duration the duration as an int which corresponds to the TIMER_DURATION
        * @pre none
        * @post getName() == "Unknown" && getScore() == score && getDuration() == TIMER_DURATION(duration)
        */
        Score(int score, TIMER_DURATION duration);

        /**
        * Destroys the Score object
        */
        virtual ~Score();

        /**
        * Gets the name of the person that made the score
        * @return the name of the person that made the score
        */
        string& getName();

        /**
        * Sets the name of the person that made the score
        * @pre none
        * @post getName() == name;
        */
        void setName(string name);

        /**
        * Gets the score
        * @return the score
        */
        int getScore();

        /**
        * Gets the duration
        * @return the duration
        */
        TIMER_DURATION getDuration();

        /**
        * Gets the duration as milliseconds
        * @param duration the duration as TIMER_DURATION
        * @return the duration as milliseconds
        */
        static int durationToMilliseconds(TIMER_DURATION duration);
    private:
        string name;
        int score;
        TIMER_DURATION duration;
};
}


#endif // SCORE_H
