
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
	return 0;
}



/*
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/


// Fixed tmp(* this );
// ++(* this );
// return tmp;