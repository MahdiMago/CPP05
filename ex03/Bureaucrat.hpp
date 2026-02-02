#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
private: 
	const	std::string name;
	int		grade;
public:
	Bureaucrat(std::string n = "Random", int g = 150);
	Bureaucrat(const Bureaucrat& cpy);
	Bureaucrat& operator=(const Bureaucrat &cpy);
	~Bureaucrat();

	std::string	getName()const;
	int			getGrade()const;
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm &f);
	void	executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif