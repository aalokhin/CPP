#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "Form.hpp"

#include <iostream>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & copy);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & obj);
		std::string getName() const;
		int getGrade() const;

		void gradeIncr();
		void gradeDecr();
		
		void signForm(Form & form);
		void executeForm(Form & form);

		class GradeTooLowException : public std::exception
		{
		public:
			GradeTooLowException();
			GradeTooLowException(GradeTooLowException const & obj);
			~GradeTooLowException() throw();
			GradeTooLowException & operator=(GradeTooLowException const & over);
			virtual const char* what() const throw();

		};
		class GradeTooHighException : public std::exception
		{
		public:
			GradeTooHighException();
			GradeTooHighException(GradeTooHighException const & obj);
			~GradeTooHighException() throw();
			GradeTooHighException & operator=(GradeTooHighException const & over);
			virtual const char* what() const throw();
		};

	
};

std::ostream & operator<<(std::ostream &os, Bureaucrat const &obj);

#endif
