#include "Weapon.hpp"


Weapon::Weapon(std::string weapon_type) : _type(weapon_type){};

Weapon::~Weapon(void){};


const std::string		&Weapon::getType(void) const
{
	return _type;
}

void					Weapon::setType(std::string weapon_type)
{
	_type = weapon_type;
}
