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
    int curr_prog_t,general_t,prog_t,error_t;
    bool (*probab) (std::vector<std::pair<Error*,std::pair<int,int>>>&, int,Error* );
    std::string name;
public:

    Program * curr_prog;
    std::map<Program*,int> used_program;
    std::vector<std::pair<Error*,std::pair<int,int>>> error_history;
    User(std::string name,bool (*new_coef) (std::vector<std::pair<Error*,std::pair<int,int>>>&, int,Error*));
    std::vector<Error*> getErrors();
    std::map<Program*,int> getPrograms();
    std::string getName();
    void startWork();
    std::vector<Error*> work(int);
    void addProgram(Program*,int);
    void clear();
};

#endif // USER_H
