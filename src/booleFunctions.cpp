#include "../includes/booleFunctions.hpp"

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

	void	_printTruthTableRecursiveV2(std::string str, std::string& construct, std::set<char> alphas)
	{
		std::string				cpy;
		char					toBoolAssign;
		std::pair<bool, bool>	result;

		if (alphas.empty())
		{
			std::cout << construct;
			result = booleanEvaluation(str);
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
		else
		{
			cpy = str;
			toBoolAssign = (*alphas.begin());
			alphas.erase(alphas.begin());
			_replaceValueInString(str, toBoolAssign, '0');
			construct += "| 0 ";
			_printTruthTableRecursiveV2(str, construct, alphas);
			_replaceValueInString(cpy, toBoolAssign, '1');
			construct.erase(construct.size() - 4);
			construct += "| 1 ";
			_printTruthTableRecursiveV2(cpy, construct, alphas);
			construct.erase(construct.size() - 4);
		}
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

	void printTruthTableV2(const std::string& str)
	{
		std::set<char> alphas;
		std::string construct;

		for (char c : str)
		{
			if (std::isupper(c))
				alphas.insert(c);
		}
		std::cout << "| ";
		for (std::set<char>::const_iterator cit = alphas.begin(); cit != alphas.end(); ++cit)
			std::cout << *cit << " | ";
		std::cout << "= |\n|";
		for (std::set<char>::size_type i = 0; i <= alphas.size(); ++i)
			std::cout << "---|";
		std::cout << '\n';
		_printTruthTableRecursiveV2(str, construct, alphas);
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

	void	_negationNormalForm(std::string &str)
	{
		_transformMaterialCondition(str);
		_transformEquivalence(str);
		_transformXor(str);
		_negationNormalFormRecursive(str);
	}

	void	_getFalseSets(std::string str, std::set<char> alphas, std::set<fComb>& allFalseSets, fComb& currentSet)
	{
		std::string				cpy;
		char					toBoolAssign;
		std::pair<bool, bool>	result;

		if (alphas.empty())
		{
			result = booleanEvaluation(str);
			if (!result.first)
				allFalseSets.insert(currentSet);
		}
		else
		{
			cpy = str;
			toBoolAssign = (*alphas.begin());
			alphas.erase(alphas.begin());
			_replaceValueInString(str, toBoolAssign, '0');
			currentSet[toBoolAssign] = false;
			_getFalseSets(str, alphas, allFalseSets, currentSet);
			_replaceValueInString(cpy, toBoolAssign, '1');
			currentSet[toBoolAssign] = true;
			_getFalseSets(cpy, alphas, allFalseSets, currentSet);
		}
	}

	std::string	_buildConjonctiveNormalForm(const std::set<fComb>& combs, double max)
	{
		std::string result;

		if (combs.empty())
			return "1";
		if (combs.size() == max)
			return "0";
		for (std::set<fComb>::const_iterator cit = combs.begin(); cit != combs.end(); ++cit)
		{
			for (fComb::const_iterator fcit = cit->begin(); fcit != cit->end(); ++fcit)
			{
				result += fcit->first;
				if (fcit->second)
					result += '!';
			}
			result.insert(result.end(), cit->size() - 1, '|');
		}
		result.insert(result.end(), combs.size() - 1, '&');
		return result;
	}

	/**
	  * A conjunction can be built thanks of all set of atoms states which return false.
	  * Then we can revert all those atom states (a -> a!, b! -> b) in each set, and
	  * disjontiv them each other ({a, b!, ..., n} -> (a v b! v ... v n)), then
	  * conjunctiv each disjonction
	  */
	std::string conjunctiveNormalForm(const std::string& str)
	{
		std::set<char>	alphas;
		std::set<fComb>	allFalseSets;
		fComb			current;

		if (!_isGoodBooleanFormula(str))
			return {};
		for (char c : str)
		{
			if (std::isupper(c))
				alphas.insert(c);
		}
		if (alphas.empty())
		{
			if (booleanEvaluation(str).first)
				return "1";
			return "0";
		}
		_getFalseSets(str, alphas, allFalseSets, current);

		return _buildConjonctiveNormalForm(allFalseSets, pow(2, alphas.size()));
	}

	bool	sat(const std::string& str)
	{
		std::string conj = conjunctiveNormalForm(str);

		if (conj.empty() || conj == "0")
			return false;
		return true;
	}

	void _recuPowerSet(std::vector<int> atoms, std::vector<int>::size_type depth, std::vector<int>& current, std::vector<std::vector<int> >& pwrSet)
	{
		if (depth == 0)
			pwrSet.push_back(current);
		else
		{
			while (depth <= atoms.size())
			{
				current.push_back(atoms.back());
				atoms.pop_back();
				_recuPowerSet(atoms, depth - 1, current, pwrSet);
				current.pop_back();
			}
		}
	}

	std::vector<std::vector<int> >	powerset(const std::vector<int>& atoms)
	{
		typedef std::vector<std::vector<int> >	Powerset;
		typedef std::vector<int>::size_type	Size;

		std::vector<int>	current;
		Powerset			pwrSet;
		for (Size depth = 0; depth <= atoms.size(); ++depth)
		{
			_recuPowerSet(atoms, depth, current, pwrSet);
		}
		return pwrSet;
	}

	std::set<int>&	_joinSets(std::set<int>& lhs, std::set<int>& rhs)
	{
		std::set<int>& smaller = lhs.size() < rhs.size() ? lhs : rhs;
		std::set<int>& bigger = lhs.size() >= rhs.size() ? lhs : rhs;

		for (std::set<int>::const_iterator cit = smaller.begin(); cit != smaller.end(); ++cit)
			bigger.insert(*cit);
		delete (&smaller);
		return bigger;
	}

	std::set<int>&	_interSets(std::set<int>& lhs, std::set<int>& rhs)
	{
		std::set<int>& smaller = lhs.size() < rhs.size() ? lhs : rhs;
		std::set<int>& bigger = lhs.size() >= rhs.size() ? lhs : rhs;

		std::set<int>::iterator it = smaller.begin();
		while (it != smaller.end())
		{
			if (bigger.find(*it) == bigger.end())
				it = smaller.erase(it);
			else
				++it;
		}
		delete (&bigger);
		return smaller;
	}

	std::set<int>&	_negateSet(std::set<int>& set)
	{
		set.clear();
		return set;
	}

	std::set<int>&	_assignSet(char c, const std::vector<std::set<int> >& sets)
	{
		std::set<int>* toRet;
	
		try
		{
			toRet = new std::set<int>(sets.at(c - 'A'));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "Bad input given, a set couldn't be assignate\n";
			toRet = new std::set<int>();
		}
		return *toRet;
	}

	std::set<int>&	_recuEvalSetConjForm(const std::string& str, const std::vector<std::set<int> >& sets, std::string::size_type& idx)
	{
		switch (str[idx])
		{
			case '!':
				return _negateSet(_recuEvalSetConjForm(str, sets, --idx));
			case '|':
				return _joinSets(_recuEvalSetConjForm(str, sets, --idx), _recuEvalSetConjForm(str, sets, --idx));
			case '&':
				return _interSets(_recuEvalSetConjForm(str, sets, --idx), _recuEvalSetConjForm(str, sets, --idx));
			default:
				return _assignSet(str[idx], sets);
		}
	}

	std::vector<int>	_evalSetConjForm(const std::string& str, const std::vector<std::set<int> >& sets)
	{
		std::string::size_type recuIdxStart = str.size() - 1;
		std::set<int>& finalSet = _recuEvalSetConjForm(str, sets, recuIdxStart);
		std::vector<int> result(finalSet.begin(), finalSet.end());

		delete (&finalSet);
		return result;
	}

	/// @brief Apply the formula to the list of sets
	/// @param str a propositional formula in reverse polish notation
	/// @param sets a list of sets as vector of vector of int
	/// @return a set resulted by the evaluation of the list of set by the formula
	std::vector<int>	eval_set(const std::string& str, const std::vector<std::vector<int> >& sets)
	{
		std::string conj;
		std::vector<std::set<int> > trueSets;

		if (str.empty() || sets.empty())
		{
			std::cout << "empty inputs.\n";
			return {};
		}
		conj = conjunctiveNormalForm(str);
		if (conj.empty())
		{
			std::cout << "the formula has wrong format.\n";
			return {};
		}
		std::cout << "conjonctive form : " << conj << '\n';
		for (std::vector<int> set : sets)
			trueSets.push_back(std::set<int>(set.begin(), set.end()));
		return _evalSetConjForm(conj, trueSets);
	}
} // namespace ft