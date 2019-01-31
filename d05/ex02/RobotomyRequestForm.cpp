#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::fifty = true;

RobotomyRequestForm::RobotomyRequestForm(){return;}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45) {return;}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy)
{ *this = copy; }

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & over)
{
	if (this != &over)
	{
		this->becomeSigned(over.get_if_Signed());
	}
	return (*this);
}
std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & over)
{
	std::string yes_no;
	if (over.get_if_Signed())
		yes_no = "not signed";
	else
		yes_no = "signed";
	std::cout << over.getName() << " is " << yes_no << " form with "
	<< over.get_Grade_Sign() << " to sign and " << over.get_Grade_Exec() << " to execute" << std::endl;
	return o;
}

void RobotomyRequestForm::execute(Bureaucrat const & officer) const
{
	if (this->get_if_Signed() && officer.getGrade() <= this->get_Grade_Exec())
	{
		std::string first_part = "  has been robotomized successfully\n";
		std::string second_part = " hasn't been robotomized. It's failure\n";
		std::cout << "drrrrriiiiiiiillllllll......" << std::endl;
		
		std::cout << this->getName();

		if (fifty)
		{
			std::cout << first_part;
			fifty = false;
		}
		else
		{
			std::cout << second_part;
			fifty = true;
		}
	}
	else if (!this->get_if_Signed())
		throw Form::Execution_Impossible();
	else if (officer.getGrade() > this->get_Grade_Exec())
		throw Bureaucrat::GradeTooLowException();
}
