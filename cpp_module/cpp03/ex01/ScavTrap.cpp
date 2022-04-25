#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap name constructor called" << name << std::endl;
}

ScavTrap::ScavTrap()
{
    name = "NULL";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & s) : ClapTrap(s)
{

}

ScavTrap& ScavTrap::operator=(ScavTrap const& s)
{
    ClapTrap::operator=(s);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
    std::cout <<  "ScavTrap " << this->name << " attack " << target << " , causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    if(energyPoints)
        std::cout << "guardGateOpen" << std::endl;
    else
        std::cout << "not guardGateOpen" << std::endl;
}


