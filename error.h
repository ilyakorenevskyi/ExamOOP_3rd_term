#ifndef ERROR_H
#define ERROR_H
#include <vector>
#include "program.h"

class Error
{
public:
    enum  {lol,kek,cheburek} error_type ;
    std::vector <Program*> programs;
    int av_solving_time;
    Error();
};

#endif // ERROR_H
