#include <iostream>
#include "easyfind.hpp"


template <typename T>
void				printElement(T &arr_el)
{
  std::cout << PINK << arr_el << NORMAL << " ";
}

template <typename T>
void				iter(std::vector<T> array, unsigned int &length, void (*f)(T &) )
{
	size_t i = 0;
	std::cout << PINK << "Here is an array: " << NORMAL << std::endl;
	while (i < length)
	{
		(*f)(array[i]);
		i++;
	}

	std::cout << std::endl;
}

int main( void )
{
	std::srand(time(NULL));

	unsigned int i = 0;

	std::cout << GREEN << ".................. Testing if element exists .................." << NORMAL << std::endl;
	std::vector<int> arr;

	unsigned int n = rand() % 10 + 1;
	//std::cout << CYAN <<  n << NORMAL << std::endl;


	while (i < n)
	{
		arr.push_back(i);
		i++;
	}

	::iter(arr, n, &printElement);



	int find = rand() % n;

	std::cout << BLUE << "An element to find: " << find << NORMAL << std::endl;

	int res;
	try
	{
		res = ::easyfind(arr, find);
		std::cout << CYAN << "Value found at position " << res << std::endl;
	}
	catch (std::logic_error &e)
	{
		std::cout << e.what();
	}


	std::cout << GREEN << "............. Testing if there is no such element ............." << NORMAL << std::endl;
	try
	{
		res = ::easyfind(arr, -1);
		std::cout << "Value found at position " << res << std::endl;

	}
	catch (std::logic_error &e)
	{
		std::cout << e.what();
	}
	return 0;
}
