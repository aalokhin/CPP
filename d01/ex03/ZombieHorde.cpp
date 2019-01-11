
#include <iostream>
#include <cstdlib>

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	system("echo \"\033[0;31m\"");
	std::cout << "Beware Zombie Horde is being created!!!" << std::endl;

	system("echo \"\033[0m\"");


	_N = N;

	system("echo \"\033[0;32m\"");

	ZombieHorde::_zombie_horde = new Zombie[_N];
	int i;
	i = 0;

	while (i < _N)
	{
		_zombie_horde[i].type = RandomType();
		_zombie_horde[i].name = RandomName();

		//std::cout << " 🧟‍♂️ ";
		i++;
	}
	std::cout << std::endl;
	system("echo \"\033[0m\"");

}

ZombieHorde::~ZombieHorde()
{
	system("echo \"\033[0;31m\"");
	std::cout << "All zombies are going to die right now!!!" << std::endl;
	system("echo \"\033[0m\"");
	delete [] _zombie_horde;
}


void			ZombieHorde::announce( void )
{
	for (int i = 0; i < _N; i++ ) {
		_zombie_horde[i].announce();
	}
}


std::string ZombieHorde::RandomName() //fix the rand non-literal characters
{
	srand(time(0));
	
	int max_len = 9;
	int len = rand() % (max_len - 1);
	int i;
	char r_name[len + 1];
	r_name[len] = '\0';

	
	for(i = 0; i < len; i++)
	{
		r_name[i] =  (char)((rand() % 52) + 65);
	}
	std::string rand_res(r_name);
	return rand_res;
}

std::string ZombieHorde::RandomType()
{
	srand(time(0));
	
	int max_len = 12;
	int len = rand() % (max_len - 1);
	int i;
	char r_name[len + 1];
	r_name[len] = '\0';

	
	for(i = 0; i < len; i++)
	{
		r_name[i] =  (char)((rand() % 52) + 65);
	}
	std::string rand_res(r_name);
	return rand_res;
}

// Zombie* ZombieHorde::randomChump()
// {
// 	Zombie *rand_zombie;

// 	system("echo \"\033[1;32m\"");

// 	//std::cout << "ZombieEvent Random Creation called" << std::endl;
// 	std::string name_r(RandomName());
// 	std::string type_r(RandomType());

// 	rand_zombie = new Zombie(name_r, type_r);
// 	//rand_zombie->announce();
// 	system("echo \"\033[0m\"");
// 	return rand_zombie;

// }
