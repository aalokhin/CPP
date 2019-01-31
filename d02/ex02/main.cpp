
#include "Fixed.class.hpp"



int 			main( void )
{
	system("echo \"\033[0;31m\"");

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed  k(9.01f);
	Fixed  g(0);

	std::cout << "zero" << k / g << std::endl;

	return 0;
}
