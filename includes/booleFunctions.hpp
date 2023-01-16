#ifndef BOOLEFUNCTIONS
#define BOOLEFUNCTIONS

#include "MyNatural.hpp"
#include "MyBoolTree.hpp"
#include <string>
#include <utility>

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

	unsigned int	GrayCode(unsigned int a)
	{
		unsigned int	result = 0;
		unsigned int	b = a >> 1;

		unsigned int	compareTo = 1;
		for (int i = 0; i < 32; ++i)
		{
			bool	bitA = compareTo & a;
			bool	bitB = compareTo & b;
			if (bitA ^ bitB)
				result |= compareTo;
			compareTo <<= 1;
		}
		return result;
	}

	std::pair<bool, bool>	_booleanEvaluationRecursive(const std::string &str, std::string::size_type &idx)
	{
		if (idx == std::string::npos
				|| (idx <= 1 && str[idx] != '1' && str[idx] != '0' && str[idx] != '!')
				|| (!idx && str[idx] == '!'))
			return std::make_pair(false, false);
		switch (str[idx])
		{
			case '1':
				return (std::make_pair(true, true));
			case '0':
				return (std::make_pair(false, true));
			case '!':
			{
				std::pair<bool, bool>	result = _booleanEvaluationRecursive(str, --idx);
				if (!result.second)
					return result;
				if (!result.first)
					return (std::make_pair(true, true));
				return (std::make_pair(false, true));
			}
			case '&':
			{
				std::pair<bool, bool>	resultRight = _booleanEvaluationRecursive(str, --idx);
				if (!resultRight.second)
					return std::make_pair(false, false);
				std::pair<bool, bool>	resultLeft = _booleanEvaluationRecursive(str, --idx);
				if (!resultLeft.second)
					return std::make_pair(false, false);
				return std::make_pair(resultLeft.first & resultRight.first, true);
			}
			case '|':
			{
				std::pair<bool, bool>	resultRight = _booleanEvaluationRecursive(str, --idx);
				if (!resultRight.second)
					return std::make_pair(false, false);
				std::pair<bool, bool>	resultLeft = _booleanEvaluationRecursive(str, --idx);
				if (!resultLeft.second)
					return std::make_pair(false, false);
				return std::make_pair(resultLeft.first | resultRight.first, true);
			}
			case '^':
			{
				std::pair<bool, bool>	resultRight = _booleanEvaluationRecursive(str, --idx);
				if (!resultRight.second)
					return std::make_pair(false, false);
				std::pair<bool, bool>	resultLeft = _booleanEvaluationRecursive(str, --idx);
				if (!resultLeft.second)
					return std::make_pair(false, false);
				return std::make_pair(resultLeft.first ^ resultRight.first, true);
			}
			case '=':
			{
				std::pair<bool, bool>	resultRight = _booleanEvaluationRecursive(str, --idx);
				if (!resultRight.second)
					return std::make_pair(false, false);
				std::pair<bool, bool>	resultLeft = _booleanEvaluationRecursive(str, --idx);
				if (!resultLeft.second)
					return std::make_pair(false, false);
				return std::make_pair(resultLeft.first == resultRight.first, true);
			}
			case '>':
			{
				std::pair<bool, bool>	resultRight = _booleanEvaluationRecursive(str, --idx);
				if (!resultRight.second)
					return std::make_pair(false, false);
				std::pair<bool, bool>	resultLeft = _booleanEvaluationRecursive(str, --idx);
				if (!resultLeft.second)
					return std::make_pair(false, false);
				return std::make_pair(!(resultLeft.first && !resultRight.first), true);
			}
			default:
				return std::make_pair(false, false);
		}
	}

	std::pair<bool, bool>	booleanEvaluation(const std::string &str)
	{
		std::string::size_type	idx = str.size() - 1;
		std::pair<bool, bool>	result = _booleanEvaluationRecursive(str, idx);
		if (idx)
			return std::make_pair(false, false);
		return result;
	}

}

#endif