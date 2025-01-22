#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	private:

	public:
			typedef typename std::stack<T>::container_type::iterator iterator;
			MutantStack();
			~MutantStack();
			MutantStack &operator=(const MutantStack &data);
			MutantStack(const MutantStack &data);
			iterator begin();
			iterator end();
};

#include "MutantStack.tpp"
#endif