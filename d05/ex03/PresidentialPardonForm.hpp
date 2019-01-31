#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const & obj);
		void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream &os, PresidentialPardonForm const &obj);

#endif
