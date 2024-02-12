#ifndef SPACEFILLINGCURVES_HPP
#define SPACEFILLINGCURVES_HPP

#include <utility>
#include <cmath>
#include <iostream>

namespace ft
{
	typedef unsigned short us;
	const us BASE = 2;

	/// @brief	map coordinates (x, y) to a decimal in a range [0, 1[.
	/// 		The goal of the exercise isn't to abuse to the mantiss which is able binarely to contain easily x and y separately.
	/// 		The goal is to find a way to store any combinations of x and y between 0 and 1 by using decimal operators.
	///			This function is injective : for each result R, they're is only one (x, y) where map(x, y) = R.
	///			This function is not surjective : It exists at least one R in the range [0, 1[ of decimals where
	///			a (x, y) does not exists for map(x, y) = R.
	/// @param	x the x coordinate
	/// @param	y the y coordinate
	/// @return	the double in range [0, 1[ which map the coordinates (x, y)
	double map(us x, us y);

	/// @brief	Map a decimale value in a range [0, 1[ to a value in N*N in range [0, 65535] * [0, 65535]
	///			This function is surjective : for each element E of [0, 65535] * [0, 65535] it exists
	///			 a d in range [0, 1[ where f(d) = E.
	///			This function is not injective : 2 realy nears values can return a same result.
	/// @param	d a double.
	/// @return	a pair of unsigned short.
	std::pair<us, us> reverse_map(double d);
}

#endif