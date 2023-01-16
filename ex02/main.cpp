#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{

	for (int i = 0; i < 16; ++i)
	{
		std::cout << MyNatural(i) << " | ";
		std::cout << MyNatural(GrayCode(i)) << '\n';
	}

	return 0;
}