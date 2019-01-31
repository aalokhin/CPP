
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


std::string ZombieHorde::RandomName() 
{
	int len = 6;
	const std::string	alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	int i;

	i = 0;

	char r_name[len + 1];
	r_name[len] = '\0';
	for(i = 0; i < len; i++)
	{
		r_name[i] =  alphabet[(get_Rand_Int(52))];
	}
	std::string rand_res(r_name);
	return rand_res;
}

int					ZombieHorde::get_Rand_Int(unsigned int from)
{

	int	i = (rand() % from);

	return ( (i >= 0) ? i : 0 );
}


std::string 		ZombieHorde::RandomType()
{
	const std::string		zombie_types[9] = 
	{"Stalker", "Spitter", "Ghoul", "Runner", "Romero", "Vodoo", "Lazy", "Crawlers", "Screamer"};
	return zombie_types[get_Rand_Int(9)];
}
