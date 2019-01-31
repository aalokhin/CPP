#include <iostream>
#include <fstream>

void		show_error(int i)
{
	if (i == 1)
		std::cout << "Incorrect number of input parameters" << std::endl;
	else if (i == 2)
		std::cout << "Something wrong with the file" << std::endl;
	else if (i == 3)
		std::cout << "Strings are corrupted" << std::endl;
	else if (i == 4)
		std::cout << "Replace file cannot be created" << std::endl;


}



int main (int argc, char **argv)
{

	if (argc != 4)
	{
		show_error(1);
		return(1);
	}
	if(!argv[1] || !strlen(argv[1]))
	{
		show_error(2);
		return(1);
	}
	std::ifstream	input_file((std::string)argv[1]);
	
	if(!input_file || !input_file.is_open() || input_file.eof())
	{
		show_error(2);
		return(1);
	}
	std::ofstream	output_file((std::string)argv[1] + (std::string)".replace");

	if (!output_file || !output_file.is_open() || output_file.eof())
	{
		show_error(4);
		return(1);
	}
	if (!argv[2] || !argv[3]|| !strlen(argv[2]) || !strlen(argv[3]))
	{
		show_error(3);
		return(1);
	}
	const std::string		Find_to_Replace(argv[2]);
	const std::string		Replace_with(argv[3]);


	std::string line;
	size_t pos;
	size_t len = Find_to_Replace.length();
	int k = 0;
	while (!input_file.eof())
	{
		if (k != 0)
			output_file << '\n';
		getline(input_file, line);
		pos = line.find(Find_to_Replace);
		if (pos != std::string::npos)
			line.replace(pos, len, Replace_with);
		output_file << line;
		k++;
	}


	std::cout << "Replacement successfully completed" << std::endl;
	input_file.close();
	output_file.close();
	return (0);
}


