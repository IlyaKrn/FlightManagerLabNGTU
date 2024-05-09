#include "CoordinateModel.h"

CoordinateModel::CoordinateModel(double x, double y)
{
    _x = x;
    _y = y;
}

CoordinateModel::CoordinateModel() = default;

double CoordinateModel::getX()
{
    return _x;
}

double CoordinateModel::getY()
{
    return _y;
}

void CoordinateModel::setX(double x)
{
    _x = x;
}

void CoordinateModel::setY(double y)
{
    _y = y;
}
