#include "DictionaryLoader.h"
namespace fileio
{
DictionaryLoader::DictionaryLoader(const string& filename)
{
    this->dictionary = new set<string>();
    string line;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            this->dictionary->insert(line);
        }
    }
}

DictionaryLoader::~DictionaryLoader()
{
    delete this->dictionary;
}

set<string> DictionaryLoader::getDictionary() const
{
    return *this->dictionary;
}
}

