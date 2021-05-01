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

char TextTwister::getRandomLetter(vector<char> usedLetters)
{
    char selected_letter = 0;
    while (selected_letter == 0)
    {
        int randomValue = rand() % this->maxBracket;
        int letterIndex = this->getLetterIndex(randomValue);
        char randomCharacter = 'a' + letterIndex;
        //if (find(usedLetters.begin(), usedLetters.end(), randomCharacter) == usedLetters.end())
        //{
            return randomCharacter;
        //}
    }
}

void TextTwister::generate()
{
    vector<char> usedLetters;
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        char letter = getRandomLetter(usedLetters);
        usedLetters.push_back(letter);
        this->letters[i] = string(1, letter);
    }
}

void TextTwister::reset()
{
    this->score = 0;
}

void TextTwister::twist()
{
    random_shuffle(begin(this->letters), end(this->letters));
}

string* TextTwister::getLetters()
{
    return this->letters;
}

void TextTwister::submit(string* letters) {
    string word;
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        string letter = letters[i];
        if (!letter.empty()) {
            word += letter;
        }
    }
    bool used = find(this->usedWords->begin(), this->usedWords->end(), word) == this->usedWords->end();
    bool inDictionary = this->dictionary->contains(word);
    if (inDictionary && !used) {
        int letterCount = word.length();
        this->score += (letterCount * letterCount * 10);  // update score
        this->usedWords->insert(word);
    } else if (!inDictionary) {
        this->score -= 10;
    }
}

int TextTwister::getScore()
{
    return this->score;
}

}

