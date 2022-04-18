#ifndef HARL
#define HARL
#include <iostream>
#include <string>

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