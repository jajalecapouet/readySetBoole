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
	us _getMaxWeigth()
	{
		us a = 1;
		us b = 0;

		if (BASE == 2)
			return 32768;
		while (a > b)
		{
			b = a;
			a *= BASE;
		}
		return b;
	}

	double map(us x, us y)
	{
		double res;
		us weigth = _getMaxWeigth();
		double divide = BASE;

		res = 0;
		while (weigth)
		{
			if (x >= weigth)
			{
				res += ((double)(x / weigth) / divide);
				x -= weigth;
			}
			divide *= BASE;
			if (y >= weigth)
			{
				res += ((double)(y / weigth) / divide);
				y -= weigth;
			}
			divide *= BASE;
			weigth /= BASE;
		}
		return res;
	}

	std::pair<us, us> reverse_map(double d)
	{
		std::pair<us, us> res;
		us weigth = _getMaxWeigth();
		us part;

		while (weigth)
		{
			d *= BASE;
			part = d;
			d -= part;
			res.first += part * weigth;
			d *= BASE;
			part = d;
			d -= part;
			res.second += part * weigth;
			weigth /= BASE;
		}
		return res;
	}
}

#endif