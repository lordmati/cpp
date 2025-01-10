#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	std::cout << "---------VALID---------" << std::endl;
	Bureaucrat firstBureacrat("FirstBureaucrat",110);
	std::cout << firstBureacrat << std::endl;
	Form firstform("FirstForm",110,110);
	firstform.beSigned(firstBureacrat);
	std::cout << firstform << std::endl;
	firstBureacrat.signForm(firstform);
	std::cout << "---------INVALID-------" << std::endl;
	Bureaucrat errorbureaucrat ("Error Bureaucrat",151);
	std::cout << errorbureaucrat << std::endl;
	Form errorform("Errorform",100,100);
	errorform.beSigned(errorbureaucrat);
	std::cout << errorform << std::endl;
	errorbureaucrat.signForm(errorform);
	std::cout << "---------DESTRUCTOR--------" << std::endl;
}