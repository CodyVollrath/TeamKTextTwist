#include "TextTwistWindow.h"
namespace view
{

TextTwistWindow::TextTwistWindow(int width, int height, const char* title, string* letters) : Fl_Window(width, height, title)
{
    begin();
    this->letters = letters;
    this->initializeLetterButtons();
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

void TextTwistWindow::initializeLetterButtons()
{
    int accumulator = 0;
    for (int i = 0; i < this->MAX_LETTER_LENGTH; i++) {
        this->letterButtons[i] =  new Fl_Button(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS,this->SIDE_LENGTH_OF_BUTTON, this->SIDE_LENGTH_OF_BUTTON, this->letters[i].c_str());
        accumulator += this->SIDE_LENGTH_OF_BUTTON + 5;
    }
}
void TextTwistWindow::initializeLetterFields()
{

}
}

