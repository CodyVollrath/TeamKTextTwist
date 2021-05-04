#include "TextTwistDictionary.h"
namespace model
{
TextTwistDictionary::TextTwistDictionary()
{
    DictionaryLoader loader;
    this->dictionary = loader.getDictionary(this->DICT_NAME);
}

TextTwistDictionary::~TextTwistDictionary()
{
    delete this->dictionary;
}

bool TextTwistDictionary::contains(string& word)
{
    return std::find(this->dictionary->begin(), this->dictionary->end(), word) != this->dictionary->end();
}

unordered_set<string>* TextTwistDictionary::getDictionary()
{
    return this->dictionary;
}

int* TextTwistDictionary::getLetterFrequencies(string& letters)
{
    int* letterFrequencies = new int[TextTwistDictionary::NUMBER_OF_LETTERS] {0};
    for (char letter : letters)
    {
        int index = letter - 'a';
        letterFrequencies[index]++;
    }
    return letterFrequencies;
}

unordered_set<string>* TextTwistDictionary::getAnagrams(string& letters, bool allowReuse)
{
    int* letterFrequencies = getLetterFrequencies(letters);
    unordered_set<string>* anagrams = new unordered_set<string>();
    unordered_set<string>::iterator it = this->dictionary->begin();
    while (it != this->dictionary->end())
    {
        string word = *it;
        bool isWordAnagram = (allowReuse && TextTwistDictionary::isAnagramWithReuse(letterFrequencies, word)) || TextTwistDictionary::isAnagram(letterFrequencies, word);
        if (isWordAnagram)
        {
            anagrams->insert(word);
        }
        it++;
    }
    delete[] letterFrequencies;
    return anagrams;
}

bool TextTwistDictionary::isAnagram(int* letterFrequencies, string& word)
{
    int* wordFrequencies = TextTwistDictionary::getLetterFrequencies(word);

    int numberOfMatchedLetters = 0;
    for (int i = 0; i < TextTwistDictionary::NUMBER_OF_LETTERS; i++ )
    {
        if (letterFrequencies[i] > 0 && letterFrequencies[i] >= wordFrequencies[i])
        {
            numberOfMatchedLetters += wordFrequencies[i];
        }
    }
    delete[] wordFrequencies;
    return numberOfMatchedLetters == word.length() && word.length() >= 3;
}

bool TextTwistDictionary::isAnagramWithReuse(int* letterFrequencies, string& word)
{
    int* wordFrequencies = TextTwistDictionary::getLetterFrequencies(word);

    int numberOfUniqueInWord = 0;
    int numberOfMatchedUniqueInWord = 0;
    for (int i = 0; i < TextTwistDictionary::NUMBER_OF_LETTERS; i++ )
    {
        if (wordFrequencies[i] > 0)
        {
            numberOfUniqueInWord++;
        }
        if (letterFrequencies[i] > 0 && wordFrequencies[i] > 0)
        {
            numberOfMatchedUniqueInWord++;
        }
    }
    delete[] wordFrequencies;
    return (numberOfMatchedUniqueInWord > 0) && (numberOfMatchedUniqueInWord == numberOfUniqueInWord) && word.length() >= 3;
}
}

