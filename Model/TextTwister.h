#ifndef TEXTTWISTER_H
#define TEXTTWISTER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "TextTwistDictionary.h"

namespace model
{
class TextTwister
{

    public:

        static const int LETTER_FREQUENCIES[];
        static const int MAX_LETTER_LENGTH = 7;

        TextTwister();
        virtual ~TextTwister();
        void generate();
        void twist();
        string* getLetters();

    private:
        TextTwistDictionary* dictionary;
        string letters[MAX_LETTER_LENGTH];
        int letterBrackets[26];
        int maxBracket;
        char getRandomLetter(vector<char> usedLetters);
        int getLetterIndex(int value);
};

}


#endif // TEXTTWISTER_H
