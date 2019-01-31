#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const & over);
		void execute(Bureaucrat const & executor) const;
	private:
		static bool fifty;
};

std::ostream & operator<<(std::ostream &o, RobotomyRequestForm const &over);

#endif
