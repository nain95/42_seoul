#include "Zombie.hpp"

int main()
{
	int n;
	std::cin >> n;
	Zombie *zombie = zombieHorde(n, "zombie");
	for (int i = 0; i < n ; i++)
		zombie[i].announceName();
	delete[] zombie;
}