#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string n, int g) : name(n), grade(g)
{
	std::cout << "Bureaucrat constructor called" << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : name(cpy.name), grade(cpy.grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat&Bureaucrat::operator=(const Bureaucrat &cpy)
{
	if (this != &cpy)
	{
		this->grade = cpy.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyer called" << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if ((grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if ((grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too Low");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}

}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}