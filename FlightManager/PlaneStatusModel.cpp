#include "PlaneStatusModel.h"

PlaneStatusModel::PlaneStatusModel(int planeId, CoordinateModel currentCoordinates, long int totalTime, long int timeLeft)
{
	_planeId = planeId;
	_currentCoordinates = currentCoordinates;
	_totalTime = totalTime;
	_timeLeft = timeLeft;
}

PlaneStatusModel::PlaneStatusModel() = default;

int PlaneStatusModel::getPlaneId()
{
	return _planeId;
}

CoordinateModel PlaneStatusModel::getCurrentCoordinates()
{
	return _currentCoordinates;
}

long int PlaneStatusModel::getTotalTime()
{
	return _totalTime;
}

long int PlaneStatusModel::getTimeLeft()
{
	return _timeLeft;
}

void PlaneStatusModel::setPlaneId(int planeId)
{
	_planeId = planeId;
}

void PlaneStatusModel::setCurrentCoordinates(CoordinateModel currentCoordinates)
{
	_currentCoordinates = currentCoordinates;
}

void PlaneStatusModel::setTotalTime(long int totalTime)
{
	_totalTime = totalTime;
}

void PlaneStatusModel::setTimeLeft(long int timeLeft)
{
	_timeLeft = timeLeft;
}
