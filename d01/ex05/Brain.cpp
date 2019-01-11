#include "Brain.hpp"

#include <sstream>

Brain::Brain(){};

Brain::~Brain(){};

std::string Brain::identify() const
{

	std::string res_str;




	std::stringstream buffer;

	buffer << this << std::endl;



	

	res_str = buffer.str();
	size_t length = res_str.length();
	res_str.erase((length - 1),1);

	//std::cout << "~~~>" << res_str << "<~~~" << std::endl;
	

	return(res_str);
}

// int main()
// {
// 	Brain br;
// 	br.identify();
// }