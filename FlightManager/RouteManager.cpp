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
	RouteModel m = routeRepo.save(route);
	return m;
}
bool RouteManager::deleteRouteById(int id) {
	std::list<ExecutingRouteModel> allexecutingroutes = executingRouteRepo.getAll();
	for (ExecutingRouteModel executingroute : allexecutingroutes) {
		if (executingroute.getRouteId() == id) {
			return false; 
		}
	}
	return routeRepo.deleteById(id);
}
PlaneModel RouteManager::addPlane(PlaneModel plane) {
	PlaneModel m = planeRepo.save(plane);
	return m;
}
bool RouteManager::deletePlaneById(int id) {
	std::list<ExecutingRouteModel> allexecutingroutes = executingRouteRepo.getAll();
	for (ExecutingRouteModel executingroute : allexecutingroutes) {
		if (executingroute.getPlaneId() == id) {
			return false;
		}
	}
	return planeRepo.deleteById(id);
}
void RouteManager::executeRoute(int routeId, int planeId) {
	updateExecutingRoutes();

	bool planeAlreadyExecuting = false;
	for (ExecutingRouteModel executingRoute : executingRouteRepo.getAll()) {
		if (executingRoute.getPlaneId() == planeId) {
			planeAlreadyExecuting = true;
			break;
		}
	}

	if (planeAlreadyExecuting) {
		throw std::string("this plane already flying");
	}
	else {
		executingRouteRepo.save(ExecutingRouteModel(routeId, planeId, timer.getCurrentTime()));
	}
}
void RouteManager::skipTime(long int skippedMillis)
{
	timer.skipTime(skippedMillis);
}
std::list<PlaneModel> RouteManager::getFreePlanes() {
	updateExecutingRoutes();
	std::list<PlaneModel> availablePlanes;
	std::list<ExecutingRouteModel> allexecutingroutes = executingRouteRepo.getAll();
	std::list<PlaneModel> allPlanes = planeRepo.getAll();
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
	std::list<ExecutingRouteModel> allexecutingroutes = executingRouteRepo.getAll();
	std::list<RouteModel> allRoutes = routeRepo.getAll();
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
	std::list<ExecutingRouteModel> allexecutingroutes = executingRouteRepo.getAll();
	return allexecutingroutes;
}


std::list<RouteModel> RouteManager::getAllRoutes()
{
	std::list<RouteModel> allRoutes = routeRepo.getAll();
	return allRoutes;
}

std::list<PlaneModel> RouteManager::getAllPlanes()
{
	std::list<PlaneModel> allPlanes = planeRepo.getAll();
	return allPlanes;
}

std::list<RouteModel> RouteManager::getRouteById(int id)
{
	std::list<RouteModel> routesbyid;
	routesbyid.push_back(routeRepo.getById(id));
	return routesbyid;
}

std::list<PlaneModel> RouteManager::getPlaneById(int id)
{
	std::list<PlaneModel> planesbyid;
	planesbyid.push_back(planeRepo.getById(id));
	return planesbyid;
}
std::list<PlaneModel> RouteManager::getFlyingPlanes()
{
	updateExecutingRoutes();
	std::list<PlaneModel> flyingPlanes;
	std::list<PlaneModel> allplanes = planeRepo.getAll();
	std::list<ExecutingRouteModel> allexecutingroutes = executingRouteRepo.getAll();
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
	return flyingPlanes;
}
#include<iostream>
std::list<PlaneStatusModel> RouteManager::getPlanesCoordinates()
{
	updateExecutingRoutes();
	std::list<PlaneStatusModel> planesStatus;
	std::list<PlaneModel> allplanes = planeRepo.getAll();
	std::list<RouteModel> allroutes = routeRepo.getAll();
	std::list<ExecutingRouteModel> allexecutingroutes = executingRouteRepo.getAll();
	for (ExecutingRouteModel executingroute : allexecutingroutes) {
		for (PlaneModel plane : allplanes) {
			for (RouteModel route : allroutes) {
				if (plane.getId() == executingroute.getPlaneId()) {
					if (executingroute.getRouteId() == route.getId()) {

						int speed = plane.getSpeed();
						CoordinateModel start = route.getStart();
						CoordinateModel end = route.getEnd();

						double duration = sqrt(pow((end.getX() - start.getX()), 2) + pow((end.getY() - start.getY()), 2));
						long int elapsedTime = timer.getCurrentTime() - executingroute.getTimestart();

						double newX = start.getX() + (end.getX() - start.getX()) * (speed * elapsedTime / duration);
						double newY = start.getY() + (end.getY() - start.getY()) * (speed * elapsedTime / duration);
						CoordinateModel currentcoordinates = CoordinateModel(newX, newY);
						long int totaltime = duration / (speed);
						long int timeleft = totaltime - elapsedTime;
						planesStatus.push_back(PlaneStatusModel(plane.getId(), currentcoordinates, totaltime, timeleft));

					}
				}
			}
		}
	}
	return planesStatus;
}
void RouteManager::updateExecutingRoutes()
{
	std::list<ExecutingRouteModel> allexecutingRoutes = executingRouteRepo.getAll();
	std::list<PlaneModel> allplanes = planeRepo.getAll();
	std::list<RouteModel> allroutes = routeRepo.getAll();
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
				if (executeroute.getRouteId() == route.getId()) {
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