#include "../includes/booleFunctions.hpp"
#include <cmath>
#include <cstring>

using namespace ft;

unsigned int myPow(int a, int b)
{
	unsigned int res = 1;

	while (b--)
	{
		res *= a;
	}
	return res;
}

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
	unsigned int aShifted;

	
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
			aStr.clear();
			bStr.clear();
			MyNatural natB(b);
			bool first = true;
			const bool* data = natB.getData();

			std::cout << "\nb = " << b << " = " << natB <<  " which is compounded by :\n";
			aStr += "     b = ";
			bStr += "result = ";
			for (int i = 0; i < 32; ++i)
			{
				if (data[31 - i])
				{
					if (!first && i < 32)
					{
						aStr += " + ";
						bStr += " + ";
					}
					first = false;
					aStr += "2^";
					aStr += std::to_string(i);
					bStr += std::to_string(a);
					bStr += " << ";
					bStr += std::to_string(i);
					bStr += " (= ";
					aShifted = a << i;
					bStr += std::to_string(aShifted);
					bStr += ')';
				}
			}
			std::cout << aStr << '\n' << bStr << '\n';
			std::cout << a << " * " << b << " = " << multiplier(a, b) << '\n';
		}
		catch (const std::exception& e)
		{
			std::cout << "invalid arguments\n";
		}
	}

	return 0;
}