#include "Timer.h"
#include <chrono>
#include <ctime>   
using namespace std;


Timer::Timer()
{
    addedTime = 0;
}

long int Timer::getCurrentTime()
{
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() + addedTime;
}

void Timer::skipTime(long int addingTime)
{
    addedTime += addingTime;
}
