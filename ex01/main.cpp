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

	unsigned int x = 135;
	unsigned int y = 29;
	std::cout << x << " * " << y << " = " << multiplier(x, y) << " = " << multiplier(y, x) << " = " << x * y << '\n';

	x = 0;
	y = 29;
	std::cout << x << " * " << y << " = " << multiplier(x, y) << " = " << multiplier(y, x) << " = " << x * y << '\n';

	x = 0;
	y = 0;
	std::cout << x << " * " << y << " = " << multiplier(x, y) << " = " << multiplier(y, x) << " = " << x * y << '\n';

	x = -1;
	y = 29;
	std::cout << x << " * " << y << " = " << multiplier(x, y) << " = " << multiplier(y, x) << " = " << x * y << '\n';

	std::string aStr;
	std::string bStr;
	unsigned int a;
	unsigned int b;
	
	while ("trou")
	{
		try
		{
			std::cout << "\nput a value for a : ";
			std::cin >> aStr;
			std::cout << "\nput a value for b : ";
			std::cin >> bStr;
			a = std::stoi(aStr);
			b = std::stoi(bStr);
			std::cout << a << " * " << b << " = " << multiplier(a, b) << '\n';
		}
		catch (const std::exception& e)
		{
			std::cout << "invalid arguments\n";
		}
	}

	return 0;
}