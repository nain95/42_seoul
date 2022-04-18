#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Foo");
	zombie->announce();
	randomChump("randomChump");
	delete zombie;
}