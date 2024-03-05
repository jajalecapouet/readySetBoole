#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{
	std::string aStr;
	unsigned int a;
	unsigned int Gray;

	while ("trou")
	{
		try
		{
			std::cout << "put a value : ";
			std::cin >> aStr;
			a = std::stoi(aStr);
			Gray = GrayCode(a);
			std::cout << a << " has a Grey code boolean values = " << MyNatural(Gray) << " which as normal binaries is equal to " << Gray << '\n';
		}
		catch (const std::exception& e)
		{
			std::cout << "bad input : " << e.what() << '\n';
		}
	}

	return 0;
}