
#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>


int main()
{
	std::string z_name;

	ZombieEvent *zombie_creation = NULL;
	srand(time(NULL));

	std::cout << "Please enter the name for your Zombie" << std::endl;
	std::cin >> z_name;
	if (std::cin.fail())
	{
		std::cout << "Error on input, try again!" << std::endl;
		exit(0);
	}

	Zombie *new_born = zombie_creation->newZombie(z_name);
	new_born->announce();
	delete new_born;


	system("echo \"\033[1;35m\"");
	std::cout << "And now time for random zombie!!!" << std::endl;
	system("echo \"\033[0m\"");

	Zombie *random_born = zombie_creation->randomChump();
	random_born->announce();
	delete random_born;
	/* system("leaks -q zombie"); */
	return (0);
}



