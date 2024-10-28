#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
			std::string type;
	public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal &data);
			WrongAnimal &operator=(const WrongAnimal &data);
			virtual void makeSound(void) const;
			virtual ~WrongAnimal();
			std::string getType(void) const;
};


#endif