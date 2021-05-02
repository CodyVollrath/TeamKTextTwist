#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

namespace model
{
class Timer
{

    public:
        Timer(int updateInterval);
        virtual ~Timer();
        void setDuration(int duration);
        void setCallback(void(*callback)(void*,chrono::milliseconds,bool), void* caller);
        void start();
        void stop();
        void resume();
        void pause();
        bool getRunning();

    private:
        bool running;
        int remainingTime;
        int duration;
        int updateInterval;
        bool threadActive;
        void* caller;
        void(*callback)(void*,chrono::milliseconds,bool);
        static void updater(Timer* timer);

};

}


#endif // TIMER_H
