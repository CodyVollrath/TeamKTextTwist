#include "Score.h"
namespace model {

        Score::Score(string name, int score, int duration)
        {
            this->name = name;
            this->score = score;
            this->duration = TIMER_DURATION(duration);
        }

        Score::Score(int score, TIMER_DURATION duration){
            this->name = "unknown";
            this->score = score;
            this->duration = duration;
        }

        Score::Score(string name, int score, TIMER_DURATION duration){
            this->name = name;
            this->score = score;
            this->duration = duration;
        }

        Score::~Score(){
        }
        string& Score::getName(){
            return this->name;
        }
        void Score::setName(string name){
            this->name = name;
        }
        int Score::getScore(){
            return this->score;
        }
        Score::TIMER_DURATION Score::getDuration(){
            return this->duration;
        }
}
