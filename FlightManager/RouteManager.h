#pragma once
#include "RouteModel.h"
#include "PlaneModel.h"
#include "PlaneStatusModel.h"
#include "ExecutingRouteModel.h"
#include "RouteRepository.h"
#include "ExecutingRouteRepository.h"
#include "PlaneRepository.h"
#include <list>
#include "Timer.h"

class RouteManager {
private:
	Timer timer;
	RouteRepository routeRepo;
	PlaneRepository planeRepo;
	ExecutingRouteRepository executingRouteRepo;
	void updateExecutingRoutes();
public:
	RouteManager();
	RouteModel addRoute(RouteModel route);
	PlaneModel addPlane(PlaneModel plane);
	bool deleteRouteById(int id);
	bool deletePlaneById(int id);
	std::list<RouteModel> getAllRoutes();
	std::list<PlaneModel> getAllPlanes();
	std::list<RouteModel> getRouteById(int id);
	std::list<PlaneModel> getPlaneById(int id);
	std::list<ExecutingRouteModel> getExecutingRoutes();
	std::list<PlaneModel> getFlyingPlanes();
	std::list<RouteModel> getFreeRoutes();
	std::list<PlaneModel> getFreePlanes();
	void executeRoute(int routeId, int planeId);
	std::list<PlaneStatusModel> getPlanesCoordinates();
	void skipTime(long int skippedMillis);

};