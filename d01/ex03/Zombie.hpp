#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>
#include <cstdlib>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		std::string type;
		std::string name;
		void announce();
};

#endif