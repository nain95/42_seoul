#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}
void Harl::info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}
void Harl::warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}
void Harl::error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::etc()
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
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
    int idx = 4;

    for (int i = 0 ; i < 4 ; ++i)
        if (level == this->level[i])
            {
                idx = i;
                break;
            }
    switch(idx)
    {
        case 0:
            (this->*list[0])();
        case 1:
            (this->*list[1])();
        case 2:
            (this->*list[2])();
        case 3:
            (this->*list[3])();
            break;
        default:
            etc();
    }
}