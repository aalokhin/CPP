#ifndef Victim_hpp
#define Victim_hpp

#include <string>
#include <iostream>

class Victim {

public:
	Victim( void );
	Victim( std::string );
	Victim( const Victim & );
	~Victim( void );
	Victim	&operator=( const Victim & );

	virtual void getPolymorphed( void ) const;

	std::string	getName( void ) const;

protected:
	std::string	_name;

};

std::ostream &operator<<( std::ostream &, const Victim & );

#endif