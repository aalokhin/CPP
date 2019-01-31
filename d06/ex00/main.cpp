#include <iostream>
#include "Transform.hpp"
#include <sstream>
#include <string>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

void		print_numeric_limits(std::string str)
{
	std::cout << "char: impossible\nint: impossible\nfloat: ";
	if (str == "-inff" || str == "-inf" )
	{
		std::cout << "-" << std::numeric_limits<float>::infinity();
	}
	else if(str == "+inff" || str == "inff" || str == "+inf" || str == "inf")
	{
		std::cout << std::numeric_limits<float>::infinity();
	}
	else if(str == "nanf" || str == "nan")
	{
		std::cout << "nan";
	}
	std::cout << "f\ndouble: ";

	if (str == "-inff" || str == "-inf" )
	{
		std::cout << "-" << std::numeric_limits<double>::infinity();
	}
	else if(str == "+inff" || str == "inff" || str == "+inf" || str == "inf")
	{
		std::cout << std::numeric_limits<double>::infinity();
	}
	else if(str == "nanf" || str == "nan")
	{
		std::cout << "nan";
	}
	std::cout << std::endl;
}

bool		validate_string(std::string input, int &precision)
{
	int i = 0;
	int points = 0;
	int fs = 0;

	while (input[i] != '\0')
	{
		if (input[i] < '0' || input[i] > '9')
		{
			if (input[i] == 'f' && i != 0 && points == 1)
				fs++;
			else if (input[i] == '.' && i != 0 && input[i + 1] >= '0' && input[i + 1] <= '9')
				points++;
			else if ((input[i] != '-' && i != 0) || (input[i] == '.' && input[i + 1] < '0' && input[i + 1] > '9'))
				return (false);
		}
		i++;
	}
	if ((fs == 1 || fs == 0) && (points == 1 || points == 0))
	{
		if (points == 1)
		{
			int i = 0;
			while(input[i] != '.')
				i++;
			i++;
			while(input[i] >= '0' && input[i] <= '9')
			{
				if (precision == 8)
					break ;
				precision++;
				i++;
			}
			//std::cout << BLUE << precision << '\n';
		}
		return (true);
	}
	else
		return (false);
}

int main(int argc, char **argv)
{
	std::string type;
	std::string input;
	int precision = 0;

	if (argc == 1)
	{
		std::cout << "Usage: \"./convert 42\" \nPlease enter string containing char, int, float or double " << std::endl;
		return (0);
	}

	input = static_cast<std::string>(argv[1]);
	input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

	

	if (input.empty())
	{
		std::cout << "EMPTY! Usage: \"./convert 42\" \nPlease enter string containing char, int, float or double " << std::endl;
		return (0);
	}
	if (input == "inf" || input == "inff" || input == "-inff" || input == "inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "nan")
	{
		print_numeric_limits(input);
		return (0);
	}
	if (!(validate_string(input, precision)))
	{
		std::cout << RED << "String contains incorrect symbols" << std::endl;
		return (1);
	}


	std::cout.setf(std::ios::fixed);

	if (precision == 0)
		precision = 1;

	
	std::cout.precision(precision);

	double d_val = std::strtod(input.c_str(), NULL);
	// std::cout << GREEN <<  d_val << NORMAL << std::endl;
	Transform transform(input, d_val);

	std::cout << "char: ";
	try
	{
		char c = static_cast<char>(transform);
	
		if (isprint(c))
			std::cout << '\'' << c << "\'\n";
		else
			std::cout << "Non displayable\n";
	}
	catch (std::exception)
	{
		std::cout << "conversion impossible\n";
	}

	std::cout << "int: ";
	try
	{
		int i = static_cast<int>(transform);
		std::cout << i << std::endl;
	}
	catch (std::exception)
	{
		std::cout << "conversion impossible\n";
	}

	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(transform) << 'f';
	}
	catch (std::exception)
	{
		std::cout << "conversion impossible\n";
	}
	std::cout << std::endl;
	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(transform);
	}
	catch (std::exception)
	{
		std::cout << "conversion impossible\n";
	}
	std::cout << std::endl;
	return (0);
}
