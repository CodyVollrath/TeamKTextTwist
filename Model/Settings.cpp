#include "Settings.h"

namespace model
{
Settings::Settings(int timeInMinutes, int scoreSortOption, bool isResuable)
{
    this->timeInMinutes = timeInMinutes;
    this->sortOption = scoreSortOption;
    this->isResuable = isResuable;

}

Settings::~Settings()
{
    //dtor
}

int Settings::getTimeInMinutes() const
{
    return this->timeInMinutes;
}

int Settings::getSortOption() const
{
    return this->sortOption;
}

bool Settings::getReusableFlag() const
{
    return this->isResuable;
}

void Settings::setTimeInMinutes(int timeInMinutes)
{
    this->timeInMinutes;
}

void Settings::setSortOption(int scoreSortOption)
{
    this->sortOption = scoreSortOption;
}

void Settings::setReusableFlag(bool isReusable)
{
    this->isResuable = isReusable;
}
}
