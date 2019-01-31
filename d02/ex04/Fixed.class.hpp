#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

class Fixed
{
  private:
	int _raw;
	static const int _fraction = 8;
  public:
	Fixed();
	Fixed(Fixed const & copy);
	Fixed(const int val_to_convert);
	Fixed(const float val_to_convert);
	~Fixed();

	Fixed & operator=(Fixed const & obj);

	bool operator>(Fixed const & obj) const;
	bool operator<(Fixed const & obj) const;
	bool operator>=(Fixed const & obj) const;
	bool operator<=(Fixed const & obj) const;
	bool operator==(Fixed const & obj) const;
	bool operator!=(Fixed const & obj) const;

	Fixed operator+(Fixed const & obj) const;
	Fixed operator-(Fixed const & obj) const;
	Fixed operator*(Fixed const & obj) const;
	Fixed operator/(Fixed const & obj) const;

	Fixed & operator++();
	Fixed & operator++(int);
	Fixed & operator--();
	Fixed & operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float 	toFloat(void) const;
	int 	toInt(void) const;
	static Fixed &min(Fixed &obj1, Fixed &obj2);
	static Fixed &max(Fixed &obj1, Fixed &obj2);
	static const Fixed &min(Fixed const &obj1, Fixed const &obj2);
	static const Fixed &max(Fixed const &obj1, Fixed const &obj2);
};

std::ostream & operator<<(std::ostream &o, Fixed const &obj);
std::string Conv_to_Postfix(std::string infix);

#endif
