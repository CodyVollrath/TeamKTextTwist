#include "ScoreBoard.h"

namespace model
{
        ScoreBoard::ScoreBoard(){
            this->scores = new vector<Score*>();
            this->order = SORT_ORDER::SCORE;
        }
        ScoreBoard::~ScoreBoard(){
            for (Score* score : *this->scores)
            {
                delete score;
            }
        }
        void ScoreBoard::insert(string name, int score, Score::TIMER_DURATION duration){
            Score* newScore = new Score(name, score, duration);
            this->scores->push_back(newScore);
            this->sort();
        }

        void ScoreBoard::insert(Score* newScore){
            this->scores->push_back(newScore);
            this->sort();
        }

        void ScoreBoard::reset(){
            for (Score* score : *this->scores)
            {
                delete score;
            }
            this->scores->clear();
        }

        bool scoreCompare(Score* a, Score* b) {
            int scoreCompare = a->getScore() - b->getScore();
            return scoreCompare > 0;
        }

        bool scoreAndTimeCompare(Score* a, Score* b) {
            int timeCompare = a->getDuration() - b->getDuration();
            return (timeCompare == 0) ? scoreCompare(a, b) : timeCompare < 0;
        }

        void ScoreBoard::sort(){
            bool (*comparator) (Score*,Score*) = 0;
            if (this->order == SORT_ORDER::SCORE) {
                comparator = &scoreCompare;
            } else {
                comparator = &scoreAndTimeCompare;
            }
            std::sort(this->scores->begin(), this->scores->end(), comparator);
        }
        void ScoreBoard::setOrder(SORT_ORDER order){
            this->order = order;
            this->sort();
        }
        vector<Score*>* ScoreBoard::getScores(){
            return this->scores;
        }
}
