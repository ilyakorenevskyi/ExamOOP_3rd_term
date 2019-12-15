#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <map>
#include <random>
#include <iostream>
#include <ctime>
#include "program.h"
class User
{
public:
    std::string name;
    Program * curr_prog;
    std::map <Program*,int> used_program;
    std::vector<std::pair<Error*,std::pair<int,int>>> error_history;
    int curr_prog_t,general_t,prog_t,error_t;
    int (*probab) (std::vector<std::pair<Error*,std::pair<int,int>>>, int,Error* );
    User(std::string name,int (*new_coef) (std::vector<std::pair<Error*,std::pair<int,int>>>, int,Error*));
    void startWork();
    Error* work();
    void addProgram(Program*,int);
};

#endif // USER_H
