#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <map>
#include "program.h"
#include "error.h"
class User
{
public:
    std::string name;
    std::map <Program*,int > used_program;
    std::map <Error*,std::pair<int,int>> error_history;
    int curr_program_t;
    int general_curr_t;
    int (*coeff) ();
    User();
};

#endif // USER_H
