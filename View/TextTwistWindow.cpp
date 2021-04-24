#include "TextTwistWindow.h"
namespace view
{

TextTwistWindow::TextTwistWindow(int width, int height, const char* title, char* letters) : Fl_Window(width, height, title)
{
    begin();
    this->letters = letters;
    this->initializeLetters();
    end();
}

TextTwistWindow::~TextTwistWindow()
{
    if (this->letters) {
        delete this->letters;
    }
    this->letters = 0;
    for (int i = 0; i < this->MAX_LETTER_LENGTH; i++) {
        if (this->letterButtons[i]) {
            delete this->letterButtons[i];
        }
    }
}

void TextTwistWindow::initializeLetters()
{
    int accumulator = 0;
    for (int i = 0; i < this->MAX_LETTER_LENGTH; i++) {
        char c[] = {this->letters[i]};
        this->letterButtons[i] =  new Fl_Button(25 + accumulator, 25,this->SIDE_LENGTH_OF_BUTTON, this->SIDE_LENGTH_OF_BUTTON, c);
        accumulator += this->SIDE_LENGTH_OF_BUTTON + 5;
    }
}
}

