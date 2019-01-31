#include "RadScorpion.hpp"


RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion") { std::cout << "* click click click *" << std::endl; }

RadScorpion::RadScorpion( const RadScorpion &Copy )
{ *this = Copy; }

RadScorpion::~RadScorpion( void )
{
	std::cout << "* SPROTCH *" << std::endl;
}



RadScorpion				&RadScorpion::operator=( const RadScorpion &Copy )
{
	Enemy::operator=(Copy);

	return *this;
}
