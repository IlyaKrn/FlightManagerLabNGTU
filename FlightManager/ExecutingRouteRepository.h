#pragma once
#include "BaseRepository.h"
#include "ExecutingRouteModel.h"

class ExecutingRouteRepository : public BaseRepository<ExecutingRouteModel> 
{
public:
    ExecutingRouteRepository(std::string filePath) : BaseRepository<ExecutingRouteModel>(filePath) {}
    std::list<ExecutingRouteModel> getAll() override;
    ExecutingRouteModel getById(int id) override;
    bool save(PlaneModel data) override;
    bool deleteById(int id) override;
};