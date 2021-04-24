#include "TextTwistWindow.h"
namespace view
{

TextTwistWindow::TextTwistWindow(int width, int height, const char* title, string* letters) : Fl_Window(width, height, title)
{
    begin();
    this->letters = letters;
    this->initializeBoardElements();
    end();
}

TextTwistWindow::~TextTwistWindow()
{
    this->letters = 0;
    for (int i = 0; i < this->MAX_LETTER_LENGTH; i++) {
        if (this->letterButtons[i]) {
            delete this->letterButtons[i];
        }
    }
}

void TextTwistWindow::initializeBoardElements()
{
    int accumulator = 0;
    for (int i = 0; i < this->MAX_LETTER_LENGTH; i++) {
        this->letterButtons[i] =  new Fl_Button(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS,this->SIDE_LENGTH_OF_BUTTON, this->SIDE_LENGTH_OF_BUTTON, this->letters[i].c_str());
        this->letterButtons[i]->callback(this->sendLetterToField, this);
        this->letterFields[i] = new Fl_Input(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS - 100, this->SIDE_LENGTH_OF_BUTTON, this->SIDE_LENGTH_OF_BUTTON, "");
        this->letterFields[i]->deactivate();
        accumulator += this->SIDE_LENGTH_OF_BUTTON + 5;
    }
}

void TextTwistWindow::sendLetterToField(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    Fl_Button* button = (Fl_Button*) widget;
    window->placeLetterToNextEmptyField(button->label());
    button->deactivate();
}

void TextTwistWindow::placeLetterToNextEmptyField(const char* letter)
{
    for (int i = 0; i < this->MAX_LETTER_LENGTH; i++) {
        string value = this->letterFields[i]->value();
        if (value == "") {
            this->letterFields[i]->value(letter);
            break;
        }
    }
}
}

