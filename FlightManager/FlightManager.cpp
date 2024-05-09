#include <iostream>
#include"ExecutingRouteRepository.h"

using namespace std;

int main()
{
    ExecutingRouteRepository repo = ExecutingRouteRepository();
    repo.save(ExecutingRouteModel(0, 2, 0));
    repo.save(ExecutingRouteModel(1, 0, 0));
    repo.save(ExecutingRouteModel(2, 2, 0));
    repo.save(ExecutingRouteModel(3, 5, 0));
    repo.save(ExecutingRouteModel(4, 5, 0));
    repo.save(ExecutingRouteModel(5, 5, 0));
    repo.save(ExecutingRouteModel(6, 5, 0));

    repo.deleteById(5);

   // cout << repo.getById(5).getPlaneId() << endl;


    std::cout << "Hello World!\n";
}