#include "Mighty.hpp"


Mighty::Mighty(): Sorcerer() { }

Mighty::Mighty( std::string name, std::string title ): Sorcerer(name, title)
{
	 std::cout << "Hurra die Welt geht unter!!!!" << std::endl;
	this->_name = name;
	this->_title = title;
	std::cout << " He is mighty and brave!" << std::endl;
}

Mighty::Mighty( const Mighty &Copy )
{
	*this = Copy;
	std::cout << "I duplicate ahahahahhaaa......" << std::endl;
}

Mighty::~Mighty( void ) { std::cout << "You ungrateful bastartds will regret this" << std::endl; }



Mighty				&Mighty::operator=( const Mighty &Copy )
{
	this->_name = Copy.getName();
	this->_title = Copy.getTitle();
	return *this;
}


void Mighty::get_back_to_life( const Victim &vict )
{	
	std::cout << "The Victim " << vict.getName() << " is now back to life. I am being kind these days." << std::endl;
}

