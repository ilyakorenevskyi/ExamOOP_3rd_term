#include "user.h"
User::User(std::string name,bool (*new_coef) (std::vector<std::pair<Error*,std::pair<int,int>>>&, int,Error*)){
    this->name = name;
    curr_prog=nullptr;
    curr_prog_t=0;
    general_t=0;
    probab=new_coef;
    error_t=0;
}
void User::startWork(){
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
std::vector<Error*> User::work(int time){
    std::vector<Error*> result;
    while(!(curr_prog_t==prog_t && time<=general_t)){
    if(error_t!=0){
        error_t--;
        continue;
    }
    if(curr_prog_t==prog_t)
        curr_prog=nullptr;
    if(curr_prog==nullptr)
        startWork();
     for(auto &err :curr_prog->errors){
            if(probab(error_history,curr_prog_t,err)){
                error_history.push_back({err,{general_t,err->av_solving_time+general_t}});
                error_t=err->av_solving_time;
                general_t+=err->av_solving_time;
                result.push_back(err);
                break;
            }
      }
        curr_prog_t++;
        general_t++;
    }
    clear();
    return result;
}
void User::addProgram(Program* new_prog,int av_time){
    used_program[new_prog]=av_time;
}
void User::clear(){
    curr_prog=nullptr;
    error_history.clear();
    general_t=0;
    error_t=0;
}
