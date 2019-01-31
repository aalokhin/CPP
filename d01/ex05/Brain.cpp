#include "Brain.hpp"

#include <sstream>

Brain::Brain()
{
	Brain::set_Attributes();
};

Brain::~Brain(){};

std::string Brain::identify() const
{

	std::string 	res_str;
	std::stringstream buffer;

	buffer << this;
	res_str = buffer.str();

	return(res_str);
}

void	Brain::set_Attributes()
{
	std::cout << "To whom does the brain belong?" << std::endl;
	std::cin >> _belongs_to;
	if (std::cin.fail())
	{
		std::cout << "Error on input, try again!" << std::endl;
		exit(0);
	}

	std::cout << "How old is the owner?" << std::endl;
	std::cin >> _age;
	if (std::cin.fail())
	{
		std::cout << "Error on input, try again!" << std::endl;
		exit(0);
	}

	std::cout << "How big is the brain?" << std::endl;
	std::cin >> _size;
	if (std::cin.fail())
	{
		std::cout << "Error on input, try again!" << std::endl;
		exit(0);
	}


}
