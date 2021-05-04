#ifndef TEXTTWISTER_H
#define TEXTTWISTER_H
#include "ResourceData.h"
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

    TextTwister();
    virtual ~TextTwister();
    void start();
    void twist();
    string* getLetters();
    unordered_set<string>* getUsedWords();
    string submit(string letters);
    int getScore();
    static int calculateScore(string& word);
    unordered_set<string>* getSolutions(string& word, bool allowReuse);

private:
    TextTwistDictionary* dictionary;
    string letters[MAX_LETTER_LENGTH];
    int letterBrackets[26];
    int maxBracket;
    char getRandomLetter();
    int getLetterIndex(int value);
    int score;
    unordered_set<string>* usedWords;

};

}


#endif // TEXTTWISTER_H
