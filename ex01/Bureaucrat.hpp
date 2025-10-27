#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form/Form.hpp"

class Bureaucrat {
private:
	const std::string name;
	int grade;
	public:
	Bureaucrat();
	Bureaucrat(std::string n);
	Bureaucrat(std::string n, int g);
	Bureaucrat(const Bureaucrat &newclass);
	Bureaucrat &operator=(const Bureaucrat &newClass);
	~Bureaucrat();

	// void GradeTooHighException();
	// void GradeTooLowException();

	const std::string getName();
	int getGrade() const;
	void	addGrade(int add);
	void	subGrade(int sub);

	void	signForm(Form &form);

	class GradeTooHighException : public std::exception {
		private:
			const char *_msg;

		public:
			GradeTooHighException(const char *msg);
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		private:
			const char *_msg;

		public:
			GradeTooLowException(const char *msg);
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream& os, Bureaucrat& bureau);


#endif
