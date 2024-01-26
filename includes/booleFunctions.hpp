#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#ifndef BOOLEFUNCTIONS
#define BOOLEFUNCTIONS

#include "MyNatural.hpp"
#include <string>
#include <utility>

namespace ft
{

	bool	isBool(int c)
	{
		return (c == '0' || c == '1');
	}

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
			unsigned int	next;
			for (int i = 0; i < 32; ++i)
			{
				next = compareTo << 1;
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

	bool	_isGoodBooleanFormulaRecursive(const std::string &str, std::string::size_type &idx)
	{
		if (idx == std::string::npos
			|| (idx <= 1 && !(isBool(str[idx]) || std::isupper(str[idx])) && str[idx] != '!')
			|| (!idx && str[idx] == '!'))
			return false;
		if (isBool(str[idx]) || std::isupper(str[idx]))
			return true;
		if (str[idx] == '!')
			return _isGoodBooleanFormulaRecursive(str, --idx);
		std::string	cmp("=&>^|");
		if (cmp.find(str[idx]) == std::string::npos)
			return false;
		return (_isGoodBooleanFormulaRecursive(str, --idx) & _isGoodBooleanFormulaRecursive(str, --idx));
	}

	bool	_isGoodBooleanFormula(const std::string &str)
	{
		std::string::size_type	idx = str.size() - 1;

		bool	result = _isGoodBooleanFormulaRecursive(str, idx);
		if (idx)
			return false;
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
				return std::make_pair(!resultLeft.first || resultRight.first, true);
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

	bool	_hasUpperCase(const std::string &str)
	{
		for (char anthese : str)
		{
			if (std::isupper(anthese))
				return true;
		}
		return false;
	}

	void	_replaceValueInString(std::string &str, char toReplace, char byThat)
	{
		for (char &bonniere : str)
		{
			if (bonniere == toReplace)
				bonniere = byThat;
		}
	}

	//I preferred to copy the string str : because of the recursive replacement of each variable (A, B, C...) by 1 or 2,
	//I can't recover the previous state of str without using memories, which is complicated and probably not better
	void	_printTruthTableRecursive(std::string str, std::string::size_type idx, std::string &construct)
	{
		if (!_hasUpperCase(str))
		{
			std::cout << construct;
			std::pair<bool, bool>	result = booleanEvaluation(str);
			if (!result.second)
				std::cout << "|Err|\n";
			else
			{
				if (result.first)
					std::cout << "| 1 |\n";
				else
					std::cout << "| 0 |\n";
			}
		}
		else if (std::isupper(str[idx]))
		{
			std::string cpy(str);
			char	toReplace = str[idx];
			_replaceValueInString(str, str[idx], '0');
			construct += "| 0 ";
			_printTruthTableRecursive(str, idx + 1, construct);
			_replaceValueInString(cpy, toReplace, '1');
			construct.erase(construct.size() - 4);
			construct += "| 1 ";
			_printTruthTableRecursive(cpy, idx + 1, construct);
			construct.erase(construct.size() - 4);
		}
		else
			_printTruthTableRecursive(str, idx + 1, construct);
	}

	void	printTruthTable(const std::string &str)
	{
		char	variables[26];
		for (int i = 0; i < 26; ++i)
			variables[i] = 0;
		size_t	size = 0;
		for (char check : str)
		{
			if (std::isupper(check))
			{
				bool insert = true;
				for (size_t i = 0; i < size; ++i)
				{
					if (variables[i] == check)
						insert = false;
				}
				if (insert)
				{
					variables[size] = check;
					++size;
				}
			}
		}
		std::cout << "| ";
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << variables[i] << " | ";
		}
		std::cout << "= |\n|";
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << "---|";
		}
		std::cout << "---|\n";
		std::string::size_type idx = 0;
		std::string construct;
		_printTruthTableRecursive(str, idx, construct);
	}

	void	_transformMaterialConditionRecursive(std::string &str, std::string::size_type &idx)
	{
		switch (str[idx])
		{
			case '>':
				str[idx] = '|';
				_transformMaterialConditionRecursive(str, --idx);
				str.insert(idx, "!");
				_transformMaterialConditionRecursive(str, --idx);
				break;
			case '!':
				_transformMaterialConditionRecursive(str, --idx);
				break;
			case '^':
				_transformMaterialConditionRecursive(str, --idx);
				_transformMaterialConditionRecursive(str, --idx);
				break;
			case '=':
				_transformMaterialConditionRecursive(str, --idx);
				_transformMaterialConditionRecursive(str, --idx);
				break;
			case '&':
				_transformMaterialConditionRecursive(str, --idx);
				_transformMaterialConditionRecursive(str, --idx);
				break;
			case '|':
				_transformMaterialConditionRecursive(str, --idx);
				_transformMaterialConditionRecursive(str, --idx);
				break;
			default:
				return;
		}
	}

	void	_transformMaterialCondition(std::string &str)
	{
		std::string::size_type idx = str.size();

		while (idx && --idx > 1)
		{
			if (str[idx] == '>')
			{
				str[idx] = '|';
				_transformMaterialConditionRecursive(str, --idx);
				str.insert(idx, "!");
				_transformMaterialConditionRecursive(str, --idx);
			}
		}
	}

	void	_inverse(std::string &str, std::string::size_type &idx);
	void	_reachEndCond(std::string &str, std::string::size_type &idx)
	{
		switch (str[idx])
		{
			case '!':
			{
				if (isBool(str[idx - 1]) || std::isupper(str[idx - 1]))
					_reachEndCond(str, --idx);
				else
				{
					str.erase(idx, 1);
					_inverse(str, --idx);
				}
				break;
			}
			case '&':
				_reachEndCond(str, --idx);
				_reachEndCond(str, --idx);
				break;
			case '|':
				_reachEndCond(str, --idx);
				_reachEndCond(str, --idx);
				break;
			default:
				return;
		}
	}

	void	_inverse(std::string &str, std::string::size_type &idx)
	{
		switch (str[idx])
		{
			case '!':
				str.erase(idx, 1);
				_reachEndCond(str, --idx);
				break;
			case '&':
				str[idx] = '|';
				_inverse(str, --idx);
				_inverse(str, --idx);
				break;
			case '|':
				str[idx] = '&';
				_inverse(str, --idx);
				_inverse(str, --idx);
				break;
			default:
				str.insert(idx + 1, "!");
		}
	}

	void	_negationNormalFormRecursive(std::string &str)
	{
		std::string::size_type idx = str.size();

		while (idx && --idx > 1) {
			if (str[idx] == '!' && !(isBool(str[idx - 1]) || std::isupper(str[idx - 1]))) {
				str.erase(idx, 1);
				switch (str[--idx])
				{
					case '!':
						str.erase(idx, 1);
						break;
					case '&':
						str[idx] = '|';
						_inverse(str, --idx);
						_inverse(str, --idx);
						break;
					default:
						str[idx] = '&';
						_inverse(str, --idx);
						_inverse(str, --idx);
				}
			}
		}
	}

	void	_reachEndCondAndConstruct(std::string &str, std::string::size_type &idx, std::string &construct)
	{
		char	abeu = str[idx];
		str.erase(idx, 1);
		construct.insert(0, 1, abeu);
		switch (abeu)
		{
			case '!':
				_reachEndCondAndConstruct(str, --idx, construct);
				break;
			case '=':
				_reachEndCondAndConstruct(str, --idx, construct);
				_reachEndCondAndConstruct(str, --idx, construct);
				break;
			case '&':
				_reachEndCondAndConstruct(str, --idx, construct);
				_reachEndCondAndConstruct(str, --idx, construct);
				break;
			case '|':
				_reachEndCondAndConstruct(str, --idx, construct);
				_reachEndCondAndConstruct(str, --idx, construct);
				break;
			case '^':
				_reachEndCondAndConstruct(str, --idx, construct);
				_reachEndCondAndConstruct(str, --idx, construct);
				break;
			default:
				return;
		}
	}

	void	_transformEquivalence(std::string &str)
	{
		std::string::size_type idx = str.size();

		while (idx && --idx > 1)
		{
			if (str[idx] == '=')
			{
				str[idx] = '|';
				std::string condA;
				std::string	condB;
				_reachEndCondAndConstruct(str, --idx, condA);
				_reachEndCondAndConstruct(str, --idx, condB);
				str.insert(idx, "!&");
				str.insert(idx, condA);
				str.insert(idx, "!");
				str.insert(idx, condB);
				str.insert(idx, "&");
				str.insert(idx, condA);
				str.insert(idx, condB);
				idx = str.size();
			}
		}
	}

	void	_transformXor(std::string &str)
	{
		std::string::size_type idx = str.size();

		while (idx && --idx > 1)
		{
			if (str[idx] == '^')
			{
				str[idx] = '|';
				std::string condA;
				std::string	condB;
				_reachEndCondAndConstruct(str, --idx, condA);
				_reachEndCondAndConstruct(str, --idx, condB);
				str.insert(idx, "!&");
				str.insert(idx, condA);
				str.insert(idx, condB);
				str.insert(idx, "&");
				str.insert(idx, condA);
				str.insert(idx, "!");
				str.insert(idx, condB);
				idx = str.size();
			}
		}
	}

	std::string	negationNormalForm(const std::string &str)
	{
		if (!_isGoodBooleanFormula(str))
			return {};
		std::string	result(str);
		_transformMaterialCondition(result);
		_transformEquivalence(result);
		_transformXor(result);
		_negationNormalFormRecursive(result);
		return result;
	}

	std::string disjunctiveNormalForm(const std::string& str)
	{
		
	}

	std::string conjunctiveNormalForm(const std::string& str)
	{

	}

}

#endif
#pragma clang diagnostic pop