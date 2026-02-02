#include "Intern.hpp"

AForm *Intern::MakeShrubberyCreationForm(std::string target_)
{
	return new ShrubberyCreationForm(target_);
}

AForm *Intern::MakePresidentialPardonForm(std::string target_)
{
	return new PresidentialPardonForm(target_);
}

AForm *Intern::MakeRobotomyRequestForm(std::string target_)
{
	return new RobotomyRequestForm(target_);
}

Intern::Intern()
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	(void)cpy;
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	std::cout << "Intern Copy operator called" << std::endl;

	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destroyer called" << std::endl;
}

AForm *Intern::makeForm(std::string form_, std::string target_)
{
	struct formTab {
	std::string	formName;
	AForm	*(Intern::*function)(std::string);
	};

	formTab formFunction[] = {
		{"shrubbery creation", &Intern::MakeShrubberyCreationForm},
		{"presidential pardon", &Intern::MakePresidentialPardonForm},
		{"robotomy request", &Intern::MakeRobotomyRequestForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (formFunction[i].formName == form_)
		{
			std::cout << "Intern creates " << form_ << std::endl;
			return (this->*formFunction[i].function)(target_);
		}
	}
	std::cout << "No Intern found to create ! " << std::endl;
	return NULL;
}
