#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"

class HumanA{
private:
	std::string humanName;
	Weapon &weapon;
public:
	HumanA();
	HumanA(std::string humanName, Weapon &weapon);
	void attack();
	~HumanA();
};

#endif