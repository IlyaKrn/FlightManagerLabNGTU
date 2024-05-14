
#include "Presenter.h"
using namespace std;

int main (){
    int stop=0;
    while (stop!=1){
        int key;
        cout << "Hi, what are you interested in?"<<endl;
        cout << "1 - Airplanes . 2 - Routes. 3 - Flight control."<<endl;
        cin >> key;
        switch (key){


         case 1:{
            int stop1=0;
            while (stop1!=1){
                int key;
                cout << "What actions with airplanes are you interested in?"<<endl;
                cout << "1 - Adding a new one. 2 - Delete an existing one. 3 - View all existing ones. 4 - Search."<<endl;
                cin >> key;
                 case 1:{
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
                case 2:{
                     cout <<"enter id"<<endl;
                     cin >> int id;
                    RouteManager::deletePlaneById(id);



               }
                case 3:{
                    std::list<PlaneModel> RouteManager::getAllPlanes();

               }
                case 4:{
                     cout <<"enter id"<<endl;
                     cin >> int id;
                   std::list<RouteModel> RouteManager::getPlaneById(id);

               }


                  default:
                  stop1=1;
                   break;}


                 }
        case 2:{
           int stop2=0;
           while (stop2!=1){
               int key;
               cout << "What actions with routes are you interested in?"<<endl;
               cout << "1 - Adding a new one. 2 - Delete an existing one. 3 - View all existing ones. 4 - Search."<<endl;
               cin >> key;
                case 1:{
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
               case 2:{
                   cout <<"enter id"<<endl;
                     cin >> int id;
                    RouteManager::deleteRouteById(id);


              }
               case 3:{
                 std::list<RouteModel> RouteManager::getAllRoutes();



              }
               case 4:{
                    cout <<"enter id"<<endl;
                     cin >> int id;
                   std::list<RouteModel> RouteManager::getRouteById(id);


              }


                 default:
                 stop2=1;
                  break;}


                 }
        case 3:{
           int stop3=0;
           while (stop3!=1){
               int key;
               cout << "What flight operations are you interested in?"<<endl;
               cout << "1 - Get a list of busy routes. 2 - Get a list of available routes. 3 - Assign the plane to the route. 4 - Get the coordinates of the planes on the routes. 5 - Get a list of available planes. 6 - Get a list of busy planes. 7 - Skip the time."<<endl;
               cin >> key;
                case 1:{
                    std::list<ExecutingRouteModel> RouteManager::getExecutingRoutes();


               }
               case 2:{
                   std::list<RouteModel> RouteManager::getAvailableRoutes();


              }
               case 3:{
                   int routeId;
                   int planeId;
                   cout <<"enter route id"<<endl;
                     cin >> routeId;
                     cout <<"enter plane id"<<endl;
                     cin >> planeId;
                    
                   RouteManager::executeRoute(routeId, planeId);



              }
               case 4:{
                   cout<< "dodelayt?"<<endl;

              }
               case 5:{
                   std::list<PlaneModel> RouteManager::getAvailablePlanes();

              }
               case 6:{
                    cout<< "dodelayt?"<<endl;


              }
              case 7:{
                  long int skippedMillis;
                  cout <<"enter how many hours to skip?"<<endl;
                     cin >> skippedMillis;
                  skipTime(skippedMillis);

              }



                 default:
                 stop3=1;
                  break;}


              }
        default:
            stop=1;
            break;

}
    }
}
