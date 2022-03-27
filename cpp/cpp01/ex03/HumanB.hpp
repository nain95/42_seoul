#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"

class HumanB{
private:
	std::string humanName;
	Weapon *weapon;
public:
	HumanB(std::string humanName);
	void setWeapon(Weapon &_weapon);
	void attack();
	~HumanB();
};

#endif