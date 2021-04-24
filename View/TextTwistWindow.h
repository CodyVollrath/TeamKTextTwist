#ifndef TEXTTWISTWINDOW_H
#define TEXTTWISTWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>

#include <string>
#include <iostream>
using namespace std;

namespace view
{
class TextTwistWindow : public Fl_Window
{
    public:
        TextTwistWindow(int width, int height, const char* title, string* letters);
        virtual ~TextTwistWindow();
        void placeLetters(char* letters);

    protected:

    private:
        static const int MAX_LETTER_LENGTH = 7;
        static const int SIDE_LENGTH_OF_BUTTON = 45;
        static const int LETTERS_X_POS = 95;
        static const int LETTERS_Y_POS = 250;

        Fl_Button* letterButtons[MAX_LETTER_LENGTH];
        string* letters;

        void initializeLetterButtons();
        void initializeLetterFields();

};
}

#endif // TEXTTWISTWINDOW_H
