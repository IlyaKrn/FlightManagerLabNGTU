#include "PlaneModel.h"

int PlaneModel::getId()
{
	return _id;
}

std::string PlaneModel::getModel()
{
	return _model;
}

std::string PlaneModel::getPilot()
{
	return _pilot;
}

int PlaneModel::getSpeed()
{
	return _speed;
}

int PlaneModel::getBuiltYear()
{
	return _builtYear;
}

std::string PlaneModel::getCounty()
{
	return _country;
}

bool PlaneModel::getIsFlying()
{
	return _isFlying;
}

void PlaneModel::setId(int id)
{
	_id = id;
}

void PlaneModel::setModel(std::string model)
{
	_model = model;
}

void PlaneModel::setPilot(std::string pilot)
{
	_pilot = pilot;
}

void PlaneModel::setSpeed(int speed)
{
	_speed = speed;
}

void PlaneModel::setBuiltYear(int builtYear)
{
	_builtYear = builtYear;
}

void PlaneModel::setCounty(std::string country)
{
	_country = country;
}

void PlaneModel::setIsFlying(bool isFlying)
{
	_isFlying = isFlying;
}
