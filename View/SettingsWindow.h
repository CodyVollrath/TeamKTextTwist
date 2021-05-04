#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include "OkCancelWindow.h"

#include <Fl/Fl_Choice.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Check_Button.H>

#include <iostream>
using namespace std;

#include "Settings.h"
using namespace model;

namespace view
{
class SettingsWindow : public OKCancelWindow
{
public:
    SettingsWindow(Settings* settings);
    virtual ~SettingsWindow();
    void okHandler();
    void cancelHandler();
    Settings* getSettings() const;

private:
    Fl_Choice* timerSettings;
    Fl_Choice* highScoreSort;
    Fl_Check_Button* allowReuse;
    static const int WINDOW_WIDTH = 500;
    static const int WINDOW_HEIGHT = 250;
    static const int X_POS = 155;
    static const int Y_POS = 35;
    static const int Y_DIFF = 45;
    static const int WIDGET_WIDTH = 100;
    static const int WIDGET_HEIGHT = 20;
    void initializeTimeOptions();
    void initializeSortOptions();
    void initializeReusableOption();
    Settings* settings;
};
}



#endif // SETTINGSWINDOW_H
