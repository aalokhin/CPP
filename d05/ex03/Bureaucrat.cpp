#include  "Bureaucrat.hpp"

/************************ SignForm added ***********************************/

void Bureaucrat::signForm(Form & form)
{
	if (form.get_Grade_Sign() >= this->_grade && !form.get_if_Signed())
	{
		form.beSigned(*this);
		std::cout << GREEN << "<" << this->_name << ">" << " signs "  << "<" << form.getName() << ">" << NORMAL << std::endl;
	}
	else if (form.get_Grade_Sign() < this->_grade)
		std::cout << RED << "<" << this->_name << ">" << " cannot sign "  << "<" << form.getName()
		<< ">" << " because he has too low of a grade" << NORMAL <<  std::endl;
	else if (form.get_if_Signed())
		std::cout << RED << "<" << this->_name << ">" << " cannot sign "  << "<" << form.getName()
		 << ">" << " because form is already signed" <<  NORMAL << std::endl;
}

void Bureaucrat::executeForm(Form & form)
{
	if (form.get_Grade_Exec() >= this->getGrade() && form.get_if_Signed())
	{
		form.execute(*this);
		std::cout << "<" << this->getName() << ">" << " executes "  << "<" << form.getName() << ">" << std::endl;
	}
	else if (form.get_Grade_Exec() < this->getGrade())
		std::cout << "<" << this->getName() << ">" << " cannot executes "  << "<" << form.getName() << ">" << " because he has low grade" << std::endl;
	else if (!form.get_if_Signed())
		std::cout << "<" << this->getName() << ">" << " cannot executes "  << "<" << form.getName()
    << ">" << " because form not signed yet" << std::endl;
}





/************************Exceptions***********************************/

Bureaucrat::GradeTooLowException::GradeTooLowException(){return;}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & obj) {*this = obj; }
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }
Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & obj)
{
  if (this != &obj)
  {
	*this = obj;
  }
  return (*this);
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{return "Grade is too low";}


Bureaucrat::GradeTooHighException::GradeTooHighException() {return;}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & obj) {*this = obj; }
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }
Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & obj)
{
  if (this != &obj)
  {
	*this = obj;
  }
  return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{return "Grade is too high";}


/************************Getters***********************************/

std::string Bureaucrat::getName() const {return this->_name;}

int Bureaucrat::getGrade() const {return this->_grade; }


void Bureaucrat::gradeIncr()
{
	if (_grade - 1 >= 1)
		_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::gradeDecr()
{
	if (_grade + 1 <= 150)
		_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}

/************************Coplien***********************************/

Bureaucrat::Bureaucrat(){return;}

Bureaucrat::Bureaucrat(std::string name, int grade) :
_name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		_grade = grade;
		/* std::cout << "Bureaucrat class has been created successfully\n"; */
	}
}


Bureaucrat::Bureaucrat(Bureaucrat const & obj){*this = obj;}


std::ostream & operator<<(std::ostream &os, Bureaucrat const &obj){
	  std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	  return os;

}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &obj){
	if (this != &obj)
	{
		this->_grade = obj._grade;
	}
	return (*this);

}

Bureaucrat::~Bureaucrat(){return;}
