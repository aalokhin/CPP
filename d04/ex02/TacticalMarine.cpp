
#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::~TacticalMarine( void ) { std::cout << "Aaargh ..." << std::endl; }

TacticalMarine::TacticalMarine( void )
{ std::cout << "Tactical Marine ready for battle" << std::endl; }

TacticalMarine::TacticalMarine( TacticalMarine const & marine )
{
	*this = marine;
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine&TacticalMarine::operator=( TacticalMarine const & marine )
{
	this->_HP = marine.getHP();
	return *this;
}

void	TacticalMarine::battleCry( void ) const
{
	std::cout << "For the holy PLOT !" << std::endl;
}
void	TacticalMarine::rangedAttack( void ) const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack( void ) const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}

int		TacticalMarine::getHP( void ) const { return this->_HP; }

ISpaceMarine* TacticalMarine::clone( void ) const { return new TacticalMarine(*this); }