#ifndef SETTINGS_H
#define SETTINGS_H
#include "ResourceData.h"

#include <string>
using namespace std;

#include "SettingsFileHandler.h"
using namespace fileio;

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
        Settings(int timeInMinutes, int scoreSortOption, bool isResuable);
        virtual ~Settings();

        int getTimeInMinutes() const;
        int getSortOption() const;
        bool getReusableFlag() const;

        void setTimeInMinutes(int timeInMinutes);
        void setSortOption(int scoreSortOption);
        void setReusableFlag(bool isResuable);
        void saveSettings();

    protected:

    private:
        int timeInMinutes;
        int sortOption;
        bool isResuable;
        const string SETTINGS_FILE = "settings.csv";


};
}


#endif // SETTINGS_H
