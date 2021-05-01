#include "TextTwistDictionary.h"
namespace model
{
TextTwistDictionary::TextTwistDictionary()
{
    DictionaryLoader loader;
    this->dictionary = new set<string>(loader.getDictionary(this->DICT_NAME));
    //filter this dictionary later
}

TextTwistDictionary::~TextTwistDictionary()
{
    delete this->dictionary;
}
}

