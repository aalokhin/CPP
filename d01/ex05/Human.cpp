#include "Human.hpp"

Human::Human(){};

Human::~Human(){};

std::string Human::identify()
{
	return(_brain.identify());
}

const Brain &Human::getBrain()
{
  return (_brain);
}

// int main()
// {
// 	Human new_human;

// 	new_human.identify();

// 	return (0);
// }