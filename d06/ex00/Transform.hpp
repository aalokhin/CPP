#ifndef CONVERT_HPP
#define CONVERT_HPP

# include <iostream>
# include <string>
# include <exception>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

class Transform
{
  public:
	Transform();
	Transform(std::string argv, double d_val);
	Transform(Transform const & copy);
	~Transform();
	Transform & operator=(Transform const & over);
/***************************** Getters ****************************************/

	std::string getFrom() const;

	int getValue();


/***************************** Operators overload ****************************************/


	operator std::string const &(void) const;
	operator char(void) const;
	operator int(void) const;
	operator float(void) const;
	operator double(void) const;


/***************************** Exception ****************************************/


	class	ConversionImpossible: public std::exception
	{
		public:
			ConversionImpossible(void);
			~ConversionImpossible(void) throw();
		char const	*what(void) const throw();
	};


  private:
	const std::string _from;
	double _d_val;

};

std::ostream & operator<<(std::ostream &o, Transform const &over);

#endif





