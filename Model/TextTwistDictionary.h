#ifndef TEXTTWISTDICTIONARY_H
#define TEXTTWISTDICTIONARY_H

#include <algorithm>
#include <unordered_set>
using namespace std;

#include "DictionaryLoader.h"
using namespace fileio;

namespace model
{

/**
* Keeps track of the text twist dictionary of words
* @author Cody Vollrath
*/
class TextTwistDictionary
{

    public:
        static const int NUMBER_OF_LETTERS = 26;
        /**
        * Creates a TextTwistDictionary
        */
        TextTwistDictionary();

        /**
        * Destroys TextTwistDictionary
        */
        virtual ~TextTwistDictionary();

        /**
        * Gets the dictionary
        * @return the dictionary
        */
        unordered_set<string>* getDictionary();

        /**
        * Checks if a word is contained in the dictionary
        * @return true if word is in dictionary, false otherwise
        */
        bool contains(string& word);

        /**
        * Gets the anagrams
        * @param letters the letters of the word
        * @param allowReuse indicates reuse
        * @return a subset of the dictionary for the matching anagrams of the word
        */
        unordered_set<string>* getAnagrams(string& letters, bool allowReuse);

    private:
        const string DICT_NAME = "dictionary.txt";
        int* getFrequencies(string& letters);
        bool isAnagram(int* letterFrequencies, string& word);
        bool isAnagramWithReuse(int* letterFrequencies, string& word);
        unordered_set<string>* dictionary;
};
}


#endif // TEXTTWISTDICTIONARY_H
