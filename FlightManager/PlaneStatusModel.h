#pragma once
#include"CoordinateModel.h"

class PlaneStatusModel
{
private:
	int _planeId;
	CoordinateModel _currentCoordinates;
	long int _totalTime;
	long int _timeLeft;
public:
	PlaneStatusModel(int planeId, CoordinateModel currentCoordinates, long int totalTime, long int timeLeft);
	PlaneStatusModel();

	int getPlaneId();
	CoordinateModel getCurrentCoordinates();
	long int getTotalTime();
	long int getTimeLeft();
	
	void setPlaneId(int planeId);
	void setCurrentCoordinates(CoordinateModel currentCoordinates);
	void setTotalTime(long int totalTime);
	void setTimeLeft(long int timeLeft);
};

