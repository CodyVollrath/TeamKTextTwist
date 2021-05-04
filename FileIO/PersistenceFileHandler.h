#ifndef PERSISTENCE_FILE_HANDLER_H
#define PERSISTENCE_FILE_HANDLER_H

#include <fstream>
using namespace std;

namespace fileio
{
//
// File handler for saving and loading file contents
//
class PersistenceFileHandler
{
public:
    //
    // Constructs a DictionaryLoader object
    //
    // @precondition none
    // @postcondition none
    //
    PersistenceFileHandler();

    //
    // Destructs the DictionaryLoader object
    //
    // @precondition none
    // @postcondition none
    //
    virtual ~PersistenceFileHandler();

    //
    // Reads the files contents into a string
    //
    // @precondition none
    // @postcondition none
    //
    // @param filename the URI of the dictionary file
    // @return the file contents as text
    string getFileContents(const string& filename) const;

    //
    // Overwrites the given text to the file provided
    //
    // @precondition none
    // @postcondition file is overwritten with contents
    //
    // @param filename the URI of the dictionary file
    // @param contents the contents to be written
    void saveToFile(const string& filename, const string& contents);

    //
    // Appends the given text to the file provided
    //
    // @precondition none
    // @postcondition contents is appended to end of file contents
    //
    // @param filename the URI of the dictionary file
    // @param contents the contents to be appended
    void appendToFile(const string& filename, const string& contents);
};
}



#endif // PERSISTENCE_FILE_HANDLER_H
