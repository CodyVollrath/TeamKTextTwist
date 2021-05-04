#include "TextTwister.h"
namespace model
{

// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
const int TextTwister::LETTER_FREQUENCIES[] = {6, 2, 2, 3, 11, 2, 2, 5, 6, 1, 1, 4, 2, 6, 8, 2, 1, 5, 6, 9, 3, 2, 3, 1, 3, 1};

TextTwister::TextTwister()
{
    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        counter += TextTwister::LETTER_FREQUENCIES[i];
        this->letterBrackets[i] = counter;
    }
    this->maxBracket = counter;
    this->dictionary = new TextTwistDictionary();
    this->score = 0;
    this->usedWords = new set<string>();
}
TextTwister::~TextTwister()
{
    delete this->dictionary;
    delete this->usedWords;
}

int TextTwister::getLetterIndex(int value)
{
    for (int i = 0; i < 26; i++)
    {
        if (value < this->letterBrackets[i])
        {
            return i;
        }
    }
}

char TextTwister::getRandomLetter()
{
    char selected_letter = 0;
    int randomValue = rand() % this->maxBracket;
    int letterIndex = this->getLetterIndex(randomValue);
    char randomCharacter = 'a' + letterIndex;
    return randomCharacter;
}

void TextTwister::generate()
{
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        char letter = getRandomLetter();
        this->letters[i] = string(1, letter);
    }
}

void TextTwister::reset()
{
    this->score = 0;
    delete this->usedWords;
    this->usedWords = new set<string>();
}

void TextTwister::twist()
{
    random_shuffle(begin(this->letters), end(this->letters));
}

string* TextTwister::getLetters()
{
    return this->letters;
}

set<string>* TextTwister::getUsedWords()
{
    return this->usedWords;
}

string TextTwister::submit(string letters) {
    string word = letters;
    bool used = find(this->usedWords->begin(), this->usedWords->end(), word) != this->usedWords->end();
    bool inDictionary = this->dictionary->contains(word);

    string response = "You already used that word!";
    if (inDictionary && !used) {
        int letterCount = word.length();
        this->score += (letterCount * letterCount * 10);  // update score
        this->usedWords->insert(word);
        response = "Correct! That word exists!";
    } else if (!inDictionary) {
        this->score -= 10;
        response = "Wrong! That word does not exist!";
    }
    return response;
}



int TextTwister::getScore()
{
    return this->score;
}

}

