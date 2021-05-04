#ifndef SOLUTIONSWINDOW_H
#define SOLUTIONSWINDOW_H
#include "OkCancelWindow.h"
#include <Fl/Fl_Scroll.H>
#include <Fl/Fl_Box.H>


#include <unordered_set>
#include <string>
using namespace std;

namespace view
{
//
// SolutionsWindow window for displaying game solution
//

class SolutionsWindow : public OKCancelWindow
{
public:
    //
    // Constructs a ScoreBoardWindow for displaying scores
    //
    // @precondition none
    // @postcondition none
    //
    // @param width the width of the window
    // @param height the height of the window
    // @param title the title of the window
    //
    SolutionsWindow(unordered_set<string>* solutions);

    //
    // Destructor of the SolutionsWindow
    //
    // @precondition none
    // @postcondition none
    //
    virtual ~SolutionsWindow();

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

protected:

private:
    static const int WINDOW_WIDTH = 500;
    static const int WINDOW_HEIGHT = 250;
    Fl_Scroll* solutionsScroll;
    void addSolutions(unordered_set<string>* solutions);
};
}


#endif // SOLUTIONSWINDOW_H
