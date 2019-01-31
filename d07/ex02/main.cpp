#include <string>
#include <iostream>
#include <exception>
#include "Array.hpp"
#include <ctime>


#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

int				main(void)
{
// 	Array<int>		test_array(5);
// 	Array<int>		test_array2;
// 	Array<int>		test_array3(5);
// 	std::cout << PINK << "........................ Initialize test_array of 5 members  ........................" << NORMAL << std::endl;
// 	try
// 	{
// 		std::cout << "No exceeding limit: [0] "<< test_array[0] << " [1] " << test_array[1] << " [2] " << test_array[2] << " [3] " << test_array[3] << " [4] " << test_array[4] << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}



// 	std::cout << PINK << ".............. Initialize test_array of 5 members and testing the exceed limit exception .............." << NORMAL << std::endl;

// 	try
// 	{
// 		std::cout << "Exceeding limit: [0] "<< test_array[0] << " [1] " << test_array[1] << " [2] " << test_array[2] << " [3] " << test_array[3] << " [4] " << test_array[4] << " [5] " << test_array[5] << " [6] " << test_array[6] << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << GREEN << "........................ Testing sizes of empty and full array ........................" << NORMAL << std::endl;


// 	std::cout << "Test array size: " << test_array.size() << std::endl;
// 	std::cout << "Test array2(empty) size: " << test_array2.size() << std::endl;

// 	std::cout << CYAN << "........................ Equating a newly created  empty array a to an array b of 5 members ........................" << NORMAL << std::endl;
	
// 	Array<int>  a;
//  	Array<int>  b(5);
// 	a = b;
// 	std::cout << "Copy array a to array c " << std::endl;
// 	Array<int>  c(a);
// 	std::cout << "size of array c: " << c.size() << std::endl;



// 	std::cout << "array a: " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << std::endl;
// 	std::cout << "array b: " << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << std::endl;
// 	std::cout << CYAN << "........................ Initializing a newly created empty array and checking values ........................" << NORMAL << std::endl;

// 	for (unsigned int i = 0; i < a.size(); i++)
// 		a[i] = i;
// 	std::cout << "array a: " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << std::endl;
// 	std::cout << "array b: " << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << std::endl;
// 	std::cout << CYAN << "........................ Creating a new array and equating to a filled array ........................" << NORMAL << std::endl;
	
// 	Array<int>  k;
// 	k = a;
// 	std::cout << "array a: " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << std::endl;
// 	std::cout << "array k: " << k[0] << " " << k[1] << " " << k[2] << " " << k[3] << " " << k[4] << std::endl;

// 	std::cout << BLUE << "........................ TTesting a string array  ........................" << NORMAL << std::endl;

	{
		std::srand(time(NULL));

		unsigned int n = rand() % 10 + 1;
		Array <std::string> myArray(n);
		unsigned int i;

		i = 0;


		while (i < n)
		{
			myArray.setElement("test" + std::to_string(i), i);
			i++;
		}
		std::cout << "test" + std::to_string(i) << std::endl;
	  i = 0;
	  while (i < n)
	  {
	    std::cout << myArray[i] << std::endl;
	    i++;
	  }
	  try
	  {
	    if (i < myArray.size())
	      std::cout << myArray[i] << std::endl;
	    else
	      throw "Incorrect array's element number";
	  }
	  catch (const char *ex)
	  {
	    std::cout << ex << std::endl;
	  }
	}

	return (0);
}
