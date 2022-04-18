#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : humanName(humanName) , weapon(nullptr)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << humanName << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << humanName << " has no weapon " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "end" << std::endl;
}