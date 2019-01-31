#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent();
		~ZombieEvent();
		void setZombieType(Zombie *new_zombie);
		Zombie* newZombie(std::string name);
		std::string RandomName();
		std::string RandomType();
		Zombie* randomChump();
	private:
		int	get_Rand_Int(unsigned int from );


};

#endif