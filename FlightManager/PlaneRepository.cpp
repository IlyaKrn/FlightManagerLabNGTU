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
        throw runtime_error("Falied to access data");
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
        throw runtime_error("Falied to access data");
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
            break;
        }
    }

    file.close();

    return plane;
}


bool PlaneRepository::save(PlaneModel data)
{
    if (data.getId() != -1) {
        ofstream file(_filePath);
        deleteById(data.getId());
        file << data.getId() << " " << data.getModel() << " " << data.getPilot() << " "
            << data.getSpeed() << " " << data.getBuiltYear() << " " << data.getCountry() << endl;
        return data.getId();
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
            throw runtime_error("Failed to access data");
        }

        file << data.getId() << " " << data.getModel() << " " << data.getPilot() << " "
            << data.getSpeed() << " " << data.getBuiltYear() << " " << data.getCountry() << endl;

        file.close();

        return data.getId();
    }
}


bool PlaneRepository::deleteById(int id)
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
