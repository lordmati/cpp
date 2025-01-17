#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Destructor Base" << std::endl;
}
Base * generate(void)
{
	srand((int)time(0));
	int numR = rand();
	if (numR % 3)
		return(new A());
	else if (numR % 2)
		return(new B());
	else
		return(new C());
}
void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Pointer is A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Pointer is B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Pointer is C" << std::endl;
	else
		std::cerr << "Unknown pointer" << std::endl;
}
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference is A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			std::cout << "Refenrence is B" << std::endl;
			(void)b;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << "Reference is C" << std::endl;
				(void)c;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}