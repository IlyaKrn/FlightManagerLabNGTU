#include "RouteModel.h"
#include "RouteRepository.h"
#include "BaseRepository.h"
#include <fstream>
#include <sstream>

std::list<RouteModel> RouteRepository::getAll()
{
    std::list<RouteModel> routes;
    std::ifstream file(_filePath);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось получить доступ к данным");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        int id;
        std::string name;
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
    std::ifstream file(_filePath);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось получить доступ к файлу с данными маршрутов");
    }

    int id;
    std::string name;
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
    throw std::invalid_argument("Маршрут с указанным идентификатором не найден");
}

bool RouteRepository::save(RouteModel data)
{
    std::ofstream file(_filePath, std::ios::app);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось получить доступ к файлу для сохранения");
    }

    file << data.getId() << " " << data.getName() << " "
        << data.getStart().getX() << " " << data.getStart().getY() << " "
        << data.getEnd().getX() << "  " << data.getEnd().getY() << std::endl;

    file.close();

    return true;
}

bool RouteRepository::deleteById(int id)
{
    std::ifstream fileIn(_filePath);
    if (!fileIn.is_open())
    {
        throw std::runtime_error("Не удалось получить доступ к файлу для удаления");
    }

    std::ofstream fileOut(_filePath + ".tmp");

    if (!fileOut.is_open())
    {
        throw std::runtime_error("Не удалось создать временный файл");
    }

    int searchId;
    std::string line;
    bool deleted = false;
    while (fileIn >> searchId)
    {
        std::getline(fileIn, line);
        if (searchId == id)
        {
            deleted = true;
            continue;
        }
        fileOut << searchId << line << std::endl;
    }

    fileIn.close();
    fileOut.close();

    std::remove(_filePath.c_str());
    std::rename((_filePath + ".tmp").c_str(), _filePath.c_str());

    return deleted;
}