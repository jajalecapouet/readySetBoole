#ifndef SPACEFILLINGCURVES_HPP
#define SPACEFILLINGCURVES_HPP

#include <utility>
#include <cmath>
#include <iostream>

namespace ft
{
	typedef unsigned short us;
	const us BASE = 2;

	/// @brief map coordinates (x, y) in a range [0, 1].
	/// The goal of the exercise isn't to abuse to the mantiss which is able binarely to contain easily x and y separately.
	/// But to find a way to store any combinations of x and y between 0 and 1 by using decimal operators.
	/// @param x the x coordinate
	/// @param y the y coordinate
	/// @return the double in range [0, 1] which map the coordinates (x, y)
	double map(us x, us y);

	std::pair<us, us> reverse_map(double d);
}

#endif