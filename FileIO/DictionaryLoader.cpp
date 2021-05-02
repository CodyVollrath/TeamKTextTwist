#include "DictionaryLoader.h"
namespace fileio
{
DictionaryLoader::DictionaryLoader()
{

}

DictionaryLoader::~DictionaryLoader()
{

}

set<string>* DictionaryLoader::getDictionary(const string& filename) const
{
    set<string>* dictionary = new set<string>();
    string line;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
            dictionary->insert(line);
        }
    }
    return dictionary;
}
}

