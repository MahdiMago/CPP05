#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool	isSigned;
	const int gradeToSign;
	const int gradeToExec;
public:
	Form(std::string n = "RandomForm", int toSign = 50, int toExec = 10);
	Form(const Form &cpy);
	Form& operator=(const Form &cpy);
	~Form();

	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void	beSigned(const Bureaucrat &b);
	std::string getName() const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif
