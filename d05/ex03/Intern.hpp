#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <locale>
#include <string>
#include <algorithm>

class Intern
{
  public:
    Intern();
    Intern(Intern const & copy);
    ~Intern();
    Intern & operator=(Intern const & over);

    Form *makeForm(std::string name, std::string target);
};

#endif
