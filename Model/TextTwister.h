#ifndef TEXTTWISTER_H
#define TEXTTWISTER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

#include "TextTwistDictionary.h"

namespace model
{
class TextTwister
{

public:

    static const int LETTER_FREQUENCIES[];
    static const int MAX_LETTER_LENGTH = 7;
    static int calculateScore(string& word);

    TextTwister();
    virtual ~TextTwister();
    void start();
    void twist();
    string* getLetters();
    unordered_set<string>* getUsedWords();
    unordered_set<string>* getAnswers(bool allowReuse);
    string submit(string letters);
    int getScore();


private:
    TextTwistDictionary* dictionary;
    string letters[MAX_LETTER_LENGTH];
    int letterBrackets[TextTwistDictionary::NUMBER_OF_LETTERS];
    int maxBracket;
    char getRandomLetter();
    int getLetterIndex(int value);
    int score;
    unordered_set<string>* usedWords;

};

}


#endif // TEXTTWISTER_H
