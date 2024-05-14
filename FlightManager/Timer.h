#pragma once
class Timer
{
private:
	long int addedTime;

public:
	Timer();
	long int getCurrentTime();
	void skipTime(long int addingTime);
};
