#include "ScoreBoardWindow.h"

namespace view
{

ScoreBoardWindow::ScoreBoardWindow(ScoreBoard* scoreboard) : OKCancelWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, "Scoreboard")
{
    this->submitName = "";
    this->scoreboard = scoreboard;
    begin();

    this->scoresScroll = new Fl_Scroll(50,50,this->WINDOW_WIDTH - 100, 100,"");
    this->scoresScroll->end();

    this->initializeScores();

    this->nameEntry = new Fl_Input(100,this->WINDOW_HEIGHT  - 80,200, 25,"Name");

    this->resetButton = new Fl_Button(100,this->WINDOW_HEIGHT  - 80, 100, 25, "Reset");
    this->resetButton->callback(cbReset,this);

    this->setOKLocation(this->WINDOW_HEIGHT - 100, this->WINDOW_HEIGHT - 50);
    this->setCancelLocation(this->WINDOW_HEIGHT, this->WINDOW_HEIGHT - 50);

    this->okButton->clear_visible();
    this->cancelButton->clear_visible();
    this->nameEntry->clear_visible();
    end();
}

ScoreBoardWindow::~ScoreBoardWindow()
{
    delete this->scoresScroll;
    delete this->nameEntry;
}

void ScoreBoardWindow::okHandler()
{
    this->hide();
}

void ScoreBoardWindow::cancelHandler()
{
    this->hide();
}

void ScoreBoardWindow::showNameEntry()
{
    this->nameEntry->set_visible();
    this->okButton->set_visible();
    this->cancelButton->set_visible();
    this->resetButton->clear_visible();
}

string ScoreBoardWindow::getNameEntry()
{
    return this->nameEntry->value();
}

void ScoreBoardWindow::initializeScores()
{
    vector<Score*>* scores = this->scoreboard->getScores();
    int accumulator = 0;
    this->scoresScroll->clear();
    this->scoresScroll->begin();
    for (Score* score : *scores)
    {
        Fl_Box* scoreBox = new Fl_Box(50,  50 + accumulator, this->WINDOW_WIDTH - 100, 25, "");
        stringstream ss;
        int durationInMinutes = (score->getDuration() + 1);
        ss <<  "Name: "<< score->getName() << " : Score: " << score->getScore() << " : Duration: " << durationInMinutes << " mins";
        scoreBox->copy_label(ss.str().c_str());
        accumulator += 25;
    }
    this->scoresScroll->end();
    this->scoresScroll->redraw();
}

void ScoreBoardWindow::cbReset(Fl_Widget* widget, void* data)
{
    ScoreBoardWindow* window = (ScoreBoardWindow*) data;
    window->scoreboard->reset();
    window->initializeScores();
}
}

