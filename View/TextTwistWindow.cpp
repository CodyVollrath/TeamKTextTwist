#include "TextTwistWindow.h"

namespace view
{

TextTwistWindow::TextTwistWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->controller = new TextTwistController();

    this->undoButton = new Fl_Button(this->LEFT_BUTTON_POS, this->LEFT_BUTTON_POS, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Undo");
    this->twistButton = new Fl_Button(this->LEFT_BUTTON_POS, this->LEFT_BUTTON_POS + this->Y_POS_DIF, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Twist");
    this->generateButton = new Fl_Button(this->LEFT_BUTTON_POS,this->LEFT_BUTTON_POS + 2 * this->Y_POS_DIF, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Start");

    this->submitButton = new Fl_Button(this->SUBMIT_BUTTON_X_POS, this->SUBMIT_BUTTON_Y_POS, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Submit");

    this->settingsButton = new Fl_Button(this->SETTINGS_BUTTON_X_POS, this->LEFT_BUTTON_POS, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Settings");
    this->scoreBoardButton = new Fl_Button(this->SETTINGS_BUTTON_X_POS, this->LEFT_BUTTON_POS + this->Y_POS_DIF, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "High Scores");
    this->clearButton = new Fl_Button(this->SETTINGS_BUTTON_X_POS, this->LEFT_BUTTON_POS + 2 * this->Y_POS_DIF, this->BUTTON_WIDTH, this->BUTTON_HIGHT, "Clear");


    this->timerLabel = new Fl_Box(this->TIME_LABEL_X_POS, this->TIME_LABEL_Y_POS, this->TIME_LABEL_SIDE_LENGTH, this->TIME_LABEL_SIDE_HEIGHT, "00:00:00");
    this->scoreLabel = new Fl_Box(this->SCORE_LABEL_X_POS, this->SCORE_LABEL_Y_POS, this->SCORE_LABEL_SIDE_LENGTH, this->SCORE_LABEL_SIDE_HEIGHT, "Score: 0");
    this->responseLabel = new Fl_Box(this->RESPONSE_LABEL_X_POS, this->RESPONSE_LABEL_Y_POS, this->RESPONSE_LABEL_SIDE_LENGTH, this->RESPONSE_LABEL_SIDE_HEIGHT, "Response here!");

    this->timerLabel->align(FL_ALIGN_CENTER);
    this->scoreLabel->align(FL_ALIGN_CENTER);
    this->responseLabel->align(FL_ALIGN_CENTER);

    this->updateTimer();

    this->undoButton->callback(this->cbUndo, this);
    this->twistButton->callback(this->cbTwist, this);
    this->generateButton->callback(this->cbGenerate, this);
    this->clearButton->callback(this->cbClear, this);
    this->submitButton->callback(this->cbSubmit, this);
    this->settingsButton->callback(this->cbDisplaySettings, this);
    this->scoreBoardButton->callback(this->cbDisplayScoreBoard, this);

    this->letterButtonsUsed = new stack<Fl_Button*>();
    this->lettersUsed = new stack<const char*>();

    this->initializeBoardElements();
    this->submitButton->deactivate();
    this->controller->bindTimer(this->cbUpdateTimer, this);

    this->usedWords = new Fl_Scroll(this->USED_SCROLL_X_POS, this->USED_SCROLL_Y_POS, this->USED_SCROLL_SIDE_LENGTH, this->USED_SCROLL_SIDE_HEIGHT,"");
    this->usedWords->end();
    end();
}

TextTwistWindow::~TextTwistWindow()
{
    while (!this->letterButtonsUsed->empty())
    {
        delete this->letterButtonsUsed->top();
        this->letterButtonsUsed->pop();
    }
    delete this->letterButtonsUsed;
    delete this->lettersField;

    delete this->undoButton;
    delete this->twistButton;
    delete this->generateButton;
    delete this->submitButton;
    delete this->timerLabel;
    delete this->clearButton;
    delete this->responseLabel;
    delete this->scoreLabel;
    delete this->settingsButton;
    delete this->usedWords;

    delete this->controller;
    delete this->letterButtonsUsed;
    delete this->lettersUsed;
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
        this->letterButtons[i]->deactivate();
        accumulator += this->SIDE_LENGTH_OF_LETTER_BUTTON + SPACE_LENGTH;
    }
    this->lettersField = new Fl_Input(this->LETTERS_X_POS, this->LETTERS_Y_POS - Y_POS_DEC, 350, 30, "");
}

void TextTwistWindow::resetBoard()
{
    string* letters = this->controller->getLetters();
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        Fl_Button* button = this->letterButtons[i];
        button->label(letters[i].c_str());
        button->activate();
    }
    this->lettersField->value("");
    delete this->letterButtonsUsed;
    delete this->lettersUsed;
    this->letterButtonsUsed = new stack<Fl_Button*>();
    this->lettersUsed = new stack<const char*>();

    this->didGameStart = true;
    this->submitButton->deactivate();
}

void TextTwistWindow::lockBoard()
{
    string* letters = this->controller->getLetters();
    for (int i = 0; i < TextTwister::MAX_LETTER_LENGTH; i++)
    {
        Fl_Button* button = this->letterButtons[i];
        button->deactivate();
    }
    this->submitButton->deactivate();
}

void TextTwistWindow::startGame() {
    this->didGameStart = true;
    this->controller->startGame();
    this->resetBoard();
    this->updateScore();
    this->updateUsedWords();
}

void TextTwistWindow::endGame() {
    this->didGameStart = false;
    ScoreBoardWindow scoreboardWindow(this->controller->getScoreBoard());
    scoreboardWindow.set_modal();
    scoreboardWindow.showNameEntry();
    scoreboardWindow.show();

    while (scoreboardWindow.shown()) {
        Fl::wait();
    }

    if (scoreboardWindow.getWindowResult() == OKCancelWindow::WindowResult::OK) {
        string scoreName = scoreboardWindow.getNameEntry();
        this->controller->addScore(scoreName);
    }
    this->lockBoard();
}

void TextTwistWindow::pauseGame() {
    this->controller->pauseGame();
}

void TextTwistWindow::resumeGame() {
    this->controller->resumeGame();
}


string TextTwistWindow::getSelectedLetters()
{
    string letters = this->lettersField->value();
    //Get the letters used
    return letters;
}

void TextTwistWindow::updateScore()
{
    int score = this->controller->getScore();
    string formattedScore = "Score: " + to_string(score);
    cout << formattedScore << endl;
    this->scoreLabel->copy_label(formattedScore.c_str());
}

void TextTwistWindow::updateUsedWords()
{
    this->usedWords->clear();
    this->usedWords->begin();
    int accumulator = 0;
    for (string word : *this->controller->getUsedWords())
    {
        Fl_Box* wordBox = new Fl_Box(this->USED_SCROLL_X_POS, this->USED_SCROLL_Y_POS + accumulator, this->USED_SCROLL_SIDE_LENGTH, 25, "");
        wordBox->copy_label(word.c_str());
        accumulator += 25;
        cout << wordBox->label() << endl;
    }
    this->usedWords->end();
    this->usedWords->redraw();
}


void TextTwistWindow::submit()
{
    string letters = this->getSelectedLetters();
    string response = this->controller->submit(letters);
    this->responseLabel->copy_label(response.c_str());
    this->resetBoard();
    this->updateScore();
    this->updateUsedWords();

}

void TextTwistWindow::cbSendLetterToField(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    Fl_Button* button = (Fl_Button*) widget;
    window->placeLetterToNextEmptyField(button->label());
    if (!window->controller->areLettersReusable()) {
        button->deactivate();
    }

    window->letterButtonsUsed->push(button);
}

void TextTwistWindow::placeLetterToNextEmptyField(const char* letter)
{
    string value = this->lettersField->value();
    value += letter;
    string addedLetter = letter;
    this->lettersField->value(value.c_str());
    this->lettersUsed->push(addedLetter.c_str());
    if (this->lettersUsed->size() >= 3) {
        this->submitButton->activate();
    }
}

void TextTwistWindow::cbUndo(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    if (!(window->letterButtonsUsed->empty() || window->lettersUsed->empty()))
    {
        Fl_Button* button = window->letterButtonsUsed->top();
        const char* field = window->lettersUsed->top();
        button->activate();
        string oldValue = window->lettersField->value();
        string newValue = oldValue.substr(0, oldValue.size()-1);
        window->lettersField->value(newValue.c_str());
        window->letterButtonsUsed->pop();
        window->lettersUsed->pop();
    }
    if (window->lettersUsed->size() < 3) {
        window->submitButton->deactivate();
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
    window->startGame();
}

void TextTwistWindow::cbClear(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    if (window->didGameStart) {
        window->resetBoard();
    }
}

void TextTwistWindow::cbSubmit(Fl_Widget* widget, void* data) {
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->submit();
}

void TextTwistWindow::cbDisplaySettings(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    if (window->didGameStart) {
        window->pauseGame();
    }
    SettingsWindow settingsWindow(window->controller->getSettings());
    settingsWindow.set_modal();
    settingsWindow.show();

    while (settingsWindow.shown()) {
        Fl::wait();
    }

    if (settingsWindow.getWindowResult() == OKCancelWindow::WindowResult::OK) {
        window->controller->applySettings();
        if (!window->didGameStart) {
            window->updateTimer();
        }
    }

    if (window->didGameStart) {
       window->resumeGame();
    }
}

void TextTwistWindow::cbDisplayScoreBoard(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    if (window->didGameStart) {
        window->pauseGame();
    }

    ScoreBoardWindow scoreboardWindow(window->controller->getScoreBoard());
    scoreboardWindow.set_modal();
    scoreboardWindow.show();

    while (scoreboardWindow.shown()) {
        Fl::wait();
    }

    if (window->didGameStart) {
       window->resumeGame();
    }
}

void TextTwistWindow::updateTimer() {
    int remainingTime = (this->controller->getDuration() + 1) * 60 * 1000;
    this->timerLabel->copy_label(this->controller->formatTime(remainingTime));
}

void TextTwistWindow::updateTimer(int remainingTime) {
    this->timerLabel->copy_label(this->controller->formatTime(remainingTime));
}

void TextTwistWindow::cbUpdateTimer(Timer* timer, void* data) {
    TextTwistWindow* window = (TextTwistWindow*)data;
    Fl::lock();
    window->updateTimer(timer->getRemainingTime());
    if (!timer->getRunning()) {
        window->endGame();
    }
    Fl::unlock();
    Fl::awake();
}

}

