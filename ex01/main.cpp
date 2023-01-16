#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{
	//Idea :
	unsigned int pouet = 127;
	while (pouet)
	{
		std::cout << MyNatural(pouet) << '\n';
		pouet *= 2;
	}
	std::cout << MyNatural(pouet) << "\n\n";
	//Here I figured out *= 2 is same as << 1
	//Same test with mine :
	pouet = 127;
	while (pouet)
	{
		std::cout << MyNatural(pouet) << '\n';
		pouet = multiplier(pouet, 2);
	}
	std::cout << MyNatural(pouet) << "\n\n";

	unsigned int a = 135;
	unsigned int b = 29;
	std::cout << a << " * " << b << " = " << multiplier(a, b) << " = " << multiplier(b, a) << " = " << a * b << '\n';

	a = 0;
	b = 29;
	std::cout << a << " * " << b << " = " << multiplier(a, b) << " = " << multiplier(b, a) << " = " << a * b << '\n';

	a = 0;
	b = 0;
	std::cout << a << " * " << b << " = " << multiplier(a, b) << " = " << multiplier(b, a) << " = " << a * b << '\n';

	a = -1;
	b = 29;
	std::cout << a << " * " << b << " = " << multiplier(a, b) << " = " << multiplier(b, a) << " = " << a * b << '\n';

	return 0;
}