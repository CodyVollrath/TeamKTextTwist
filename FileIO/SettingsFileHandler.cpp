#include "SettingsFileHandler.h"
namespace fileio
{
SettingsFileHandler::SettingsFileHandler()
{
    //ctor
}

SettingsFileHandler::~SettingsFileHandler()
{
    //dtor
}

string SettingsFileHandler::getFileContents(const string& filename) const
{
    string output;
    string line;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            output += line + "\n";
        }
    }
    return output;
}

void SettingsFileHandler::saveToFile(const string& filename, const string& contents)
{
    ofstream file(filename);
    file << contents;
    file.close();
}
}

