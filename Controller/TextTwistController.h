#ifndef TEXT_TWIST_CONTROLLER_H
#define TEXT_TWIST_CONTROLLER_H

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <set>
using namespace std;

#include "TextTwister.h"
#include "Timer.h"
#include "Settings.h"
#include "ScoreBoard.h"
using namespace model;


namespace controller
{
//
// TextTwist game controller for MVC pattern
//
class TextTwistController
{

public:
    //
    // Constructs a TextTwistController object
    //
    // @precondition none
    // @postcondition getAnswers() == nullptr;
    //                getSettings() != nullptr
    //                getScoreBoard() != nullptr;
    //
    TextTwistController();

    //
    // Destructs the TextTwistController object
    //
    // @precondition none
    // @postcondition none
    //
    virtual ~TextTwistController();

    //
    // Constructs a InterlacedRoster object
    //
    // @precondition none
    // @postcondition getHeader() != 0
    //
    void startGame();

    //
    // Pauses the game
    //
    // @precondition none
    // @postcondition none
    //
    void pauseGame();

    //
    // Resumes the game
    //
    // @precondition none
    // @postcondition none
    //
    void resumeGame();

    //
    // Twists the letters randomly
    //
    // @precondition none
    // @postcondition the order of getLetters() is randomized
    //
    void twist();

    //
    // Constructs a InterlacedRoster object
    //
    // @precondition none
    // @postcondition none

    // @param name Name of the player
    //
    void addScore(string name);

    //
    // Submits the letters given, and adds appropriate score
    //
    // @precondition none
    // @postcondition score is added based on game rules

    // @param letters Letters to be submitted
    //
    string submit(string letters);

    //
    // Sets the duration of the game
    //
    // @precondition none
    // @postcondition getDuration() == duration

    // @param duration duration of the game
    //
    void setDuration(Score::TIMER_DURATION duration);

    //
    // Binds the timer's interval callback
    //
    // @precondition none
    // @postcondition none
    //
    // @param callback callback function of the timer
    // @param data object to be passed to callback
    void bindTimer(void(*callback)(Timer*, void*), void* data);

    //
    // Applies the current settings to the game
    //
    // @precondition none
    // @postcondition duration and scoreboard sort order are updated
    //
    void applySettings();

    //
    // Formats the number of milliseconds into format:
    // MM:SS:MS
    //
    // @precondition none
    // @postcondition none
    //
    // @return the formatted time
    char* formatTime(int milliseconds) const;


    //
    // Returns whether letters are reusable based on settings
    //
    // @precondition none
    // @postcondition none
    //
    // @return whether letters are reusable based on settings
    bool areLettersReusable() const;


    // Gets the settings
    //
    // @precondition none
    // @postcondition none
    //
    // @return the settings
    Settings* getSettings();

    // Gets the scoreboard
    //
    // @precondition none
    // @postcondition none
    //
    // @return the scoreboard
    ScoreBoard* getScoreBoard();

    // Gets the duration
    //
    // @precondition none
    // @postcondition none
    //
    // @return the duration
    Score::TIMER_DURATION getDuration();

    // Gets the current letters possible answers
    //
    // @precondition none
    // @postcondition none
    //
    // @return the current letters possible answers
    unordered_set<string>* displayAllPossibleWords(string& word);

    // Gets the used words
    //
    // @precondition none
    // @postcondition none
    //
    // @return the used words
    unordered_set<string>* getUsedWords();

    // Gets the chosen letters
    //
    // @precondition none
    // @postcondition none
    //
    // @return the chosen letters
    string* getLetters();

    //
    // Gets the current score
    //
    // @precondition none
    // @postcondition getHeader() != 0
    //
    // @return the current score
    int getScore();



private:
    TextTwister* twister;
    Timer* timer;
    Settings* settings;
    ScoreBoard* scoreboard;
    unordered_set<string>* answers;


};

}


#endif // TEXT_TWIST_CONTROLLER_H
