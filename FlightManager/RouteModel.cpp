#include "RouteModel.h"

RouteModel::RouteModel(int id, std::string name, CoordinateModel start, CoordinateModel end)
{
    _id = id;
    _name = name;
    _start = start;
    _end = end;
}

RouteModel::RouteModel() = default;

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
