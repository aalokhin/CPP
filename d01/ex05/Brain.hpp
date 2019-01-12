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
		void	set_Attributes();
		size_t  _size;
		size_t  _age;
		std::string  _belongs_to;
};

#endif