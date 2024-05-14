#pragma once
#include<string>
#include"CoordinateModel.h"

class RouteModel
{
private:
	int _id;
	std::string _name;
	CoordinateModel _start;
	CoordinateModel _end;

public:
	RouteModel(int id, std::string name, CoordinateModel start, CoordinateModel end);
	RouteModel();

	int getId();
	std::string getName();
	CoordinateModel getStart();
	CoordinateModel getEnd();

	void setId(int id);
	void setName(std::string name);
	void setStart(CoordinateModel start);
	void setEnd(CoordinateModel end);
	bool operator==(const RouteModel& other) const {
		return _id == other._id;
	}
};

