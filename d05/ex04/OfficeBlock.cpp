
#include <string>
#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

OfficeBlock::OfficeBlock(void)
{}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor)
{
	this->_intern = &intern;
	this->_signer = &signer;
	this->_executor = &executor;
}

OfficeBlock::~OfficeBlock(void)
{}

void						OfficeBlock::doBureaucracy(std::string const &name, std::string const &target)
{
	Form					*form;

	if (!this->_intern)
		throw (MissingIntern());
	if (!this->_signer)
		throw (MissingSignatory());
	if (!this->_executor)
		throw (MissingSEO());


	form = this->_intern->makeForm(name, target);
	if (form == NULL)
			throw (MissingForm());


	try
	{
		this->_signer->signForm(*form);
	}
	catch (Form::GradeTooLowException &e)
	{
		throw (SignGradeTooLowException());
	}

	try
	{
		this->_executor->executeForm(*form);
	}
	catch (Form::GradeTooLowException &e)
	{
		throw (SEOGradeTooLowException());
	}
}

void	OfficeBlock::setIntern(Intern &intern) { this->_intern = &intern; }
void	OfficeBlock::setSigner(Bureaucrat &signer) { this->_signer = &signer; }
void	OfficeBlock::setExecutor(Bureaucrat &executor) { this->_executor = &executor; }


OfficeBlock::MissingForm::MissingForm(void) {}
OfficeBlock::MissingForm::~MissingForm(void) throw() {}
OfficeBlock::MissingForm::MissingForm(MissingForm const &src)
{ *this = src; }

OfficeBlock::MissingForm	&OfficeBlock::MissingForm::operator=(OfficeBlock::MissingForm const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*OfficeBlock::MissingForm::what(void) const throw()
{return ("The Form is missing, fire that idiot who should have made it!"); }



OfficeBlock::MissingIntern::MissingIntern(void) {}
OfficeBlock::MissingIntern::~MissingIntern(void) throw() {}
OfficeBlock::MissingIntern::MissingIntern(MissingIntern const &src) { *this = src; }
OfficeBlock::MissingIntern	&OfficeBlock::MissingIntern::operator=(OfficeBlock::MissingIntern const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
char const	*OfficeBlock::MissingIntern::what(void) const throw() { return ("No Intern"); }

OfficeBlock::MissingSignatory::MissingSignatory(void) {}
OfficeBlock::MissingSignatory::~MissingSignatory(void) throw() {}
OfficeBlock::MissingSignatory::MissingSignatory(MissingSignatory const &src) {*this = src;}
OfficeBlock::MissingSignatory	&OfficeBlock::MissingSignatory::operator=(OfficeBlock::MissingSignatory const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
char const	*OfficeBlock::MissingSignatory::what(void) const throw()
{ return ("No Signatory"); }

OfficeBlock::MissingSEO::MissingSEO(void) {}
OfficeBlock::MissingSEO::~MissingSEO(void) throw() {}
OfficeBlock::MissingSEO::MissingSEO(MissingSEO const &src) { *this = src; }

OfficeBlock::MissingSEO	&OfficeBlock::MissingSEO::operator=(OfficeBlock::MissingSEO const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*OfficeBlock::MissingSEO::what(void) const throw() { return ("No Executor");}

OfficeBlock::SignGradeTooLowException::SignGradeTooLowException(void) {}
OfficeBlock::SignGradeTooLowException::~SignGradeTooLowException(void) throw() {}
OfficeBlock::SignGradeTooLowException::SignGradeTooLowException(SignGradeTooLowException const &src) {*this = src; }

OfficeBlock::SignGradeTooLowException	&OfficeBlock::SignGradeTooLowException::operator=(OfficeBlock::SignGradeTooLowException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*OfficeBlock::SignGradeTooLowException::what(void) const throw()
{ return ("Signer Grade Too Low");}

OfficeBlock::SEOGradeTooLowException::SEOGradeTooLowException(void) {}
OfficeBlock::SEOGradeTooLowException::~SEOGradeTooLowException(void) throw() {}
OfficeBlock::SEOGradeTooLowException::SEOGradeTooLowException(SEOGradeTooLowException const &src)
{ *this = src; }

OfficeBlock::SEOGradeTooLowException	&OfficeBlock::SEOGradeTooLowException::operator=(OfficeBlock::SEOGradeTooLowException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*OfficeBlock::SEOGradeTooLowException::what(void) const throw()
{return ("Executor Grade Too Low"); }