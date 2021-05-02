#ifndef DICTIONARYLOADER_H
#define DICTIONARYLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

namespace fileio
{
class DictionaryLoader
{
    public:
        DictionaryLoader();
        virtual ~DictionaryLoader();
        set<string>* getDictionary(const string& filename) const;

    protected:

    private:

};
}


#endif // DICTIONARYLOADER_H
