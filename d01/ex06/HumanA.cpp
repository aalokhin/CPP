#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon &weapon_type)
: _name(name), _weapon(weapon_type) {};

HumanA::~HumanA(void) {};



void				HumanA::attack( void ) const
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}