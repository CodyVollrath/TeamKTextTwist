#include "TextTwistWindow.h"
using namespace view;



int main (int argc, char ** argv)
{
    string letters[] = {"d", "e", "f", "a", "u", "l", "t"};
    TextTwistWindow window(540, 375, "Test", letters);
    window.show();

    int exitCode = Fl::run();
    return exitCode;
}
