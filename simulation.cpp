#include "simulation.h"
Simulation::Simulation()
{

}
bool Simulation::fixedProbab(std::vector<std::pair<Error*,std::pair<int,int>>> error_history, int time,Error* error){
    return 1;
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
    programs.push_back(new_prog);
    for(auto &i:new_prog->errors){
       errors.push_back(i);
    }
}
void Simulation::addError(Error* new_error){
    errors.push_back(new_error);
}
void Simulation::generateErrors(){
   for(int i=0;i<10;i++){
       addError(new Error("Error "+std::to_string(i+errors.size()),rand(0,5)));
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
    for(int i=0;i<10;i++){
        users.push_back(new User("User" +std::to_string(i+users.size()),fixedProbab));
        int program_count=rand(1,4);
        for(int i=0;i<program_count;i++){
            users[users.size()-1]->addProgram(programs[rand(0,programs.size()-1)],rand(2,10));
        }
    }
}
