#include "Bureaucrat.hpp"

int				main()
{
	std::cout << CYAN << "DUMB STUDENT" << NORMAL <<  std::endl;

	try
	{
		Bureaucrat student("aalokhin", 0);
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
		 std::cout << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
		 std::cout << exception.what() << std::endl;
	}

	std::cout << PINK << "SMARTASS STUDENT" << NORMAL <<  std::endl;
	try
	{
			Bureaucrat student1("vlikhotk", 151);
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
			std::cout << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
			std::cout << exception.what() << std::endl;
	}

	std::cout << GREEN << "ELIGIBLE STUDENT" << NORMAL <<  std::endl;
	try
	{
			Bureaucrat student2("gdanylov", 1);
			std::cout << student2;
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
			std::cout << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
			std::cout << exception.what() << std::endl;
	}
	std::cout << PINK << "ELIGIBLE STUDENT NO INCREMENT POSSIBLE" << NORMAL <<  std::endl;
	try
	{
			Bureaucrat student3("me_again", 1);
			try
			{
				student3.gradeIncr();
				std::cout << "Incremented successfully🙌🏻\n";

			}
			catch(Bureaucrat::GradeTooHighException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
			catch(Bureaucrat::GradeTooLowException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
			try
			{
				student3.gradeDecr();
				std::cout << "Deceremented successfully🙌🏻\n";
			}
			catch(Bureaucrat::GradeTooHighException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
			catch(Bureaucrat::GradeTooLowException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
			std::cout << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
			std::cout << exception.what() << std::endl;
	}

	std::cout << CYAN << "ELIGIBLE STUDENT NO DECREMENT POSSIBLE" << NORMAL <<  std::endl;

	try
	{
			Bureaucrat student4("me_again", 150);
			try
			{
				student4.gradeDecr();
				std::cout << "Deceremented successfully🙌🏻\n";
			}
			catch(Bureaucrat::GradeTooHighException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
			catch(Bureaucrat::GradeTooLowException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
			try
			{
				student4.gradeIncr();
				std::cout << "Incremented successfully🙌🏻\n";

			}
			catch(Bureaucrat::GradeTooHighException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
			catch(Bureaucrat::GradeTooLowException &exception)
			{
					std::cout << exception.what() << std::endl;
			}
	}
	catch(Bureaucrat::GradeTooHighException &exception)
	{
			std::cout << exception.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &exception)
	{
			std::cout << exception.what() << std::endl;
	}
	return (0);
}
