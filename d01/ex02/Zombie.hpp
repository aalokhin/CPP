#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>


class Zombie
{
	public:
		Zombie(std::string name, std::string type);
		~Zombie();
		std::string type;
		std::string name;
		void announce();
};

#endif