#include <iostream>
#include "Fixed.class.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int val_to_convert)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(val_to_convert << _fraction);
}

Fixed::Fixed(const float val_to_convert)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(val_to_convert * (1 << _fraction)));
}



Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
}




Fixed & Fixed::operator=(Fixed const& over)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &over)
	{
		this->_raw = over.getRawBits();

	}
	else
		std::cout << "Self assignment!" << std::endl;
	return (*this);
}



int Fixed::getRawBits(void) const
{
	return this->_raw;
}

void     Fixed::setRawBits( int const raw )
{
    this->_raw = raw;
}

float Fixed::toFloat(void) const
{
	float f;
	f = getRawBits();
	return (f / (1 << _fraction));
}

int Fixed::toInt(void) const
{
	return getRawBits() >> _fraction;
}


std::ostream & operator<<(std::ostream & stream, Fixed const & object)
{
	stream << object.toFloat();
	return stream;
}
