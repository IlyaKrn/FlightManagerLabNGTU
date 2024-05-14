#pragma once
class ExecutingRouteModel
{
private:
	int _routeId;
	int _planeId;
	long int _timestart;

public:
	ExecutingRouteModel(int routeId, int planeId, long int timestart);
	ExecutingRouteModel();

	int getRouteId();
	int getPlaneId();
	long int getTimestart();

	void setRouteId(int routeId);
	void setPlaneId(int planeId);
	void setTimestart(long int timestart);
	bool operator==(const ExecutingRouteModel& other) const {
		return _planeId == other._planeId && _routeId == other._routeId;
	}
	
};

