#ifndef SETTINGS_H
#define SETTINGS_H
#include "ResourceData.h"


namespace model
{
class Settings
{
    public:
        Settings(int timeInMinutes, int scoreSortOption, bool isResuable);
        virtual ~Settings();

        int getTimeInMinutes() const;
        int getSortOption() const;
        bool getReusableFlag() const;

        void setTimeInMinutes(int timeInMinutes);
        void setSortOption(int scoreSortOption);
        void setReusableFlag(bool isResuable);

    protected:

    private:
        int timeInMinutes;
        int sortOption;
        bool isResuable;


};
}


#endif // SETTINGS_H
