#include "program.h"
Program::Program(std::string name){
    this->name=name;
}
void Program::addError(Error* new_error){
   for(auto i:errors){
       if(i==new_error) return;
   }
   errors.push_back(new_error);
}
std::string Program::getName(){
    return name;
}
