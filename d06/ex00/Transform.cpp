#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include  <cstdlib>
#include "Transform.hpp"

/***************************** Coplien ****************************************/

Transform::Transform(){return ;}

Transform::Transform(std::string argv, double d_val) : _from(argv), _d_val(d_val)
{

	//std::cout << GREEN <<  _d_val << NORMAL << std::endl;
	return;
}

Transform::Transform(Transform const & copy)
{ *this = copy; }

Transform::~Transform(){}

Transform & Transform::operator=(Transform const & obj)
{
	if (this != &obj)
	{
		this->_d_val = obj._d_val;
	}
	 return (*this);
}

std::ostream & operator<<(std::ostream & o, Transform const & obj)
{
	std::cout << "String to Transform is " << obj.getFrom() << std::endl;
	return o;
}
/***************************** Getters ****************************************/

std::string Transform::getFrom() const
{
	return this->_from;
}

int Transform::getValue()
{
	return this->_d_val;
}




/***************************** Exception functions ****************************************/

Transform::ConversionImpossible::ConversionImpossible(void) {}
Transform::ConversionImpossible::~ConversionImpossible(void) throw() {}

char const	*Transform::ConversionImpossible::what(void) const throw()
{ return ("Conversion is impossible"); }

/***************************** Overload cast operator ****************************************/


Transform::operator std::string const &(void) const
{ return (_from); }

Transform::operator char(void) const
{

	//std::cout << PINK <<  _d_val << NORMAL << std::endl;

	if (_d_val > static_cast<double>(CHAR_MAX) || _d_val < static_cast<double>(CHAR_MIN))
		throw ConversionImpossible();

	char n = static_cast<char>(std::atoi(this->_from.c_str()));
	if (errno)
	{
		throw (ConversionImpossible());
	}
	return (n);
}

Transform::operator int(void) const
{
	if (_d_val > static_cast<double>(INT_MAX) || _d_val < static_cast<double>(INT_MIN))
		throw ConversionImpossible();
	//std::cout << PINK <<  _d_val << NORMAL << std::endl;
	int		n =  static_cast<int>(_d_val);
	if (errno)
	{
		throw (ConversionImpossible());
	}
	return (n);
}

Transform::operator float(void) const
{
	float		n =  static_cast<float>(_d_val);
	if (errno)
		throw (ConversionImpossible());
	return (n);
}

Transform::operator double(void) const
{
	//std::cout << BLUE <<  _d_val << NORMAL << std::endl;

	return (_d_val);
}


