#ifndef DICTIONARYLOADER_H
#define DICTIONARYLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

namespace fileio
{
class DictionaryLoader
{
public:
    //
    // Constructs a TextTwistController object
    //
    // @precondition none
    // @postcondition getAnswers() == nullptr;
    //                getSettings() != nullptr
    //                getScoreBoard() != nullptr;
    //
    DictionaryLoader();
        //
    // Destructs the TextTwistController object
    //
    // @precondition none
    // @postcondition none
    //
    virtual ~DictionaryLoader();
        //
    // Destructs the TextTwistController object
    //
    // @precondition none
    // @postcondition none
    //
    unordered_set<string>* getDictionary(const string& filename) const;

protected:

private:

};
}


#endif // DICTIONARYLOADER_H
