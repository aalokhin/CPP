#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5, 21) { return ; }

PlasmaRifle::PlasmaRifle( const PlasmaRifle &Copy ) { *this = Copy; }

PlasmaRifle::~PlasmaRifle( void ) { return ;}

PlasmaRifle				&PlasmaRifle::operator=( const PlasmaRifle &Copy )
{ AWeapon::operator=(Copy); 	return *this; }

void					PlasmaRifle::attack( void ) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}