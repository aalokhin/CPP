#include "Rebel.hpp"

Rebel::Rebel( void ): Victim()  { std::cout << "Hella guys!" << std::endl; }

Rebel::~Rebel( void ) {
	system("echo \"\033[0;31m\"");

std::cout << "You'll regret doing this!" << std::endl;
	system("echo \"\033[0m\"");
}

Rebel::Rebel( std::string name): Victim(name) { this->_name = name; std::cout << "Hella guys!" << std::endl; }

Rebel::Rebel( const Rebel &Copy )
{
	system("echo \"\033[0;31m\"");

	*this = Copy;
	std::cout << "I am not a victim." << std::endl;
	system("echo \"\033[0m\"");

}

Rebel	&Rebel::operator=( const Rebel &Copy )
{
	this->_name = Copy.getName();
	return *this;
}

void				Rebel::getPolymorphed( void ) const
{
	system("echo \"\033[0;31m\"");
	std::cout << _name << " is still alive, safe and sound! I can resist, you are nothing to me!" << std::endl;
	system("echo \"\033[0m\"");
}
