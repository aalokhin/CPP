
#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
#include <vector>
#include <algorithm>  
#include <stdexcept>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

template <typename T>
int easyfind(T arr, int a)
{
	typename T::iterator it;

	typename T::const_iterator itB = arr.begin();
	typename T::const_iterator itE = arr.end();
	it = std::find (arr.begin(), arr.end(), a);
	if (it != arr.end())
	{
		/*
			std::cout << "Element found in myvector: " << *it << '\n';
		*/
		unsigned int i = 0;
		while (itB != itE)
		{
			if (*itB == a)
				return i;
			i++;
			itB++;
		}
	}
	else
		throw std::logic_error("Element not found in the array\n");
	return (-1);
}

#endif