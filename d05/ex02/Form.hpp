#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string _name;
		bool _signed;
		const int _grade_sign;
		const int _grade_exec;
	public:
		/*********** COPLIEN ***********/

		Form();
		Form(std::string name, int grade_sign, int grade_exec);
		Form(Form const & copy);
		~Form();
		Form & operator=(Form const & obj);



		/*********** GETTERS ***********/

		std::string getName() const;
		int get_Grade_Sign() const;
		int get_Grade_Exec() const;
		bool get_if_Signed() const;

		/*********** FORM ACTIONS ***********/

		virtual void execute(Bureaucrat const & executor) const = 0;
		void	beSigned(Bureaucrat & officer);
		void	becomeSigned(bool sign);

		/*********** EXCEPTIONS ***********/
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const & copy);
				~GradeTooLowException() throw();
				GradeTooLowException & operator=(GradeTooLowException const & obj);
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const & copy);
				~GradeTooHighException() throw();
				GradeTooHighException & operator=(GradeTooHighException const & obj);
				virtual const char* what() const throw();
		};

		class AlreadySigned : public std::exception
		{
			public:
				AlreadySigned();
				AlreadySigned(AlreadySigned const & copy);
				~AlreadySigned() throw();
				AlreadySigned & operator=(AlreadySigned const & obj);
				virtual const char* what() const throw();
		};
		class Execution_Impossible : public std::exception
		{
			public:
				Execution_Impossible();
				Execution_Impossible(Execution_Impossible const & copy);
				~Execution_Impossible() throw();
				Execution_Impossible & operator=(Execution_Impossible const & over);
				virtual const char* what() const throw();
		};

};

std::ostream & operator<<(std::ostream &os, Form const &obj);

#endif
