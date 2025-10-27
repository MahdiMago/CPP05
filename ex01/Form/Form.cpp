#include "Form.hpp"

Form::Form()
{
	std::cout << "Form's default constructor called" << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	std::cout << "Form's parametring constructor called" << std::endl;
}

Form::Form(const Form &form) : _name(form._name), _gradeToExec(form._gradeToExec), _gradeToSign(form._gradeToSign), _signed(form._signed)
{
	std::cout << "Form's copy constructor called" << std::endl;
}


Form &Form::operator=(const Form &form)
{
	if (this == &form)
		return (*this);
	this->_signed = form._signed;
	std::cout << "Form's copy operator constructor called" << std::endl;
}

std::string	Form::getName()
{return (this->_name);}

bool		Form::getSigned()
{return (this->_signed);}

const int	Form::getGradeToSign()
{return (this->_gradeToSign);}

const int	Form::getGradeToExec()
{return (this->_gradeToExec);}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	try {
		if (bureaucrat.getGrade >> this->getGradeToSign)
			
	}
}

Form::~Form()
{
	std::cout << "Form's Destructor called" << std::endl;
}