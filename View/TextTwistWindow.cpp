#include "TextTwistWindow.h"
namespace view
{

TextTwistWindow::TextTwistWindow(int width, int height, const char* title, string* letters) : Fl_Window(width, height, title)
{
    begin();
    this->letters = letters;
    this->initializeBoardElements();
    this->undoButton = new Fl_Button(25, 25, 100,30, "Undo");
    this->undoButton->callback(this->cbUndo, this);
    this->letterButtonsUsed = new stack<Fl_Button*>();
    this->letterFieldsUsed = new stack<Fl_Input*>();
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
        this->letterButtons[i]->callback(this->cbSendLetterToField, this);
        this->letterFields[i] = new Fl_Input(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS - 100, this->SIDE_LENGTH_OF_BUTTON, this->SIDE_LENGTH_OF_BUTTON, "");
        this->letterFields[i]->deactivate();
        accumulator += this->SIDE_LENGTH_OF_BUTTON + 5;
    }
}

void TextTwistWindow::cbSendLetterToField(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    Fl_Button* button = (Fl_Button*) widget;
    window->placeLetterToNextEmptyField(button->label());
    button->deactivate();
    window->letterButtonsUsed->push(button);
}

void TextTwistWindow::placeLetterToNextEmptyField(const char* letter)
{
    for (int i = 0; i < this->MAX_LETTER_LENGTH; i++) {
        string value = this->letterFields[i]->value();
        if (value == "") {
            this->letterFields[i]->value(letter);
            this->letterFieldsUsed->push(this->letterFields[i]);
            break;
        }
    }
}

void TextTwistWindow::cbUndo(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    if (!(window->letterButtonsUsed->empty() || window->letterFieldsUsed->empty())) {
        Fl_Button* button = window->letterButtonsUsed->top();
        Fl_Input* field = window->letterFieldsUsed->top();
        button->activate();
        field->value("");
        window->letterButtonsUsed->pop();
        window->letterFieldsUsed->pop();
    }
}
}

