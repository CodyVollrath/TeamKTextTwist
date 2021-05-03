 #include "SettingsWindow.h"
namespace view
{
SettingsWindow::SettingsWindow() : OKCancelWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, "Settings")
{
    begin();
    this->timerSettings = new Fl_Choice(this->X_POS, this->Y_POS, this->WIDGET_WIDTH, this->WIDGET_HEIGHT, "Timer:");
    this->highScoreSort = new Fl_Choice(this->X_POS, this->Y_POS + this->Y_DIFF, this->WIDGET_WIDTH + 100, this->WIDGET_HEIGHT, "Score Sort:");
    this->initializeTimeOptions();
    this->initializeSortOptions();
    this->allowReuse = new Fl_Check_Button(this->X_POS, this->Y_POS + 2 * this->Y_DIFF, this->WIDGET_WIDTH, this->WIDGET_HEIGHT, "Allow characters to be reused");
    this->setOKLocation(this->WINDOW_HEIGHT - 100, this->WINDOW_HEIGHT - 50);
    this->setCancelLocation(this->WINDOW_HEIGHT, this->WINDOW_HEIGHT - 50);
    this->settings = 0;
    end();

}

SettingsWindow::~SettingsWindow()
{
    delete this->timerSettings;
    delete this->highScoreSort;
    delete this->allowReuse;
}

void SettingsWindow::okHandler()
{
    if (this->settings) {
        delete this->settings;
    }
    int timeInMinutes = this->timerSettings->value() + 1;
    int sortOption = this->highScoreSort->value();
    bool isReusable = this->allowReuse->value();
    this->settings = new Settings(timeInMinutes, sortOption, isReusable);
    this->settings->saveSettings();
    this->hide();
}

void SettingsWindow::cancelHandler()
{
    if (this->settings) {
        delete this->settings;
    }
    this->settings = 0;
    this->hide();
}

Settings* SettingsWindow::getSettings() const
{
    return this->settings;
}


void SettingsWindow::initializeTimeOptions()
{
    this->timerSettings->add("1 Minute");
    this->timerSettings->add("2 Minutes");
    this->timerSettings->add("3 Minutes");
    this->timerSettings->value(0);
}

void SettingsWindow::initializeSortOptions()
{
    this->highScoreSort->add("Overall Score");
    this->highScoreSort->add("Score & Time");
    this->highScoreSort->value(0);
}
}
