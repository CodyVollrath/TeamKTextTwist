#include "TextTwistController.h"
namespace controller
{

TextTwistController::TextTwistController()
{
    this->twister = new TextTwister();
}
TextTwistController::~TextTwistController()
{
    delete this->twister;
}

void TextTwistController::generate()
{
    this->twister->generate();
}
void TextTwistController::twist()
{
    this->twister->twist();
}

string* TextTwistController::getLetters()
{
    return this->twister->getLetters();
}
}
