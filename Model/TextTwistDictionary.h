#ifndef TEXTTWISTDICTIONARY_H
#define TEXTTWISTDICTIONARY_H

#include "DictionaryLoader.h"
using namespace fileio;

namespace model
{
class TextTwistDictionary
{
    public:
        TextTwistDictionary();
        virtual ~TextTwistDictionary();
    protected:

    private:
        const string DICT_NAME = "dictionary.txt";
        set<string>* dictionary;
};
}


#endif // TEXTTWISTDICTIONARY_H
