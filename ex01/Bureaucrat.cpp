#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n) : name(n), grade(150)
{
	std::cout << "Naming constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g) : name(n)
{
	if (g > 150)
				throw (Bureaucrat::GradeTooHighException("Grade too high exception\n"));
	if (g < 1)
		throw (Bureaucrat::GradeTooLowException("Grade too low exception\n"));
	std::cout << "Name and grading constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &newclass)
{
	*this = newclass;
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &newClass)
{
	if (this != &newClass)
		*this = newClass;
	std::cout << "Copy operator called" << std::endl;
	return (*this);
}

const std::string Bureaucrat::getName()
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return(grade);
}

void Bureaucrat::addGrade(int add)
{
	if ((grade + add) > 150)
		throw (Bureaucrat::GradeTooHighException("Grade too low exception\n"));
	this->grade += add;
}

void	Bureaucrat::subGrade(int sub)
{
	if ((grade - sub) < 1)
		throw (Bureaucrat::GradeTooLowException("Grade too low exception\n"));
	this->grade -= sub;
}

//grade too high

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg)
{
	_msg = msg;
}

inline const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return _msg;
}

//grade too low

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg)
{
	_msg = msg;
}

inline const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return _msg;
}

std::ostream &operator<<(std::ostream& os, Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << "." << std::endl;
	return (os);
}

void	Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}
