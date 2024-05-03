#include "PlaneRepository.h"

std::list<PlaneModel> PlaneRepository::getAll()
{
    //get and return all planer from file
    //or throw "cant access to data" if error while io operations
    return std::list<PlaneModel>();
}

PlaneModel PlaneRepository::getById(int id)
{
    //get and return plane by id; if not exists return nullptr
    //or throw "cant access to data" if error while io operations
    return PlaneModel();
}

bool PlaneRepository::save(PlaneModel data)
{
    //create and writre to file new plane with unique id if data id is -1
    //update and writre to file plane by data id
    //or throw "cant access to data" if error while io operations
    //or throw "data cant be nullptr" if data is nullptr
    return false;
}

bool PlaneRepository::deleteById(int id)
{
    //delete plane from file by id and return true
    //or return false if plane with data id not exists
    //or throw "cant access to data" if error while io operations
    return false;
}
