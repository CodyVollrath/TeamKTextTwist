#include "TextTwistDictionary.h"
namespace model
{
TextTwistDictionary::TextTwistDictionary()
{
    DictionaryLoader loader;
    this->dictionary = loader.getDictionary(this->DICT_NAME);
}

TextTwistDictionary::TextTwistDictionary(unordered_set<string>* dictionary)
{
    this->dictionary = dictionary;
}

TextTwistDictionary::~TextTwistDictionary()
{
    delete this->dictionary;
}

bool TextTwistDictionary::contains(string& word)
{
    return std::find(this->dictionary->begin(), this->dictionary->end(), word) != this->dictionary->end();
}

int* getFrequencies(string& letters)
{
    int* letterFrequencies = new int[TextTwistDictionary::NUMBER_OF_LETTERS] {0};
    return letterFrequencies;
}

bool isAnagram(int* letterFrequencies, string& word)
{
    return false;
}

bool isAnagramWithReuse(int* letterFrequencies, string& word)
{
    return false;
}

unordered_set<string>* TextTwistDictionary::getAnagrams(string& letters, bool allowReuse)
{
    unordered_set<string>* anagrams = new unordered_set<string>();
    return anagrams;
}

}

