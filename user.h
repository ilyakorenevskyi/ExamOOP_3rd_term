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
    std::map<Program*,int> used_program;
    std::vector<std::pair<Error*,std::pair<int,int>>> error_history;
    int curr_prog_t,general_t,prog_t,error_t;
    bool (*probab) (std::vector<std::pair<Error*,std::pair<int,int>>>&, int,Error* );
    User(std::string name,bool (*new_coef) (std::vector<std::pair<Error*,std::pair<int,int>>>&, int,Error*));
    void startWork();
    std::vector<Error*> work(int);
    void addProgram(Program*,int);
    void clear();
};

#endif // USER_H
