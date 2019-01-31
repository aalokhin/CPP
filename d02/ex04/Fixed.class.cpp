#include "Fixed.class.hpp"


Fixed::Fixed() : _raw(0)
{
  return ;

}


Fixed::Fixed(Fixed const &copy)
{
  
  *this = copy;

}

Fixed & Fixed::operator=(Fixed const& obj)
{

  if (this != &obj)
    this->_raw = obj.getRawBits();
  return (*this);
}


Fixed::Fixed(const int val_to_convert)
{
  setRawBits(val_to_convert << _fraction);
}

Fixed::Fixed(const float val_to_convert)
{
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
  return ;
}

int Fixed::getRawBits(void) const { return this->_raw; }

void Fixed::setRawBits(int const raw) { this->_raw = raw; }

std::ostream & operator<<(std::ostream & stream, Fixed const & object)
{
  stream << object.toFloat();
  return stream;
}


Fixed Fixed::operator+(Fixed const & obj) const { return (Fixed(this->toFloat() + obj.toFloat())); }

Fixed Fixed::operator-(Fixed const & obj) const { return (Fixed(this->toFloat() - obj.toFloat())); }

Fixed Fixed::operator*(Fixed const & obj) const { return (Fixed(this->toFloat() * obj.toFloat())); }

Fixed Fixed::operator/(Fixed const & obj) const
{
  if (obj.toFloat() == 0)
  {
    std::cout << "Please don't do this. Don't divide by zero. Never." << std::endl;
    return (Fixed(0));
  }
  return (Fixed(this->toFloat() / obj.toFloat()));
}

bool Fixed::operator>(Fixed const & obj) const
{
  if (this->_raw > obj._raw)
    return (true);
  return (false);
}

bool Fixed::operator<(Fixed const & obj) const
{
  if (this->_raw < obj._raw)
    return (true);
  return (false);
}


bool Fixed::operator<=(Fixed const & obj) const
{
  if (this->_raw <= obj._raw)
    return (true);
  return (false);
}

bool Fixed::operator>=(Fixed const & obj) const
{
  if (this->_raw >= obj._raw)
    return (true);
  return (false);
}

bool Fixed::operator!=(Fixed const & obj) const
{
  if (this->_raw != obj._raw)
    return (true);
  return (false);
}

bool Fixed::operator==(Fixed const & obj) const
{
  if (this->_raw == obj._raw)
    return (true);
  return (false);
}


Fixed & Fixed::min(Fixed & obj1, Fixed & obj2)
{
  if (obj1._raw <= obj2._raw)
    return (obj1);
  return (obj2);

}

Fixed & Fixed::max(Fixed & obj1, Fixed & obj2)
{
  if (obj1._raw >= obj2._raw)
    return (obj1);
  return (obj2);

}


const Fixed & Fixed::min(Fixed const & obj1, Fixed const & obj2)
{
  if (obj1._raw <= obj2._raw)
    return (obj1);
  return (obj2);
}

const Fixed & Fixed::max(Fixed const & obj1, Fixed const & obj2)
{
  if (obj1._raw >= obj2._raw)
    return (obj1);
  return (obj2);
}

Fixed & Fixed::operator++()
{
  this->_raw++;
  return *this;
}

Fixed & Fixed::operator++(int)
{

  Fixed *tmp = new Fixed(* this );
  ++(* this );
  return (*tmp);
}

Fixed & Fixed::operator--()
{
  this->_raw--;
  return *this;
}

Fixed & Fixed::operator--(int)
{
  Fixed *tmp = new Fixed(*this);
  --(*this);
  return (*tmp);
}

