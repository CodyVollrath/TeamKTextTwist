#include "Settings.h"
namespace model
{

Settings::Settings()
{
    SettingsFileHandler handler;
    string values = handler.getFileContents(this->SETTINGS_FILE);
    this->timeInMinutes = stoi(values.substr(0,1));
    this->sortOption = stoi(values.substr(2,3));
    this->isResuable = stoi(values.substr(4,5));
}
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
    this->timeInMinutes = timeInMinutes;
}

void Settings::setSortOption(int scoreSortOption)
{
    this->sortOption = scoreSortOption;
}

void Settings::setReusableFlag(bool isReusable)
{
    this->isResuable = isReusable;
}

void Settings::saveSettings()
{
    string line = to_string(this->timeInMinutes) + "," + to_string(this->sortOption) + "," + to_string(this->isResuable);
    SettingsFileHandler handler;
    handler.saveToFile(this->SETTINGS_FILE, line);
}

}
