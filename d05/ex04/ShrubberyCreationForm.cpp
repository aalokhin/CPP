#include <iostream>
#include <fstream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->get_if_Signed() && executor.getGrade() <= this->get_Grade_Exec())
	{
		std::string name1 = this->getName();
		std::string name2 = "_shrubbery";
		std::string name = name1 + name2;

		std::ofstream ofile(name, std::ios_base::out);
		if (!ofile.is_open())
		{
			std::cout << "Output file not opened" << std::endl;
		}
		else
		{
			ofile << "         *	           " << std::endl;
			ofile << "     *  *r*  *         " << std::endl;
			ofile << "  * *a* ^Y^ *i* *      " << std::endl;
			ofile << " *m*^Y^*^\\^*^Y^*s*    " << std::endl;
			ofile << " ^Y^*\\*e*/*l*/*^Y^    " << std::endl;
			ofile << " *\\*t*|Y^\\^Y|*l*/*   " << std::endl;
			ofile << "*s*|Y^\\^/^//^Y|*a*    " << std::endl;
			ofile << "^Y^\\_^\\\\//^_//^Y^   " << std::endl;
			ofile << "^\\_^\\_\\_\\//_/_/^_/^" << std::endl;
			ofile << " ^^\\_^\\_\\/_/^_/^^   " << std::endl;
			ofile << "   ^^\\_ \\// _/^^     " << std::endl;
			ofile << "       \\_\\_/         " << std::endl;
			ofile << "        /|\\           " << std::endl;
			ofile << "       /\\/\\          " << std::endl;

			ofile.close();
		}
	}
	else if (!this->get_if_Signed())
		throw Form::Execution_Impossible();
	else if (executor.getGrade() > this->get_Grade_Exec())
		throw Bureaucrat::GradeTooLowException();
}

/********************************* COPLIEN ********************************/

ShrubberyCreationForm::ShrubberyCreationForm(){return ;}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137)
{ return ;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy)
{ *this = copy; }

ShrubberyCreationForm::~ShrubberyCreationForm(){return ;}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj)
{
	if (this != &obj)
	{
		this->becomeSigned(obj.get_if_Signed());
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & os, ShrubberyCreationForm const & obj)
{
	std::string yes_no;
	if (obj.get_if_Signed())
		yes_no = "not signed";
	else
		yes_no = "signed";
	std::cout << obj.getName() << " is " << yes_no << " form with " << obj.get_Grade_Sign() << " to sign and " << obj.get_Grade_Exec() << " to execute" << std::endl;
	return os;
}


// ofile << "         *	           " << std::endl;
// ofile << "     *  *r*  *         " << std::endl;
// ofile << "  * *a* ^Y^ *i* *      " << std::endl;
// ofile << " *m*^Y^*^\\^*^Y^*s*    " << std::endl;
// ofile << " ^Y^*\\*e*/*l*/*^Y^    " << std::endl;
// ofile << " *\\*t*|Y^\\^Y|*l*/*   " << std::endl;
// ofile << "*s*|Y^\\^/^//^Y|*a*    " << std::endl;
// ofile << "^Y^\\_^\\\\//^_//^Y^   " << std::endl;
// ofile << "^\\_^\\_\\_\\//_/_/^_/^" << std::endl;
// ofile << " ^^\\_^\\_\\/_/^_/^^   " << std::endl;
// ofile << "   ^^\\_ \\// _/^^     " << std::endl;
// ofile << "       \\_\\_/         " << std::endl;
// ofile << "        /|\\           " << std::endl;
// ofile << "       /\\/\\          " << std::endl;