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
        static const int NUMBER_OF_LETTERS = 26;
        TextTwistDictionary();
        virtual ~TextTwistDictionary();
        set<string>* getDictionary();
        bool contains(string& word);
        set<string>* getAnagrams(string& letters, bool allowReuse);

    private:
        const string DICT_NAME = "dictionary.txt";
        int* getFrequencies(string& letters);
        bool isAnagram(int* letterFrequencies, string& word);
        bool isAnagramWithReuse(int* letterFrequencies, string& word);
        set<string>* dictionary;
};
}


#endif // TEXTTWISTDICTIONARY_H
