
#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant( const SuperMutant & Copy)
{
	*this = Copy;
}

SuperMutant::~SuperMutant( void ){
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant	&SuperMutant::operator=( const SuperMutant &Copy )
{
	Enemy::operator=(Copy);
	return *this;
}

void		SuperMutant::takeDamage( int amount ){
	Enemy::takeDamage((amount - 3));
}


