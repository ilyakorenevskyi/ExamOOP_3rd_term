#include "error.h"
Error::Error(std::string type, int time){
    this->error_type=type;
    av_solving_time=time;
}
