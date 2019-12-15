#ifndef ERROR_H
#define ERROR_H
#include <string>
class Error
{
public:
    std::string error_type ;
    int av_solving_time;
    Error(std::string,int);
};

#endif // ERROR_H
