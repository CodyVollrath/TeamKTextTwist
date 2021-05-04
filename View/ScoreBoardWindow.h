#ifndef SCOREBOARD_WINDOW_H
#define SCOREBOARD_WINDOW_H

#include <Fl/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <iostream>
#include <sstream>
using namespace std;

#include "OkCancelWindow.h"

#include "ScoreBoard.h"

using namespace model;

namespace view
{
//
// ScoreBoard window for displaying scores and entering new score entries
//
class ScoreBoardWindow : public OKCancelWindow
{
public:
    //
    // Constructs a ScoreBoardWindow for displaying scores
    //
    // @precondition none
    // @postcondition getNameEntry() == ""
    //
    // @param scoreboard the scoreboard to be displayed
    //
    ScoreBoardWindow(ScoreBoard* scoreboard);

    //
    // Constructs a ScoreBoardWindow for displaying scores and entering new score
    //
    // @precondition none
    // @postcondition getNameEntry() == ""
    //
    // @param scoreboard the scoreboard to be displayed
    // @param score the score to be entered
    // @param duration the duration to be entered
    //
    ScoreBoardWindow(ScoreBoard* scoreboard, int score, Score::TIMER_DURATION duration);

    //
    // Destructor of the ScoreBoardWindow
    //
    // @precondition none
    // @postcondition none
    //
    virtual ~ScoreBoardWindow();

    //
    // Closes the window
    //
    // @precondition none
    // @postcondition none
    //
    void okHandler();

    //
    // Closes the window
    //
    // @precondition none
    // @postcondition none
    //
    void cancelHandler();

    //
    // Shows the name entry buttons on window
    //
    // @precondition none
    // @postcondition name entry buttons visible
    //
    //
    void showNameEntry();

    //
    // Returns the name entry
    //
    // @precondition none
    // @postcondition none
    //
    // @return the name entered on window
    //
    string getNameEntry();

private:
    static const int WINDOW_WIDTH = 500;
    static const int WINDOW_HEIGHT = 250;
    static const int X_POS = 155;
    static const int Y_POS = 35;
    static const int Y_DIFF = 45;
    static const int WIDGET_WIDTH = 100;
    static const int WIDGET_HEIGHT = 20;
    void initializeScores();
    Fl_Scroll* scoresScroll;
    Fl_Input* nameEntry;
    Fl_Button* resetButton;
    string submitName;
    ScoreBoard* scoreboard;
    static void cbReset(Fl_Widget* widget, void* data);
};
}



#endif // SCOREBOARD_WINDOW_H
