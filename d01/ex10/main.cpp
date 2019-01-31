#include <fstream>
#include <iostream>

int		main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::string save;
		while(true)
		{
			getline(std::cin, save);
			std::cout << save << std::endl;
			save.clear();
		}
	}
	else
	{
		std::string backup;
		std::ifstream ifs(argv[1], std::ifstream::in);
		
		if (ifs.is_open())
		{
			while (!ifs.eof())
			{
				getline(ifs, backup);

				if(!ifs.eof())
					std::cout << backup << std::endl;
				backup.clear();
			}
		}
		else
			std::cout << "cato9tails: " << argv[1] << ": No such file or directory" << std::endl;
	}
	return(0);
}
