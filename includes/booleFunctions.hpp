#ifndef BOOLEFUNCTIONS
#define BOOLEFUNCTIONS

#include "MyNatural.hpp"
#include <cmath>
#include <string>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

namespace ft
{

	bool	_hasUpperCase(const std::string &str);

	unsigned int	adderDemoVersion(unsigned int a, unsigned int b);

	unsigned int	adder(unsigned int a, unsigned int b);

	unsigned int	multiplier(unsigned int a, unsigned int b);

	unsigned int	GrayCode(unsigned int a);

	std::pair<bool, bool>	booleanEvaluation(const std::string &str);

	void	printTruthTable(const std::string &str);

	void printTruthTableV2(const std::string& str);

	std::string	negationNormalForm(const std::string &str);

	typedef std::map<char, bool>	fComb; //represent a map of pair (atom, state) which has booleanEvaluation to false.

	/**
	  * A conjunction can be built thanks of all set of atoms states which return false.
	  * Then we can revert all those atom states (a -> a!, b! -> b) in each set, and
	  * disjontiv them each other ({a, b!, ..., n} -> (a v b! v ... v n)), then
	  * conjunctiv each disjonction
	  */
	std::string conjunctiveNormalForm(const std::string& str);

	bool	sat(const std::string& str);

	std::vector<std::vector<int> >	powerset(const std::vector<int>& atoms);

	/// @brief Apply the formula to the list of sets
	/// @param str a propositional formula in reverse polish notation
	/// @param sets a list of sets as vector of vector of int
	/// @return a set resulted by the evaluation of the list of set by the formula
	std::vector<int>	eval_set(const std::string& str, const std::vector<std::vector<int> >& sets);

}

#endif