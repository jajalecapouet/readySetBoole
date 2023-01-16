#ifndef BOOLEFUNCTIONS
#define BOOLEFUNCTIONS

#include "MyNatural.hpp"

namespace ft
{

	unsigned int	adderDemoVersion(unsigned int a, unsigned int b)
	{
		int loop = 0;
		while (b)
		{
			std::cout << "loop " << ++loop << '\n';
			std::cout << "a      = " << MyNatural(a) << '\n';
			std::cout << "b      = " << MyNatural(b) << '\n';
			unsigned int	retain = 0;
			unsigned int	compareTo = 1;
			for (int i = 0; i < 32; ++i)
			{
				unsigned int	next = compareTo << 1;
				bool bitA = a & compareTo;
				bool bitB = b & compareTo;
				if (bitB)
				{
					a ^= compareTo;
					if (bitA)
						retain |= next;
				}
				compareTo = next;
			}
			b = retain;
		}
		std::cout << "result = " << MyNatural(a) << '\n';
		return a;
	}

	unsigned int	adder(unsigned int a, unsigned int b)
	{
		while (b)
		{
			unsigned int	retain = 0;
			unsigned int	compareTo = 1;
			for (int i = 0; i < 32; ++i)
			{
				unsigned int	next = compareTo << 1;
				bool bitA = a & compareTo;
				bool bitB = b & compareTo;
				if (bitB)
				{
					a ^= compareTo;
					if (bitA)
						retain |= next;
				}
				compareTo = next;
			}
			b = retain;
		}
		return a;
	}

	unsigned int	multiplier(unsigned int a, unsigned int b)
	{
		unsigned int	result = 0;
		unsigned int	compareTo = 1;
		for (int i = 0; i < 32; ++i)
		{
			if (b & compareTo)
				result = adder(result, a << i);
			compareTo <<= 1;
		}
		return result;
	}

}

#endif