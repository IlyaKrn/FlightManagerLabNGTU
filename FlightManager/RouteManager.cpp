#include "RouteManager.h"
#include "RouteModel.h"
#include "RouteRepository.h"
#include "PlaneModel.h"
#include "PlaneRepository.h"
#include "ExecutingRouteModel.h"
#include "ExecutingRouteRepository.h"
#include "Timer.h"
void RouteManager::addRoute(RouteModel route) {
	RouteRepository routes = RouteRepository("routes.txt");
	routes.save(route);
	return;
}
bool RouteManager::deleteRouteById(int id) {
	RouteRepository routes = RouteRepository("routes.txt");
	routes.deleteById(id);
	return true;
}
void RouteManager::addPlane(PlaneModel plane) {
	PlaneRepository planes = PlaneRepository("planes.txt");
	planes.save(plane);
	return;
}
bool RouteManager::deletePlaneById(int id) {
	PlaneRepository planes = PlaneRepository("planes.txt");
	planes.deleteById(id);
	return true;
}
void RouteManager::executeRoute(int routeId, int planeId, long int timestart) {
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	executingroutes.save(ExecutingRouteModel(routeId, planeId, timestart));
	return;
}
std::list<PlaneModel> RouteManager::getAvailablePlanes() {
	std::list<PlaneModel> availablePlanes;
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	PlaneRepository planes = PlaneRepository("planes.txt");
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
std::list<RouteModel> RouteManager::getAvailableRoutes() {
	std::list<RouteModel> availableRoutes;
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	RouteRepository routes = RouteRepository("routes.txt");
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
std::list<ExecutingRouteModel> RouteManager::getExecutingRoutes() {
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	return allexecutingroutes;
}

std::list<RouteModel> RouteManager::getAllRoutes()
{
	RouteRepository routes = RouteRepository("routes.txt");
	routes.getAll();
	return std::list<RouteModel>();
}

std::list<PlaneModel> RouteManager::getAllPlanes()
{
	PlaneRepository planes = PlaneRepository("planes.txt");
	planes.getAll();
	return std::list<PlaneModel>();
}

std::list<RouteModel> RouteManager::getRouteById(int id)
{
	RouteRepository routes = RouteRepository("routes.txt");
	routes.getById(id);
	return std::list<RouteModel>();
}

std::list<PlaneModel> RouteManager::getPlaneById(int id)
{
	PlaneRepository planes = PlaneRepository("planes.txt");
	planes.getById(id);
	return std::list<PlaneModel>();
}

void skipTime(long int skippedMillis) {
	Timer timer;
	long int newcurrenttime;
	newcurrenttime = timer.getCurrentTime() + skippedMillis;
	return;
}

