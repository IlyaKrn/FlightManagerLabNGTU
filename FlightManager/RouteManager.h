#pragma once
#include "RouteModel.h"
#include "PlaneModel.h"
#include "ExecutingRouteModel.h"
#include <list>
#include <map>
#include "Timer.h"
class RouteManager {
private:
	Timer timer;
public:
	void addRoute(RouteModel route);
	bool deleteRouteById(int id);
	void addPlane(PlaneModel plane);
	bool deletePlaneById(int id);
	void executeRoute(int routeId, int planeId, long int timestart);
	std::list<PlaneModel> getAvailablePlanes();
	std::list<RouteModel> getAvailableRoutes();
	std::list<ExecutingRouteModel> getExecutingRoutes();
	std::list<RouteModel> getAllRoutes();
	std::list<PlaneModel> getAllPlanes();
	std::list<RouteModel> getRouteById(int id);
	std::list<PlaneModel> getPlaneById(int id);
	void skipTime(long int skippedMillis);
};