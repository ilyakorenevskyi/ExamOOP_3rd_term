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
Error* User::work(bool end){
    if(error_t!=0){
        error_t--;
        return nullptr;
    }
    if(curr_prog_t==prog_t){
        std::cout <<"Prog is done" <<std::endl;
        curr_prog=nullptr;
    }
    if(curr_prog==nullptr && end){
        return nullptr;
    }
    else if(curr_prog==nullptr){
        startWork();
        general_t++;
        curr_prog_t++;
    }
    else{
        for(auto &err :curr_prog->errors){
            if(probab(error_history,curr_prog_t,err)){
                error_history.push_back({err,{general_t,err->av_solving_time+general_t}});
                error_t=err->av_solving_time;
                general_t+=err->av_solving_time;
                return err;
            }
        }
        curr_prog_t++;
        general_t++;
    }
    return nullptr;
}
void User::addProgram(Program* new_prog,int av_time){
    used_program[new_prog]=av_time;
}
void User::clear(){
    error_history.clear();
    general_t=0;
    error_t=0;
}
