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
/**
* Allows for the twist of characters
* @author Furichous Jones
*/
class TextTwister
{


    public:

        static const int LETTER_FREQUENCIES[];
        static const int MAX_LETTER_LENGTH = 7;

        /**
        * Creates the TextTwister
        */
        TextTwister();

        /**
        * Destroys the TextTwister
        */
        virtual ~TextTwister();

        /**
        * Starts the game by generating the letters
        */
        void start();

        /**
        * Shuffles the letters
        */
        void twist();

        /**
        * Gets the letters generated
        * @return the letters generated
        */
        string* getLetters();

        /**
        * Gets used words
        * @return the used words
        */
        unordered_set<string>* getUsedWords();

        /**
        * Publishes the letters to be evaluated by the dictionary
        * @param letters
        * @return a string indicating the letters were correct, incorrect, or already used
        */
        string submit(string letters);

        /**
        * Gets the score
        * @return the score
        */
        int getScore();

        /**
        * Calculates the score by the length of the word
        * @param word the word to be calculated
        * @return the score for that word
        */
        static int calculateScore(string& word);

        /**
        * Gets the solutions for a word
        * @param word the word for the solutions
        * @param allowReuse indicates if reusable letters should be accounted for
        * @return the set of words that match the solution
        */
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
