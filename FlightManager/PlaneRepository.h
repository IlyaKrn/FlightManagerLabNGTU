#pragma once
#include"BaseFileRepository.h"
#include"PlaneModel.h"
#include<list>

class PlaneRepository : public BaseFileRepository<PlaneModel>
{
public:
	PlaneRepository(std::string filepath);
	PlaneRepository();
	std::list<PlaneModel> getAll() override;
	PlaneModel getById(int id) override;
	PlaneModel save(PlaneModel data) override;
	bool deleteById(int id) override;
};

