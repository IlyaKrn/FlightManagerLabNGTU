#pragma once
#include"RouteManager.h"
class Presenter{
private:
	RouteManager manager;
public:
	Presenter();
	void createAndAddPlane();
	void createAndAddRoute();
	void deletePlane();
	void deleteRoute();
	void getingAllPlanes();
	void getingAllRoutes();
	void searchPlane();
	void searchRoute();
	void getBusyRoutes();
	void getAvaiableRoutes();
	void getBusyPlanes();
	void getAvaiablePlanes();
	void assignPlaneToRoute();
	void getCoordinates();
	void skip();
	
};
