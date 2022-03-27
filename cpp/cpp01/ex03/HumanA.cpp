#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon &weapon) : humanName(humanName), weapon(weapon)
{
}

void HumanA::attack()
{
	std::cout << humanName << " attacks with his " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "end" << std::endl;
}