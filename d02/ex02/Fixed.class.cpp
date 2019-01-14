#include "Fixed.class.hpp"


Fixed::Fixed() : _raw(0)
{
  //std::cout << "Default constructor called" << std::endl;
  return ;

}


Fixed::Fixed(Fixed const &copy)
{
  //std::cout << "Copy constructor called" << std::endl;
  
  *this = copy;

}

Fixed & Fixed::operator=(Fixed const& obj)
{
	//std::cout << "Assignation operator called" << std::endl;

	if (this != &obj)
		this->_raw = obj.getRawBits();
	//else
		//std::cout << "Self assignment!" << std::endl;
	return (*this);
}


Fixed::Fixed(const int val_to_convert)
{
  //std::cout << "Int constructor called" << std::endl;
  setRawBits(val_to_convert << _fraction);
}

Fixed::Fixed(const float val_to_convert)
{
  //std::cout << "Float constructor called" << std::endl;
  setRawBits(roundf(val_to_convert * (1 << this->_fraction)));
}


float Fixed::toFloat(void) const
{
  float f = getRawBits();
  return (f / (1 << this->_fraction));
}


int Fixed::toInt(void) const { return getRawBits() >> this->_fraction; }

Fixed::~Fixed()
{
  //std::cout << "Destructor called" << std::endl;
  return ;
}

int Fixed::getRawBits(void) const { return this->_raw; }

void Fixed::setRawBits(int const raw) { this->_raw = raw; }

std::ostream & operator<<(std::ostream & stream, Fixed const & object)
{
	stream << object.toFloat();
	return stream;
}
