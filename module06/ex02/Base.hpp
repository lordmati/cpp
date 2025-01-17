#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base() = 0;
};
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif