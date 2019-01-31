#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
  std::cout <<  CYAN << " Example 1" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 150);
    ShrubberyCreationForm test_form("form");
    test_form.execute(aalokhin);
    test_form.beSigned(aalokhin);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 2" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 146);
    ShrubberyCreationForm test_form("form");
    test_form.beSigned(aalokhin);
    test_form.execute(aalokhin);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 3" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 100);
    ShrubberyCreationForm test_form("form");
    test_form.beSigned(aalokhin);
    test_form.execute(aalokhin);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 4" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 30);
    RobotomyRequestForm test_form("form");
    test_form.beSigned(aalokhin);
    test_form.execute(aalokhin);
    test_form.execute(aalokhin);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 5" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 30);
    PresidentialPardonForm test_form("form");
    test_form.beSigned(aalokhin);
    test_form.execute(aalokhin);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 6" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 150);
    ShrubberyCreationForm test_form("form");
    aalokhin.executeForm(test_form);
    test_form.beSigned(aalokhin);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 7" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 146);
    ShrubberyCreationForm test_form("form");
    test_form.beSigned(aalokhin);
    aalokhin.executeForm(test_form);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 8" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 100);
    ShrubberyCreationForm test_form("form");
    test_form.beSigned(aalokhin);
    aalokhin.executeForm(test_form);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 9" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 30);
    RobotomyRequestForm test_form("form");
    test_form.beSigned(aalokhin);
    aalokhin.executeForm(test_form);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }

  std::cout << CYAN <<  " Example 10" << NORMAL << std::endl;
  try
  {
    Bureaucrat aalokhin("aalokhin", 30);
    PresidentialPardonForm test_form("form");
    test_form.beSigned(aalokhin);
    aalokhin.executeForm(test_form);
  }
  catch(Form::GradeTooLowException &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  catch(Form::Execution_Impossible &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  return 0;
}
