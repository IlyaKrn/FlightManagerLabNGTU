#include "BaseRepository.h"
#include "PlaneRepository.h"
#include <fstream>
#include <sstream>

using namespace std;

PlaneRepository::PlaneRepository(string filepath)
{
    _filePath = filepath;
}

list<PlaneModel> PlaneRepository::getAll()
{
    list<PlaneModel> planes;
    ifstream file(_filePath);

    if (!file.is_open())
    {
        throw runtime_error("Íå óäàëîñü ïîëó÷èòü äîñòóï ê äàííûì");
    }
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);

        int id, speed, builtYear;
        string model, pilot, country;
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
    ifstream file(_filePath);

    if (!file.is_open())
    {
        throw runtime_error("Не удалось получить доступ к данным");
    }

    int searchId, speed, builtYear;
    string model, pilot, country;
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
    ofstream file(_filePath, ios::app);

    if (!file.is_open())
    {
        throw runtime_error("Не удалось получить доступ к файлу для сохранения");
    }

    file << data.getId() << " " << data.getModel() << " " << data.getPilot() << " "
        << data.getSpeed() << " " << data.getBuiltYear() << " " << data.getCountry() << " "
        << data.getIsFlying() << endl;

    file.close();

    return true;
}


bool PlaneRepository::deleteById(int id)
{
    //delete plane from file by id and return true
    //or return false if plane with data id not exists
    //or throw "cant access to data" if error while io operations
    return false;
}
