#include "TextTwistWindow.h"
using namespace view;


int main (int argc, char ** argv)
{

    TextTwistWindow window(540, 375, "Test");
    window.show();

    int exitCode = Fl::run();
    return exitCode;
}
