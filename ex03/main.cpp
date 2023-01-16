#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{
	while (true)
	{
		std::cout << "insert a bool sentence :";
		std::string	input;
		if (!getline(std::cin, input))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (input == "quit")
			break;
		std::cout << input;
		std::pair<bool, bool>	result = booleanEvaluation(input);
		if (result.second)
		{
			if (result.first)
				std::cout << " is true.\n";
			else
				std::cout << " is false.\n";
		}
		else
			std::cout << " isn't evaluable.\n";
	}
	return 0;
}