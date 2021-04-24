#include "TextTwistWindow.h"
using namespace view;



int main (int argc, char ** argv)
{
    char* letters = "gasrtyi";

    TextTwistWindow window(540, 375, "Test", letters);
    window.show();

    int exitCode = Fl::run();
    return exitCode;
}
