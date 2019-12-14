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
    void startWork(){
       static std::random_device rd;
        std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
        static std::mt19937_64 gen(seed);
        std::uniform_int_distribution<> int_dis1(0, used_program.size()-1);
        std::map<Program*,int>::iterator it = used_program.begin();
        std::advance( it, int_dis1(gen) );
        curr_prog= it->first;
        std::uniform_int_distribution<> int_dis2(used_program[curr_prog]-2, used_program[curr_prog]+2);
        prog_t=int_dis2(gen);
         curr_prog_t = 0;
    }
    void work(){
        if(error_t!=0){
            error_t--;
            return;
        }
        if(curr_prog_t==prog_t)
            curr_prog=nullptr;
        if(curr_prog==nullptr){startWork();curr_prog_t++;general_t++;}
        else{
            for(auto err :curr_prog->errors){
                if(probab(error_history,curr_prog_t,err)){
                    error_history.push_back({err,{curr_prog_t,err->av_solving_time}});
                    error_t=err->av_solving_time;
                    general_t+=err->av_solving_time;
                }
                curr_prog_t++;
            }
        }
    }
};

#endif // USER_H
