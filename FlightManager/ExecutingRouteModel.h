#pragma once
class ExecutingRouteModel
{
private:
	int _routeId;
	int _planeId;
	long int _timestart;

public:

	int getRouteId();
	int getPlaneId();
	long int getTimestart();

	void setRouteId(int routeId);
	void setPlaneId(int planeId);
	void setTimestart(long int timestart);

};

