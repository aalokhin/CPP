#include "Bureaucrat.hpp"
#include "Form.hpp"



int				main()
{
	Form test_form("test_form", 1, 100);

	std::cout << CYAN << "TESTING FORM, SIGNING IT AND CATCHING ALREADY SIGNED" << NORMAL <<  std::endl;
	try
	{
		Bureaucrat student("aalokhin", 1);
		test_form.beSigned(student);
		test_form.beSigned(student);
		std::cout << GREEN << "Signs form successfully\n";
		std::cout << test_form << std::endl;

	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}
	catch(Form::AlreadySigned &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}

	
	std::cout << CYAN << "STUDENT FAILS TO SIGN A FORM" << NORMAL <<  std::endl;
	try{	
		Bureaucrat student1("aalokhin", 1);
		student1.signForm(test_form);
		std::cout << test_form << std::endl;

	}
	catch(Bureaucrat::GradeTooLowException &exception){
		std::cout << RED << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &exception){
		std::cout << RED << exception.what() << std::endl;
	}
	catch(Form::AlreadySigned &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}

	class Form test_form2("test_form2", 1, 100);

	std::cout << CYAN << "ANOTHER EXAMPLE FOR ELIGIBLE FORM SIGNING" << NORMAL <<  std::endl;
	try
	{
		Bureaucrat student2("vlikhotk", 1);
		student2.signForm(test_form2);
		std::cout << GREEN << "Signs form successfully\n";
		std::cout << test_form2 << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}
	catch(Form::AlreadySigned &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}

	std::cout << CYAN << "AGAIN ANOTHER EXAMPLE WITH TOO LOW GRADE" << NORMAL <<  std::endl;

	class Form test_form3("test_form3", 1, 100);
	try
	{
		Bureaucrat student3("olbondar", 2);
		student3.signForm(test_form3);
		std::cout << test_form3 << std::endl;

	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
		std::cout <<  RED <<exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}
	catch(Form::AlreadySigned &exception)
	{
		std::cout << RED << exception.what() << std::endl;
	}
	
	std::cout << CYAN << "THAT'S IT" << NORMAL <<  std::endl;
	

	return (0);
}
