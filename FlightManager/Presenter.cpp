#include <iostream>
#include "Presenter.h"
using namespace std;

Presenter::Presenter() = default;

void Presenter::createAndAddPlane() {
    std::string model;
    std::string pilot;
    int speed;
    int builtYear;
    std::string country;

    cout << "enter model" << endl;
    cin >> model;
    cout << "enter pilot" << endl;
    cin >> pilot;
    cout << "enter speed (m/s)" << endl;
    cin >> speed;
    cout << "enter built Year" << endl;
    cin >> builtYear;
    cout << "enter country" << endl;
    cin >> country;
    int id = manager.addPlane(PlaneModel(-1, model, pilot, speed, builtYear, country)).getId();
    cout << "Plane with id " << id << " created" << endl;
}

void Presenter::deletePlane() {
    cout << "enter id" << endl;
    int id;
    cin >> id;
    cout << "plane with id: " << id << (manager.deletePlaneById(id) ? " deleted successful" : "failed to delete") << endl;
}

void Presenter::getingAllPlanes() {
    for (PlaneModel& plane : manager.getAllPlanes()) {
        cout <<
            "id: " << plane.getId() <<
            " model: " << plane.getModel() <<
            " pilot: " << plane.getPilot() <<
            " country: " << plane.getCountry() <<
            " speed: " << plane.getSpeed() <<
            " built year: " << plane.getBuiltYear() << endl;
    }
}

void Presenter::searchPlane() {
    int id;
    cin >> id;
    for (PlaneModel& plane : manager.getPlaneById(id)) {
        cout <<
            "id: " << plane.getId() <<
            " model: " << plane.getModel() <<
            " pilot: " << plane.getPilot() <<
            " country: " << plane.getCountry() <<
            " speed: " << plane.getSpeed() <<
            " built year: " << plane.getBuiltYear() << endl;
    }
}

void Presenter::createAndAddRoute(){
    std::string name;
    int x1;
    int x2;
    int y1;
    int y2;

    cout <<"enter name"<<endl;
    cin >> name;
    cout << "enter start x (m)" << endl;
    cin >> x1;
    cout << "enter start y (m)" << endl;
    cin >> y1;
    cout << "enter end x (m)" << endl;
    cin >> x2;
    cout << "enter end y (m)" << endl;
    cin >> y2;
    
    int id = manager.addRoute(RouteModel(-1, name, CoordinateModel(x1, y1), CoordinateModel(x2, y2))).getId();
    
    cout <<"route with id "<< id<< " created" <<endl;
}

void Presenter::deleteRoute(){
    cout << "enter id" << endl;
    int id;
    cin >> id;
    cout << "route with id: " << id << (manager.deletePlaneById(id) ? " deleted successful" : "failed to delete") << endl;
}

void Presenter::getingAllRoutes(){
    for (RouteModel& route : manager.getAllRoutes()) {
        cout <<
            "id: " << route.getId() <<
            " name: " << route.getName() <<
            " start: (" << route.getStart().getX() << ", " << route.getStart().getY() << ")" <<
            " end: (" << route.getEnd().getX() << ", " << route.getEnd().getY() << ")" << endl;
    }
}

void Presenter::searchRoute(){
    cout << "enter id" << endl;
    int id;
    cin >> id;
    for (RouteModel& route : manager.getRouteById(id)) {
        cout <<
            "id: " << route.getId() <<
            " name: " << route.getName() <<
            " start: (" << route.getStart().getX() << ", " << route.getStart().getY() << ")" <<
            " end: (" << route.getEnd().getX() << ", " << route.getEnd().getY() << ")" << endl;
    }
}

void Presenter::getBusyRoutes(){
    for (ExecutingRouteModel& route : manager.getExecutingRoutes()) {
        cout <<
            "plane id: " << route.getPlaneId() <<
            " route id: " << route.getRouteId() <<
            " timestart: (" << route.getTimestart() << endl;
    }
}

void Presenter::getAvaiableRoutes(){
    for (RouteModel& route : manager.getFreeRoutes()) {
        cout <<
            "id: " << route.getId() <<
            " name: " << route.getName() <<
            " start: (" << route.getStart().getX() << ", " << route.getStart().getY() << ")" <<
            " end: (" << route.getEnd().getX() << ", " << route.getEnd().getY() << ")" << endl;
    }
}

void Presenter::getBusyPlanes(){
    for (PlaneModel& plane : manager.getFlyingPlanes()) {
        cout <<
            "id: " << plane.getId() <<
            " model: " << plane.getModel() <<
            " pilot: " << plane.getPilot() <<
            " country: " << plane.getCountry() <<
            " speed: " << plane.getSpeed() <<
            " built year: " << plane.getBuiltYear() << endl;
    }
}

void Presenter::getAvaiablePlanes(){
    for (PlaneModel& plane : manager.getFreePlanes()) {
        cout <<
            "id: " << plane.getId() <<
            " model: " << plane.getModel() <<
            " pilot: " << plane.getPilot() <<
            " country: " << plane.getCountry() <<
            " speed: " << plane.getSpeed() <<
            " built year: " << plane.getBuiltYear() << endl;
    }
}

void Presenter::assignPlaneToRoute(){
    int rid;
    int pid;
    cout << "enter route id" << endl;
    cin >> rid;
    cout << "enter plane id" << endl;
    cin >> pid;

    manager.executeRoute(rid, pid);

    cout << "plane with id " << pid << " assigned to route with id: " << rid << endl;
}

void Presenter::getCoordinates(){

    for (PlaneStatusModel& plane : manager.getPlanesCoordinates()) {
        cout <<
            "id: " << plane.getPlaneId() <<
            " total time: " << plane.getTotalTime() <<
            " time left: " << plane.getTimeLeft() <<
            " coordinates: (" << plane.getCurrentCoordinates().getX() << ", " << plane.getCurrentCoordinates().getY() << ")" << endl;
    }
}

void Presenter::skip(){
    long int skipped;
    cout << "enter skipped milliseconds" << endl;
    cin >> skipped;
    manager.skipTime(skipped);
    cout << skipped << " milliseconds skipped" << endl;
}