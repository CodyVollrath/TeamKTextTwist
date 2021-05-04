#ifndef OKCANCELWINDOW_H
#define OKCANCELWINDOW_H


#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

namespace view
{

/**
* OkCancelWindow is an abstract class that will be derived for any modal like window in the application
* @author UWG CS Department
*/
class OKCancelWindow : public Fl_Window
{
public:
    enum WindowResult {OK, CANCEL, NONE};

protected:
    Fl_Button* okButton;
    Fl_Button* cancelButton;

private:
    WindowResult buttonInvoked;

public:
    /**
    * Creates an ok cancel window
    * @param width the width of the window
    * @param height the height of the window
    * @param title the title of the window
    */
    OKCancelWindow(int width, int height, const char* title);

    /**
    * Destroys the cancel window
    */
    virtual ~OKCancelWindow();

    /**
    * Sets the location of the OK button
    * @param x the x cord
    * @param y the y cord
    */
    void setOKLocation(int x, int y);

    /**
    * Sets the location of the Cancel button
    * @param x the x cord
    * @param y the y cord
    */
    void setCancelLocation(int x, int y);

    /**
    * the call back for the OK button
    */
    static void cbOk(Fl_Widget* widget, void* data);

    /**
    * The handler for OK
    */
    virtual void okHandler() = 0;

    /**
    * The call back for the cancel button
    */
    static void cbCancel(Fl_Widget* widget, void* data);

    /**
    The handler for Cancel
    */
    virtual void cancelHandler() = 0;

    /**
    * Sets the window result
    * @param result the result of the window
    * @post getWindowResult() == result
    * @return the window result
    */
    OKCancelWindow::WindowResult setWindowResult(OKCancelWindow::WindowResult result);

    /**
    * Gets the window result
    * @param result the result of the window
    */
    OKCancelWindow::WindowResult getWindowResult();
};

}

#endif // OKCANCELWINDOW_H
