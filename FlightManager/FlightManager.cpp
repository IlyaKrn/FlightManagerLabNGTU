#include <iostream>
#include"ExecutingRouteRepository.h"
#include "RouteManager.h"
#include "PlaneModel.h"
#include <list>
using namespace std;

int main()
{
    RouteManager manager;
    manager.addPlane(PlaneModel(1, "rgdgh", "wdaaf", 23, 231, "gwg"));
    manager.addPlane(PlaneModel(-1, "wewfwegf", "wegweg", 324, 12345, "awggb"));
    /*manager.deletePlaneById(1);
    manager.deletePlaneById(2);*/
    
    
    list<PlaneModel> availablePlanes = manager.getAvailablePlanes();

    
    for (PlaneModel& plane : availablePlanes) {
        cout << plane.getId() << plane.getBuiltYear() << plane.getCountry() << plane.getModel() << plane.getPilot() << plane.getSpeed() << endl;
    }
    
    /*repo.deleteById(5);*/

   // cout << repo.getById(5).getPlaneId() << endl;


}