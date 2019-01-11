#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>
#include <cstdlib>

class Brain
{
	public:
		Brain();
		~Brain();
		std::string identify() const;
};

#endif