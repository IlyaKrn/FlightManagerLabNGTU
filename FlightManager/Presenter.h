#pragma once
#include <iostream>
#include "RouteManager.h"


#include "BaseFileRepository.h"
#include "BaseRepository.h"
#include "ExecutingRouteRepository.h"
#include "PlaneRepository.h"
#include "RouteRepository.h"

namespace Presenter{

	void createAndAddPlane();
	void createAndAddRoute();
	void deletePlane();
	void deleteRoute();
	void getingAllPlanes();
	void getingAllRoutes();
	void searchPlane();
	void searchRoute();
	void GetBusyRoutes();
	void GetAvaiableRoutes();
	void GetBusyPlanes();
	void GetAvaiablePlanes();
	void AssignPlaneToRoute();
	void GetCoordinates();
	void skip();
	
};
