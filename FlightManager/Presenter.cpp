#include<iostream>
#include "BaseFileRepository.h"
#include "BaseRepository.h"
#include "ExecutingRouteRepository.h"
#include "PlaneRepository.h"
#include "RouteRepository.h"
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
                     cout <<"¬ведите "
                     cin >> ;
                          

                }
                case 2:{


               }
                case 3:{


               }
                case 4:{


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


               }
               case 2:{


              }
               case 3:{


              }
               case 4:{


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
               cout << "1 - Get a list of busy routes with planes. 2 - Get a list of available routes. 3 - Assign the plane to the route. 4 - Get the coordinates of the planes on the routes. 5 - Get a list of available planes. 6 - Skip the time."<<endl;
               cin >> key;
                case 1:{


               }
               case 2:{


              }
               case 3:{


              }
               case 4:{


              }
               case 5:{


              }
               case 6:{


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
