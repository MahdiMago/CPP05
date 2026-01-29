#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "../AForm.hpp"
#include <cstdlib>

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
};

#endif
