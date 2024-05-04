#pragma once
#include"RouteModel.h"
#include<list>
#include"BaseRepository.h"

class RouteRepository : BaseRepository<RouteModel>
{
	std::list<RouteModel> getAll() override;
	RouteModel getById(int id) override;
	bool save(RouteModel data) override;
	bool deleteById(int id) override;
};

