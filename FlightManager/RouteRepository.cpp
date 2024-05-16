#include "RouteModel.h"
#include "RouteRepository.h"
#include <fstream>
#include <sstream>

using namespace std;

RouteRepository::RouteRepository(std::string filepath)
{
    _filePath = filepath;
}

RouteRepository::RouteRepository()
{
    _filePath = "routes.txt";
}

list<RouteModel> RouteRepository::getAll()
{
    list<RouteModel> routes;
    ifstream file(_filePath);

    if (!file.is_open())
    {
        throw runtime_error("Falied to access data");
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);

        int id;
        string name;
        double startX, startY, endX, endY; 
        if (!(iss >> id >> name >> startX >> startY >> endX >> endY))
        {
            continue;
        }

        CoordinateModel start;
        start.setX(startX);
        start.setY(startY);

        CoordinateModel end;
        end.setX(endX);
        end.setY(endY);
        RouteModel route;
        route.setId(id);
        route.setName(name);
        route.setStart(start); 
        route.setEnd(end); 

        routes.push_back(route);
    }

    file.close();

    return routes;
}

RouteModel RouteRepository::getById(int searchId)
{
    ifstream file(_filePath);

    if (!file.is_open())
    {
        throw runtime_error("Falied to access data");
    }

    int id;
    string name;
    double startX, startY, endX, endY;
    RouteModel route;
    while (file >> id >> name >> startX >> startY >> endX >> endY)
    {
        if (searchId == id)
        {
            CoordinateModel start;
            start.setX(startX);
            start.setY(startY);
            CoordinateModel end;
            end.setX(endX);
            end.setY(endY);

            
            route.setId(id);
            route.setName(name);
            route.setStart(start);
            route.setEnd(end);
            break;
        }
        else {
            throw runtime_error("Route with this id is not found");
        }
    }

    file.close();
    return route;
}

RouteModel RouteRepository::save(RouteModel data)
{
    if (data.getId() != -1) {
        ofstream file(_filePath);
        deleteById(data.getId());
        file << data.getId() << " " << data.getName() << " "
            << data.getStart().getX() << " " << data.getStart().getY() << " "
            << data.getEnd().getX() << "  " << data.getEnd().getY() << std::endl;
        return data;
    }
    else {
        ifstream readFile(_filePath);
        int maxId = 0;
        string line;
        while (getline(readFile, line))
        {
            stringstream ss(line);
            int id;
            ss >> id;
            maxId = max(maxId, id);
        }
        readFile.close();

        data.setId(maxId + 1);
        ofstream file(_filePath, ios::app);

        if (!file.is_open())
        {
            throw runtime_error("Falied to access data");
        }

        file << data.getId() << " " << data.getName() << " "
            << data.getStart().getX() << " " << data.getStart().getY() << " "
            << data.getEnd().getX() << "  " << data.getEnd().getY() << std::endl;

        file.close();

        return data;
    }
}

bool RouteRepository::deleteById(int id)
{
    ifstream fileIn(_filePath);
    if (!fileIn.is_open())
    {
        throw runtime_error("Falied to access data");
    }

    ofstream fileOut(_filePath + ".tmp");

    if (!fileOut.is_open())
    {
        throw runtime_error("Falied to access data");
    }

    int searchId;
    string line;
    bool deleted = false;
    while (fileIn >> searchId)
    {
        getline(fileIn, line);
        if (searchId == id)
        {
            deleted = true;
            continue;
        }
        fileOut << searchId << line << endl;
    }

    fileIn.close();
    fileOut.close();

    remove(_filePath.c_str());
    rename((_filePath + ".tmp").c_str(), _filePath.c_str());

    return deleted;
}
