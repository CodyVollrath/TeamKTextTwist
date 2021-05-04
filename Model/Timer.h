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
        void setCallback(void(*callback)(Timer*, void*), void*);
        void start();
        void stop();
        void resume();
        void pause();
        bool getRunning();
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
