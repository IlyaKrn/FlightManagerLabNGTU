#include "RouteModel.h"

int RouteModel::getId()
{
    return _id;
}

std::string RouteModel::getName()
{
    return _name;
}

CoordinateModel RouteModel::getStart()
{
    return _start;
}

CoordinateModel RouteModel::getEnd()
{
    return _end;
}

void RouteModel::setId(int id)
{
    _id = id;
}

void RouteModel::setName(std::string name)
{
    _name = name;
}

void RouteModel::setStart(CoordinateModel start)
{
    _start = start;
}

void RouteModel::setEnd(CoordinateModel end)
{
    _end = end;
}
