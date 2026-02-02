#include <iostream>
#include <cstdlib> // Pour srand
#include <ctime>   // Pour time

#include "Bureaucrat.hpp"
#include "AForm.hpp" 
#include "childs/ShrubberyCreationForm.hpp"
#include "childs/RobotomyRequestForm.hpp"
#include "childs/PresidentialPardonForm.hpp"

void printTitle(std::string title) {
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	printTitle("TEST 1: SHRUBBERY CREATION (Jardinage)");
	try {
		Bureaucrat  bob("Bob (Jardinier)", 137); // Grade suffisant pour tout
		ShrubberyCreationForm shrub("Jardin");

		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;

		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTitle("TEST 2: ROBOTOMY REQUEST (50% Chance)");
	try {
		Bureaucrat  doc("Dr. House", 45); // Grade limite mais OK
		RobotomyRequestForm robot("Bender");

		std::cout << doc << std::endl;
		
		doc.signForm(robot);

		std::cout << "\n[Tentative 1]" << std::endl;
		doc.executeForm(robot);
		
		std::cout << "\n[Tentative 2]" << std::endl;
		doc.executeForm(robot);
		
		std::cout << "\n[Tentative 3]" << std::endl;
		doc.executeForm(robot);
		
		std::cout << "\n[Tentative 4]" << std::endl;
		doc.executeForm(robot);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTitle("TEST 3: PRESIDENTIAL PARDON");
	try {
		Bureaucrat  president("Zaphod", 1); // Le boss
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << president << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTitle("TEST 4: ERROR HANDLING");
	    
	try {
		std::cout << "[Cas A : Exécution sans signature]" << std::endl;
		Bureaucrat badGuy("Hacker", 1);
		PresidentialPardonForm illegalForm("Target");

		badGuy.executeForm(illegalForm); 
	}
	catch (std::exception &e) {
		std::cout << "Main catch: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "[Cas B : Grade trop bas pour exécuter]" << std::endl;
		Bureaucrat  stagiaire("Stagiaire", 140); // Peut signer Shrubbery (145) mais pas exec (137)
		ShrubberyCreationForm bush("Buisson");

		stagiaire.signForm(bush); // Ça devrait marcher
		stagiaire.executeForm(bush); // Ça doit échouer (GradeTooLow)
	}
	catch (std::exception &e) {
		std::cout << "Main catch: " << e.what() << std::endl;
	}

	return 0;
}