#include <iostream>
#include <cstdlib>

int			main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string *p_str;
	std::string &r_str = str;

	p_str = &str;
	system("echo \"\033[1;31m\"");

	std::cout << str << std::endl;
	std::cout << p_str << std::endl;
	std::cout << *p_str << std::endl;
	std::cout << r_str << std::endl;
	
	*p_str = "another string";
	system("echo \"\033[1;35m\"");

	std::cout << str << std::endl;
	std::cout << p_str << std::endl;
	std::cout << *p_str << std::endl;
	std::cout << r_str << std::endl;
	system("echo \"\033[0;32m\"");

	r_str = "and string2";
	std::cout << str << std::endl;
	std::cout << p_str << std::endl;
	std::cout << *p_str << std::endl;
	std::cout << r_str << std::endl;

	system("echo \"\033[0m\"");


	return (0);
}


	

