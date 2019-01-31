#ifndef HUMANA_hpp
#define HUMANA_hpp

#include "Weapon.hpp"
#include <iostream>

class HumanA {

public:
	HumanA(std::string name, const Weapon &weapon_type);
	~HumanA(void);
	void					attack(void) const;
	const std::string		_name;
	const Weapon 		&	_weapon;

};

#endif


