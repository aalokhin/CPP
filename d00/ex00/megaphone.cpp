#include <iostream>

char	make_capital(char c)
{
	c = (c >= 97 && c <= 122) ? (c - 32) : c;
	return (c);
}

int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << make_capital(argv[i][j]);
				j++;
			}
			//std::cout << std::endl;
			i++;
		}
	}
	return (0);
}
