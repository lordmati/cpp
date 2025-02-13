#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T,typename F>
void iter(T *address,int length,F function)
{
	if (!address || !function)
		return ;
	int i = 0;
	while(i < length)
	{
		function(address[i]);
		i++;
	}
}

#endif