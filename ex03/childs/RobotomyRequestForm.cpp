#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("RobotomyRequestForm", 72, 45), target(t)
{
	std::cout << "RobotomyRequestForm construtor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), target(cpy.target)
{
	std::cout << "RobotomyRequestForm copy construtor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		this->target = rhs.target;
		AForm::operator=(rhs);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyer called" << std::endl;
}

void RobotomyRequestForm::beExecuted() const
{
	std::cout << "....Drilling noise...." << std::endl;
	int random = std::rand();

	if (random % 2)
		std::cout << this->target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "The robotomy of " << this->target << " failed !" << std::endl;
}
