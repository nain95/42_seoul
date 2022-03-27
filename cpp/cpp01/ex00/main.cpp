#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Foo");
	zombie->announceName();
	randomChump("randomChump");
	delete zombie;
}