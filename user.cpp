#include "user.h"
User::User(std::string name,int (*new_coef) (std::vector<std::pair<Error*,std::pair<int,int>>>, int,Error*)){
    this->name = name;
    curr_prog_t=0;
    general_t=0;
    probab=new_coef;
}
