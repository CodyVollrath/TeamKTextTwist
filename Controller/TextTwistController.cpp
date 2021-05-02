#include "TextTwistController.h"
namespace controller
{

TextTwistController::TextTwistController()
{
    this->twister = new TextTwister();
    this->timer = new Timer(100);
}
TextTwistController::~TextTwistController()
{
    delete this->twister;
    delete this->timer;
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

}
