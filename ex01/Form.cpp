#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string n, int toSign, int toExec) : name(n), gradeToSign(toSign), gradeToExec(toExec), isSigned(false)
{
	std::cout << "Form constructor called" << std::endl;
	if (toSign < 1 || toExec < 1)
		throw GradeTooHighException();
	else if (toSign > 150 || toExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &cpy) : name(cpy.name), isSigned(cpy.isSigned), gradeToSign(cpy.gradeToSign), gradeToExec(cpy.gradeToExec)
{
	std::cout << "Form's copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &cpy)
{
	if (this != &cpy)
	{
		this->isSigned = cpy.isSigned;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Grade too High to sign");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade too Low to sign");
}

Form::~Form()
{
	std::cout << "Form's destoyer called" << std::endl;
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExec() const
{
	return(this->gradeToExec);
}

bool Form::getSigned() const
{
	return (this->isSigned);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	else if (b.getGrade() < 1)
		throw GradeTooHighException();
	else
		this->isSigned = true;
}

std::string	Form::getName() const
{
	return (name);
}

std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
	o << "Form " << rhs.getName()
		<< ", signed: " << (rhs.getSigned() ? "yes" : "no")
		<< ", sign grade: " << rhs.getGradeToSign()
		<< ", exec grade: " << rhs.getGradeToExec();
	return o;
}
