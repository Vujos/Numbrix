#ifndef TIMER_H
#define TIMER_H

#include <string>

using namespace std;

class Timer
{
    public:
        Timer();
        string CurrentTime();
        string time;
    private:
        int second;
        int minut;
        int hour;
};

#endif // TIMER_H
