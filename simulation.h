#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <set>
#include <map>
#include "user.h"
class Simulation
{
public:
    int time_;
    int error_time;
    std::vector <User*> users ;
    std::vector <Program*> programs;
    std::vector <Error *> errors;
    std::vector <Error *> appeared_errors;
    std::pair<std::vector <Error*>,int> work(int time);
    int rand(int beg,int end);
    void addUser(User*);
    void addError(Error*);
    void addProgram(Program*);
    void generateErrors();
    void generatePrograms();
    void generateUsers();
    bool fixedProbab(std::vector<std::pair<Error*,std::pair<int,int>>>, int,Error* );
    Simulation();

};

#endif // SIMULATION_H
