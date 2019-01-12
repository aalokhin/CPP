#ifndef HUMANB_hpp
#define HUMANB_hpp

#include "Weapon.hpp"
#include <iostream>

class HumanB {

public:
	HumanB(std::string name);
	~HumanB(void);

	void					attack(void);
	void					setWeapon(Weapon &weapon);
	
	const std::string		_name;
	const Weapon*			_weapon;

};

#endif
