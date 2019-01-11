#ifndef HUMAN_HPP
#define HUMAN_HPP


#include <iostream>
#include <cstdlib>
#include "Brain.hpp"

class Human
{
	public:
		Human();
		~Human();
		const Brain _brain;

		std::string identify();


		const Brain &getBrain();
};

#endif
