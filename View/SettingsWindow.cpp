 #include "SettingsWindow.h"
namespace view
{
SettingsWindow::SettingsWindow() : OKCancelWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, "Settings")
{
    begin();
    this->timerSettings = new Fl_Choice(this->X_POS, this->Y_POS, this->WIDGET_WIDTH, this->WIDGET_HEIGHT, "Timer:");
    this->highScoreSort = new Fl_Choice(this->X_POS, this->Y_POS + this->Y_DIFF, this->WIDGET_WIDTH, this->WIDGET_HEIGHT, "Score Sort:");
    this->allowReuse = new Fl_Check_Button(this->X_POS, this->Y_POS + 2 * this->Y_DIFF, this->WIDGET_WIDTH, this->WIDGET_HEIGHT, "Allow characters to be reused");
    this->setOKLocation(this->WINDOW_HEIGHT - 100, this->WINDOW_HEIGHT - 50);
    this->setCancelLocation(this->WINDOW_HEIGHT, this->WINDOW_HEIGHT - 50);
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
    cout << "Ok Handler" << endl;
    this->hide();
}

void SettingsWindow::cancelHandler()
{
    cout << "Cancel Handler" << endl;
    this->hide();
}
}

