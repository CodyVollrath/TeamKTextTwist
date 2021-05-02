#include "TextTwistController.h"
namespace controller
{

TextTwistController::TextTwistController()
{
    this->twister = new TextTwister();
    this->timer = new Timer(100);
    //TODO Load settings from file
    this->settings = new Settings(1, 0, false);
    this->applySettings();
}
TextTwistController::~TextTwistController()
{
    delete this->twister;
    delete this->timer;
    delete this->settings;
}

void TextTwistController::startGame()
{
    this->timer->start();
    this->twister->generate();
}

void TextTwistController::pauseGame()
{
    this->timer->pause();
}

void TextTwistController::resumeGame()
{
    this->timer->resume();
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

void TextTwistController::setDuration(int duration)
{
    this->timer->setDuration(duration*60*1000);
}


string TextTwistController::submit(string* letters) {
    return this->twister->submit(letters);
}

int TextTwistController::getScore()
{
    return this->twister->getScore();
}

void TextTwistController::bindTimer(void(*callback)(void*,chrono::milliseconds,bool), void* caller) {
    this->timer->setCallback(callback, caller);
}

void TextTwistController::changeSettings(Settings* settings) {
    this->settings->setTimeInMinutes(settings->getTimeInMinutes());
    this->settings->setSortOption(settings->getSortOption());
    this->settings->setReusableFlag(settings->getReusableFlag());
    this->applySettings();
}

void TextTwistController::applySettings()
{
    //Put time in minutes into timer
    //Put score sort in for the scoreboard object
    //Change state for allowCharacterReuse
    cout << this->settings->getTimeInMinutes() << "" << this->settings->getSortOption() << "" << this->settings->getReusableFlag()<< endl;
}

}
