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
class Settings
{
    public:



        /**
        * Constructs settings object: Empty Constructor loads from a file
        * @pre the file it is loading from must exist and be validly formatted as a csv
        * @post getTimeInMinutes() == item1 && getSortOption == item2 && getReusableFlag == item3
        */
        Settings();
        Settings(Score::TIMER_DURATION duration, ScoreBoard::SORT_ORDER scoreSortOption, bool isResuable);
        virtual ~Settings();

        Score::TIMER_DURATION getDuration() const;
        ScoreBoard::SORT_ORDER getSortOption() const;
        bool getReusableFlag() const;

        void setDuration(Score::TIMER_DURATION duration);
        void setSortOption(ScoreBoard::SORT_ORDER scoreSortOption);
        void setReusableFlag(bool isResuable);
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
