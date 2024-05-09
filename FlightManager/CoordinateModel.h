#pragma once
class CoordinateModel
{
private:
	double _x;
	double _y;

public:
	CoordinateModel(double x, double y);
	CoordinateModel();

	double getX();
	double getY();

	void setX(double x);
	void setY(double y);
};

