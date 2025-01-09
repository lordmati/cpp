#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat *e = NULL;
	Bureaucrat a("Bureaucrat1", 100);
	Bureaucrat b("Bureaucrat2", 1);
	Bureaucrat c;
	Bureaucrat d(b);
	e = new Bureaucrat(a);
	std::cout << "a: " << a << "\n";
	std::cout << "b: " << b << "\n";
	std::cout << "c: " << c << "\n";
	d.decrementRange();
	std::cout << "d: " << d << "\n";
	e->incrementRange();
	std::cout << "e: " << *e << "\n";
	while (a.getGrade() <= 151)
	{
		a.decrementRange();
		std::cout << "a: " << a << "\n";
	}
	delete e;
}