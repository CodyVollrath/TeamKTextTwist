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

bool TextTwistDictionary::contains(string& word) {
    return std::find(this->dictionary->begin(), this->dictionary->end(), word) != this->dictionary->end();
}

}

