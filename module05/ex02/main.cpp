#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{
	Bureaucrat Mati("Mati",4);
	PresidentialPardonForm President("Mauri");
	//President.beSigned(Mati);
	std::cout << President << std::endl;
	President.execute(Mati);
}