#include "Logger.hpp"

int		main( void )
{
	Logger	L;

	std::string login;
	std::cout << "Who are you?" << std::endl;
	std::cin >> login;

	system("echo \"\033[1;35m\"");
	std::cout << "Welcome, " << login << "!" << std::endl << "Your log-in has been recorded!" << std::endl;
	system("echo \"\033[0m\"");


	L.log("logToConsole", login);
	L.log("logToFile", login);
	system("echo \"\033[1;35m\"");

	std::cout << "Here is the LogFile, " << login << ":" << std::endl;
	system("echo \"\033[0m\"");

	system("cat  Logfile.log");
	return 0;
}
