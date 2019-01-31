#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <exception>
#include <iostream>
#include <string>

int				main(void)
{
	OfficeBlock				office;
	Intern					intern;
	Bureaucrat				boss1("Boss1", 50);
	Bureaucrat				boss2("Boss2", 2);

	office.setIntern(intern);
	office.setSigner(boss1);
	office.setExecutor(boss2);
	std::cout << BLUE << "Let's get down to business now... " << NORMAL << std::endl;
	try
	{
		office.doBureaucracy("shrubbery request", "crappy notice");
		office.doBureaucracy("robotomy request", "documentation");
		office.doBureaucracy("presidential request", "NotaBene");
		std::cout << GREEN << "Cool! You managed to complete the beurocracy." << NORMAL << std::endl;
	}
	catch (std::exception &excpt)
	{
		std::cout << RED << "Ooooops..... " << excpt.what()  << NORMAL << std::endl;
	}

	try
	{
		office.doBureaucracy("shrubbbery request", "mars");
	}
	catch (std::exception &excpt)
	{
		std::cout << RED << "Ooooops..... " << excpt.what()  << NORMAL << std::endl;
	}

	OfficeBlock				office2;
	office2.setIntern(intern);
	try
	{
		office2.doBureaucracy("shrubbbery request", "mars");
	}
	catch (std::exception &excpt)
	{
		std::cout << RED << "Ooooops..... " << excpt.what()  << NORMAL << std::endl;
	}

	OfficeBlock				office3;
	Bureaucrat				boss11("Boss1", 3);
	Bureaucrat				boss22("Boss2", 3);

	office.setSigner(boss11);
	office.setExecutor(boss22);
	office3.setIntern(intern);
	try
	{
		office2.doBureaucracy("shrubbbery request", "mars");
	}
	catch (std::exception &excpt)
	{
		std::cout << RED << "Ooooops..... " << excpt.what()  << NORMAL << std::endl;
	}




	return (0);
}