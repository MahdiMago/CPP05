#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void printTitle(std::string title) {
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	Intern  someRandomIntern;
	AForm* rrf;

	printTitle("TEST 1: ROBOTOMY REQUEST");
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	printTitle("TEST 2: PRESIDENTIAL PARDON");
	rrf = someRandomIntern.makeForm("presidential pardon", "Alice");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	printTitle("TEST 3: SHRUBBERY CREATION");
	rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	printTitle("TEST 4: UNKNOWN FORM");
	rrf = someRandomIntern.makeForm("coffee request", "Boss");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	printTitle("TEST 5: FULL WORKFLOW (INTERN + BUREAUCRAT)");
	Bureaucrat  director("Director", 1);
	rrf = someRandomIntern.makeForm("presidential pardon", "Criminal");
	    
	if (rrf)
	{
		std::cout << director << std::endl;
		std::cout << *rrf << std::endl;

		director.signForm(*rrf);
		director.executeForm(*rrf);

		delete rrf;
	}

	return 0;
}