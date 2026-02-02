#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../AForm.hpp"

class PresidentialPardonForm : public AForm
{
private :
	std::string target;
public : 
	PresidentialPardonForm(std::string t = "randomTarget");
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& rhs);
	~PresidentialPardonForm();

	virtual void beExecuted() const;
};

#endif
