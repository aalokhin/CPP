#ifndef REBEL_HPP
# define REBEL_HPP
#include "Victim.hpp"

class Rebel: public Victim {

public:
	Rebel();
	Rebel( std::string );
	Rebel( const Rebel &Copy );
	~Rebel();
	Rebel	&operator=( const Rebel &Copy );

	virtual void getPolymorphed() const;
	

protected:
	std::string	_name;

};

#endif

