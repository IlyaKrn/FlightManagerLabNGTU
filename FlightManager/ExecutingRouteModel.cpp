#include "ExecutingRouteModel.h"

int ExecutingRouteModel::getRouteId()
{
    return _routeId;
}

int ExecutingRouteModel::getPlaneId()
{
    return _planeId;
}

long int ExecutingRouteModel::getTimestart()
{
    return _timestart;
}

void ExecutingRouteModel::setRouteId(int routeId)
{
    _routeId = routeId;
}

void ExecutingRouteModel::setPlaneId(int planeId)
{
    _planeId = planeId;
}

void ExecutingRouteModel::setTimestart(long int timestart)
{
    _timestart = timestart;
}
