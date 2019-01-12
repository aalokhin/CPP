#include "Brain.hpp"

#include <sstream>

Brain::Brain(){
	Brain::set_Attributes();
};

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

void	Brain::set_Attributes()
{
	std::cout << "To whom does the brsain belog?" << std::endl;
	std::cin >> _belongs_to;
	std::cout << "How old is the owner?" << std::endl;
	std::cin >> _age;
	std::cout << "How big is the brain?" << std::endl;
	std::cin >> _size;

}


// int main()
// {
// 	Brain br;
// 	br.identify();
// }