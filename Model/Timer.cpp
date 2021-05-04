#include "Timer.h"

namespace model
{


Timer::Timer(int updateInterval)
{
    this->callback = 0;
    this->caller = 0;
    this->updateInterval = updateInterval;
    this->duration = 60000;
    this->running = false;
    this->remainingTime = 0;
    this->threadActive = false;
}
Timer::~Timer()
{

}

void Timer::setCallback(void(*callback)(void*,chrono::milliseconds,bool), void* caller){
    this->callback = callback;
    this->caller = caller;
}

void Timer::setDuration(int duration)
{
    this->duration = duration;
}

void Timer::updater(Timer* timer)
{
    if (timer->threadActive) {
        return;
    }
    timer->threadActive = true;
    while(true)
    {
        if (!timer->running) break;

        this_thread::sleep_for (chrono::milliseconds(timer->updateInterval));
        timer->remainingTime -= timer->updateInterval;

        if (!timer->running) break;

        if (timer->remainingTime <= 0) {
            timer->running = false;
        }
        if (timer->callback) {
            timer->callback(timer->caller, chrono::milliseconds(timer->remainingTime), timer->running);
        }
    }
    timer->threadActive = false;
}

bool Timer::getRunning()
{
    return this->running;
}

void Timer::start()
{
    this->remainingTime = this->duration;
    this->resume();

}
void Timer::stop()
{
    this->remainingTime = this->duration;
    this->running = false;
}
void Timer::resume()
{
    this->running = true;
    thread update(updater, this);
    update.detach();
}
void Timer::pause()
{
    this->running = false;
}

}
