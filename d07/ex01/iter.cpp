#include <iostream>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

template <typename myType>
void				printElement(myType &arr_el)
{
  std::cout << PINK << arr_el << NORMAL << std::endl;
}

template <typename myType>
void				iter( myType *array, std::size_t length, void (*f)(myType &) )
{
	size_t i = 0;

	while (i < length)
	{
		(*f)(array[i]);
		i++;
	}
}

class Pony
{
  public:
  	Pony( std::string name ) : _name(name) {return ;}
  	~Pony() {return ;}
  	std::string getName() const {return this->_name;}
 private:
  	std::string _name;
};


std::ostream & operator<<(std::ostream & stream, Pony const & object)
{
	stream << CYAN << "Pony " << object.getName() << " is zogging around 🌈 🦄\n" << NORMAL;
	return stream;
}

class Awesome
{
	public:
		Awesome ( void ) : _n(42), _f(42), _d(424242424242) { return; }
		int getN( void ) const { return this->_n; }
		float getF( void ) const 
		{
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			return (static_cast<float>(this->_f)); }
		double getD( void ) const 
		{
			std::cout.setf(std::ios::fixed);
			std::cout.precision(1);
			return (static_cast<double>(this->_d)); }
	private:
		int _n;
		float _f;
		double _d;
	};
	std::ostream & operator<<( std::ostream & os, Awesome const & overload )
	{
		os << BLUE << overload.getN() << " & " << overload.getF() << " & " << overload.getD() << NORMAL << std::endl;
		return os;
	}

int main( void )
{
	std::cout << GREEN << "............. Testing Numeric Types ............." << NORMAL << std::endl;
	int arr1[3] = {-1, 0, 1};
	::iter(arr1, 3, &printElement);
	std::cout << GREEN << "................................................." << NORMAL << std::endl;

	float arr2[3] = {2.23, 3.56, 0.19};
	::iter(arr2, 3, &printElement);

	
	std::cout << GREEN << "................................................." << NORMAL << std::endl;

	std::string arr3[3] = {"some", "random", "string"};
	::iter(arr3, 3, &printElement);
	std::cout << GREEN << "............. Testing String Types .............." << NORMAL << std::endl;

	Awesome tab[5];

	::iter( tab, 5, &printElement );

	std::cout << GREEN << ".............. Testing Class Pony ..............." << NORMAL << std::endl;

	Pony horde[] = {Pony("Carl😎"), Pony("Lilly🌺"), Pony("ShittyPony🤦🏻‍♀️"), Pony("Chmo")};

	::iter( horde, 4, &printElement );
/*
	system("leaks -q iter");
*/
	return 0;
}
