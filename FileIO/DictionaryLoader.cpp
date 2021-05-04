#include "DictionaryLoader.h"
namespace fileio
{
DictionaryLoader::DictionaryLoader()
{

}

DictionaryLoader::~DictionaryLoader()
{

}

unordered_set<string>* DictionaryLoader::getDictionary(const string& filename) const
{
    unordered_set<string>* dictionary = new unordered_set<string>();
    string line;
    ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
            dictionary->insert(line);
        }
    }
    return dictionary;
}
}

