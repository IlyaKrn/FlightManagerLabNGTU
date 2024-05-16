#include "Timer.h"
#include <chrono>
#include <ctime>   
#include <iostream> 
using namespace std;


Timer::Timer()
{
    addedTime = 0;
}

long int Timer::getCurrentTime()
{
    cout << time(0) << endl;
    return time(0) + addedTime;
}

void Timer::skipTime(long int addingTime)
{
    addedTime += addingTime;
}
