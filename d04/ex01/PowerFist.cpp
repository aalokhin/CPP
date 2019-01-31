#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50) { return ; }

PowerFist::PowerFist( const PowerFist &toCopy ) { *this = toCopy; }

PowerFist::~PowerFist( void ) { return ; }



PowerFist				&PowerFist::operator=( const PowerFist &toCopy )
{
	AWeapon::operator=(toCopy);
	return *this;
}


void					PowerFist::attack( void ) const
{
	
	std::cout << "* pschhh... SBAM! *" << std::endl;
}