
#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::string z_name;

	ZombieEvent *zombie_creation = NULL;

	std::cout << "Please enter the name for your Zombie" << std::endl;
	std::cin >> z_name;
	if (std::cin.fail())
		exit (0);



	Zombie *new_born = zombie_creation->newZombie(z_name);
	new_born->announce();
	delete new_born;


	std::cout << "Zombie with random name" << std::endl;
	Zombie *random_born = zombie_creation->randomChump();
	random_born->announce();
	delete random_born;

	system("leaks -q zombie");
	return (0);
}



