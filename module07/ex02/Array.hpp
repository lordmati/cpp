#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
			T *array;
			int len;
	public:
			Array();
			Array(unsigned int n);
			Array(const Array &data);
			Array &operator=(const Array &data);
			T &operator[](unsigned int n);
			int size();
			~Array();

};
#include "Array.tpp"

#endif