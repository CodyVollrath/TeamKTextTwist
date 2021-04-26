#include "TextTwistWindow.h"
using namespace view;



int main (int argc, char ** argv)
{
    //TODO MOVE this to controller
    string letters[] = {"d", "e", "f", "a", "u", "l", "t"};

    //TODO Remove the parameter for the window and have the controller in the itself.
    TextTwistWindow window(540, 375, "Test", letters);
    window.show();

    int exitCode = Fl::run();
    return exitCode;
}
