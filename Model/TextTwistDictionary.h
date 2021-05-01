#ifndef TEXTTWISTDICTIONARY_H
#define TEXTTWISTDICTIONARY_H

#include <algorithm>
using namespace std;

#include "DictionaryLoader.h"
using namespace fileio;

namespace model
{
class TextTwistDictionary
{
    public:
        TextTwistDictionary();
        virtual ~TextTwistDictionary();
        set<string>* getDictionary();
        bool contains(string& word);

    private:
        const string DICT_NAME = "dictionary.txt";
        set<string>* dictionary;
};
}


#endif // TEXTTWISTDICTIONARY_H
