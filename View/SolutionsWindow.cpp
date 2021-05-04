#include "SolutionsWindow.h"
namespace view
{
SolutionsWindow::SolutionsWindow(unordered_set<string>* solutions) : OKCancelWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, "Solutions")
{
    begin();
    this->solutionsScroll = new Fl_Scroll(50,50,this->WINDOW_WIDTH - 100, 100,"");
    this->solutionsScroll->end();
    this->addSolutions(solutions);
        this->setOKLocation(this->WINDOW_HEIGHT - 100, this->WINDOW_HEIGHT - 50);
    this->setCancelLocation(this->WINDOW_HEIGHT, this->WINDOW_HEIGHT - 50);this->setOKLocation(this->WINDOW_HEIGHT - 100, this->WINDOW_HEIGHT - 50);
    this->setCancelLocation(this->WINDOW_HEIGHT, this->WINDOW_HEIGHT - 50);
    end();
}

SolutionsWindow::~SolutionsWindow()
{
    //dtor
}

void SolutionsWindow::addSolutions(unordered_set<string>* solutions)
{

    int accumulator = 0;
    this->solutionsScroll->clear();
    this->solutionsScroll->begin();
    unordered_set<string>::iterator it = solutions->begin();
    while (it != solutions->end()) {
        Fl_Box* scoreBox = new Fl_Box(50,  50 + accumulator, this->WINDOW_WIDTH - 100, 25, "");
        string word = *it;
        scoreBox->copy_label(word.c_str());
        accumulator += 25;
        it++;
    }
    this->solutionsScroll->end();
    this->solutionsScroll->redraw();
}

void SolutionsWindow::okHandler(){
    this->hide();
}

void SolutionsWindow::cancelHandler(){
    this->hide();
}
}

