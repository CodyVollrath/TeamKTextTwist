#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

namespace model
{
/**
* Keeps track of the time to complete the puzzle
* @author Furichous Jones
*/
class Timer
{

public:
    /**
    * Creates the Timer
    * @param updateInterval the interval to be appended to the time
    */
    Timer(int updateInterval);

    /**
    * Destroys the timer object
    */
    virtual ~Timer();

    /**
    * Sets the duration
    * @param duration the duration to be given to the timer
    */
    void setDuration(int duration);

    /**
    * Sets the call back
    * @param callback function the call back function to be set
    * @param data to be added
    */
    void setCallback(void(*callback)(Timer*, void*), void* data);

    /**
    * Starts the timer
    */
    void start();

    /**
    * Stops the timer
    */
    void stop();

    /**
    * Resumes the timer
    */
    void resume();

    /**
    * Pauses the timer
    */
    void pause();

    /**
    * Gets the running flag
    * @return true if running, false otherwise
    */
    bool getRunning();

    /**
    * Get the remaining time
    * @return the remaining time
    */
    int getRemainingTime();

private:
    bool running;
    int remainingTime;
    int duration;
    int updateInterval;
    bool threadActive;
    void* data;
    void(*callback)(Timer*, void*);
    static void updater(Timer* timer);

};

}


#endif // TIMER_H
