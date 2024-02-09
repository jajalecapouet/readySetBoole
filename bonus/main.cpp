#include "../includes/spaceFillingCurves.hpp"
#include <iostream>
#include <map>
#include <fstream>

int main()
{
	typedef std::map<double, std::pair<ft::us, ft::us> > Curve;
	Curve curve;
	double d = ft::map(8922, 1342);
	std::cout << d << '\n';

	std::pair<ft::us, ft::us> coord = ft::reverse_map(d);
	std::cout << coord.first << " | " << coord.second << '\n';

	std::cout << "check for curve\n";

	std::ofstream out("jaja.csv");

	double d2 = 0;
	for (ft::us y = 0; y < 200; ++y)
	{
		for (ft::us x = 0; x < 200; ++x)
		{
			coord.first = x;
			coord.second = y;
			curve[ft::map(x, y)] = coord;
		}
	}

	out << "x,y\n";
	for (Curve::const_iterator cit = curve.begin(); cit != curve.end(); ++cit)
		out << cit->second.first << "," << cit->second.second << '\n';
	out.close();

	std::cout << "ULTIMATE TEST : " << '\n';

	bool iMaxReached = false;
	bool jMaxReached;
	ft::us i = 0;
	ft::us j;
	bool fail = false;
	while (!fail && !iMaxReached)
	{
		if (i == (ft::us)~0)
			iMaxReached = true;
		j = 0;
		jMaxReached = false;
		while (!jMaxReached)
		{
			if (std::make_pair(i, j) != ft::reverse_map(ft::map(i, j)))
			{
				std::cout << "failed at x = " << i << " y = " << j << '\n';
				fail = true;
				break;
			}
			if (j == (ft::us)~0)
				jMaxReached = true;
			++j;
		}
		++i;
	}

	if (!fail)
		std::cout << "test succeed\n";
	return 0;
}