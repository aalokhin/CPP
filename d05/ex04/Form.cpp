#include "Bureaucrat.hpp"
#include "Form.hpp"


/******************************* GETTERS **********************************/

std::string Form::getName() const {
	return this->_name;

}

int Form::get_Grade_Sign() const {
	return this->_grade_sign;
}

int Form::get_Grade_Exec() const {
	return this->_grade_exec;
}

bool Form::get_if_Signed() const {
	return this->_signed;
}

void Form::beSigned(Bureaucrat & officer){
	if (officer.getGrade() > this->_grade_sign)
		throw Form::GradeTooLowException();
	if (this->_signed == true)
		throw Form::AlreadySigned();
	_signed = true;
}

void Form::becomeSigned(bool sign)
{
	this->_signed = sign;
}

/******************************* COPLIEN **********************************/

Form::Form() : _grade_sign(150), _grade_exec(150)
{

}

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
	else if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	_signed = false;

}

Form::Form(Form const & copy) : _name(copy._name), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{ *this = copy; }

Form::~Form() { }

Form & Form::operator=(Form const & obj)
{
	if (this != &obj)
	{
		this->_signed = obj._signed;
	}
	return (*this);

}

std::ostream & operator<<(std::ostream & os, Form const & obj)
{
	if (obj.get_if_Signed() == true)
		std::cout << BLUE <<  "A form " << obj.getName() << " is signed requiring " << obj.get_Grade_Sign() << " to sign and " << obj.get_Grade_Exec() << " to execute" << std::endl;
	else
		std::cout << BLUE << "A form " << obj.getName() << " is not yet signed and requires " << obj.get_Grade_Sign() << " to sign and " << obj.get_Grade_Exec() << " to execute" << std::endl;
	return os;
}


/******************************* EXCEPTIONS **********************************/

Form::GradeTooLowException::GradeTooLowException(){return;}
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & copy)
{ *this = copy; }
Form::GradeTooLowException::~GradeTooLowException() throw(){return;}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return (*this);
}

const char* Form::GradeTooLowException::what() const throw()
{ return "Grade is too low"; }



Form::GradeTooHighException::GradeTooHighException(){return;}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & copy)
{ *this = copy; }
Form::GradeTooHighException::~GradeTooHighException() throw(){return;}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const & obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{ return "Grade is too high"; }



Form::AlreadySigned::AlreadySigned(){return;}
Form::AlreadySigned::AlreadySigned(AlreadySigned const & copy)
{ *this = copy; }
Form::AlreadySigned::~AlreadySigned() throw(){return;}

Form::AlreadySigned & Form::AlreadySigned::operator=(AlreadySigned const & obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return (*this);
}

const char* Form::AlreadySigned::what() const throw()
{ return "The form is already signed"; }






Form::Execution_Impossible::Execution_Impossible(){return;}
Form::Execution_Impossible::Execution_Impossible(Execution_Impossible const & copy)
{ *this = copy; }
Form::Execution_Impossible::~Execution_Impossible() throw(){return;}

Form::Execution_Impossible & Form::Execution_Impossible::operator=(Execution_Impossible const & obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return (*this);
}

const char* Form::Execution_Impossible::what() const throw()
{ return "Form should be signed before it can be executed"; }


