#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
  Intern  intern;
  Form*   rrf;
  rrf = intern.makeForm("robotomy request", "Bender");
  rrf = intern.makeForm("presidential request", "Bender");
  rrf = intern.makeForm("shrubbery request", "Bender");
  rrf = intern.makeForm("request", "Bender");
  return 0;
}

