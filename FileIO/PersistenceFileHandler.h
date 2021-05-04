#ifndef SETTINGSFILEHANDLER_H
#define SETTINGSFILEHANDLER_H

#include <fstream>
using namespace std;

namespace fileio
{
class PersistenceFileHandler
{
public:
    PersistenceFileHandler();
    virtual ~PersistenceFileHandler();
    string getFileContents(const string& filename) const;
    void saveToFile(const string& filename, const string& contents);
    void appendToFile(const string& filename, const string& contents);
protected:

private:
};
}



#endif // SETTINGSFILEHANDLER_H
