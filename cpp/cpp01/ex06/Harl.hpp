#ifndef HARL
#define HARL
#include <iostream>

class karen;
typedef struct s_functionList{
    std::string level;
    void (karen::*function)(void);
}               t_functionList;
class Harl{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void etc(void);
    // t_functionList list[4];
    void (Harl::*list[4])(void);
    std::string level[4];
public:
    void complain(std::string level);
    ~Harl();
    Harl();
};
#endif