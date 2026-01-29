#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool	isSigned;
	const int gradeToSign;
	const int gradeToExec;
public:
	AForm(std::string n = "RandomForm", int toSign = 50, int toExec = 10);
	AForm(const AForm &cpy);
	AForm& operator=(const AForm &cpy);
	virtual	~AForm();

	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void	beSigned(const Bureaucrat &b);
	std::string getName() const;

	void	execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class FormNotSigned : public std::exception {
	public:
		virtual const char* what() const throw();
	};
protected:
	virtual void beExecuted() const = 0;
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif
