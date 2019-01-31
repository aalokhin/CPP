#include <iostream>
#include "Fixed.class.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_raw = copy.getRawBits();
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
	std::cout << "getRawBits member function called" << std::endl;
	
	return this->_raw;
}

void     Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    
    this->_raw = raw;
}


