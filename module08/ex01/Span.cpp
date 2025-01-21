#include "Span.hpp"

Span::Span()
{
	std::cout << "Constructor Span" << std::endl;
	this->N = 0;
}

Span &Span::operator=(const Span &data)
{
	std::cout << "Span assignament operator" << std::endl;
	this->N = data.N;
	this->Array = data.Array;
	return(*this);
}

Span::Span(const Span &data)
{
	std::cout << "Constructor Span copy" << std::endl;
	if(this != &data)
		*this = data;
}
Span::Span(unsigned int N)
{
	if(this->Array.size() == N)
		throw std::out_of_range("The vector has the maximum number of elements");
	this->N = N;
}
void Span::addNumber(int n)
{
	this->Array.push_back(n);
}
int Span::shortestSpan()
{
	int i = 1;
	std::sort(this->Array.begin(),this->Array.end());
	if (this->Array.size() <= 1)
		throw std::logic_error("There aren't enough numbers");
	int result = std::abs(this->Array[1] - this->Array[0]);
	while(i < (int)this->Array.size())
	{
		if(result > std::abs(this->Array[i] - this->Array[i - 1]))
			result = std::abs(this->Array[i] - this->Array[i - 1]);
		i++;
	}
	return (result);
}
int Span::longestSpan()
{
	std::sort(this->Array.begin(),this->Array.end());
	if(this->Array.size() <= 1)
		throw std::logic_error("There aren't enough numbers");
	int result = std::abs(this->Array[this->Array.size() - 1] - this->Array[0]);
	return(result);
}
void Span::addMultipleNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	int d = std::distance(start,end);
	if (d + this->Array.size() > this->N)
		throw std::out_of_range("the total number of elements is bigger than the maximum number of allowed elements");
	this->Array.insert(this->Array.end(),start,end);
}
Span::~Span()
{
	std::cout << "Destructor Span" << std::endl;
}