#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Constructor Array" << std::endl;
	this->array = new T[0];
	this->len = 0;
}
template <typename T>
Array<T>::Array(unsigned int n)
{

	this->array = new T[n];
	this->len = n;
}
template <typename T>
Array<T>::Array(const Array &data)
{
	std::cout << "Array constructor copy" << std::endl;
	int i = 0;
	this->array = new T[data.len];
	while(i < data.len)
	{
		this->array[i] = data.array[i];
		i++;
	}
	this->len = data.len;
}
template <typename T>
Array<T> &Array<T>::operator=(const Array &data)
{
	int i = 0;
	this->array = new T[data.len];
	std::cout << "Array operator constructor" << std::endl;
	while(i < data.len)
	{
		this->array[i] = data.array[i];
		i++;
	}
	this->len = data.len;
	return(*this);
}
template<typename T>
T &Array<T>::operator[](unsigned int n)
{
	if(n >= (unsigned int)this->len)
		throw std::out_of_range("Index out of bounds");
	return(this->array[n]);
}

template <typename T>
int Array<T>::size()
{
	return(this->len);
}
template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor Array" << std::endl;
	delete[] this->array;
}