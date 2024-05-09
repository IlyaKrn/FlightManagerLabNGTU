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
        throw runtime_error("Не удалось получить доступ к данным");
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
        throw runtime_error("Не удалось получить доступ к файлу с данными маршрутов");
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
    throw invalid_argument("Маршрут с указанным идентификатором не найден");
}

bool RouteRepository::save(RouteModel data)
{
    ofstream file(_filePath, ios::app);

    if (!file.is_open())
    {
        throw runtime_error("Не удалось получить доступ к файлу для сохранения");
    }

    file << data.getId() << " " << data.getName() << " "
        << data.getStart().getX() << " " << data.getStart().getY() << " "
        << data.getEnd().getX() << "  " << data.getEnd().getY() << std::endl;

    file.close();

    return true;
}

bool RouteRepository::deleteById(int id)
{
    return false;
}
