#include "TextTwistWindow.h"

namespace view
{

TextTwistWindow::TextTwistWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->controller = new TextTwistController();


    this->undoButton = new Fl_Button(25, 25, 100,30, "Undo");
    this->twistButton = new Fl_Button(25, 60, 100, 30, "Twist");
    this->generateButton = new Fl_Button(25,95, 100, 30, "Start");

    this->timerLabel = new Fl_Box(250, 25, 25, 40, "00:00:00");
    this->undoButton->callback(this->cbUndo, this);
    this->twistButton->callback(this->cbTwist, this);
    this->generateButton->callback(this->cbGenerate, this);

    this->letterButtonsUsed = new stack<Fl_Button*>();
    this->letterFieldsUsed = new stack<Fl_Input*>();

    this->initializeBoardElements();
    end();
}

TextTwistWindow::~TextTwistWindow()
{

    for (int i = 0; i < TextTwistController::MAX_LETTER_LENGTH; i++)
    {
        delete this->letterButtons[i];
        delete this->letterFields[i];
    }
    delete this->undoButton;
    delete this->twistButton;
    delete this->generateButton;

    delete this->controller;
    delete this->letterButtonsUsed;
    delete this->letterFieldsUsed;
}

void TextTwistWindow::initializeBoardElements()
{
    int accumulator = 0;
    for (int i = 0; i < TextTwistController::MAX_LETTER_LENGTH; i++)
    {
        this->letterButtons[i] =  new Fl_Button(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS,this->SIDE_LENGTH_OF_BUTTON, this->SIDE_LENGTH_OF_BUTTON, "");
        this->letterButtons[i]->callback(this->cbSendLetterToField, this);
        this->letterFields[i] = new Fl_Input(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS - 100, this->SIDE_LENGTH_OF_BUTTON, this->SIDE_LENGTH_OF_BUTTON, "");
        this->letterFields[i]->deactivate();
        this->letterButtons[i]->deactivate();
        accumulator += this->SIDE_LENGTH_OF_BUTTON + 5;
    }
}

void TextTwistWindow::resetBoard()
{
    string* letters = this->controller->getLetters();
    for (int i = 0; i < TextTwistController::MAX_LETTER_LENGTH; i++)
    {
        Fl_Button* button = this->letterButtons[i];
        button->label(letters[i].c_str());
        button->activate();
        this->letterFields[i]->value("");
    }
    delete this->letterButtonsUsed;
    delete this->letterFieldsUsed;
    this->letterButtonsUsed = new stack<Fl_Button*>();
    this->letterFieldsUsed = new stack<Fl_Input*>();
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
    for (int i = 0; i < TextTwistController::MAX_LETTER_LENGTH; i++)
    {
        string value = this->letterFields[i]->value();
        if (value == "")
        {
            this->letterFields[i]->value(letter);
            this->letterFieldsUsed->push(this->letterFields[i]);
            break;
        }
    }
}

void TextTwistWindow::cbUndo(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    if (!(window->letterButtonsUsed->empty() || window->letterFieldsUsed->empty()))
    {
        Fl_Button* button = window->letterButtonsUsed->top();
        Fl_Input* field = window->letterFieldsUsed->top();
        button->activate();
        field->value("");
        window->letterButtonsUsed->pop();
        window->letterFieldsUsed->pop();
    }
}

void TextTwistWindow::cbTwist(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->controller->twist();
    window->resetBoard();
}

void TextTwistWindow::cbGenerate(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->controller->generate();
    window->resetBoard();
}
}

