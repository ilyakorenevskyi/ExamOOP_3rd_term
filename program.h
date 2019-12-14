#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>
#include <vector>
#include "error.h"
class Program
{
public:
    std::string name;
    std::vector <Error *> errors;
    Program(std::string);
    void addError(Error*);
};

#endif // PROGRAM_H
