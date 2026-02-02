#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "../AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private :
	std::string target;
public : 
	ShrubberyCreationForm(std::string t = "randomTarget");
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();

	virtual void beExecuted() const;

	class ExecutionError : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
