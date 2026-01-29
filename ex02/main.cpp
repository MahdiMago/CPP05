#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--- TEST 1 : SUCCESSFUL SIGN ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 2);
		Form	taxForm("Tax Form", 20, 50);

		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);
		
		std::cout << taxForm << std::endl; 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2 : GRADE TOO LOW TO SIGN ---" << std::endl;
	try {
		Bureaucrat stagiaire("Stagiaire", 150);
		Form	   contract("Contract", 100, 50);

		std::cout << stagiaire << std::endl;
		std::cout << contract << std::endl;

		stagiaire.signForm(contract);
		
		std::cout << contract << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3 : FORM CREATION ERRORS ---" << std::endl;
	try {
		Form badForm("Bad", 0, 50);
	}
	catch (std::exception &e) {
		std::cout << "Construction failed: " << e.what() << std::endl;
	}

	return 0;
}