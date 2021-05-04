
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
class ScoreBoardWindow : public OKCancelWindow
{
    public:
        ScoreBoardWindow(ScoreBoard* scoreboard);
        ScoreBoardWindow(ScoreBoard* scoreboard, int score, Score::TIMER_DURATION duration);
        virtual ~ScoreBoardWindow();

        void okHandler();
        void cancelHandler();

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
        Score* submitScore;
        ScoreBoard* scoreboard;
};
}



#endif // SCOREBOARD_WINDOW_H
