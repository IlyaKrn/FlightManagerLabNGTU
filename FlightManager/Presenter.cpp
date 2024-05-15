#include <iostream>
#include "Presenter.h"
using namespace std;
using namespace Presenter;
                void createAndAddPlane(){
                     PlaneModel plane;
                     std::string model;
                     std::string pilot;
                     int speed;
                     int builtYear;
                     std::string country;

                     cout <<"enter model"<<endl;
                     cin >> model;
                     cout <<"enter pilot"<<endl;
                     cin >> pilot;
                     cout <<"enter speed"<<endl;
                     cin >> speed;
                     cout <<"enter built Year"<<endl;
                     cin >> builtYear;
                     cout <<"enter country"<<endl;
                     cin >> country;
                     PlaneModel::PlaneModel(-1, model, pilot, speed, builtYear, country)
                     RouteManager::addPlane(plane);
                     cout <<"Plane with id "<< id<< " created" <<endl;
                }
                void deletePlane(){
                     cout <<"enter id"<<endl;
                     cin >> int id;
                    RouteManager::deletePlaneById(id);



               }
                void getingAllPlanes(){
                    std::list<PlaneModel> RouteManager::getAllPlanes();

               }
                void searchPlane(){
                     cout <<"enter id"<<endl;
                     cin >> int id;
                   std::list<RouteModel> RouteManager::getPlaneById(id);
                }
              


                 
      
                	void createAndAddRoute(){
                   RouteModel route;
                   
                    int id;
                    std::string name;
                    CoordinateModel start;
                    CoordinateModel end;

                    cout <<"enter name"<<endl;
                     cin >> name;
                     cout <<"enter start"<<endl;
                     cin >> start;
                     cout <<"enter end"<<endl;
                     cin >> end;
                    RouteModel::RouteModel(-1, name, start, end);
                    RouteManager::addRoute(route);
                     cout <<"route with id "<< id<< " created" <<endl;
                     



               }
              void deleteRoute(){
                   cout <<"enter id"<<endl;
                     cin >> int id;
                    RouteManager::deleteRouteById(id);


              }
              void getingAllRoutes(){
                 std::list<RouteModel> RouteManager::getAllRoutes();



              }
              void searchRoute(){
                    cout <<"enter id"<<endl;
                     cin >> int id;
                   std::list<RouteModel> RouteManager::getRouteById(id);


              }


      
                void GetBusyRoutes(){
                    std::list<ExecutingRouteModel> RouteManager::getExecutingRoutes();


               }
               void GetAvaiableRoutes(){
                   std::list<RouteModel> RouteManager::getAvailableRoutes();


              }
              void GetBusyPlanes(){
                   int routeId;
                   int planeId;
                   cout <<"enter route id"<<endl;
                     cin >> routeId;
                     cout <<"enter plane id"<<endl;
                     cin >> planeId;
                    
                   RouteManager::executeRoute(routeId, planeId);



              }
             void GetAvaiablePlanes(){
                   std::list<PlaneStatusModel> RouteManager::getAllPlanesCoordinates();


              }
              void AssignPlaneToRoute(){
                   std::list<PlaneModel> RouteManager::getAvailablePlanes();

              }
               void GetCoordinates(){
                    std::list<PlaneModel> RouteManager::getFlyingPlanes()



              }
             void skip(){
                  long int skippedMillis;
                  cout <<"enter how many hours to skip?"<<endl;
                     cin >> skippedMillis;
                  skipTime(skippedMillis);

              }


