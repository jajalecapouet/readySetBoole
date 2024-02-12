#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{
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
			std::cout << a << " + " << b << " = " << adderDemoVersion(a, b) << '\n';
		}
		catch (const std::exception& e)
		{
			std::cout << "invalid arguments\n";
		}
	}

	return 0;
}