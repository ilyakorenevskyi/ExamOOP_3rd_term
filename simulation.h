#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <set>
#include <map>
#include "user.h"
class Simulation
{
public:
    int error_time;
    std::vector <User*> users ;
    std::vector <Program*> programs;
    std::vector <Error *> errors;
    std::vector <Error *> appeared_errors;
    std::pair<std::vector <Error*>,int> work(int time);
    static int rand(int beg,int end);
    void addUser(User*);
    void addError(Error*);
    void addProgram(Program*);
    void generateErrors();
    void generatePrograms();
    void generateUsers();
    void generateSimulation();
    static bool fixedProbab(std::vector<std::pair<Error*,std::pair<int,int>>> &, int,Error* );
    static bool genTimeProbab(std::vector<std::pair<Error*,std::pair<int,int>>> &, int,Error* );
    static bool errorsProbab(std::vector<std::pair<Error*,std::pair<int,int>>> &, int,Error* );
    Simulation();

};

#endif // SIMULATION_H
