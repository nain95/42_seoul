#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("NULL"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
}

void ClapTrap::attack(const std::string & target)
{
    std::cout << "ClapTrap " << this->name << " attack " << target << " , causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((unsigned int)hitPoints <= amount)
    {
        hitPoints = 0;
        std::cout << name << " died" <<  std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << name << "take Damage : " << amount << " present HP = " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints + amount < 100)
    {
        hitPoints += amount;
    }
    else
    {
        hitPoints = 100;
    }
    
    std::cout << "ClapTrap <" << this->name << "> be Repaired <" << amount << ">" <<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    *this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
    if (this != &src)
    {
        name = src.name;
        hitPoints = src.hitPoints;
        energyPoints = src.energyPoints;
        attackDamage = src.attackDamage;
    }
    return (*this);
}