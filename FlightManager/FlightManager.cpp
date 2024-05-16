#include <iostream>
#include"Presenter.h"
using namespace std;

int main()
{
	Presenter p = Presenter();
	cout << "select action:" << endl <<
		"1. add plane" << endl <<
		"2. add route" << endl <<
		"3. delete plane" << endl <<
		"4. delete route" << endl <<
		"5. get all planes" << endl <<
		"6. get all routes" << endl <<
		"7. get free planes" << endl <<
		"8. get free routes" << endl <<
		"9. get executing routes" << endl <<
		"10. get flying planes" << endl <<
		"11. search plane" << endl <<
		"12. search route" << endl <<
		"13. assign plane to route" << endl <<
		"14. skip time" << endl <<
		"15. get flying planes coordinates" << endl <<
		"16. exit" << endl;
	int action = 0;
	while (true) {
		try {
			cout << "==================" << endl << "enter action: " << endl;
			cin >> action;
			switch (action)
			{
			case 1:
				p.createAndAddPlane();
				break;
			case 2:
				p.createAndAddRoute();
				break;
			case 3:
				p.deletePlane();
				break;
			case 4:
				p.deleteRoute();
				break;
			case 5:
				p.getingAllPlanes();
				break;
			case 6:
				p.getingAllRoutes();
				break;
			case 7:
				p.getAvaiablePlanes();
				break;
			case 8:
				p.getAvaiableRoutes();
				break;
			case 9:
				p.getBusyRoutes();
				break;
			case 10:
				p.getBusyPlanes();
				break;
			case 11:
				p.searchPlane();
				break;
			case 12:
				p.searchRoute();
				break;
			case 13:
				p.assignPlaneToRoute();
				break;
			case 14:
				p.skip();
				break;
			case 15:
				p.getCoordinates();
				break;
			case 16:
				return 0;
			default:
				cout << "cant find action " << action << endl;
				break;
			}
		}
		catch (string exception) {
			cout << exception << endl;
		}
		catch (...) {
			cout << "ERROR" << endl;
		}
		
	}
}