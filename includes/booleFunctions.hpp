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

	/// @brief	Detect if the input string has at least one uppercase.
	/// @param	str The input string.
	/// @return	true of false.
	bool	_hasUpperCase(const std::string &str);

	/// @brief	Do an addition between 2 integers with using only bit operations.
	///			and displaying each step of the operation.
	/// @param	a a int.
	/// @param	b a int.
	/// @return	a + b.
	unsigned int	adderDemoVersion(unsigned int a, unsigned int b);

	/// @brief	Do an addition between 2 integers with using only bit operations.
	/// @param	a a int.
	/// @param	b a int.
	/// @return	a + b.
	unsigned int	adder(unsigned int a, unsigned int b);

	/// @brief	Do an multiplication between 2 integers with using only bit operations.
	/// @param	a a int.
	/// @param	b a int.
	/// @return	a * b.
	unsigned int	multiplier(unsigned int a, unsigned int b);

	/// @brief	Transform an int to another int which interpret his binary code to a Grey code.
	/// @param	a a int.
	/// @return	An integer.
	unsigned int	GrayCode(unsigned int a);

	/// @brief	Read a binary formula in reverse polish notation without unknown term.
	///			exemple 01!&1| return true 11|! return false.
	/// @param	str a binary formula in reverse polish notation.
	/// @return	true or false.
	std::pair<bool, bool>	booleanEvaluation(const std::string &str);

	/// @brief	Read a binary formula in reverse polish notation and print his truth table.
	/// @param	str a binary formula in reverse polish notation.
	void	printTruthTable(const std::string &str);

	/// @brief	Read a binary formula in reverse polish notation and print his truth table. 
	///			This one has better optimization and display the table in alphabetical order.
	/// @param	str a binary formula in reverse polish notation.
	void printTruthTableV2(const std::string& str);

	/// @brief	Transform a binary formula in reverse polish notation to a negation normal form.
	///			That means that every negation operators (!) must be located right after a variable.
	/// @param	str a binary formula in reverse polish notation.
	std::string	negationNormalForm(const std::string &str);

	/// @brief	Represent a map of pair (atom, state) which has booleanEvaluation to false.
	typedef std::map<char, bool>	fComb;

	///	@brief	A conjunction can be built thanks of all set of atoms states which return false.
	///			Then we can revert all those atom states (a -> a!, b! -> b) in each set, and
	///			disjontiv them each other ({a, b!, ..., n} -> (a v b! v ... v n)), then
	///			conjunctiv each disjonction
	///	@param	str a binary formula in reverse polish notation.
	///	@return	a new binary formula in reverse polish notation as conjunctive normal form.
	std::string conjunctiveNormalForm(const std::string& str);

	///	@brief	Read a binary formula in reverse polish notation and determines if it has a true solution.
	///	@param	str a binary formula in reverse polish notation.
	///	@return	true or false.
	bool	sat(const std::string& str);

	///	@brief	Read a set of integers and returns his powerset.
	///			A powerset represents all possible subsets in this set.
	///	@param	atoms a vector of ints.
	///	@return	a vector of vector of ints.
	std::vector<std::vector<int> >	powerset(const std::vector<int>& atoms);

	/// @brief Apply the formula to the list of sets.
	/// @param str a propositional formula in reverse polish notation.
	/// @param sets a list of sets as vector of vector of int.
	/// @return a set resulted by the evaluation of the list of set by the formula.
	std::vector<int>	eval_set(const std::string& str, const std::vector<std::vector<int> >& sets);

}

#endif