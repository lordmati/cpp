#include "Fixed.hpp"

static void own_tests(void)
{
	std::cout << "\n------WELCOME TO MY OWN TESTS------\n\n";

	Fixed b(10);
	Fixed c = 10;
	Fixed d = 5;

	const Fixed e = 7;

	std::cout << "result b + 2: " << (b + 2) << std::endl;
	std::cout << "result b + c: " << (b + c)  << std::endl;
	std::cout << "result b - c: " << (b - c) << std::endl;
	std::cout << "result b * c: " << (b * c) << std::endl;
	std::cout << "result b / c: " << (b / c) << std::endl;

	std::cout << "result b is greater: " << (b > d) << std::endl;
	std::cout << "result b is smaller: " << (b < d) << std::endl;
	std::cout << "result b and c they are the same: " << (b == c) << std::endl;
	std::cout << "result b and c they are differents: " << (b != c) << std::endl;
	std::cout << "result b is greater or equal: " << (b >= d) << std::endl;
	std::cout << "result b is smaller or equal: " << (b <= d) << std::endl;

	std::cout << "result min is: " << Fixed::min(e, b) << std::endl;
}

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	own_tests();
	return 0;
}