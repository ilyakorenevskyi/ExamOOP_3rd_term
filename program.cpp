#include "program.h"
Program::Program(std::string name){
    this->name=name;
}
void Program::addError(Error* new_error){
   errors.insert(new_error);
}

