#include "../includes/spaceFillingCurves.hpp"
#include <iostream>

int main()
{
	double d = ft::map(145, 432);
	std::cout << d << '\n';

	std::pair<ft::ui, ft::ui> coord = ft::reverse_map(d);
	std::cout << coord.first << " | " << coord.second << '\n';
	return 0;
}