#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "childs/ShrubberyCreationForm.hpp"
#include "childs/RobotomyRequestForm.hpp"
#include "childs/PresidentialPardonForm.hpp"

class Intern {
private:
	AForm	*MakeShrubberyCreationForm(std::string target_);
	AForm	*MakePresidentialPardonForm(std::string target_);
	AForm	*MakeRobotomyRequestForm(std::string target_);
public:
	Intern();
	Intern(const Intern &cpy);
	Intern &operator=(const Intern &rhs);
	~Intern();
	AForm	*makeForm(std::string form_, std::string target_);
};

#endif