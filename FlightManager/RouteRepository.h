#pragma once
#include"BaseFileRepository.h"
#include"RouteModel.h"
#include<list>

class RouteRepository : public BaseFileRepository<RouteModel>
{
public:
	RouteRepository(std::string filepath);
	std::list<RouteModel> getAll() override;
	RouteModel getById(int id) override;
	RouteModel save(RouteModel data) override;
	bool deleteById(int id) override;
};

