#include "Fixed.class.hpp"

Fixed Fixed::operator+(Fixed const & obj) const { return (Fixed(this->toFloat() + obj.toFloat())); }

Fixed Fixed::operator-(Fixed const & obj) const { return (Fixed(this->toFloat() - obj.toFloat())); }

Fixed Fixed::operator*(Fixed const & obj) const { return (Fixed(this->toFloat() * obj.toFloat())); }

Fixed Fixed::operator/(Fixed const & obj) const { return (Fixed(this->toFloat() / obj.toFloat())); }



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

  //return ((obj1._raw <= obj2._raw) ? obj1 : obj2);
}

Fixed & Fixed::max(Fixed & obj1, Fixed & obj2)
{
	if (obj1._raw >= obj2._raw)
		return (obj1);
	return (obj2);

  //return ((obj1._raw >= obj2._raw) ? obj1 : obj2);
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

