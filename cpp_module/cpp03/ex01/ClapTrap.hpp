#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
public:
    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(ClapTrap const & src);
    ClapTrap & operator=(ClapTrap const & src);

protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
};

#endif