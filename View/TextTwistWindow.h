#ifndef TEXT_TWIST_WINDOW_H
#define TEXT_TWIST_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>

#include "SettingsWindow.h"

#include <string>
#include <iostream>
#include <stack>
using namespace std;

#include "TextTwistController.h"
using namespace controller;


namespace view
{


class TextTwistWindow : public Fl_Window
{
    public:
        TextTwistWindow(int width, int height, const char* title);
        virtual ~TextTwistWindow();
        void resetBoard();

    protected:

    private:
        static const int BUTTON_WIDTH = 100;
        static const int BUTTON_HIGHT = 30;

        static const int Y_POS_DIF = 35;
        static const int LEFT_BUTTON_POS = 25;

        static const int SIDE_LENGTH_OF_LETTER_BUTTON = 45;
        static const int LETTERS_X_POS = 95;
        static const int LETTERS_Y_POS = 250;

        static const int TIME_LABEL_X_POS = 250;
        static const int TIME_LABEL_Y_POS = 25;
        static const int TIME_LABEL_SIDE_LENGTH = 25;

        static const int SUBMIT_BUTTON_X_POS = 220;
        static const int SUBMIT_BUTTON_Y_POS = 325;
        static const int SETTINGS_BUTTON_X_POS = 400;

        bool didGameStart = false;


        Fl_Button* letterButtons[TextTwister::MAX_LETTER_LENGTH];
        Fl_Input* letterFields[TextTwister::MAX_LETTER_LENGTH];

        Fl_Button* undoButton;
        Fl_Button* twistButton;
        Fl_Button* generateButton;
        Fl_Button* submitButton;
        Fl_Button* settingsButton;
        Fl_Box* timerLabel;
        Fl_Box* scoreLabel;

        stack<Fl_Button*>* letterButtonsUsed;
        stack<Fl_Input*>* letterFieldsUsed;

        TextTwistController* controller;

        void initializeBoardElements();
        void establishCallBacks();
        void placeLetterToNextEmptyField(const char* letter);
        void submit();
        string* getSelectedLetters();
        void updateScore();

        static void cbSendLetterToField(Fl_Widget* widget, void* data);
        static void cbUndo(Fl_Widget* widget, void* data);
        static void cbGenerate(Fl_Widget* widget, void* data);
        static void cbTwist(Fl_Widget* widget, void* data);
        static void cbSubmit(Fl_Widget* widget, void* data);
        static void cbDisplaySettings(Fl_Widget* widget, void* data);
};
}
#endif // TEXT_TWIST_WINDOW_H
