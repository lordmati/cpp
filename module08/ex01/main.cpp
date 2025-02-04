#include "Span.hpp"

int main(void)
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		Span largeSpan = Span(10000);
		Span errorSpan = Span(8);

		std::vector<int> numbers;
		std::vector<int>error;
		for (unsigned int i = 0; i < 10000; ++i)
		{
			numbers.push_back(i);
		}
		for (unsigned int i = 0; i < 9; ++i)
		{
			error.push_back(i);
		}
		errorSpan.addMultipleNumbers(numbers.begin(),numbers.end());
		largeSpan.addMultipleNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest Span (large): " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span (large): " << largeSpan.longestSpan() << std::endl;

	} catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}