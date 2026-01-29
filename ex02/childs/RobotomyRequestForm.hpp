#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
private :
	std::string target;
public : 
	RobotomyRequestForm(std::string t = "randomTarget");
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm();

	virtual void beExecuted() const;

	class ExecutionError : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
