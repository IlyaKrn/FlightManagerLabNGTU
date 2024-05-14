#include "RouteManager.h"
#include "RouteModel.h"
#include "RouteRepository.h"
#include "PlaneModel.h"
#include "PlaneRepository.h"
#include "ExecutingRouteModel.h"
#include "ExecutingRouteRepository.h"
#include "Timer.h"
RouteManager::RouteManager() = default;
RouteModel RouteManager::addRoute(RouteModel route) {
	RouteRepository routes = RouteRepository(fileRoutes);
	RouteModel m = routes.save(route);
	return m;
}
bool RouteManager::deleteRouteById(int id) {
	//check if this route in executing route
	RouteRepository routes = RouteRepository(fileRoutes);
	return routes.deleteById(id);
}
PlaneModel RouteManager::addPlane(PlaneModel plane) {
	PlaneRepository planes = PlaneRepository(filePlanes);
	PlaneModel m = planes.save(plane);
	return m;
}
bool RouteManager::deletePlaneById(int id) {
	//check if this plane in executing route
	PlaneRepository planes = PlaneRepository(filePlanes);
	return planes.deleteById(id);
}
void RouteManager::executeRoute(int routeId, int planeId) {
	updateExecutingRoutes();
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	executingroutes.save(ExecutingRouteModel(routeId, planeId, timer.getCurrentTime()));
	return;
}
void RouteManager::skipTime(long int skippedMillis)
{
	timer.skipTime(skippedMillis);
}
std::list<PlaneModel> RouteManager::getFreePlanes() {
	updateExecutingRoutes();
	std::list<PlaneModel> availablePlanes;
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	PlaneRepository planes = PlaneRepository(filePlanes);
	std::list<PlaneModel> allPlanes = planes.getAll();
	for (PlaneModel& plane : allPlanes) {
		bool isUsed = false;
		for (ExecutingRouteModel& executingroute : allexecutingroutes) {
			if (executingroute.getPlaneId() == plane.getId()) {
				isUsed = true;
				break;
			}
		}
		if (!isUsed) {
			availablePlanes.push_back(plane);
		}
	}
	return availablePlanes;
}
std::list<RouteModel> RouteManager::getFreeRoutes() {
	updateExecutingRoutes();
	std::list<RouteModel> availableRoutes;
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	RouteRepository routes = RouteRepository(fileRoutes);
	std::list<RouteModel> allRoutes = routes.getAll();
	for (RouteModel& route : allRoutes) {
		bool isUsed = false;
		for (ExecutingRouteModel& executingroute : allexecutingroutes) {
			if (executingroute.getRouteId() == route.getId()) {
				isUsed = true;
				break;
			}
		}
		if (!isUsed) {
			availableRoutes.push_back(route);
		}
	}
	return availableRoutes;
}
std::list<ExecutingRouteModel> RouteManager::getExecutingRoutes() 
{
	updateExecutingRoutes();
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	return allexecutingroutes;
}


std::list<RouteModel> RouteManager::getAllRoutes()
{
	RouteRepository routes = RouteRepository(fileRoutes);
	routes.getAll();
	return std::list<RouteModel>();
}

std::list<PlaneModel> RouteManager::getAllPlanes()
{
	PlaneRepository planes = PlaneRepository(filePlanes);
	planes.getAll();
	return std::list<PlaneModel>();
}

std::list<RouteModel> RouteManager::getRouteById(int id)
{
	RouteRepository routes = RouteRepository(fileRoutes);
	routes.getById(id);
	return std::list<RouteModel>();
}

std::list<PlaneModel> RouteManager::getPlaneById(int id)
{
	PlaneRepository planes = PlaneRepository(filePlanes);
	planes.getById(id);
	return std::list<PlaneModel>();
}
std::list<PlaneModel> RouteManager::getFlyingPlanes()
{
	updateExecutingRoutes();
	//return flying planes
	return std::list<PlaneModel>();
}
std::list<PlaneStatusModel> RouteManager::getAllPlanesCoordinates()
{
	updateExecutingRoutes();
	//return list of planes status (id, currentCoordinbate ....)
	return std::list<PlaneStatusModel>();
}
void RouteManager::updateExecutingRoutes()
{
	//update executing routes in file (calculate time ending of roude and if current time > time of ending delete this executing route)
}