#ifndef SPACEFILLINGCURVES_HPP
#define SPACEFILLINGCURVES_HPP

#include <utility>
#include <cmath>
#include <iostream>

namespace ft
{
	typedef __UINT16_TYPE__ ui;

	/// @brief map coordinates (x, y) in a range [0, 1].
	/// The goal of the exercise isn't to abuse to the mantiss which is able binarely to contain easily x and y separately.
	/// But to find a way to store any combinations of x and y between 0 and 1 by using decimal operators.
	/// @param x the x coordinate
	/// @param y the y coordinate
	/// @return the double in range [0, 1] which map the coordinates (x, y)
	double map(ui x, ui y)
	{
		double res;
		unsigned int divide = 10;

		res = 0;
		while (x)
		{
			res += (double)(x % 10) / divide;
			x /= 10;
			divide *= 100;
		}
		divide = 100;
		while (y)
		{
			res += (double)(y % 10) / divide;
			divide *= 100;
			y /= 10;
		}
		return res;
	}

	std::pair<ui, ui> reverse_map(double d)
	{
		std::pair<ui, ui> res;
		ui xMlt;
		ui yMlt;
		bool xTurn;
		ui part;

		xMlt = 1;
		yMlt = 1;
		xTurn = true;
		while (d != 0)
		{
			std::cout << "d = " << d << '\n';
			d *= 10;
			part = d;
			std::cout << "d = " << d << '\n';
			std::cout << "part = " << part << '\n';
			d -= part;
			std::cout << "d = " << d << '\n';
			if (xTurn)
			{
				res.first += part * xMlt;
				xMlt *= 10;
			}
			else
			{
				res.second += part * yMlt;
				yMlt *= 10;
			}
			xTurn = !xTurn;
		}
		return res;
	}
}

#endif