
#include "ScoreBoardWindow.h"

namespace view {

    ScoreBoardWindow::ScoreBoardWindow(ScoreBoard* scoreboard) : OKCancelWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, "Scoreboard") {
        this->submitScore = 0;
        this->nameEntry = 0;
        this->scoreboard = scoreboard;
        begin();

        this->scoresScroll = new Fl_Scroll(50,50,this->WINDOW_WIDTH - 100, 100,"");
        this->initializeScores();
        this->scoresScroll->end();

        this->okButton->clear_visible();
        this->cancelButton->clear_visible();
        end();
    }

    ScoreBoardWindow::ScoreBoardWindow(ScoreBoard* scoreboard, int score, Score::TIMER_DURATION duration) : OKCancelWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, "Scoreboard") {

        this->submitScore = new Score("", score, duration);
        this->scoreboard = scoreboard;
        begin();


        this->scoresScroll = new Fl_Scroll(50,20,200, 100,"");
        this->initializeScores();
        this->scoresScroll->end();

        this->nameEntry = new Fl_Input(100,this->WINDOW_HEIGHT  - 80,200, 25,"Name");

        this->setOKLocation(this->WINDOW_HEIGHT - 100, this->WINDOW_HEIGHT - 50);
        this->setCancelLocation(this->WINDOW_HEIGHT, this->WINDOW_HEIGHT - 50);

        end();
    }

    ScoreBoardWindow::~ScoreBoardWindow() {
        delete this->scoresScroll;
        delete this->nameEntry;
    }

    void ScoreBoardWindow::okHandler(){
        if (this->submitScore) {
            string name = this->nameEntry->value();
            this->submitScore->setName(name);
            this->scoreboard->insert(this->submitScore);
        }
        this->hide();
    }
    void ScoreBoardWindow::cancelHandler(){
        delete this->submitScore;
        this->hide();
    }

    void ScoreBoardWindow::initializeScores(){
        vector<Score*>* scores = this->scoreboard->getScores();
        int accumulator = 0;
        for (Score* score : *scores) {
            Fl_Box* scoreBox = new Fl_Box(50,  50 + accumulator, this->WINDOW_WIDTH - 100, 25, "");
            stringstream ss;
            ss <<  "Name: "<< score->getName() << " : Score: " << score->getScore() << " : Duration: " << (score->getDuration() + 1) << " mins";
            scoreBox->copy_label(ss.str().c_str());
            accumulator += 25;
            cout << scoreBox->label() << endl;
        }
    }
}

