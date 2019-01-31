#include "Intern.hpp"

Intern::Intern(){return;}

Intern::Intern(Intern const & copy) { *this = copy; }

Intern::~Intern(){return;}

Intern & Intern::operator=(Intern const &) { return *this; }

Form *Intern::makeForm(std::string name, std::string target)
{
	if (name == "shrubbery request")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (name == "robotomy request")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (name == "presidential request")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << "Intern doesn't create anything as the form type is unknown\n";
		return (NULL);
	}
}
