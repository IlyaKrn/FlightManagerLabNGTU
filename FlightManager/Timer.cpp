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
    cout << addedTime << endl;
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() + addedTime;
}

void Timer::skipTime(long int addingTime)
{
    addedTime += addingTime;
}
