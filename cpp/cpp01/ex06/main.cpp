#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl ex = Harl();
    std::string level;

    if (ac == 2)
    {
        level = av[1];
        ex.complain(level);
    }
}