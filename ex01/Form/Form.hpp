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
public:

};

std::ostream &operator<<(std::ostream& os, Form &form);


#endif
