#include "../includes/spaceFillingCurves.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>

void ultimateTest()
{
	std::cout << "ULTIMATE TEST : " << '\n';
	bool iMaxReached = false;
	bool jMaxReached;
	ft::us i = 0;
	ft::us j;
	ft::us pourcent = 0;
	bool fail = false;
	while (!fail && !iMaxReached)
	{
		if (!(i % 655))
			std::cout << pourcent++ << "%\n";
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
		std::cout << "test succeed.\n";
}

int main()
{
	typedef std::map<double, std::pair<ft::us, ft::us> > Curve;
	std::cout << std::setprecision(16);
	std::ofstream out("jaja.csv");
	std::pair<ft::us, ft::us> coord;
	Curve curve;
	double d;
	std::string aStr;
	std::string bStr;
	std::string input;
	ft::us a;
	ft::us b;

	std::cout << "Exercise 10 : map a coordinate of unsigned short (a, b) in a double in range [0, 1[\n";
	while (1)
	{
		try
		{
			std::cout << "\nput a value for a : ";
			std::cin >> aStr;
			a = std::stoi(aStr);
			std::cout << "\nput a value for b : ";
			std::cin >> bStr;
			b = std::stoi(bStr);
			std::cout << '(' << a << ", " << b << ") has for mapped value : " << ft::map(a, b) << 'n';
		}
		catch (const std::exception& e)
		{
			break;
		}
	}

	std::cout << "Exercise 11 : reverse_map a double in range [0, 1[ to retrieve the coordinate of unsigned shorts (a, b)\n";
	while (1)
	{
		try
		{
			std::cout << "\nput a value for d : ";
			std::cin >> input;
			d = std::stod(input);
			coord = ft::reverse_map(d);
			std::cout << d << " has for reverse_mapped value : (" << coord.first << ", " << coord.second << ")\n";
		}
		catch (const std::exception& e)
		{
			break;
		}
	}

	std::cout << "creating csv file of my space filling curve function\n";
	for (ft::us y = 0; y < 40; ++y)
	{
		for (ft::us x = 0; x < 40; ++x)
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
	std::cout << "file done and ready to get read by the curveDrawer\n";

	std::cout << "do you want to do the ultimate test (~40minutes) ? yes or whatever";
	try
	{
		std::cin >> input;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (errno);
	}
	if (input == "yes")
		ultimateTest();
	std::cout << "GoodBye !\n";
	return 0;
}