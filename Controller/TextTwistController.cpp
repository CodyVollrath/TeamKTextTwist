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

void TextTwistController::reset() {
    this->twister->reset();
}

string* TextTwistController::getLetters()
{
    return this->twister->getLetters();
}

string TextTwistController::submit(string* letters) {
    return this->twister->submit(letters);
}

int TextTwistController::getScore()
{
    return this->twister->getScore();
}

}
