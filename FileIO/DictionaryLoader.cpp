#include "DictionaryLoader.h"
namespace fileio
{
DictionaryLoader::DictionaryLoader()
{

}

DictionaryLoader::~DictionaryLoader()
{

}

set<string> DictionaryLoader::getDictionary(const string& filename) const
{
    set<string> dictionary;
    string line;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            dictionary.insert(line);
        }
    }
    return dictionary;
}
}

