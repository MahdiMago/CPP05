#include "Bureaucrat.hpp"

int	main(void)
{
	try {
	Bureaucrat b;
	Bureaucrat a("elien");
	Bureaucrat c("amandine", 45);

	std::cout << b << std::endl;
	std::cout << a << std::endl;
	std::cout << c << std::endl;

	// b.addGrade(5);
	c.subGrade(500);

	std::cout << c << std::endl;


	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	return (0);
}
