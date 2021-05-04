#include "TextTwistController.h"
namespace controller
{

TextTwistController::TextTwistController()
{
    this->twister = new TextTwister();
    this->timer = new Timer(100);
    this->settings = new Settings();
    this->scoreboard = new ScoreBoard();
    this->applySettings();
}
TextTwistController::~TextTwistController()
{
    delete this->twister;
    delete this->timer;
    delete this->settings;
    delete this->scoreboard ;
}

void TextTwistController::startGame()
{
    this->timer->start();
    this->twister->start();
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

ScoreBoard* TextTwistController::getScoreBoard(){
    return this->scoreboard;
}

string* TextTwistController::getLetters()
{
    return this->twister->getLetters();
}

Settings* TextTwistController::getSettings() {
    return this->settings;
}

void TextTwistController::setDuration(Score::TIMER_DURATION duration)
{
    this->timer->setDuration((duration + 1) * 60 * 1000);
}


string TextTwistController::submit(string* letters) {
    return this->twister->submit(letters);
}

void TextTwistController::addScore(string name) {
    Score* submitScore = new Score(name, this->twister->getScore(), this->settings->getDuration());
    this->scoreboard->insert(submitScore);
}

int TextTwistController::getScore()
{
    return this->twister->getScore();
}

Score::TIMER_DURATION TextTwistController::getDuration()
{
    return this->settings->getDuration();
}

set<string>* TextTwistController::getUsedWords()
{
    return this->twister->getUsedWords();
}

void TextTwistController::bindTimer(void(*callback)(Timer*, void*), void* data) {
    this->timer->setCallback(callback, data);
}

void TextTwistController::applySettings()
{
    this->setDuration(this->settings->getDuration());
    this->scoreboard->setOrder(this->settings->getSortOption());
    //Change state for allowCharacterReuse
}

char* TextTwistController::formatTime(int milliseconds) const
{
    chrono::milliseconds remainingTime = chrono::milliseconds(milliseconds);
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
    ss <<  setw(2) << setfill('0') << ms.count() / 10;
    return const_cast<char*>(ss.str().c_str());
}


}
