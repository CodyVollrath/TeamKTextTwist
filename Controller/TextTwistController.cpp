#include "TextTwistController.h"
namespace controller
{

// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
const int TextTwistController::LETTER_FREQUENCIES[] = {6, 2, 2, 3, 11, 2, 2, 5, 6, 1, 1, 4, 2, 6, 8, 2, 1, 5, 6, 9, 3, 2, 3, 1, 3, 1};

TextTwistController::TextTwistController()
{
    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        counter += TextTwistController::LETTER_FREQUENCIES[i];
        this->letterBrackets[i] = counter;
    }
    this->maxBracket = counter;
    this->dictionary = new TextTwistDictionary();
}
TextTwistController::~TextTwistController()
{
    delete this->dictionary;
}

int TextTwistController::getLetterIndex(int value)
{
    for (int i = 0; i < 26; i++)
    {
        if (value < this->letterBrackets[i])
        {
            return i;
        }
    }
}

char TextTwistController::getRandomLetter(vector<char> usedLetters)
{
    char selected_letter = 0;
    while (selected_letter == 0)
    {
        int randomValue = rand() % this->maxBracket;
        int letterIndex = this->getLetterIndex(randomValue);
        char randomCharacter = 'a' + letterIndex;
        if (find(usedLetters.begin(), usedLetters.end(), randomCharacter) == usedLetters.end())
        {
            return randomCharacter;
        }
    }

}


void TextTwistController::generate()
{
    vector<char> usedLetters;
    for (int i = 0; i < TextTwistController::MAX_LETTER_LENGTH; i++)
    {
        char letter = getRandomLetter(usedLetters);
        usedLetters.push_back(letter);
        this->letters[i] = string(1, letter);
    }
}
void TextTwistController::twist()
{
    random_shuffle(begin(this->letters), end(this->letters));
}

string* TextTwistController::getLetters()
{
    return this->letters;
}
}
