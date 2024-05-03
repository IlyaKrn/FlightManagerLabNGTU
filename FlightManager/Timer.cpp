#include "Timer.h"
#include <chrono>
#include <ctime>   
using namespace std;

long int Timer::getCurrentTime()
{
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() + addedTime;
}
