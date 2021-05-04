#ifndef SCOREBOARDFILEHANDLER_H
#define SCOREBOARDFILEHANDLER_H

#include <fstream>
#include <string>
using namespace std;

namespace fileio
{
class ScoreboardFileHandler
{
    public:
        ScoreboardFileHandler();
        virtual ~ScoreboardFileHandler();
        void saveToFile(const string& filename);
        string loadFromFile(const string& filename);
    protected:

    private:
};
}


#endif // SCOREBOARDFILEHANDLER_H
