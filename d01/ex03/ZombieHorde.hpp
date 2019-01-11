
#ifndef ZOMBIEHORDE_HPP

#define ZOMBIEHORDE_HPP

#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"


class ZombieHorde
{
	public:
		ZombieHorde(int N);
		~ZombieHorde();
		void			announce(void);

	//private:
		int				_N;
		Zombie			*_zombie_horde;
		std::string		RandomName();
		std::string 	RandomType();
};

#endif
