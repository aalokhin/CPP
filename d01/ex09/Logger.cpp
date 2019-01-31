#include "Logger.hpp"

Logger::Logger() : _logfile("LogFile.log", std::ios::app) { return ;}

Logger::~Logger() { return ; }


const std::string	Logger::makeLogEntry( std::string const & simple_message ) const
{
	std::string	messg(_displayTimestamp());
	messg += simple_message;
	return messg;
}



void				Logger::logToConsole( std::string const & messg )
{
	std::cout << messg << std::endl;
}

void				Logger::logToFile( std::string const & messg )
{
	Logger::_logfile << messg << std::endl;
}

std::string 		Logger::_displayTimestamp() const  
{ 
	time_t t ; 
	struct tm *tmp ; 
	char current_time[22]; 
	time( &t ); 
	tmp = localtime(&t); 
	strftime(current_time, sizeof(current_time), "[%Y%m%d_%H%M%S] ", tmp);
	return std::string(current_time); 
}


void				Logger::log(std::string const & dest, std::string const & message)
{
	int i;

	void		(Logger::*funcs_ptr[2])( std::string const & ) =
	{
		&Logger::logToConsole,
		&Logger::logToFile
	};

	std::string	logs_var[] = {"logToConsole", "logToFile"};
	int arr_len = (int)(sizeof(logs_var)/sizeof(logs_var[0]));



	i = 0;
	while (i < arr_len)
	{
		if (logs_var[i].compare(dest) == 0)
		{
			(this->*funcs_ptr[i])( this->makeLogEntry(message));
			break ;
		}
		i++;
	}
}


