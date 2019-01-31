#ifndef PEON_HPP
#define PEON_HPP
#include "Victim.hpp"
#include <string>
#include <iostream>

class Peon: public Victim {

public:
	Peon();
	Peon( std::string );
	Peon( const Peon &Copy );
	~Peon();
	Peon	&operator=( const Peon &Copy );

	virtual void getPolymorphed() const;
	

protected:
	std::string	_name;

};

#endif

