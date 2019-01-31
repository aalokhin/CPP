#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>

class Logger {

public:
	Logger();
	~Logger();
	void			log(std::string const & dest, std::string const & message);

private:
	std::ofstream		_logfile;

	void				logToConsole( std::string const & log );
	void				logToFile( std::string const & log );
	const std::string	makeLogEntry( std::string const & simple_message ) const;
	std::string 		_displayTimestamp() const;

};


#endif