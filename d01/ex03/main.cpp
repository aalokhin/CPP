
#include <iostream>

#include "ZombieHorde.hpp"

int main(void)
{
	int N = 0;
	system("echo \"\033[0;94m\"");


	std::cout << "How many zombies do you want to have in your allmighty horde?" << std::endl;
	std::cin >> N;
	if (std::cin.fail())
	{
		std::cout << "Error on input, try again!" << std::endl;
		exit(0);
	}

	srand(time(NULL));
	ZombieHorde	zombie_army(N);

	zombie_army.announce();
	

	/* system("leaks -q zombie_horde"); */

	return (0);
}
