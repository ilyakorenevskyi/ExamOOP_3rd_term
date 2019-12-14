#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <map>

#include "user.h"
class Simulation
{
public:
    int time;
    int error_time;
    std::vector <User*> users;
    std::vector <Program*> programs;
    std::vector <Error *> errors;
    std::vector <Error *> appeared_errors;
    Simulation();

};

#endif // SIMULATION_H
