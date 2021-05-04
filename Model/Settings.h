#ifndef SETTINGS_H
#define SETTINGS_H
#include "ResourceData.h"

#include <string>
using namespace std;

#include "PersistenceFileHandler.h"
using namespace fileio;

#include "ScoreBoard.h"

namespace model
{

/**
* Keeps track of the user settings
* @author Cody Vollrath
*/
class Settings
{
public:

    /**
    * Constructs settings object: Empty Constructor loads from a file
    * @pre the file it is loading from must exist and be validly formatted as a csv
    * @post getDuration() == item1 && getSortOption == item2 && getReusableFlag == item3
    */
    Settings();

    /**
    * Constructs a settings object: Allows for manual set
    * @param duration the timer duration
    * @param scoreSortOption the sort order
    * @param isReusable the flag that indicates if words are allowed to be reused
    * @post getDuration() == duration && getSortOption == scoreSortOption && getReusableFlag() == isReusable
    */
    Settings(Score::TIMER_DURATION duration, ScoreBoard::SORT_ORDER scoreSortOption, bool isResuable);

    /**
    * Destroys the settings
    */
    virtual ~Settings();
    /**
    * Gets the duration
    * @return the timer duration
    */
    Score::TIMER_DURATION getDuration() const;

    /**
    * Gets the sort order option
    * @return the sort order
    */
    ScoreBoard::SORT_ORDER getSortOption() const;

    /**
    * Gets the reusable flag
    * @return the flag indicating if letters are reusable
    */
    bool getReusableFlag() const;

    /**
    * Sets the duration of the setting
    * @param duration the duration
    * @post getDuration() == duration
    */
    void setDuration(Score::TIMER_DURATION duration);

    /**
    * Sets the sort option
    * @param scoreSortOption the score sort option
    * @post getSortOption() == scoreSortOption
    */
    void setSortOption(ScoreBoard::SORT_ORDER scoreSortOption);

    /**
    * Sets the reusable flag
    * @param isReusable the reusable flag
    * @post getReusableFlag == isReusable
    */
    void setReusableFlag(bool isReusable);

    /**
    * Saves the settings to a file
    */
    void saveSettings();

protected:

private:
    Score::TIMER_DURATION duration;
    ScoreBoard::SORT_ORDER sortOption;
    bool isResuable;
    const string SETTINGS_FILE = "settings.csv";


};
}


#endif // SETTINGS_H
