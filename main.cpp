#include "TextTwistWindow.h"
using namespace view;


int main (int argc, char ** argv)
{
    const int WIDTH = 540;
    const int HEIGHT = 375;
    TextTwistWindow window(WIDTH, HEIGHT, "Team K Text Twist Game");
    window.show();

    int exitCode = Fl::run();
    return exitCode;
}
