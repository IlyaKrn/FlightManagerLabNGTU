#include "ExecutingRouteRepository.h"
#include<string>
using namespace std;

ExecutingRouteRepository::ExecutingRouteRepository()
{
	_executingRoutes = list<ExecutingRouteModel>();
}

list<ExecutingRouteModel> ExecutingRouteRepository::getAll()
{
	return _executingRoutes;
}

ExecutingRouteModel ExecutingRouteRepository::getById(int id)
{
	list<ExecutingRouteModel>::iterator it = _executingRoutes.begin();
	for (int i = 0; i < _executingRoutes.size(); i++) {
		if (it->getRouteId() == id)
			return *it;
		++it;
	}
	throw string("not found executingRoute with id " + id);
}

bool ExecutingRouteRepository::save(ExecutingRouteModel data)
{
	list<ExecutingRouteModel>::iterator it = _executingRoutes.begin();
	for (int i = 0; i < _executingRoutes.size(); i++) {
		if (it->getRouteId() == data.getRouteId()) 
		{
			*it = data;
			return true;
		}
		++it;
	}
	_executingRoutes.push_back(data);
	return true;
}

bool ExecutingRouteRepository::deleteById(int id)
{
	list<ExecutingRouteModel>::iterator it = _executingRoutes.begin();
	for (int i = 0; i < _executingRoutes.size(); i++) {
		if (it->getRouteId() == id)
		{
			_executingRoutes.erase(it);
			return true;
		}
		++it;
	}
	throw string("not found executingRoute with id " + id);
}
