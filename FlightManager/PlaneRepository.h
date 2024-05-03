#pragma once
#include"BaseRepository.h"
#include"PlaneModel.h"
#include<list>

class PlaneRepository : BaseRepository<PlaneModel>
{
	std::list<PlaneModel> getAll() override;
	PlaneModel getById(int id) override;
	bool save(PlaneModel data) override;
	bool deleteById(int id) override;
};

