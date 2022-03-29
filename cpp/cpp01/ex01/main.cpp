#include "Zombie.hpp"

int main()
{
	int n = 10;
	// std::cin >> n;
	Zombie *zombie = zombieHorde(10, "zombie");
	for (int i = 0; i < n ; i++)
		zombie[i].announceName();
	delete[] zombie;
}