#ifndef HARL
#define HARL
#include <iostream>
#include <string>
#include <algorithm>

// class Harl;

// typedef struct s_functionList{
//     std::string level;
//     void (Harl::*function)(void);
// }             t_functionList;

class Harl{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void (Harl::*list[4])(void);
    std::string level[4];
public:
    void complain(std::string level);
    ~Harl();
    Harl();
};

#endif 