#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "../Bureaucrat.hpp"

class Form {
private:
	const std::string	_name;
	bool	_signed;
	const int	_gradeToSign;
	const int	_gradeToExec;
	Form();
public:
	Form(std::string name, const int gradeToSign, const int gradeToExec);
	Form(const Form &form);
	~Form();
	Form &operator=(const Form &form);

	std::string	getName();
	bool		getSigned();
	const int	getGradeToSign();
	const int	getGradeToExec();

	void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream& os, Form &form);


#endif
