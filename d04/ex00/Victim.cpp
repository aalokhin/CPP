#include "Victim.hpp"

Victim::Victim() { std::cout << "Some random victim called " << _name << " just popped !" << std::endl; }

Victim::Victim( std::string name ) : _name(name)
{ std::cout << "Some random victim called " << _name << " just popped !" << std::endl; }

Victim::Victim( const Victim &Copy )
{
	*this = Copy;
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::~Victim() { std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl; }

Victim				&Victim::operator=( const Victim &Copy )
{
	this->_name = Copy.getName();
	return *this;
}

void				Victim::getPolymorphed( void ) const
{ std::cout << _name << " has been turned into a cute little sheep !" << std::endl; }



std::string				Victim::getName( void ) const
{
	return this->_name;
}

std::ostream			&operator<<( std::ostream &o, const Victim &v )
{
	o << "I'm " << v.getName() << " and I like otters !" << std::endl;

	return o;
}