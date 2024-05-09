#include "BaseRepository.h"
#include "PlaneRepository.h"
#include "PlaneModel.h"
#include <fstream>
#include <sstream>

std::list<PlaneModel> PlaneRepository::getAll()
{
    std::list<PlaneModel> planes;
    std::ifstream file(_filePath);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось получить доступ к данным");
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        int id, speed, builtYear;
        std::string model, pilot, country;
        bool isFlying;

        if (!(iss >> id >> model >> pilot >> speed >> builtYear >> country >> isFlying))
        {
            continue;
        }

        PlaneModel plane;
        plane.setId(id);
        plane.setModel(model);
        plane.setPilot(pilot);
        plane.setSpeed(speed);
        plane.setBuiltYear(builtYear);
        plane.setCountry(country);
        plane.setIsFlying(isFlying);
        
        planes.push_back(plane);
        
        
    }

    file.close();

    
    return planes;
}


PlaneModel PlaneRepository::getById(int id)
{
    std::ifstream file(_filePath);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось получить доступ к данным");
    }

    int searchId, speed, builtYear;
    std::string model, pilot, country;
    bool isFlying;

    PlaneModel plane;
    while (file >> searchId >> model >> pilot >> speed >> builtYear >> country >> isFlying)
    {
        if (searchId == id)
        {
            plane.setId(searchId);
            plane.setModel(model);
            plane.setPilot(pilot);
            plane.setSpeed(speed);
            plane.setBuiltYear(builtYear);
            plane.setCountry(country);
            plane.setIsFlying(isFlying);
            break;
        }
    }

    file.close();

    return plane;
}


bool PlaneRepository::save(PlaneModel data)
{
    std::ofstream file(_filePath, std::ios::app);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось получить доступ к файлу для сохранения");
    }

    file << data.getId() << " " << data.getModel() << " " << data.getPilot() << " "
        << data.getSpeed() << " " << data.getBuiltYear() << " " << data.getCountry() << " "
        << data.getIsFlying() << std::endl;

    file.close();

    return true;
}


bool PlaneRepository::deleteById(int id)
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