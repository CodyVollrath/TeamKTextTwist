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

//
// Dictionary loader for reading dictionary file contents
//
class DictionaryLoader
{
public:
    //
    // Constructs a DictionaryLoader object
    //
    // @precondition none
    // @postcondition none
    //
    DictionaryLoader();

    //
    // Destructs the DictionaryLoader object
    //
    // @precondition none
    // @postcondition none
    //
    virtual ~DictionaryLoader();

    //
    // Creates a new has set of dictionary words from the given file
    //
    // @precondition none
    // @postcondition none
    //
    // @param filename the URI of the dictionary file
    // @return the dictionary in a hash set
    unordered_set<string>* getDictionary(const string& filename) const;

};
}


#endif // DICTIONARYLOADER_H
