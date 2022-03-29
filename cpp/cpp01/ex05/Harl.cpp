#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[" << "DEBUG" << "]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
    std::cout << "[" << "INFO" << "]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{   
    std::cout << "[" << "WARNING" << "]" << std::endl;
    std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{   
    std::cout << "[" << "ERROR" << "]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
    level[0] = "DEBUG";
    list[0] = &Harl::debug;
    level[1] = "INFO";
    list[1] = &Harl::info;
    level[2] = "WARNING";
    list[2] = &Harl::warning;
    level[3] = "ERROR";
    list[3] = &Harl::error;
}
Harl::~Harl(){}

void Harl::complain(std::string level)
{
    int idx = 0;
    std::string *tmp;

    tmp = find(this->level, this->level + 4, level);
    idx = tmp - this->level;
    if (0 <= idx && idx < 4)
        (this->*list[idx])();
    // for (int i = 0; i < 4; i++)
    // {
    //     if (list[i].level == level)
	// 		(this->*list[i].function)();
    // }
} 