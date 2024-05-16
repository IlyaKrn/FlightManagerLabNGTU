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
    return time(0) + addedTime;
}

void Timer::skipTime(long int addingTime)
{
    addedTime += addingTime;
}
