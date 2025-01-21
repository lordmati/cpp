#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
			std::vector<int> Array;
			unsigned int N;
	public:
			Span();
			Span(const Span &data);
			Span(unsigned int N);
			Span &operator=(const Span &data);
			void addNumber(int N);
			void addMultipleNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
			int shortestSpan();
			int longestSpan();
			~Span();
};
#endif