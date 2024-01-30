#include "../includes/booleFunctions.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string			input;
	std::string			lineCout;
	std::vector<int>	nbrSet;
	std::vector<std::vector<int> >	powerSet;

	while (true)
	{
		std::cout << "insert numbers or empty line to end : ";
		if (!getline(std::cin, input))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (input.empty())
			break;
		try
		{
			nbrSet.push_back(std::stoi(input));
		}
		catch (std::invalid_argument& e)
		{
			std::cout << "bad argument, input ignored.\n";
		}
	}
	for (int i : nbrSet)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	powerSet = ft::powerset(nbrSet);
	
	for (std::vector<int> v : powerSet)
	{
		lineCout.clear();
		std::cout << '{';
		for (int i : v)
		{
			lineCout += std::to_string(i);
			lineCout += ", ";
		}
		if (!lineCout.empty())
			lineCout.erase(lineCout.size() - 2);
		std::cout << lineCout << "}\n";
	}

	return 0;
}