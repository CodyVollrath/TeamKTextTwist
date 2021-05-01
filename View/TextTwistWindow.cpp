#include "TextTwistWindow.h"

namespace view
{

TextTwistWindow::TextTwistWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->controller = new TextTwistController();
    const int GENERATE_BUTTON_POS_ADDER = 2 * this->Y_POS_DIF;

    this->undoButton = new Fl_Button(this->LEFT_BUTTON_POS, this->LEFT_BUTTON_POS, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Undo");
    this->twistButton = new Fl_Button(this->LEFT_BUTTON_POS, this->LEFT_BUTTON_POS + this->Y_POS_DIF, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Twist");
    this->generateButton = new Fl_Button(this->LEFT_BUTTON_POS,this->LEFT_BUTTON_POS + GENERATE_BUTTON_POS_ADDER, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Start");

    this->submitButton = new Fl_Button(220, 325, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Submit");

    this->settingsButton = new Fl_Button(400, this->LEFT_BUTTON_POS, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Settings");

    this->timerLabel = new Fl_Box(this->TIME_LABEL_X_POS, this->TIME_LABEL_Y_POS, this->TIME_LABEL_SIDE_LENGTH, this->TIME_LABEL_SIDE_LENGTH, "00:00:00");
    this->scoreLabel = new Fl_Box(this->TIME_LABEL_X_POS - 50, this->TIME_LABEL_Y_POS + 50, 150, 50, "Score: 0");

    this->undoButton->callback(this->cbUndo, this);
    this->twistButton->callback(this->cbTwist, this);
    this->generateButton->callback(this->cbGenerate, this);
    this->submitButton->callback(this->cbSubmit, this);

    this->letterButtonsUsed = new stack<Fl_Button*>();
    this->letterFieldsUsed = new stack<Fl_Input*>();

    this->initializeBoardElements();
    end();
}

TextTwistWindow::~TextTwistWindow()
{

    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        delete this->letterButtons[i];
        delete this->letterFields[i];
    }
    delete this->undoButton;
    delete this->twistButton;
    delete this->generateButton;
    delete this->submitButton;
    delete this->timerLabel;

    delete this->controller;
    delete this->letterButtonsUsed;
    delete this->letterFieldsUsed;
}

void TextTwistWindow::initializeBoardElements()
{
    int accumulator = 0;
    const int Y_POS_DEC = 100;
    const int SPACE_LENGTH = 5;
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        this->letterButtons[i] =  new Fl_Button(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS,this->SIDE_LENGTH_OF_LETTER_BUTTON, this->SIDE_LENGTH_OF_LETTER_BUTTON, "");
        this->letterButtons[i]->callback(this->cbSendLetterToField, this);
        this->letterFields[i] = new Fl_Input(this->LETTERS_X_POS + accumulator, this->LETTERS_Y_POS - Y_POS_DEC, this->SIDE_LENGTH_OF_LETTER_BUTTON, this->SIDE_LENGTH_OF_LETTER_BUTTON, "");
        this->letterFields[i]->deactivate();
        this->letterButtons[i]->deactivate();
        accumulator += this->SIDE_LENGTH_OF_LETTER_BUTTON + SPACE_LENGTH;
    }
}

void TextTwistWindow::resetBoard()
{
    string* letters = this->controller->getLetters();
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
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
    this->didGameStart = true;
}


string* TextTwistWindow::getSelectedLetters()
{
    string* letters = new string[TextTwister::MAX_LETTER_LENGTH];
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        Fl_Input* field = this->letterFields[i];
        letters[i] = field->value();
    }
    return letters;
}

void TextTwistWindow::updateScore()
{
    int score = this->controller->getScore();
    string formattedScore = "Score: " + to_string(score);
    cout << formattedScore << endl;
    this->scoreLabel->label(formattedScore.c_str());
}

void TextTwistWindow::submit()
{
    string* letters = this->getSelectedLetters();
    this->controller->submit(letters);
    delete[] letters;
    this->updateScore();
    this->resetBoard();
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
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
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
    if (window->didGameStart) {
        window->resetBoard();
    }

}

void TextTwistWindow::cbGenerate(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->controller->generate();
    window->resetBoard();
}

void TextTwistWindow::cbSubmit(Fl_Widget* widget, void* data) {
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->submit();
}
}

