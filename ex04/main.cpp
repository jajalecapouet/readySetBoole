#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{
	while (true)
	{
		std::cout << "insert a truth table sentence :";
		std::string	input;
		if (!getline(std::cin, input))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (input == "quit")
			break;
		printTruthTable(input);
		std::cout << '\n';
	}
	return 0;
}