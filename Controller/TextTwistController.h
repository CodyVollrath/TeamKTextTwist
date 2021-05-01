#ifndef TEXT_TWIST_CONTROLLER_H
#define TEXT_TWIST_CONTROLLER_H

#include <string>
using namespace std;

#include "TextTwister.h"
using namespace model;


namespace controller
{

class TextTwistController
{

public:
    TextTwistController();
    virtual ~TextTwistController();
    void generate();
    void twist();
    string* getLetters();

private:
    TextTwister* twister;

};

}


#endif // TEXT_TWIST_CONTROLLER_H
