#ifndef TEXT_TWIST_CONTROLLER_H
#define TEXT_TWIST_CONTROLLER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "TextTwistDictionary.h"
using namespace model;

namespace controller
{

class TextTwistController
{

public:

    static const int LETTER_FREQUENCIES[];
    static const int MAX_LETTER_LENGTH = 7;

    TextTwistController();
    virtual ~TextTwistController();
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


#endif // TEXT_TWIST_CONTROLLER_H
