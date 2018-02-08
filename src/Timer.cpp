#include "Timer.h"

Timer::Timer()
{
    time = "00:00:00";
    second = 0;
    minut = 0;
    hour = 0;
}

string Timer::CurrentTime(){
    second++;
    if(second == 61){
        second = 0;
        minut++;
    }if(minut == 61){
        minut = 0;
        hour++;
    }
    if(hour > 9){
        time = to_string(hour) + ":";
    }else{
        time = "0" + to_string(hour) + ":";
    }
    if(minut > 9){
        time = time + to_string(minut) + ":";
    }else{
        time = time + "0" + to_string(minut) + ":";
    }
    if (second > 9){
        time = time + to_string(second);
    }else{
        time = time + "0" + to_string(second);
    }
    return time;
}
