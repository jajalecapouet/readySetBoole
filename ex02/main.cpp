#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{
	std::string aStr;
	unsigned int a;

	while ("trou")
	{
		try
		{
			std::cout << "put a value : ";
			std::cin >> aStr;
			a = std::stoi(aStr);
			std::cout << MyNatural(a) << " which has a Grey code value = " << GrayCode(a) << '\n';
		}
		catch (const std::exception& e)
		{
			std::cout << "bad input : " << e.what() << '\n';
		}
	}

	return 0;
}