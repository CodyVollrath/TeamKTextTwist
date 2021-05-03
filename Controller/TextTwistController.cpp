#include "TextTwistController.h"
namespace controller
{

TextTwistController::TextTwistController()
{
    this->twister = new TextTwister();
    this->timer = new Timer(100);
    this->settings = new Settings();
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

void TextTwistController::changeSettings(Settings* newSettings) {
    this->settings->setTimeInMinutes(newSettings->getTimeInMinutes());
    this->settings->setSortOption(newSettings->getSortOption());
    this->settings->setReusableFlag(newSettings->getReusableFlag());
    this->applySettings();
}

void TextTwistController::applySettings()
{
    this->setDuration(this->settings->getTimeInMinutes());
    //Put score sort in for the scoreboard object
    //Change state for allowCharacterReuse
    cout << this->settings->getTimeInMinutes() << "" << this->settings->getSortOption() << "" << this->settings->getReusableFlag()<< endl;
}

char* TextTwistController::getTime() const
{
    int minutes = this->settings->getTimeInMinutes();
    chrono::milliseconds remainingTime = chrono::milliseconds(minutes * 60 * 1000);
    return this->getTime(remainingTime);
}

char* TextTwistController::getTime(chrono::milliseconds remainingTime) const
{
    chrono::seconds secs = chrono::duration_cast<chrono::seconds>(remainingTime);
    chrono::milliseconds ms = remainingTime - chrono::duration_cast<chrono::milliseconds>(secs);

    chrono::minutes mins = chrono::duration_cast<chrono::minutes>(secs);
    secs -= chrono::duration_cast<chrono::seconds>(mins);

    chrono::hours hour = chrono::duration_cast<chrono::hours>(mins);
    mins -= chrono::duration_cast<chrono::minutes>(hour);

    stringstream ss;
    ss <<  setw(1) << setfill('0') << mins.count();
    ss << ":";
    ss <<  setw(2) << setfill('0') << secs.count();
    ss << ":";
    ss <<  setw(3) << setfill('0') << ms.count();
    return const_cast<char*>(ss.str().c_str());
}
}
