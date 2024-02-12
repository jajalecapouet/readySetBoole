#include "../includes/booleFunctions.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string	formula;
	std::vector<int> result;
	std::vector<std::vector<int> > sets({
		{0, 1, 2},
		{2, 1, 4},
		{2, 3, 4},
		{4, 5}
	});

	while (1)
	{
		std::cout << "insert a bool sentence :";
		if (!getline(std::cin, formula))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		result = ft::eval_set(formula, sets);
		std::cout << '{';
		for (int i : result)
		{
			std::cout << i << ' ';
		}
		std::cout << "}\n";
	}



	return 0;
}