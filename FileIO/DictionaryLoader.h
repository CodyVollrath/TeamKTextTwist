#ifndef DICTIONARYLOADER_H
#define DICTIONARYLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

namespace fileio
{
class DictionaryLoader
{
    public:
        DictionaryLoader(const string& filename);
        virtual ~DictionaryLoader();
        set<string> getDictionary() const;

    protected:

    private:
        set<string>* dictionary;
};
}


#endif // DICTIONARYLOADER_H
