#include "easyfind.hpp"
template <typename T>
int easyfind(T container,int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(),num);
	if(it == container.end())
		throw std::runtime_error("Value not found in the container");
	return(std::distance(container.begin(), it));
}