
#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

# include <string>
# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
	private:
		Intern					*_intern;
		Bureaucrat				*_signer;
		Bureaucrat				*_executor;

	public:
		OfficeBlock(void);
		~OfficeBlock(void);
		OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);

		void	setIntern(Intern &intern);
		void	setSigner(Bureaucrat &signer);
		void	setExecutor(Bureaucrat &executor);

		
		void	doBureaucracy(std::string const &name, std::string const &target);
		
		class 				MissingForm: public std::exception
		{
			public:
				MissingForm(void);
				~MissingForm(void) throw();
				MissingForm(MissingForm const &src);
				MissingForm		&operator=(MissingForm const &rhs);
				char const				*what(void) const throw();
		};

		class				MissingIntern: public std::exception
		{
			public:
				MissingIntern(void);
				~MissingIntern(void) throw();
				MissingIntern(MissingIntern const &src);
				MissingIntern		&operator=(MissingIntern const &rhs);
				char const				*what(void) const throw();
		};

		class					MissingSignatory: public std::exception
		{
			public:
				MissingSignatory(void);
				~MissingSignatory(void) throw();
				MissingSignatory(MissingSignatory const &src);
				MissingSignatory		&operator=(MissingSignatory const &rhs);
				char const				*what(void) const throw();
		};

		class					MissingSEO: public std::exception
		{
			public:
				MissingSEO(void);
				~MissingSEO(void) throw();
				MissingSEO(MissingSEO const &src);
				MissingSEO				&operator=(MissingSEO const &rhs);
				char const				*what(void) const throw();
		};

		class					SignGradeTooLowException: public std::exception
		{
			public:
				SignGradeTooLowException(void);
				~SignGradeTooLowException(void) throw();
				SignGradeTooLowException(SignGradeTooLowException const &src);
				SignGradeTooLowException		&operator=(SignGradeTooLowException const &rhs);
				char const				*what(void) const throw();
		};

		class					SEOGradeTooLowException: public std::exception
		{
			public:
				SEOGradeTooLowException(void);
				~SEOGradeTooLowException(void) throw();
				SEOGradeTooLowException(SEOGradeTooLowException const &src);
				SEOGradeTooLowException		&operator=(SEOGradeTooLowException const &rhs);
				char const				*what(void) const throw();
		};

};

#endif




