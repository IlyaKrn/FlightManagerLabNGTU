#pragma once
#include<string>

class PlaneModel
{
private:
	int _id;
	std::string _model;
	std::string _pilot;
	int _speed;
	int _builtYear;
	std::string _country;
	bool _isFlying;



	int getId();
	std::string getModel();
	std::string getPilot();
	int getSpeed();
	int getBuiltYear();
	std::string getCounty();
	bool getIsFlying();

	void setId(int id);
	void setModel(std::string model);
	void setPilot(std::string pilot);
	void setSpeed(int speed);
	void setBuiltYear(int builtYear);
	void setCounty(std::string country);
	void setIsFlying(bool isFlying);

};
