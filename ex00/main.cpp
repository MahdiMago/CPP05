#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- TEST 1 : Normal usage ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;

		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\n----------------------------------\n" << std::endl;

	std::cout << "--- TEST 2 : Increment Error (Too High) ---" << std::endl;
	try
	{
		Bureaucrat boss("The Boss", 1);
		std::cout << boss << std::endl;
		
		std::cout << "Try to increment grade 1..." << std::endl;
		boss.incrementGrade();
		
		std::cout << "This line should not print." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\n----------------------------------\n" << std::endl;

	std::cout << "--- TEST 3 : Decrement Error (Too Low) ---" << std::endl;
	try
	{
		Bureaucrat stagiaire("Intern", 150);
		std::cout << stagiaire << std::endl;

		std::cout << "Try to decrement grade 150..." << std::endl;
		stagiaire.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\n----------------------------------\n" << std::endl;

	std::cout << "--- TEST 4 : Constructor Error (Too High) ---" << std::endl;
	try
	{
		std::cout << "Try to create God with grade 0..." << std::endl;
		Bureaucrat god("God", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\n----------------------------------\n" << std::endl;

	std::cout << "--- TEST 5 : Constructor Error (Too Low) ---" << std::endl;
	try
	{
		std::cout << "Try to create Alien with grade 200..." << std::endl;
		Bureaucrat alien("Alien", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	return 0;
}
