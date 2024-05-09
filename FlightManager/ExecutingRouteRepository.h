#pragma once
#include "BaseRepository.h"
#include "ExecutingRouteModel.h"

class ExecutingRouteRepository : public BaseRepository<ExecutingRouteModel>
{
private:
    std::list<ExecutingRouteModel> _executingRoutes;
public:
    ExecutingRouteRepository();

    std::list<ExecutingRouteModel> getAll() override;
    ExecutingRouteModel getById(int id) override;
    bool save(ExecutingRouteModel data) override;
    bool deleteById(int id) override;
};