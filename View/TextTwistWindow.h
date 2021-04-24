#ifndef TEXTTWISTWINDOW_H
#define TEXTTWISTWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Input.H>

#include <string>
#include <iostream>
#include <stack>
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
        Fl_Input* letterFields[MAX_LETTER_LENGTH];
        Fl_Button* undoButton;
        Fl_Button* twistButton;

        stack<Fl_Button*>* letterButtonsUsed;
        stack<Fl_Input*>* letterFieldsUsed;

        string* letters;
        void initializeBoardElements();
        void establishCallBacks();
        void placeLetterToNextEmptyField(const char* letter);

        static void cbSendLetterToField(Fl_Widget* widget, void* data);
        static void cbUndo(Fl_Widget* widget, void* data);
};
}
#endif // TEXTTWISTWINDOW_H
