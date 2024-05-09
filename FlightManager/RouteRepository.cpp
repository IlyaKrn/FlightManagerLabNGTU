#include "RouteModel.h"
#include "RouteRepository.h"
#include <fstream>
#include <sstream>

using namespace std;

RouteRepository::RouteRepository(std::string filepath)
{
    _filePath = filepath;
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

            RouteModel route;
            route.setId(id);
            route.setName(name);
            route.setStart(start);
            route.setEnd(end);

            file.close();
            return route;
        }
    }

    file.close();
    throw invalid_argument("The route with the specified identifier was not found");
}

bool RouteRepository::save(RouteModel data)
{
    ofstream file(_filePath, ios::app);

    if (!file.is_open())
    {
        throw runtime_error("Falied to access data");
    }

    file << data.getId() << " " << data.getName() << " "
        << data.getStart().getX() << " " << data.getStart().getY() << " "
        << data.getEnd().getX() << "  " << data.getEnd().getY() << std::endl;

    file.close();

    return true;
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
