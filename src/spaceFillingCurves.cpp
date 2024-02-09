#include "../includes/spaceFillingCurves.hpp"

namespace ft
{
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