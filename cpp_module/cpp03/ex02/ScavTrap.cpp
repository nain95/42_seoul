#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "default constructor called" << std::endl;
    this->name = "NULL";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

void ClapTrap::attack(const std::string & target)
{
    std::cout << "ClapTrap " << this->name << " attack " << target << " , causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((unsigned int)energyPoints <= amount)
    {
        energyPoints = 0;
        std::cout << name << " died" <<  std::endl;
    }
    else
    {
        energyPoints -= amount;
        std::cout << name << "take Damage : " << amount << " present energy = " << energyPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints + amount < 100)
    {
        energyPoints += amount;
    }
    else
    {
        energyPoints = 100;
    }
    
    std::cout << "ClapTrap <" << this->name << "> be Repaired <" << amount << ">" <<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{

}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
    name = src.name;
    hitPoints = src.hitPoints;
    energyPoints = src.energyPoints;
    attackDamage = src.attackDamage;
    return (*this);
}