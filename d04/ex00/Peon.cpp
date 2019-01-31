#include "Peon.hpp"

Peon::Peon( void ): Victim()  { std::cout << "Zog zog." << std::endl; }

Peon::~Peon( void ) { std::cout << "Bleuark..." << std::endl; }

Peon::Peon( std::string name): Victim(name) { this->_name = name; std::cout << "Zog zog." << std::endl; }

Peon::Peon( const Peon &Copy )
{
	*this = Copy;
	std::cout << "Zog zog." << std::endl;
}

Peon	&Peon::operator=( const Peon &Copy )
{
	this->_name = Copy.getName();
	return *this;
}

void				Peon::getPolymorphed( void ) const
{ std::cout << _name << " has been turned into a pink pony !" << std::endl; }
