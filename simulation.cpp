#include "simulation.h"
Simulation::Simulation()
{
    error_time=0;
}
bool Simulation::fixedProbab(std::vector<std::pair<Error*,std::pair<int,int>>> &error_history, int time,Error* error){
    if(((double)rand(1,100))/100 >=0.9) return true;
    else return false;
}
bool Simulation::genTimeProbab(std::vector<std::pair<Error*,std::pair<int,int>>>& error_history, int time,Error* error){
    double prob;
    prob=((double)rand(0,20))/100 +time*((double)rand(0,5)/100);
     std::cout <<"time" <<prob<<std::endl;
    if(prob>0.5) return true;
    else return false;

}
bool Simulation::errorsProbab(std::vector<std::pair<Error*,std::pair<int,int>>> &error_history, int time,Error* error){
    double prob =(double)rand(0,60)/100;
    for(auto i :error_history){
          if(i.first==error){
              prob+=0.03;
          }
    }
    std::cout <<"error" <<prob<<std::endl;
    if(prob>=0.47 && prob<1 ) return true;
    else return false;
}
int Simulation::rand(int beg,int end){
    static std::random_device rd;
      std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
     static std::mt19937_64 gen(seed);
     std::uniform_int_distribution<> int_dis(beg, end);
     return int_dis(gen);
}
void Simulation::addUser(User* new_user){
    users.push_back(new_user);
    for(auto &i:new_user->used_program){
        addProgram(i.first);
    }
}
void Simulation::addProgram(Program* new_prog){
    for(auto i:programs){
        if(i==new_prog) return;
    }
    programs.push_back(new_prog);
    for(auto &i:new_prog->errors){
       addError(i);
    }
}
void Simulation::addError(Error* new_error){
    for(auto i:errors){
        if(i==new_error) return;
    }
    errors.push_back(new_error);
}
void Simulation::generateErrors(){
   for(int i=0;i<10;i++){
       addError(new Error("Error "+std::to_string(1+errors.size()),rand(1,5)));
   }
}
void Simulation::generatePrograms(){
    for(int i=0;i<10;i++){
         programs.push_back(new Program("Program " +std::to_string(i+programs.size())));
        int error_count=rand(1,4);
        for(int i=0;i<error_count;i++){
            programs[programs.size()-1]->addError(errors[rand(0,errors.size()-1)]);
        }
    }
}
void Simulation::generateUsers(){
    for(int i=0;i<5;i++){
        int probabType(rand(1,3));
        switch(probabType){
        case(1):{users.push_back(new User("User" +std::to_string(1+users.size()),&Simulation::fixedProbab)); break;}
        case(2):{users.push_back(new User("User" +std::to_string(1+users.size()),&Simulation::genTimeProbab)); break;}
        case(3):{users.push_back(new User("User" +std::to_string(1+users.size()),&Simulation::errorsProbab)); break;}
          }
        int program_count=rand(1,4);
        for(int i=0;i<program_count;i++){
            users[users.size()-1]->addProgram(programs[rand(0,programs.size()-1)],rand(2,10));
        }
    }
}
void Simulation::generateSimulation(){
    generateErrors();
    generatePrograms();
    generateUsers();
}
std::pair<std::vector <Error*>,int> Simulation::work(int time){
    std::vector<Error*> temp;
    for(auto curr_user:users){
        temp=curr_user->work(time);
        appeared_errors.insert(appeared_errors.begin()+appeared_errors.size(),temp.begin(),temp.end());
    }
    for(auto err:appeared_errors){
        error_time+=err->av_solving_time;
    }
    return {appeared_errors,error_time};
}
