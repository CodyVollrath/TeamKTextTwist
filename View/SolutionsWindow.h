#ifndef SOLUTIONSWINDOW_H
#define SOLUTIONSWINDOW_H
#include "OkCancelWindow.h"
#include <Fl/Fl_Scroll.H>
#include <Fl/Fl_Box.H>


#include <set>
#include <string>
using namespace std;

namespace view
{
class SolutionsWindow : public OKCancelWindow
{
    public:
        SolutionsWindow(set<string>* solutions);
        virtual ~SolutionsWindow();
        void addSolutions(set<string>* solutions);
        void okHandler();
        void cancelHandler();

    protected:

    private:
        static const int WINDOW_WIDTH = 500;
        static const int WINDOW_HEIGHT = 250;
        Fl_Scroll* solutionsScroll;
};
}


#endif // SOLUTIONSWINDOW_H
