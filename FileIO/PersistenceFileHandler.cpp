#include "PersistenceFileHandler.h"
namespace fileio
{
PersistenceFileHandler::PersistenceFileHandler()
{
    //ctor
}

PersistenceFileHandler::~PersistenceFileHandler()
{
    //dtor
}

string PersistenceFileHandler::getFileContents(const string& filename) const
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

void PersistenceFileHandler::saveToFile(const string& filename, const string& contents)
{
    ofstream file(filename);
    file << contents;
    file.close();
}

void PersistenceFileHandler::appendToFile(const string& filename, const string& contents)
{
    string output = this->getFileContents(filename);
    output += contents;
    this->saveToFile(filename, output);
}
}

