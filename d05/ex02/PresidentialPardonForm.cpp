#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 72, 45)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy)
{
  *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & over)
{
  if (this != &over)
  {
    this->becomeSigned(over.get_if_Signed());
  }
  return (*this);
}
std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & over)
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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
  if (this->get_if_Signed() && executor.getGrade() <= this->get_Grade_Exec())
  {
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
  }
  else if (!this->get_if_Signed())
    throw Form::Execution_Impossible();
  else if (executor.getGrade() > this->get_Grade_Exec())
    throw Bureaucrat::GradeTooLowException();
}
