#include "Settings.h"
namespace model
{

Settings::Settings()
{
    SettingsFileHandler handler;
    string values = handler.getFileContents(this->SETTINGS_FILE);
    this->duration = Score::TIMER_DURATION(stoi(values.substr(0,1)));
    this->sortOption = stoi(values.substr(2,3)) ? ScoreBoard::SORT_ORDER::SCORE_AND_TIME : ScoreBoard::SORT_ORDER::SCORE;
    this->isResuable = stoi(values.substr(4,5));
}
Settings::Settings(Score::TIMER_DURATION duration, ScoreBoard::SORT_ORDER scoreSortOption, bool isResuable)
{
    this->duration = duration;
    this->sortOption = scoreSortOption;
    this->isResuable = isResuable;

}

Settings::~Settings()
{
    //dtor
}

Score::TIMER_DURATION Settings::getDuration() const
{
    return this->duration;
}

ScoreBoard::SORT_ORDER Settings::getSortOption() const
{
    return this->sortOption;
}

bool Settings::getReusableFlag() const
{
    return this->isResuable;
}

void Settings::setDuration(Score::TIMER_DURATION timeInMinutes)
{
    this->duration = duration;
}

void Settings::setSortOption(ScoreBoard::SORT_ORDER scoreSortOption)
{
    this->sortOption = scoreSortOption;
}

void Settings::setReusableFlag(bool isReusable)
{
    this->isResuable = isReusable;
}

void Settings::saveSettings()
{
    string line = to_string(this->duration) + "," + to_string(this->sortOption) + "," + to_string(this->isResuable);
    SettingsFileHandler handler;
    handler.saveToFile(this->SETTINGS_FILE, line);
}

}
