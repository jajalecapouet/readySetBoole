#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{

	while (true)
	{
		std::string	input;
		bool satResult;

		std::cout << "insert a boolean formula : ";
		if (!getline(std::cin, input))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (input == "quit" || input == "exit" || input == "end" || input == "tg")
			break;
		
		satResult = sat(input);
		if (satResult)
			std::cout << "has combinations\n";
		else
			std::cout << "doesn't have combination.\n";
	}

	return 0;
}