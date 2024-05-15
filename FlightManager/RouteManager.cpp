#include "RouteManager.h"
#include "RouteModel.h"
#include "RouteRepository.h"
#include "PlaneModel.h"
#include "PlaneRepository.h"
#include "ExecutingRouteModel.h"
#include "ExecutingRouteRepository.h"
#include "Timer.h"
#include <cmath>
RouteManager::RouteManager() = default;
RouteModel RouteManager::addRoute(RouteModel route) {
	RouteRepository routes = RouteRepository(fileRoutes);
	RouteModel m = routes.save(route);
	return m;
}
bool RouteManager::deleteRouteById(int id) {
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	for (ExecutingRouteModel executingroute : allexecutingroutes) {
		if (executingroute.getRouteId() == id) {
			return false; 
		}
	}
	RouteRepository routes = RouteRepository(fileRoutes);
	return routes.deleteById(id);
}
PlaneModel RouteManager::addPlane(PlaneModel plane) {
	PlaneRepository planes = PlaneRepository(filePlanes);
	PlaneModel m = planes.save(plane);
	return m;
}
bool RouteManager::deletePlaneById(int id) {
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	for (ExecutingRouteModel executingroute : allexecutingroutes) {
		if (executingroute.getPlaneId() == id) {
			return false;
		}
	}
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
	std::list<PlaneModel> flyingPlanes;
	PlaneRepository planes = PlaneRepository(filePlanes);
	std::list<PlaneModel> allplanes = planes.getAll();
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingroutes = executingroutes.getAll();
	for (PlaneModel plane : allplanes) {
		bool isFlying = false;
		for (ExecutingRouteModel route : allexecutingroutes) {
			if (route.getPlaneId() == plane.getId()) {
				isFlying = true;
				break;
			}
		}

		if (isFlying) {
			flyingPlanes.push_back(plane);
		}
	}
	return std::list<PlaneModel>();
}
std::list<PlaneStatusModel> RouteManager::getPlanesCoordinates()
{
	updateExecutingRoutes();
	std::list<PlaneStatusModel> planesStatus;
	for (PlaneStatusModel plane : planesStatus) {
		PlaneStatusModel planestatus;
		planestatus.setPlaneId(plane.getPlaneId());
		planestatus.setCurrentCoordinates(plane.getCurrentCoordinates());
		planestatus.setTotalTime(plane.getTotalTime());
		planestatus.setTimeLeft(plane.getTimeLeft());
	}
	return std::list<PlaneStatusModel>();
}
void RouteManager::updateExecutingRoutes()
{
	ExecutingRouteRepository executingroutes = ExecutingRouteRepository();
	std::list<ExecutingRouteModel> allexecutingRoutes = executingroutes.getAll();
	PlaneRepository planes = PlaneRepository(filePlanes);
	std::list<PlaneModel> allplanes = planes.getAll();
	RouteRepository routes = RouteRepository(fileRoutes);
	std::list<RouteModel> allroutes = routes.getAll();
	long int currentTime = timer.getCurrentTime();

	auto it = allexecutingRoutes.begin();

	while (it != allexecutingRoutes.end())
	{
		int speed;
		for (ExecutingRouteModel executeroute : allexecutingRoutes) {
			for (PlaneModel plane : allplanes) {
				if (executeroute.getPlaneId() == plane.getId()) {
					speed = plane.getSpeed();
				}
			}
		}
		CoordinateModel start;
		CoordinateModel end;
		for (ExecutingRouteModel executeroute : allexecutingRoutes) {
			for (RouteModel route : allroutes) {
				if (executeroute.getPlaneId() == route.getId()) {
					start = route.getStart();
					end = route.getEnd();
				}
			}
		}
		double duration = sqrt(pow((end.getX() - start.getX()),2) + pow((end.getY() - start.getY()), 2));

		long int routeEndTime = it->getTimestart() + duration / (speed * 1000);

		if (currentTime > routeEndTime)
		{
			it = allexecutingRoutes.erase(it);
		}
		else
		{
			++it;
		}
	}
}