#include "../includes/booleFunctions.hpp"
#include <iostream>
#include <string>

int main()
{
	std::vector<std::vector<int> > sets({
		{0, 1, 2},
		{2, 1, 4},
		{2, 3, 4},
		{4, 5}
	});

	std::string formula("AC>A=B|D|");
	std::vector<int> result = ft::eval_set(formula, sets);

	std::cout << '{';
	for (int i : result)
	{
		std::cout << i << ' ';
	}
	std::cout << "}\n";

	return 0;
}