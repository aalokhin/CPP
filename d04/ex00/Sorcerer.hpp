#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer {

public:
	Sorcerer( void );
	Sorcerer( std::string name, std::string title );
	Sorcerer( const Sorcerer &Copy );
	~Sorcerer( void );
	Sorcerer &operator=( const Sorcerer &Copy );
	std::string	getName( void ) const;
	std::string	getTitle( void ) const;

	void	polymorph( const Victim & );
protected:
	std::string	_name;
	std::string	_title;

};

std::ostream	&operator<<( std::ostream &o, const Sorcerer &s );

#endif
