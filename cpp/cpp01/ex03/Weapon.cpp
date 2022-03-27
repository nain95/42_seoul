#include "Weapon.hpp"

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string const &Weapon::getType()
{
	return type;
}

Weapon::Weapon(std::string type) : type(type){}

Weapon::~Weapon()
{
}
