#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 145, 137), target(t)
{
	std::cout << "ShrubberyCreationForm construtor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), target(cpy.target)
{
	std::cout << "ShrubberyCreationForm copy construtor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		this->target = rhs.target;
		AForm::operator=(rhs);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyer called" << std::endl;
}

void ShrubberyCreationForm::beExecuted() const
{
	std::string filename = this->target + "_shrubbery";
	std::ofstream TreeFile(filename.c_str());
	
	if (!TreeFile.is_open())
	{
		throw ExecutionError();
	}
	TreeFile << "       _-_" << std::endl;
	TreeFile << "    /~~   ~~\\" << std::endl;
	TreeFile << " /~~         ~~\\" << std::endl;
	TreeFile << "{               }" << std::endl;
	TreeFile << " \\  _-     -_  /" << std::endl;
	TreeFile << "   ~  \\\\ //  ~" << std::endl;
	TreeFile << "_- -   | | _- _" << std::endl;
	TreeFile << "  _ -  | |   -_" << std::endl;
	TreeFile << "      // \\\\" << std::endl;

	TreeFile.close();
}

const char *ShrubberyCreationForm::ExecutionError::what() const throw()
{
	return "Error during the creation of the file";
}