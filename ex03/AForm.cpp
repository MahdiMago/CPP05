#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string n, int toSign, int toExec) : name(n), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
	std::cout << "Form constructor called" << std::endl;
	if (toSign < 1 || toExec < 1)
		throw GradeTooHighException();
	else if (toSign > 150 || toExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &cpy) : name(cpy.name), isSigned(cpy.isSigned), gradeToSign(cpy.gradeToSign), gradeToExec(cpy.gradeToExec)
{
	std::cout << "Form's copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
	{
		this->isSigned = cpy.isSigned;
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade too High to sign");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade too Low to sign");
}

AForm::~AForm()
{
	std::cout << "Form's destoyer called" << std::endl;
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExec() const
{
	return(this->gradeToExec);
}

bool AForm::getSigned() const
{
	return (this->isSigned);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	else if (b.getGrade() < 1)
		throw GradeTooHighException();
	else
		this->isSigned = true;
}

std::string	AForm::getName() const
{
	return (name);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned == false)
		throw FormNotSigned();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	else
		beExecuted();
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs)
{
	o << "Form " << rhs.getName()
		<< ", signed: " << (rhs.getSigned() ? "yes" : "no")
		<< ", sign grade: " << rhs.getGradeToSign()
		<< ", exec grade: " << rhs.getGradeToExec();
	return o;
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "The Form is not signed";
}

