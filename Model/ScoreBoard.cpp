#include "ScoreBoard.h"
#include <iostream>
using namespace std;
namespace model
{
ScoreBoard::ScoreBoard()
{
    this->scores = new vector<Score*>();
    this->order = SORT_ORDER::SCORE;
}
ScoreBoard::~ScoreBoard()
{
    for (Score* score : *this->scores)
    {
        delete score;
    }
}
void ScoreBoard::insert(string name, int score, Score::TIMER_DURATION duration)
{
    Score* newScore = new Score(name, score, duration);
    this->scores->push_back(newScore);
    this->sort();
}

void ScoreBoard::insert(Score* newScore)
{
    this->scores->push_back(newScore);
    this->sort();
}

void ScoreBoard::reset()
{
    for (Score* score : *this->scores)
    {
        delete score;
    }
    this->scores->clear();
    this->saveScoreBoardToFile();
}

bool scoreCompare(Score* a, Score* b)
{
    int scoreCompare = a->getScore() - b->getScore();
    return scoreCompare > 0;
}

bool scoreAndTimeCompare(Score* a, Score* b)
{
    int timeCompare = a->getDuration() - b->getDuration();
    return (timeCompare == 0) ? scoreCompare(a, b) : timeCompare < 0;
}

void ScoreBoard::sort()
{
    bool (*comparator) (Score*,Score*) = 0;
    if (this->order == SORT_ORDER::SCORE)
    {
        comparator = &scoreCompare;
    }
    else
    {
        comparator = &scoreAndTimeCompare;
    }
    std::sort(this->scores->begin(), this->scores->end(), comparator);
}
void ScoreBoard::setOrder(SORT_ORDER order)
{
    this->order = order;
    this->sort();
}
vector<Score*>* ScoreBoard::getScores()
{
    return this->scores;
}
bool ScoreBoard::empty() const
{
    return this->scores->empty();
}
void ScoreBoard::loadScoreBoardFromFile()
{
    PersistenceFileHandler handler;
    string scoreboardData = handler.getFileContents(this->SCOREBOARD_FILE);
    int start = 0;
    string delimiter = "\n";
    int end = scoreboardData.find(delimiter);
    while (end != -1)
    {
        string scoreItem = scoreboardData.substr(start, end - start);
        vector<string> itemData = splitString(scoreItem, ",");
        string name = itemData.at(0);
        int score = stoi(itemData.at(1));
        int duration = stoi(itemData.at(2));
        this->insert(new Score(name, score, duration));
        start = end + delimiter.size();
        end = scoreboardData.find(delimiter, start);
    }

}
void ScoreBoard::saveScoreBoardToFile()
{
    PersistenceFileHandler handler;
    string data = "";
    for (Score* score : *this->scores)
    {
        data += score->getName() + "," +to_string(score->getScore()) + "," + to_string(score->getDuration()) + "\n";
    }
    handler.saveToFile(this->SCOREBOARD_FILE, data);
}
}
